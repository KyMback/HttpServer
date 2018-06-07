#pragma once
#include <string>
#include <vector>
#include "MimeType.h"

using std::string;
using std::vector;
using std::stringstream;
using namespace HttpServer::Infrustructure::Enums;

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
				MimeType ContentType = MimeType::TextHtml;
				double HttpVersion = 1.1;

				void virtual SetBody(string rowBody) = 0;
				string virtual GetBody() = 0;
			};
		}
	}
}