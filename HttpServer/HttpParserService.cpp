#include "HttpParserService.h"
#include "StringUtils.h"
#include "HttpUtils.h"

using HttpServices::HttpParserService;
using namespace HttpServer::Infrustructure::Utils;
using std::to_string;

const string HttpParserService::ContentTypeKey = "ContentType";
const string HttpParserService::ContentLengthKey = "ContentLength";

HttpRequest HttpParserService::ParseStringToHttpRequest(string rowString)
{
	return HttpRequest();
}

string HttpParserService::ParseResponseToString(HttpResponse response)
{
	stringstream resultStringStream;
	resultStringStream << GetTitle(response);
	resultStringStream << HttpUtils::GetDefaultBodyDelimeter();
	resultStringStream << GetHeaders(response);
	resultStringStream << HttpUtils::GetDefaultBodyDelimeter() << HttpUtils::GetDefaultBodyDelimeter();
	resultStringStream << GetBody(response);

	return resultStringStream.str();
}

string HttpParserService::GetTitle(HttpResponse& response)
{
	return HttpUtils::GetResponseTitle(response.HttpVersion, response.StatusCode);
}

string HttpParserService::GetHeaders(HttpResponse& response)
{
	stringstream resultStringStream;
	vector<string> vector;
	vector.push_back(HttpUtils::GetHeader(HttpUtils::GetHttpLocalizedValue(ContentTypeKey), response.ContentType));
	vector.push_back(HttpUtils::GetHeader(HttpUtils::GetHttpLocalizedValue(ContentLengthKey), to_string(response.ContentLength)));
	resultStringStream << HttpUtils::GetNewLineSeparatedHeaders(vector);
	return resultStringStream.str();
}

string HttpParserService::GetBody(HttpResponse& response)
{
	return response.GetBody();
}
