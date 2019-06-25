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
/**        \file  calculatorInterface_proxy_someip_binding.h
 *        \brief  SOME/IP binding of service proxy for service 'calculatorInterface'
 *
 *      \details
 *
 *********************************************************************************************************************/

#ifndef ADAPTIVECALCULATORCLIENT_SOMEIP_POSIX_VECTOR_CALCULATORSERVICE_CALCULATORINTERFACE_PROXY_SOMEIP_BINDING_H_
#define ADAPTIVECALCULATORCLIENT_SOMEIP_POSIX_VECTOR_CALCULATORSERVICE_CALCULATORINTERFACE_PROXY_SOMEIP_BINDING_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <map>
#include <memory>
#include <tuple>
#include "ara-someip-posix/aracom_someip_binding_interface.h"
#include "ara-someip-posix/aracom_someip_proxy_interface.h"
#include "ara-someip-posix/service_proxy_someip_event_interface.h"
#include "ara/log/logging.hpp"
#include "vector/calculatorService/calculatorInterface_proxy.h"
#include "vector/calculatorService/calculatorInterface_proxy_impl_interface.h"
#include "vector/calculatorService/calculatorInterface_proxy_someip_event_manager.h"
#include "vector/calculatorService/calculatorInterface_proxy_someip_method_manager.h"

