#include "HttpUtils.h"
#include "StringUtils.h"

using namespace HttpServer::Infrustructure::Http;
using namespace HttpServer::Infrustructure::Utils;

const char* HttpUtils::defaultLineSeparatedString = "\r\n";

string HttpUtils::GetNewLineSeparatedHeaders(vector<string>& headers)
{
	return StringUtils::GetSeparatedString(headers, "\r\n");
}

string HttpUtils::GetResponseTitle(HttpResponse& response)
{
	return response.GetTitle();
}
