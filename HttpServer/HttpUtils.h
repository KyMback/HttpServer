#pragma once
#include <string>
#include <vector>
#include "HttpResponse.h"

using std::string;
using std::vector;

namespace HttpServer
{
	namespace Infrustructure
	{
		namespace Http
		{
			class HttpUtils
			{
			public:
				static const char* defaultLineSeparatedString;
				static string GetNewLineSeparatedHeaders(vector<string>& headers);
				static string GetResponseTitle(HttpResponse& response);
			};
		}
	}
}