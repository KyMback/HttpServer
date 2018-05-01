#pragma once
#include <WinSock2.h>

namespace HttpServer
{
	namespace Infrustructure
	{
		namespace Sockets
		{
			class Socket
			{
				SOCKET SocketFileDescriptor = NULL;
				addrinfo* SocketAddressInformation = nullptr;
			public:
				Socket(SOCKET socketFileDescriptor, addrinfo* socketAddressInformation);
				SOCKET GetSocketFileDescriptor() const;
				addrinfo GetSocketAddressInformation() const;
				~Socket();
			};
		}
	}
}