#pragma once
#include "HttpRequest.h"


namespace HttpServer
{
	namespace Infrustructure
	{
		namespace Http
		{
			class HttpContext
			{
				HttpRequest ClientRequest;
			};
		}
	}
}
