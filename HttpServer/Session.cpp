#include "Session.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "Exception.h"
#include "HttpParserService.h"

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
		auto response = new HttpResponse();
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
		response->SetBody(StartExecute(request));
		_connection->SetData(HttpParserService::ParseResponseToString(*response));
		delete response;
		delete request;
	}
}

string Session::StartExecute(HttpRequest* request)
{
	ifstream myfile(".." + request->Uri);
	string body;
	if(myfile.is_open())
	{		
		getline(myfile, body);
	}else
	{
		body = "File not found";
	}
	myfile.close();
	return body;
}

Session::~Session()
{
	delete _connection;
}
