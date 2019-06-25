/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH. All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  calculatorInterface_proxy_someip_binding.cc
 *        \brief  SOME/IP proxy binding of service 'calculatorInterface'
 *
 *      \details
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vector/calculatorService/calculatorInterface_proxy_someip_binding.h"
#include <utility>
#include "vector/calculatorService/calculatorInterface_proxy.h"

namespace vector {
namespace calculatorService {

constexpr someip_posix_common::someip::ServiceId CalculatorInterfaceProxySomeIpBinding::kServiceId;
constexpr someip_posix_common::someip::MajorVersion CalculatorInterfaceProxySomeIpBinding::kMajorVersion;

CalculatorInterfaceProxySomeIpBinding::CalculatorInterfaceProxySomeIpBinding(
    someip_posix_common::someip::InstanceId instance_id,
    ara::com::someip_posix::AraComSomeIpBindingInterface& someip_binding)
    : instance_id_(instance_id),
      client_id_(someip_binding.GetNextClientId()),
      someip_binding_(someip_binding),
      logger_(ara::log::CreateLogger("CalculatorInterfaceProxySomeIpBinding", "")),
      method_manager_subtract_(*this),
      method_manager_add_(*this),
      method_manager_divide_(*this),
      event_manager_divisionByZero_(*this),
      field_notifier_divideResult_(*this),
      field_manager_divideResult_get_(*this),
      field_manager_divideResult_set_(*this) {
  // Register this proxy binding for method responses and event notifications.
  someip_binding_.RegisterProxyBinding(
      std::make_tuple(CalculatorInterfaceProxySomeIpBinding::kServiceId, instance_id_, client_id_), this);
}

CalculatorInterfaceProxySomeIpBinding::~CalculatorInterfaceProxySomeIpBinding() {
  someip_binding_.DeRegisterProxyBinding(
      std::make_tuple(CalculatorInterfaceProxySomeIpBinding::kServiceId, instance_id_, client_id_));
}

void CalculatorInterfaceProxySomeIpBinding::SendMethodRequest(someip_posix_common::someip::SomeIpPacket&& packet) {
  someip_binding_.SendMethodRequest(instance_id_, std::move(packet));
}

void CalculatorInterfaceProxySomeIpBinding::SubscribeEvent(
    someip_posix_common::someip::EventId event_id,
    ara::com::someip_posix::ServiceProxySomeIpEventInterface* event_manager) {
  std::pair<EventSubscriptionsMap::iterator, bool> insert_pair{event_subscriptions_.end(), false};
  {
    // Protect concurrent modification of event_subscriptions_
    std::lock_guard<std::mutex> guard(event_subscriptions_lock_);

    // Subscribe to event
    insert_pair = event_subscriptions_.emplace(event_id, event_manager);
  }

  if (insert_pair.second) {
    someip_binding_.SubscribeEvent(CalculatorInterfaceProxySomeIpBinding::kServiceId, instance_id_, event_id);
  } else {
    logger_.LogWarn() << "Event with ID " << event_id << " already subscribed! Subscription is dropped.";
  }
}

void CalculatorInterfaceProxySomeIpBinding::UnsubscribeEvent(someip_posix_common::someip::EventId event_id) {
  ara::com::someip_posix::ServiceProxySomeIpEventInterface* event_manager = nullptr;
  {
    // Protect concurrent modification of event_subscriptions_
    std::lock_guard<std::mutex> guard(event_subscriptions_lock_);

    // Search event by ID
    auto it = event_subscriptions_.find(event_id);

    if (it != event_subscriptions_.end()) {
      // Store related event handler for later notification of subscription state update
      event_manager = it->second;

      // Delete route and unsubscribe from event
      event_subscriptions_.erase(it);
      someip_binding_.UnsubscribeEvent(CalculatorInterfaceProxySomeIpBinding::kServiceId, instance_id_, event_id);
    }
  }

  /* Notify the related event manager about subscription state update.
   * Done outside of event_subscriptions_lock_ due to possible dead-locks in case the event
   * subscription state update handler directly calls SubscribeEvent API. A possible unexpected
   * event notification in case of a Subscribe call between lock_guard and handler call is accepted. */
  if (event_manager) {
    event_manager->HandleEventSubscriptionStateUpdate(ara::com::SubscriptionState::kNotSubscribed);
  } else {
    logger_.LogWarn() << "No subscription active for event with SOME/IP event ID " << event_id
                      << " active. Unsubscription is dropped.";
  }
}

void CalculatorInterfaceProxySomeIpBinding::HandleMethodResponse(
    const ::someip_posix_common::someip::SomeIpMessageHeader& header, RootDeserializerAlias&& deserializer) {
  // Get method ID from header
  const someip_posix_common::someip::MethodId method_id = header.method_id_;

  // Based on the method id -> static dispatching to the method request/response manager
  switch (method_id) {
    case CalculatorInterfaceProxySomeIpMethodManagerSubtract::kMethodId: {
      method_manager_subtract_.HandleMethodResponse(header, std::move(deserializer));
      break;
    }
    case CalculatorInterfaceProxySomeIpMethodManagerAdd::kMethodId: {
      method_manager_add_.HandleMethodResponse(header, std::move(deserializer));
      break;
    }
    case CalculatorInterfaceProxySomeIpMethodManagerDivide::kMethodId: {
      method_manager_divide_.HandleMethodResponse(header, std::move(deserializer));
      break;
    }
    case CalculatorInterfaceProxySomeIpFieldManagerDivideResultGet::kMethodId: {
      field_manager_divideResult_get_.HandleMethodResponse(header, std::move(deserializer));
      break;
    }
    case CalculatorInterfaceProxySomeIpFieldManagerDivideResultSet::kMethodId: {
      field_manager_divideResult_set_.HandleMethodResponse(header, std::move(deserializer));
      break;
    }
    default: {
      logger_.LogError() << "Method response handling implementation for SOME/IP method ID " << method_id
                         << " is missing. Please re-configure.";
      break;
    }
  }
}

void CalculatorInterfaceProxySomeIpBinding::HandleEventNotification(
    const ::someip_posix_common::someip::SomeIpMessageHeader& header, RootDeserializerAlias&& deserializer) {
  // We need at least two things to assign the response to its request:
  // The method / event ID and the session ID.
  const someip_posix_common::someip::MethodId event_id = header.method_id_;

  ara::com::someip_posix::ServiceProxySomeIpEventInterface* event_manager = nullptr;
  {
    // Protect concurrent modification of event_subscriptions_ container.
    // Required in case of concurrent reception of new event notifications by reactor and Subscribe/Unsubscribe by
    // Application
    std::lock_guard<std::mutex> guard(event_subscriptions_lock_);

    // Search event subscription and call event notification handler
    auto it = event_subscriptions_.find(event_id);
    if (it != event_subscriptions_.end()) {
      event_manager = it->second;
    }
  }

  /* Call event notification handler. Explicitly done outside of event_subscriptions_lock_ to avoid
   * potential dead-locks in case application handler calls other event subscribe/unsubscribe APIs.
   * A possible unexpected event notification in case of Unsubscribe call between lock_guard and handler
   * call is accepted. */
  if (event_manager) {
    event_manager->HandleEventNotification(std::move(deserializer));
  } else {
    logger_.LogError() << "Routing of event notification failed. No event subscription found for event ID: "
                       << event_id;
  }
}

void CalculatorInterfaceProxySomeIpBinding::HandleEventSubscriptionStateUpdate(
    const someip_posix_common::someip::MethodId event_id, ara::com::SubscriptionState state) {
  ara::com::someip_posix::ServiceProxySomeIpEventInterface* event_manager = nullptr;
  {
    // Protect concurrent modification of event_subscriptions_ container.
    // Required in case of concurrent subscription state update by reactor and Subscribe/Unsubscribe by Application
    std::lock_guard<std::mutex> guard(event_subscriptions_lock_);

    // Search event subscription and call subscription state update handler
    auto it = event_subscriptions_.find(event_id);
    if (it != event_subscriptions_.end()) {
      event_manager = it->second;
    }
  }

  /* Call event subscription state change handler. Explicitely done outside of event_subscriptions_lock_ to avoid
   * potential dead-locks in case application handler calls other event subscribe/unsubscribe APIs. A possible
   * unexpected state change update in case of Unsubscribe call between lock_guard and handler call is accepted. */
  if (event_manager) {
    event_manager->HandleEventSubscriptionStateUpdate(state);
  } else {
    // event_subscription entry might have already been removed after UnsubscribeEvent call.
    if (state != ara::com::SubscriptionState::kNotSubscribed) {
      logger_.LogError()
          << "Routing of event subscription state update failed. No event subscription found for event ID: "
          << event_id;
    }
  }
}

}  // namespace calculatorService
}  // namespace vector
