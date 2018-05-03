#pragma once
#include "ConnectionStatus.h"
#include <string>

using HttpServer::Infrustructure::Enums::ConnectionStatus;
using std::string;

namespace HttpServer
{
	namespace Infrustructure
	{
		class ConnectionInfo
		{
		public:
			ConnectionStatus Status = ConnectionStatus::Closed;
			string Data;
			explicit ConnectionInfo(ConnectionStatus connectionStatus, string data);
			explicit ConnectionInfo();
		};
	}
}