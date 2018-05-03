#pragma once
#include <string>
#include <vector>
#include "HttpResponse.h"
#include <map>

using std::string;
using std::vector;
using std::map;

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
			public:
				static const string HttpResponseTitleTemplate;
				static const string HttpHeaderTemplate;

				static string GetNewLineSeparatedHeaders(vector<string>& headers);
				static string GetResponseTitle(double httpVersion, HttpStatusCode statusCode);
				static string GetDefaultBodyDelimeter();
				static string GetHeader(string type, string value);
				static string GetHttpLocalizedValue(string key);
			};
		}
	}
}