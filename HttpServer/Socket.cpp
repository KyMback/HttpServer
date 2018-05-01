#include "Socket.h"
#include <WS2tcpip.h>

using namespace HttpServer::Infrustructure::Sockets;

Socket::Socket(SOCKET socketFileDescriptor, addrinfo* socketAddressInformation)
{
	this->SocketFileDescriptor = socketFileDescriptor;
	this->SocketAddressInformation = socketAddressInformation;
}

SOCKET Socket::GetSocketFileDescriptor() const
{
	return this->SocketFileDescriptor;
}

addrinfo Socket::GetSocketAddressInformation() const
{
	return *this->SocketAddressInformation;
}

Socket::~Socket()
{
	closesocket(SocketFileDescriptor);
	freeaddrinfo(SocketAddressInformation);
}
