#pragma once
namespace HttpServer
{
	namespace Infrustructure
	{
		namespace Enums
		{
			enum class ConnectionStatus
			{
				Alive = 1,
				Closed = 2,
				Timeout = 3
			};
		}
	}
}