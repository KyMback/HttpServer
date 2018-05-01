#pragma once
#include <iosfwd>
#include <WinSock2.h>

namespace HttpServer
{
	namespace Infrustructure
	{
		class Session
		{
		private:
			const int _defaultSessionTimeout = 60;
			const int _maxClientBufferSize = 1024;

			int SocketDescriptor = 0;

			fd_set SetForWaiting;
			timeval Timeout;
			int SessionTimeout = _defaultSessionTimeout;

			void InitializeConfigures();
			void GetResponse(std::stringstream& stream, char* buffer);			
		public:
			Session(int socketDescriptor);
			int StartSession();
			~Session();
		};
	}
}
