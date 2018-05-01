#include "Server.h"
#include <iostream>
#include <sstream>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "Exception.h"
#include "Session.h"

using namespace HttpServer;
using namespace Infrustructure::Exceptions;
using Infrustructure::Session;
using Infrustructure::Connection;
using namespace std;

int Server::Start()
{
	cout << "Starting of the server..." << endl;
	this->ServerConfigurations = new Configuration();	
	this->ServerConfigurations->OpenNewSocket();
	cout << "Socket successfully created..." << endl;
	int listenSocket = ServerConfigurations->GetSocketFileDescriptor();	
	cout << "Start listening in 127.0.0.1:8000..." << endl;

	while(true) {
		int clientSocket = INVALID_SOCKET;
		clientSocket = accept(listenSocket, nullptr, nullptr);		// Принимаем входящие соединения
		cout << "Client socket descriptor: " << clientSocket << endl;
		if (clientSocket == INVALID_SOCKET) {
			printf("accept failed");
		}
		CreateNewSession(clientSocket);
	}
}

DWORD WINAPI Server::StartNewSession(LPVOID param)
{
	Session* session = new Session(new Connection(reinterpret_cast<int>(param)));
	int result = 0;
	try
	{
		result = session->StartSession();
	}
	catch (Exception ex)
	{
		printf("%s", ex.GetEceptionMessage());
		result = -1;
	}	
	delete session;
	return result;
}

HANDLE Server::CreateNewSession(int socketDescriptor)
{
	return CreateThread(nullptr, 0, StartNewSession, reinterpret_cast<LPVOID>(socketDescriptor), 0, nullptr);
}

Server::Server() = default;

Server::~Server()
{
	delete ServerConfigurations;
}

Server& Server::GetInstance()
{
	static Server server;
	return server;
}

