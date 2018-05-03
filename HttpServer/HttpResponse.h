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