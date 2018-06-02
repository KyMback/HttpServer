#include "HttpUtils.h"
#include "StringUtils.h"
#include "HttpRequestType.h"
#include <map>
#include "HttpContentType.h"

using namespace HttpServer::Infrustructure::Http;
using namespace HttpServer::Infrustructure::Utils;
using namespace HttpServer::Infrustructure::Enums;
using namespace std;

const string HttpUtils::HttpResponseTitleTemplate = "HTTP/%.1f %d %s";
const string HttpUtils::HttpHeaderTemplate = "%s : %s";

const map<string, string> HttpUtils::HttpLocalizedValues = {
	{ "HttpStatusCode.200", "OK" },
	{ "ContentType", "Content-Type" },
	{ "ContentLength", "content-length" }
};

const map<string, HttpRequestType> HttpUtils::HttpRequestTypeValues = {
	{ "GET", HttpRequestType::Get},
	{ "POST", HttpRequestType::Post},
	{ "DELETE", HttpRequestType::Delete},
	{ "POST", HttpRequestType::Post},
	{ "HEAD", HttpRequestType::Head},
	{ "TRACE", HttpRequestType::Trace},
	{ "PUT", HttpRequestType::Put},
	{ "CONNECT", HttpRequestType::Connect},
	{ "OPTIONS", HttpRequestType::Options},
	{ "PATCH", HttpRequestType::Patch}
};

const map<HttpContentType, string> HttpUtils::HttpContentTypeValues = {
	{ HttpContentType::TextHtml, "text/html" }
};

string HttpUtils::GetNewLineSeparatedHeaders(vector<string>& headers)
{
	return StringUtils::GetSeparatedString(headers, StringUtils::DefaultLineSeparatedString);
}

string HttpUtils::GetResponseTitle(double httpVersion, HttpStatusCode statusCode)
{
	char* buffer = new char[StringUtils::DefaultBufferSizeForFormatting];
	snprintf(buffer,
		StringUtils::DefaultBufferSizeForFormatting,
		HttpResponseTitleTemplate.c_str(),
		httpVersion,
		static_cast<int>(statusCode),
		HttpLocalizedValues.at(StringUtils::GetLocalizedEnumValue<HttpStatusCode>(statusCode)).c_str()
	);
	string resultString = string(buffer);
	delete[] buffer;
	return resultString;
}

string HttpUtils::GetDefaultBodyDelimeter()
{
	return StringUtils::DefaultLineSeparatedString;
}

string HttpUtils::GetHeader(string type, string value)
{
	char* buffer = new char[StringUtils::DefaultBufferSizeForFormatting];
	snprintf(buffer, StringUtils::DefaultBufferSizeForFormatting, HttpHeaderTemplate.c_str(), type.c_str(), value.c_str());
	string resultString = string(buffer);
	delete[] buffer;
	return resultString;
}

string HttpUtils::GetHttpLocalizedValue(string key)
{
	return HttpLocalizedValues.at(key);
}

HttpRequestType HttpUtils::GetHttpRequestTypeValue(string key)
{
	return HttpRequestTypeValues.at(key);
}

string HttpUtils::GetHttpContentTypeValue(HttpContentType key)
{
	return HttpContentTypeValues.at(key);
}
