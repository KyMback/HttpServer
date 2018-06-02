#pragma once
#include <string>
#include <vector>
#include "HttpResponse.h"
#include <map>
#include "HttpRequestType.h"
#include "HttpContentType.h"

using std::string;
using std::vector;
using std::map;
using HttpServer::Infrustructure::Enums::HttpRequestType;
using HttpServer::Infrustructure::Enums::HttpContentType;

namespace HttpServer
{
	namespace Infrustructure
	{
		namespace Http
		{
			class HttpUtils
			{
			private:
				static const map<string, string> HttpLocalizedValues;
				static const map<string, HttpRequestType> HttpRequestTypeValues;
				static const map<HttpContentType, string> HttpContentTypeValues;
			public:
				static const string HttpResponseTitleTemplate;
				static const string HttpHeaderTemplate;

				static string GetNewLineSeparatedHeaders(vector<string>& headers);
				static string GetResponseTitle(double httpVersion, HttpStatusCode statusCode);
				static string GetDefaultBodyDelimeter();
				static string GetHeader(string type, string value);
				static string GetHttpLocalizedValue(string key);
				static HttpRequestType GetHttpRequestTypeValue(string key);
				static string GetHttpContentTypeValue(HttpContentType key);
			};
		}
	}
}