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

			HttpResponse* GetResponse(string body);
			HttpRequest* GetRequest(stringstream& stream);

			string GetCustomData(string body);
		public:
			HttpContext* UserContext = nullptr;
			Session(Connection* connection);
			int StartSession();
			~Session();
		};
	}
}
