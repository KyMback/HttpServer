#include "Configuration.h"
#include <WS2tcpip.h>
#include "Exception.h"
#include "SocketsFactory.h"

using HttpServer::Configuration;
using HttpServer::Infrustructure::Exceptions::Exception;

void Configuration::OpenNewSocket()
{
	delete this->Socket;
	this->Socket = Infrustructure::Sockets::SocketsFactory::GetInstance().BuildSocket(this->IpAddress, this->PortAdress);
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
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		throw Exception("WSAStartup failed");
	}
}

Configuration::~Configuration()
{
	delete this->Socket;
	WSACleanup();
}
