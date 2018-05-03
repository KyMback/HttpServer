#include "HttpUtils.h"
#include "StringUtils.h"
#include <map>

using namespace HttpServer::Infrustructure::Http;
using namespace HttpServer::Infrustructure::Utils;
using namespace std;

const string HttpUtils::HttpResponseTitleTemplate = "HTTP/%f.1 %d %s";
const string HttpUtils::HttpHeaderTemplate = "%s : %s";

const map<string, string> HttpUtils::HttpLocalizedValues = {
	{ "HttpStatusCode.200", "OK" },
	{ "ContentType", "Content-Type" },
	{ "ContentLength", "content-length" }
};

string HttpUtils::GetNewLineSeparatedHeaders(vector<string>& headers)
{
	return StringUtils::GetSeparatedString(headers, "\r\n");
}

string HttpUtils::GetResponseTitle(double httpVersion, HttpStatusCode statusCode)
{
	char* buffer = new char[StringUtils::DefaultBufferSizeForFormatting];
	snprintf(buffer,
		StringUtils::DefaultBufferSizeForFormatting,
		HttpResponseTitleTemplate.c_str(),
		to_string(httpVersion).c_str(),
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
