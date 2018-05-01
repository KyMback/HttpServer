#include "Http.h"
#include "HttpUtils.h"

using std::stringstream;
using namespace  HttpServer::Infrustructure::Http;

stringstream Http::GetStringStream()
{
	stringstream resultStream;
	resultStream << GetTitle() << HttpUtils::defaultLineSeparatedString;
	for (const auto& header : GetHeaders())
	{
		resultStream << header << HttpUtils::defaultLineSeparatedString;
	}
	resultStream << HttpUtils::defaultLineSeparatedString;
	resultStream << GetBody();

	return resultStream;
}
