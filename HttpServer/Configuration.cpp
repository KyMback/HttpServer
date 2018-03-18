#include "Configuration.h"

#include <WS2tcpip.h>
#include "Exception.h"
#include "SocketsFactory.h"

using HttpServer::Configuration;
using HttpServer::SocketsFactory;
using HttpServer::Exception;

void Configuration::OpenNewSocket()
{
	delete this->Socket;
	this->Socket = SocketsFactory::GetInstance().BuildSocket(this->IpAddress, this->PortAdress);
}

SOCKET Configuration::GetSocketFileDescriptor()
{
	if(this->Socket == nullptr)
	{
		throw Exception("Null reference exception");
	}
	return this->Socket->GetSocketFileDescriptor();
}

Configuration::Configuration()
{
	WSADATA wsaData; // служебная структура для хранение информации
					 // о реализации Windows Sockets
					 // старт использования библиотеки сокетов процессом
					 // (подгружается Ws2_32.dll)
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		throw Exception("WSAStartup failed");
	}
}

Configuration::~Configuration()
{
	delete this->Socket;
	WSACleanup();
}
