#include "HttpResponse.h"

using namespace HttpServer::Infrustructure::Http;

void HttpResponse::SetBody(string rowBody)
{
	this->Body = rowBody;
}

string HttpResponse::GetBody()
{
	return this->Body;
}
