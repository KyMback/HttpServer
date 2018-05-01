#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

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
				void virtual SetTitle(string rowTitle) = 0;
				string virtual GetTitle() = 0;

				void virtual SetHeaders(string rowTitle[]) = 0;
				vector<string> virtual GetHeaders() = 0;

				void virtual SetBody(string rowTitle) = 0;
				string virtual GetBody() = 0;
			};
		}
	}
}