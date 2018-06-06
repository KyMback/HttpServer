#include "Connection.h"
#include "Exception.h"
#include <sstream>

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
	TimeoutForDataExistence.tv_sec = NULL;
	TimeoutForDataExistence.tv_usec = NULL;
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
	return GetFullData();
}

bool Connection::IsDataExist()
{
	switch (select(NULL, &SetForWaiting, nullptr, nullptr, &TimeoutForDataExistence))
	{
		case 0: return false;
		case 1: return true;
		default: throw Exception("Error has occured while keep-alive connection");
	}
}

ConnectionInfo Connection::GetFullData()
{
	stringstream stream;	
	while(IsDataExist())
	{
		char buf[_maxClientBufferSize];
		int result = recv(SocketDescriptor, buf, _maxClientBufferSize - 1, 0);
		switch (result)
		{
			case SOCKET_ERROR: throw Exception("Error has occured while getting data");
			case 0: return ConnectionInfo(ConnectionStatus::Closed, stream.str());
			default: break;
		}
		buf[result] = '\0';
		stream << buf;
	}
	FD_SET(SocketDescriptor, &SetForWaiting);
	return ConnectionInfo(ConnectionStatus::Alive, stream.str());
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
