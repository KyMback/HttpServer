#pragma once
#include <WinSock2.h>
#include "HttpResponse.h"
#include "ConnectionInfo.h"

using HttpServer::Infrustructure::ConnectionInfo;

namespace HttpServer
{
	namespace Infrustructure
	{
		class Connection
		{
		private:
			static const int _defaultSessionTimeout = 10;
			static const int _maxClientBufferSize = 1024;
			int SocketDescriptor = 0;
			fd_set SetForWaiting;
			timeval Timeout;

			void InitializeConnectionConfigures();
			int KeepAliveConnection();
		public:
			explicit Connection(int socketDescriptor);
			ConnectionInfo GetData();
			void SetData(string data);
			void CloseConnection();
			~Connection();
		};
	}
}