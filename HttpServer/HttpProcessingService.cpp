#include "HttpProcessingService.h"
#include <fstream>
#include <sstream>
#include "HttpParserService.h"

using namespace std;
using namespace HttpServices;

const string HttpProcessingService::DefaultRootDirectoryPath = "..";

HttpResponse* HttpProcessingService::StartProcessing(HttpRequest * request)
{
	try
	{
		return StartProcessingInternal(request);
	}
	catch (exception& ex)
	{
		auto response = new HttpResponse();
		response->StatusCode = HttpStatusCode::InternalServerError;
		response->SetBody(ex.what());
		return response;
	}
}

HttpResponse* HttpProcessingService::StartProcessingInternal(HttpRequest * request)
{
	auto response = new HttpResponse();
	string path = DefaultRootDirectoryPath + request->Uri;
	if (!IsRequestedStaticContent(path))
	{
		//TODO: search execution code
		response->StatusCode = HttpStatusCode::NotFound;
	}
	else
	{
		ifstream content(path);
		stringstream resultStringStream;
		string temp;
		while (getline(content, temp))
		{
			resultStringStream << temp;
		}
		response->ContentType = HttpParserService::GetMimeTypeOfContent(request->Uri);
		response->SetBody(resultStringStream.str());
		response->StatusCode = HttpStatusCode::OK;
		content.close();
	}
	return response;
}

bool HttpProcessingService::IsRequestedStaticContent(string path)
{
	ifstream content(path);
	bool isOpen = content.is_open();
	content.close();
	return isOpen;
}

