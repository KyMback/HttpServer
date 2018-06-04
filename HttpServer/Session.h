#pragma once
#include "HttpContext.h"
#include "HttpResponse.h"
#include "Connection.h"

using namespace  HttpServer::Infrustructure::Http;
using std::stringstream;

namespace HttpServer
{
	namespace Infrustructure
	{
		class Session
		{
		private:
			Connection* _connection = nullptr;
		public:
			HttpContext* UserContext = nullptr;
			Session(Connection* connection);
			int StartSession();
			~Session();
		};
	}
}
