#include "HttpRequest.h"

using namespace HttpServer::Infrustructure::Http;

void HttpRequest::SetTitle(string rowTitle)
{
}

string HttpRequest::GetTitle()
{
	return this->Title;
}

void HttpRequest::SetHeaders(string rowTitle[])
{
}

vector<string> HttpRequest::GetHeaders()
{
	return this->Headers;
}

void HttpRequest::SetBody(string rowTitle)
{
}

string HttpRequest::GetBody()
{
	return this->Body;
}
