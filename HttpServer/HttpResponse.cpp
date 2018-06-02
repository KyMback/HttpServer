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

void HttpResponse::SetBody(string rowBody)
{
	this->Body = rowBody;
}

string HttpResponse::GetBody()
{
	return this->Body;
}
