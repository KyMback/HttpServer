#pragma once
#include "Configuration.h"

namespace HttpServer
{
	class __declspec(dllexport) Server final
	{
		Configuration *ServerConfigurations = nullptr;

		Server();
		~Server();
	public:
		static Server& GetInstance();
		int Start();

		Server(Server const&) = delete;
		Server& operator= (Server const&) = delete;
	};
}