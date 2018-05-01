#include "ConnectionInfo.h"

using HttpServer::Infrustructure::ConnectionInfo;

ConnectionInfo::ConnectionInfo(ConnectionStatus connectionStatus, string data)
{
	this->Status = connectionStatus;
	this->Data = data;
}

ConnectionInfo::ConnectionInfo() : ConnectionInfo(ConnectionStatus::Closed, string())
{
	
}
