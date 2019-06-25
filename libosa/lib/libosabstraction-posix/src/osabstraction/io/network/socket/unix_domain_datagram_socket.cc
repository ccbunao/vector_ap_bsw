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

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "osabstraction/io/network/socket/unix_domain_datagram_socket.h"

#include <unistd.h>
#include <cassert>

#include "osabstraction/io/network/address/unix_domain_socket_address.h"

namespace osabstraction {
namespace io {
namespace network {
namespace socket {

UnixDomainDatagramSocket UnixDomainDatagramSocket::CreateSocket(const address::UnixDomainSocketAddress& local_address) {
  UnixDomainDatagramSocket socket(local_address.GetAddressFamily());
  socket.Bind(local_address);
  return socket;
}

UnixDomainDatagramSocket UnixDomainDatagramSocket::CreateSocket(
    const address::UnixDomainSocketAddress& local_address, const address::UnixDomainSocketAddress& remote_address) {
  UnixDomainDatagramSocket socket = UnixDomainDatagramSocket::CreateSocket(local_address);
  socket.Connect(remote_address);
  return socket;
}

UnixDomainDatagramSocket::~UnixDomainDatagramSocket() { Close(); }

void UnixDomainDatagramSocket::Close() {
  if (shall_unlink_ && handle_ != kInvalidFileDescriptor) {
    address::SocketAddress local_address = GetLocalAddress();
    assert(local_address.toSockAddr()->sa_family == AF_UNIX);
    address::UnixDomainSocketAddress* udsaddr = static_cast<address::UnixDomainSocketAddress*>(&local_address);
    ::unlink(udsaddr->toSockAddrUn()->sun_path);
  }
  FileDescriptor::Close();
}

}  // namespace socket
}  // namespace network
}  // namespace io
}  // namespace osabstraction
