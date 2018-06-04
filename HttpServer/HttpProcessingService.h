#pragma once
#include <string>
#include <map>
#include "HttpRequest.h"
#include "HttpResponse.h"

using std::string;
using namespace HttpServer::Infrustructure::Http;

namespace HttpServer
{
	namespace  Infrustructure
	{
		namespace Http
		{
			namespace HttpServices
			{
				class HttpProcessingService
				{
				public:
					static HttpResponse* StartProcessing(HttpRequest* request);
				private:
					static HttpResponse* StartProcessingInternal(HttpRequest * request);
					static const string DefaultRootDirectory;
					static bool IsRequestedStaticContent(string path);
				};
			}
		}
	}
}