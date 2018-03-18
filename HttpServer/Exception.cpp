#pragma once

#include "Exception.h"
using HttpServer::Exception;

Exception::Exception(const char* message) : exception(message)
{
	cerr << message;
}

Exception::Exception() : exception()
{

}
