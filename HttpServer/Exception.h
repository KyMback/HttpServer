#pragma once
#include <exception>
#include <iostream>

using std::exception;
using std::cerr;

namespace HttpServer
{
	class Exception : exception
	{
	public:
		Exception(const char* message);
		Exception();
	};
}
