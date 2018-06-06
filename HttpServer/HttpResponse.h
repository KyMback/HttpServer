#pragma once
#include "Http.h"
#include "HttpStatusCode.h"

using HttpServer::Infrustructure::Enums::HttpStatusCode;

namespace HttpServer
{
	namespace Infrustructure
	{
		namespace Http
		{
			class HttpResponse final : public Http
			{
				
			public:
				HttpStatusCode StatusCode = HttpStatusCode::OK;

				void SetBody(string rowBody) override;
				string GetBody() override;
			};
		}
	}
}