namespace vector {
namespace calculatorService {

/**
 * \brief SOME/IP proxy binding of Service 'calculatorInterface'.
 * \details Handles serialization and deserialization of all method calls, events, etc.
 * \remark generated
 */
class CalculatorInterfaceProxySomeIpBinding : public CalculatorInterfaceProxyImplInterface,
                                              public ara::com::someip_posix::AraComSomeIpProxyInterface {
 public:
  /**
   * \brief Generated SOME/IP related service ID.
   */
  static constexpr someip_posix_common::someip::ServiceId kServiceId{0x682U};

  /**
   * \brief SOME/IP major version of this service interface deployment.
   */
  static constexpr ::someip_posix_common::someip::MajorVersion kMajorVersion{1U};

  /**
   * \brief Constructor
   * \param instance_id SOME/IP instance identifier to be used
   * \param someip_binding Reference to the related SOME/IP transport binding
   */
  explicit CalculatorInterfaceProxySomeIpBinding(someip_posix_common::someip::InstanceId instance_id,
                                                 ara::com::someip_posix::AraComSomeIpBindingInterface& someip_binding);

  /**
   * \brief Destructor releases the proxy-binding instance in the AraComSomeIpBinding.
   */
  virtual ~CalculatorInterfaceProxySomeIpBinding();

  /**
   * \brief Get the ProxyId this ProxyImplInterface can handle.
   * \returns The ProxyId this ProxyImplInterface can handle.
   */
  ara::com::internal::ProxyId GetProxyId() const override { return CalculatorInterfaceProxy::GetProxyIdStatic(); }

  /**
   * \brief Receive handler for method responses.
   * \details At the point of this method call from AraComSomeIpBinding, we only have to dispatch method id and session
   * id
   * and look in the correct pending request container, to serve the promise.
   * \param header The deserialized SOME/IP header for direct access.
   * \param deserializer Root deserializer containing the bytestream to deserialize.
   */
  void HandleMethodResponse(const ::someip_posix_common::someip::SomeIpMessageHeader& header,
                            RootDeserializerAlias&& deserializer) override;

  /**
   * \brief Receive handler for event notifications.
   * \param header The deserialized SOME/IP header for direct access.
   * \param deserializer Root deserializer containing the bytestream to deserialize.
   */
  void HandleEventNotification(const ::someip_posix_common::someip::SomeIpMessageHeader& header,
                               RootDeserializerAlias&& deserializer) override;

  /**
   * \brief Handle an update of the subscription state of the event
   * \param event_id The event identifier
   * \param state The updated event subscription state
   */
  void HandleEventSubscriptionStateUpdate(const someip_posix_common::someip::EventId event_id,
                                          ara::com::SubscriptionState state) override;

  /**
   * \brief Forward a prepared packet to the AraComSomeIpBinding.
   *
   * \param packet the serialized packet from the method.
   */
  void SendMethodRequest(someip_posix_common::someip::SomeIpPacket&& packet);

  /**
   * \brief Subscribe to an event
   * \param event_id The SOME/IP event ID to subscribe to
   * \param event_manager The related event manager instance subscribing to the event
   */
  void SubscribeEvent(someip_posix_common::someip::EventId event_id,
                      ara::com::someip_posix::ServiceProxySomeIpEventInterface* event_manager);

  /**
   * \brief Unsubscribe from an event
   * \param event_id The SOME/IP event ID to unsubscribe from
   */
  void UnsubscribeEvent(someip_posix_common::someip::EventId event_id);

  /**
   * \brief Getter for accessing the SOME/IP binding.
   */
  ara::com::someip_posix::AraComSomeIpBindingInterface& GetBinding() { return someip_binding_; }

  /**
   * \brief Getter for the client id, that was assigned on construction of this object.
   */
  someip_posix_common::someip::ClientId GetCliendId() const { return client_id_; }

  /* ---- Methods -------------------------------------------------------------------------------------------------- */

  /**
   * \brief Serialization implementation of service method 'subtract'.
   * \param arg1 IN parameter of type uint32
   * \param arg2 IN parameter of type uint32
   * \return ara::com::Future with output struct arguments
   *         result OUT parameter of type uint32
   */
  ara::com::Future<proxy::methods::Subtract::Output> MethodSubtract(uint32& arg1, uint32& arg2) override {
    return method_manager_subtract_.HandleMethodRequest(arg1, arg2);
  }

  /**
   * \brief Serialization implementation of service method 'add'.
   * \param arg1 IN parameter of type uint32
   * \param arg2 IN parameter of type uint32
   * \return ara::com::Future with output struct arguments
   *         result OUT parameter of type uint32
   */
  ara::com::Future<proxy::methods::Add::Output> MethodAdd(uint32& arg1, uint32& arg2) override {
    return method_manager_add_.HandleMethodRequest(arg1, arg2);
  }

  /**
   * \brief Serialization implementation of service method 'divide'.
   * \param divident IN parameter of type uint32
   * \param divisor IN parameter of type uint32
   * \return ara::com::Future with output struct arguments
   *         result OUT parameter of type uint32
   */
  ara::com::Future<proxy::methods::Divide::Output> MethodDivide(uint32& divident, uint32& divisor) override {
    return method_manager_divide_.HandleMethodRequest(divident, divisor);
  }

  /* ---- Events --------------------------------------------------------------------------------------------------- */

  /**
   * \brief Get the event manager object for event 'divisionByZero'
   */
  CalculatorInterfaceProxySomeIpEventManagerDivisionByZero& GetEventManagerDivisionByZero() override {
    return event_manager_divisionByZero_;
  }

  /* ---- Fields --------------------------------------------------------------------------------------------------- */

  /* ---- Field 'divideResult' ---- */
  /**
   * \brief Get the field notifier object for field 'divideResult'.
   */
  CalculatorInterfaceProxySomeIpFieldNotifierDivideResult& GetFieldNotifierDivideResult() override {
    return field_notifier_divideResult_;
  }

  /**
   * \brief Realized getter for the field 'divideResult' on SOME/IP level.
   * \return a future object
   */
  ara::com::Future<proxy::fields::DivideResult::Output> FieldDivideResultMethodGet() override {
    return field_manager_divideResult_get_.HandleMethodRequest();
  }

  /**
   * \brief Realized setter for the field 'divideResult' on SOME/IP level.
   * \return a future object that contains the value after the promise is served.
   */
  ara::com::Future<proxy::fields::DivideResult::Output> FieldDivideResultMethodSet(
      vector::calculatorService::uint32& value) override {
    return field_manager_divideResult_set_.HandleMethodRequest(value);
  }

 private:
  /** Subscribed events with the related event manager */
  using EventSubscriptionsMap =
      std::map<someip_posix_common::someip::EventId, ara::com::someip_posix::ServiceProxySomeIpEventInterface*>;

  /** SOME/IP instance ID used by this binding. */
  someip_posix_common::someip::InstanceId instance_id_;

  /** SOME/IP related client ID used by this concrete proxy instance. */
  someip_posix_common::someip::ClientId client_id_;

  /** Related SOME/IP binding */
  ara::com::someip_posix::AraComSomeIpBindingInterface& someip_binding_;

  /** Logger for tracing and debugging */
  ara::log::Logger& logger_;

  /** Event subscriptions */
  EventSubscriptionsMap event_subscriptions_;

  /** Mutex for protection of event_subscriptions_ */
  std::mutex event_subscriptions_lock_;

  /* ---- Methods manager ------------------------------------------------------------------------------------------ */

  /** Method request/response manager for proxy method 'subtract' */
  CalculatorInterfaceProxySomeIpMethodManagerSubtract method_manager_subtract_;

  /** Method request/response manager for proxy method 'add' */
  CalculatorInterfaceProxySomeIpMethodManagerAdd method_manager_add_;

  /** Method request/response manager for proxy method 'divide' */
  CalculatorInterfaceProxySomeIpMethodManagerDivide method_manager_divide_;

  /* ---- Event manager -------------------------------------------------------------------------------------------- */

  /** Event  manager for proxy event 'divisionByZero' */
  CalculatorInterfaceProxySomeIpEventManagerDivisionByZero event_manager_divisionByZero_;

  /* ---- Field method/event manager ------------------------------------------------------------------------------- */
  /** Field notifier for the the proxy field 'divideResult' */
  CalculatorInterfaceProxySomeIpFieldNotifierDivideResult field_notifier_divideResult_;

  /** Field method manager for method Get of proxy field 'divideResult' */
  CalculatorInterfaceProxySomeIpFieldManagerDivideResultGet field_manager_divideResult_get_;

  /** Field method manager for method Set of proxy field 'divideResult' */
  CalculatorInterfaceProxySomeIpFieldManagerDivideResultSet field_manager_divideResult_set_;
};

}  // namespace calculatorService
}  // namespace vector

#endif  // ADAPTIVECALCULATORCLIENT_SOMEIP_POSIX_VECTOR_CALCULATORSERVICE_CALCULATORINTERFACE_PROXY_SOMEIP_BINDING_H_
