#pragma once
#pragma comment(lib, "Ws2_32.lib")

#include <WinSock2.h>
#include <string>
#include "Socket.h"

using std::string;

namespace HttpServer 
{
	class Configuration final
	{
		string IpAddress = "127.0.0.1";
		string PortAdress = "8000";
		Socket* Socket = nullptr;
	public:
		void OpenNewSocket();
		SOCKET GetSocketFileDescriptor();
		Configuration();
		~Configuration();
	};
}

