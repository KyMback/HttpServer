#include "HttpParserService.h"
#include "StringUtils.h"
#include "HttpUtils.h"
#include <regex>
#include <sstream>

using HttpServices::HttpParserService;
using namespace HttpServer::Infrustructure::Utils;
using namespace std;

const string HttpParserService::ContentTypeKey = "ContentType";
const string HttpParserService::ContentLengthKey = "ContentLength";
const string HttpParserService::HttpRequestPartsDivisionRegEx = R"(([^\0]+?)(?:\r?\n)([^\0]+?)(?:[\r?\n]{4})([^\0]*))";
const string HttpParserService::HttpRequestTitleRegEx = R"((\w+)(?:[[:space:]])(.+)(?:HTTP\/)(.+))";
const string HttpParserService::HttpRequestHeadersSplitingRegEx = R"((.+?:.+))";
const string HttpParserService::HttpRequestHeaderDefaultRegEx = R"((.+?)(?::[[:space:]])(.+))";
const string HttpParserService::HttpRequestContentExtension = R"(.+[.](\w+))";

const int HttpParserService::HttpRequestTitlePositionNumber = 0;
const int HttpParserService::HttpRequestHeadersPositionNumber = 1;
const int HttpParserService::HttpRequestBodyPositionNumber = 2;

HttpRequest* HttpParserService::ParseStringToHttpRequest(string rawString)
{
	auto request = new HttpRequest();
	vector<string> separatedParts = SeparateHttpRequestParts(rawString);
	SetRequestTitleData(*request, separatedParts[HttpRequestTitlePositionNumber]);
	SetRequestHeaderData(*request, separatedParts[HttpRequestHeadersPositionNumber]);
	SetRequestBodyData(*request, separatedParts[HttpRequestBodyPositionNumber]);
	return request;
}

string HttpParserService::ParseResponseToString(HttpResponse response)
{
	response.ContentLength = response.GetBody().size();
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
	vector.push_back(HttpUtils::GetHeader(HttpUtils::GetHttpLocalizedValue(ContentTypeKey), HttpUtils::GetHttpContentTypeValue(response.ContentType)));
	vector.push_back(HttpUtils::GetHeader(HttpUtils::GetHttpLocalizedValue(ContentLengthKey), to_string(response.ContentLength)));
	resultStringStream << HttpUtils::GetNewLineSeparatedHeaders(vector);
	return resultStringStream.str();
}

string HttpParserService::GetBody(HttpResponse& response)
{
	return response.GetBody();
}

vector<string> HttpParserService::SeparateHttpRequestParts(string rawString)
{
	vector<string> resultStrings;
	smatch match;
	regex_search(rawString, match, regex(HttpRequestPartsDivisionRegEx));
	resultStrings.push_back(match[HttpRequestTitlePositionNumber + 1]);
	resultStrings.push_back(match[HttpRequestHeadersPositionNumber + 1]);
	resultStrings.push_back(match[HttpRequestBodyPositionNumber + 1]);
	return resultStrings;
}

void HttpParserService::SetRequestTitleData(HttpRequest& request, string titleRawString)
{
	smatch match;
	regex_search(titleRawString, match, regex(HttpRequestTitleRegEx));
	request.RequestType = HttpUtils::GetHttpRequestTypeValue(match[1]);
	request.Uri = match[2];
	request.HttpVersion = stod(match[3]);
}

void HttpParserService::SetRequestBodyData(HttpRequest& request, string bodyRawString)
{
	request.SetBody(bodyRawString);
}

string HttpParserService::GetContentStringExtension(string path)
{
	smatch match;
	regex_search(path, match, regex(HttpRequestContentExtension));
	return match[1];
}

MimeType HttpParserService::GetMimeTypeOfContent(string path)
{
	return HttpUtils::GetHttpMimeTypeMatchingValues(GetContentStringExtension(path));
}

void HttpParserService::SetRequestHeaderData(HttpRequest& request, string headerRawString)
{
	vector<string> resultStrings;
	auto regEx = regex(HttpRequestHeadersSplitingRegEx);
	regex_token_iterator<string::iterator> rend;
	regex_token_iterator<string::iterator> it(headerRawString.begin(), headerRawString.end(), regEx);
	for(;it != rend; ++it)
	{
		resultStrings.push_back(it->str());
	}
	//TODO: End headers processing
}
