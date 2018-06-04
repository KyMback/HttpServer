#include "HttpUtils.h"
#include "StringUtils.h"
#include "HttpRequestType.h"
#include <map>
#include "MimeType.h"

using namespace HttpServer::Infrustructure::Http;
using namespace HttpServer::Infrustructure::Utils;
using namespace HttpServer::Infrustructure::Enums;
using namespace std;

const string HttpUtils::HttpResponseTitleTemplate = "HTTP/%.1f %d %s";
const string HttpUtils::HttpHeaderTemplate = "%s : %s";

const map<string, string> HttpUtils::HttpLocalizedValues = {
	{ "HttpStatusCode.200", "OK" },
	{ "HttpStatusCode.404", "Not Found" },
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

const map<MimeType, string> HttpUtils::HttpContentTypeValues = {
	{ MimeType::TextPlain, "text/plain; charset=utf-8" },
	{ MimeType::TextHtml, "text/html; charset=utf-8" },
	{ MimeType::TextСss, "text/css; charset=utf-8" },
	{ MimeType::TextJavascript, "text/javascript; charset=utf-8" },

	{ MimeType::ImageBmp, "image/bmp;" },
	{ MimeType::ImageGif, "image/gif;" },
	{ MimeType::ImageJpeg, "image/jpeg;" },
	{ MimeType::ImagePng, "image/png;" },
	{ MimeType::ImageWebp, "image/webp;" }
};

const map<string, MimeType> HttpUtils::HttpContentTypeMatchingValues = {
	{"html", MimeType::TextHtml},
	{"js", MimeType::TextJavascript},
	{"css", MimeType::TextСss },

	{"bmp", MimeType::ImageBmp },
	{"gif", MimeType::ImageGif },
	{"jpeg", MimeType::ImageJpeg },
	{"png", MimeType::ImagePng }
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

string HttpUtils::GetHttpContentTypeValue(MimeType key)
{
	return HttpContentTypeValues.at(key);
}

MimeType HttpUtils::GetHttpMimeTypeMatchingValues(string key)
{
	return HttpContentTypeMatchingValues.count(key) == 1 ? HttpContentTypeMatchingValues.at(key) : MimeType::TextPlain;
}
