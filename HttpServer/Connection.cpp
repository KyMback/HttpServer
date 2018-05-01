#include "Connection.h"
#include "Exception.h"

using namespace HttpServer::Infrustructure;
using HttpServer::Infrustructure::Connection;
using namespace Exceptions;
using namespace std;

Connection::Connection(int socketDescriptor)
{
	this->SocketDescriptor = socketDescriptor;
	InitializeConnectionConfigures();
}

void Connection::InitializeConnectionConfigures()
{
	Timeout.tv_sec = _defaultSessionTimeout;
	Timeout.tv_usec = NULL;
	FD_ZERO(&SetForWaiting);
	FD_SET(SocketDescriptor, &SetForWaiting);
}

int Connection::KeepAliveConnection()
{
	int result = 0;
	if ((result = select(NULL, &SetForWaiting, nullptr, nullptr, &Timeout)) == -1)
	{
		throw Exception("Error has occured while keep-alive connection");
	}
	return result;
}


ConnectionInfo Connection::GetData()
{
	if (KeepAliveConnection() == 0)
	{
		return ConnectionInfo(ConnectionStatus::Timeout, string());
	}
	char buf[_maxClientBufferSize];
	int result = recv(SocketDescriptor, buf, _maxClientBufferSize, 0);
	// TODO do magic with buffer
	switch (result)
	{
		case SOCKET_ERROR: throw Exception("Error has occured while getting data");
		case 0: return ConnectionInfo(ConnectionStatus::Closed, string());
		default: buf[result] = '\0'; return ConnectionInfo(ConnectionStatus::Alive, string(buf));
	}
}

void Connection::SetData(string data)
{
	if (send(SocketDescriptor, data.c_str(),
		data.length(), 0) == SOCKET_ERROR) {
		throw Exception("Error has occured while sending data");
	}
}

void Connection::CloseConnection()
{
	closesocket(SocketDescriptor);
}

Connection::~Connection()
{
	closesocket(SocketDescriptor);
}
