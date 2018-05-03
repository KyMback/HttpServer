#pragma once
#include "Http.h"
#include "HttpRequestType.h"

using HttpServer::Infrustructure::Enums::HttpRequestType;

namespace HttpServer
{
	namespace Infrustructure
	{
		namespace Http
		{
			class HttpRequest final : protected Http
			{
			public:
				string Uri = string();
				HttpRequestType RequestType = HttpRequestType::Get;

				void SetTitle(string rowTitle) override;
				string GetTitle() override;

				void SetHeaders(string rowTitle[]) override;
				vector<string> GetHeaders() override;

				void SetBody(string rowTitle) override;
				string GetBody() override;
			};
		}
	}
}
