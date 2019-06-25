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
/**        \file
 *        \brief  TODO
 *
 *      \details  TODO
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Damian Philipp               visdap       Vector Informatik GmbH
 *********************************************************************************************************************/

#ifndef LIB_LIBOSABSTRACTION_POSIX_INCLUDE_OSABSTRACTION_IO_NETWORK_SOCKET_UNIX_DOMAIN_STREAM_SERVER_SOCKET_H_
#define LIB_LIBOSABSTRACTION_POSIX_INCLUDE_OSABSTRACTION_IO_NETWORK_SOCKET_UNIX_DOMAIN_STREAM_SERVER_SOCKET_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "osabstraction/io/network/address/unix_domain_socket_address.h"
#include "osabstraction/io/network/socket/stream_server_socket.h"
#include "osabstraction/io/network/socket/unix_domain_stream_socket.h"

namespace osabstraction {
namespace io {
namespace network {
namespace socket {

/**
 * \brief Represents a UnixDomainSocket of type SocketType::kStream capable of accepting connections.
 */
class UnixDomainStreamServerSocket : public StreamServerSocket {
 public:
  /**
   * \brief Socket Type yielded by Accept() calls of this object
   */
  using ClientSocketType = UnixDomainStreamSocket;

  /**
   * \brief Constructor for a TCPServerSocket for a given address_family.
   */
  explicit UnixDomainStreamServerSocket(address::SocketAddressFamily address_family)
      : StreamServerSocket(address_family) {}

  virtual ~UnixDomainStreamServerSocket();

  /**
   * \brief Closes a socket.
   */
  void Close() override;

  /**
   * \brief Returns the next connection request from the queue of pending connections.
   *
   * \return The next connection request.
   */
  virtual ClientSocketType Accept();

  /**
   * \brief Returns the next connection request from the queue of pending connections.
   *
   * \param remote_address The remote socket address of the next connection request.
   * \return The next connection request.
   */
  virtual ClientSocketType Accept(address::UnixDomainSocketAddress* remote_address);
};

}  // namespace socket
}  // namespace network
}  // namespace io
}  // namespace osabstraction

#endif  // LIB_LIBOSABSTRACTION_POSIX_INCLUDE_OSABSTRACTION_IO_NETWORK_SOCKET_UNIX_DOMAIN_STREAM_SERVER_SOCKET_H_
