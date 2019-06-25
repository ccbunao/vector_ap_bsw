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
/**        \file  skeleton_impl_interface.h
 *        \brief  TODO
 *
 *      \details  Skeleton implementation interface
 *
 *********************************************************************************************************************/

#ifndef LIB_LIBARA_INCLUDE_ARA_COM_INTERNAL_SKELETON_INTERFACE_H_
#define LIB_LIBARA_INCLUDE_ARA_COM_INTERNAL_SKELETON_INTERFACE_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "ara/com/types.h"

namespace ara {
namespace com {
namespace internal {

/**
 * \brief Interface of a skeleton frontend
 */
class SkeletonInterface {
 public:
  virtual ~SkeletonInterface() = default;

  /**
   * \brief Get the SkeletonId this SkeletonInterface can handle.
   * \returns The SkeletonId this SkeletonInterface can handle.
   */
  virtual ara::com::internal::SkeletonId GetSkeletonId() const = 0;
};

}  // namespace internal
}  // namespace com
}  // namespace ara

#endif  // LIB_LIBARA_INCLUDE_ARA_COM_INTERNAL_SKELETON_INTERFACE_H_
