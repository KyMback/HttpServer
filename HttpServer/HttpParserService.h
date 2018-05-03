#pragma once
#include <string>
#include <map>
#include "Http.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

using std::string;
using std::map;
using namespace HttpServer::Infrustructure::Http;

namespace HttpServer
{
	namespace  Infrustructure
	{
		namespace Http
		{
			namespace HttpServices
			{
				class HttpParserService
				{
				public:
					static HttpRequest ParseStringToHttpRequest(string rowString);
					static string ParseResponseToString(HttpResponse response);
				private:
					static const string ContentTypeKey;
					static const string ContentLengthKey;

					static string GetTitle(HttpResponse& response);
					static string GetHeaders(HttpResponse& response);
					static string GetBody(HttpResponse& response);
				};
			}
		}
	}
}