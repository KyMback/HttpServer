#include "HttpResponse.h"

using namespace HttpServer::Infrustructure::Http;

void HttpResponse::SetTitle(string rowTitle)
{
}

string HttpResponse::GetTitle()
{
	return this->Title;
}

void HttpResponse::SetHeaders(string rowTitle[])
{
}

vector<string> HttpResponse::GetHeaders()
{
	return this->Headers;
}

void HttpResponse::SetBody(string rowTitle)
{
}

string HttpResponse::GetBody()
{
	return this->Body;
}

void HttpResponse::SetStatusCode(HttpStatusCode statusCode)
{
	this->StatusCode = statusCode;
}

HttpStatusCode HttpResponse::GetStatusCode()
{
	return this->StatusCode;
}
