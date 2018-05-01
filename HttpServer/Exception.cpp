#include "Exception.h"
using namespace HttpServer::Infrustructure::Exceptions;

Exception::Exception(const char* message) : exception(message)
{
	cerr << message;
}

Exception::Exception() : exception()
{

}
