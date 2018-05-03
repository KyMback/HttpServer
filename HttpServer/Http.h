#pragma once
#include <string>
#include <vector>
#include <sstream> 

using std::string;
using std::vector;
using std::stringstream;

namespace HttpServer
{
	namespace Infrustructure
	{
		namespace Http
		{
			class Http
			{
			protected:
				string Title;
				vector<string> Headers;
				string Body;
			public:
				bool IsKeepAliveConnection = false;
				int ContentLength = 0;
				string ContentType = string();
				double HttpVersion = 1.1;


				void virtual SetTitle(string rowTitle) = 0;
				string virtual GetTitle() = 0;

				void virtual SetHeaders(string rowTitle[]) = 0;
				vector<string> virtual GetHeaders() = 0;

				void virtual SetBody(string rowTitle) = 0;
				string virtual GetBody() = 0;

				stringstream GetStringStream();
			};
		}
	}
}