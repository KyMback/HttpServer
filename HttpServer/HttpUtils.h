#pragma once
#include <string>
#include <vector>
#include "HttpResponse.h"
#include <map>
#include "HttpRequestType.h"
#include "MimeType.h"

using std::string;
using std::vector;
using std::map;
using HttpServer::Infrustructure::Enums::HttpRequestType;
using HttpServer::Infrustructure::Enums::MimeType;

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
				static const map<MimeType, string> HttpContentTypeValues;
				static const map<string, MimeType> HttpContentTypeMatchingValues;
			public:
				static const string HttpResponseTitleTemplate;
				static const string HttpHeaderTemplate;

				static string GetNewLineSeparatedHeaders(vector<string>& headers);
				static string GetResponseTitle(double httpVersion, HttpStatusCode statusCode);
				static string GetDefaultBodyDelimeter();
				static string GetHeader(string type, string value);
				static string GetHttpLocalizedValue(string key);
				static HttpRequestType GetHttpRequestTypeValue(string key);
				static string GetHttpContentTypeValue(MimeType key);
				static MimeType GetHttpMimeTypeMatchingValues(string key);
			};
		}
	}
}