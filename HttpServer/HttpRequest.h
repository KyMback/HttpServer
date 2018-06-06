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
			class HttpRequest final : public Http
			{
			public:
				string Uri = string();
				HttpRequestType RequestType = HttpRequestType::Get;

				void SetBody(string rowTitle) override;
				string GetBody() override;
			};
		}
	}
}
