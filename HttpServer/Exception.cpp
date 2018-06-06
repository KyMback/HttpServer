#include "Exception.h"
using namespace HttpServer::Infrustructure::Exceptions;

Exception::Exception(const char* message) : exception(message)
{
	cerr << message;
}

const char * Exception::GetEceptionMessage() const
{
	return this->what();
}
