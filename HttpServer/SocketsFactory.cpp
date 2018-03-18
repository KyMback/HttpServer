#include "SocketsFactory.h"
#include "Exception.h"
#include <iostream>
#include <string>
#include <WS2tcpip.h>

using HttpServer::SocketsFactory;
using HttpServer::Exception;
using std::string;
using HttpServer::Socket;

SocketsFactory::SocketsFactory() { }

addrinfo SocketsFactory::GetTemplateForAddressStructure()
{
	addrinfo addressInformation;
	ZeroMemory(&addressInformation, sizeof(addressInformation));

	addressInformation.ai_family = AF_INET;			// AF_INET определяет, что будет использоваться сеть для работы с сокетом
	addressInformation.ai_socktype = SOCK_STREAM;	// Задаем потоковый тип сокета
	addressInformation.ai_protocol = IPPROTO_TCP;	// Используем протокол TCP
	addressInformation.ai_flags = AI_PASSIVE;		// Сокет будет биндиться на адрес, чтобы принимать входящие соединения

	return addressInformation;
}

SOCKET SocketsFactory::CreateNewSocketsFileDescriptor(addrinfo* socketInformation)
{
	// Создание сокета
	SOCKET socketFileDescriptor = socket(
		socketInformation->ai_family,
		socketInformation->ai_socktype,
		socketInformation->ai_protocol);
	if (socketFileDescriptor == INVALID_SOCKET)
	{
		throw Exception("Error while creating socket");
	}
	return socketFileDescriptor;
}

void SocketsFactory::InitializeListenSocket(Socket* socket)
{
	if (listen(socket->GetSocketFileDescriptor(), SOMAXCONN) == SOCKET_ERROR) {
		throw Exception("Initialize of listen socket has been failed");
	}
}

void SocketsFactory::BindSocketToIpAddress(Socket* socket)
{
	// Привязываем сокет к IP-адресу
	if (bind(socket->GetSocketFileDescriptor(),
		socket->GetSocketAddressInformation().ai_addr,
		socket->GetSocketAddressInformation().ai_addrlen) == SOCKET_ERROR)
	{
		throw Exception("bind failed");
	}
}

Socket* SocketsFactory::BuildSocket(string ipAddress, string portAdress)
{
	addrinfo* socketAddressInformation = GetSocketInformation(ipAddress, portAdress);
	SOCKET socketFileDescriptor = CreateNewSocketsFileDescriptor(socketAddressInformation);
	Socket* socket = new Socket(socketFileDescriptor, socketAddressInformation);
	BindSocketToIpAddress(socket);
	InitializeListenSocket(socket);
	return socket;
}

addrinfo* SocketsFactory::GetSocketInformation(string ipAddress, string portAdress)
{
	addrinfo *socketInformation;
	if (getaddrinfo(
		ipAddress.c_str(),
		portAdress.c_str(),
		&GetTemplateForAddressStructure(),
		&socketInformation) != 0) {
		throw Exception("getaddrinfo failed");
	}
	return socketInformation;
}

SocketsFactory& SocketsFactory::GetInstance()
{
	static SocketsFactory factory;
	return factory;
}

SocketsFactory::~SocketsFactory() { }