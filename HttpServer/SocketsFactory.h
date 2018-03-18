#pragma once

#include <WinSock2.h>
#include "Socket.h"
#include <string>

using std::string;

namespace HttpServer
{
	class SocketsFactory final
	{
		SocketsFactory();
		addrinfo GetTemplateForAddressStructure();
		SOCKET CreateNewSocketsFileDescriptor(addrinfo *socketInformation);
		void InitializeListenSocket(Socket* socket);
		void BindSocketToIpAddress(Socket* socket);
		addrinfo* GetSocketInformation(string ipAddress, string portAdress);
		~SocketsFactory();
	public:
		Socket* BuildSocket(string ipAddress, string portAdress);
		static SocketsFactory& GetInstance();
		SocketsFactory(SocketsFactory const&) = delete;
		SocketsFactory& operator= (SocketsFactory const&) = delete;
	};
}