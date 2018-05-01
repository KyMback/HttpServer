#pragma once
#include <exception>
#include <iostream>

using std::exception;
using std::cerr;

namespace HttpServer
{
	namespace Infrustructure
	{
		namespace Exceptions
		{
			class Exception : exception
			{
			public:
				Exception(const char* message);
				const char* GetEceptionMessage() const;
				Exception();
			};
		}
	}
}
