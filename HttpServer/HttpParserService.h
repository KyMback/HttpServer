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
					static HttpRequest* ParseStringToHttpRequest(string rawString);
					static string ParseResponseToString(HttpResponse response);
					static MimeType GetMimeTypeOfContent(string path);
				private:
					static const string ContentTypeKey;
					static const string ContentLengthKey;
					static const string HttpRequestPartsDivisionRegEx;
					static const string HttpRequestTitleRegEx;
					static const string HttpRequestHeadersSplitingRegEx;
					static const string HttpRequestHeaderDefaultRegEx;
					static const string HttpRequestContentExtension;

					static const int HttpRequestTitlePositionNumber;
					static const int HttpRequestHeadersPositionNumber;
					static const int HttpRequestBodyPositionNumber;

					static string GetTitle(HttpResponse& response);
					static string GetHeaders(HttpResponse& response);
					static string GetBody(HttpResponse& response);

					static vector<string> SeparateHttpRequestParts(string rawString);
					static void SetRequestTitleData(HttpRequest& request, string titleRawString);
					static void SetRequestHeaderData(HttpRequest& request, string headerRawString);
					static void SetRequestBodyData(HttpRequest& request, string bodyRawString);

					static string GetContentStringExtension(string path);					
				};
			}
		}
	}
}