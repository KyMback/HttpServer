#include "Http.h"
#include "HttpUtils.h"
#include "StringUtils.h"

using std::stringstream;
using namespace  HttpServer::Infrustructure::Http;
using HttpServer::Infrustructure::Utils::StringUtils;

stringstream Http::GetStringStream()
{
	stringstream resultStream;
	resultStream << GetTitle() << StringUtils::DefaultLineSeparatedString;
	StringUtils::GetDefaultSeparatedString(GetHeaders());
	resultStream << StringUtils::DefaultLineSeparatedString << StringUtils::DefaultLineSeparatedString;
	resultStream << GetBody();

	return resultStream;
}
