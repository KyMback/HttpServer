#pragma once
#include "Http.h"


namespace HttpServer
{
	namespace Infrustructure
	{
		namespace Http
		{
			class HttpRequest final : protected Http
			{
			public:
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
