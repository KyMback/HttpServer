#include "Session.h"
#include <string>
#include <fstream>
#include "Exception.h"
#include "HttpParserService.h"
#include "HttpProcessingService.h"

using namespace HttpServer::Infrustructure;
using namespace Http;
using namespace Exceptions;
using namespace std;
using namespace HttpServices;

Session::Session(Connection* connection)
{
	this->_connection = connection;
}

int Session::StartSession()
{
	while(true)
	{
		ConnectionInfo information = _connection->GetData();
		if(information.Status != ConnectionStatus::Alive)
		{
			if(information.Status == ConnectionStatus::Timeout)
			{
				printf("Timeout\n");
			}
			return 0;			
		}
		HttpRequest* request = HttpParserService::ParseStringToHttpRequest(information.Data);
		HttpResponse* response = HttpProcessingService::StartProcessing(request);
		_connection->SetData(HttpParserService::ParseResponseToString(*response));
		delete response;
		delete request;
	}
}

Session::~Session()
{
	delete _connection;
}
