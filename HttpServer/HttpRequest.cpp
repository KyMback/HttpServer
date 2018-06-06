#include "HttpRequest.h"

using namespace HttpServer::Infrustructure::Http;

void HttpRequest::SetBody(string rowTitle)
{
	this->Body = rowTitle;
}

string HttpRequest::GetBody()
{
	return this->Body;
}
