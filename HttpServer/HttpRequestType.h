#pragma once
namespace HttpServer
{
	namespace Infrustructure
	{
		namespace Enums
		{
			enum class HttpRequestType
			{
				Get = 1,
				Head = 2,
				Post = 3,
				Put = 4,
				Delete = 5,
				Connect = 6,
				Options = 7,
				Trace = 8,
				Patch = 9
			};
		}
	}
}