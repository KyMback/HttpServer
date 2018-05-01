#include "Session.h"
#include <iostream>
#include <sstream>
#include <string>
#include "Exception.h"

using namespace HttpServer::Infrustructure;
using namespace Http;
using namespace Exceptions;
using namespace std;

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
		//TODO: Execute
		//_connection->SetData(GetResponse(nullptr)->GetStringStream().str());
		_connection->SetData(GetCustomData(information.Data));
	}
}

string Session::GetCustomData(string body)
{
	stringstream stream;
	stringstream response_body;
	response_body << "<title>Test C++ HTTP Server</title>\n"
		<< "<h1>Test page</h1>\n"
		<< "<p>This is body of the test page...</p>\n"
		<< "<h2>Request headers</h2>\n"
		<< "<pre>" << body << "</pre>\n"
		<< "<em><small>Test C++ Http Server</small></em>\n";

	// Формируем весь ответ вместе с заголовками
	stream << "HTTP/1.1 200 OK\r\n"
		<< "Version: HTTP/1.1\r\n"
		<< "Content-Type: text/html; charset=utf-8\r\n"
		<< "Content-Length: " << response_body.str().length()
		<< "\r\n\r\n"
		<< response_body.str();
	return stream.str();
}

HttpResponse* Session::GetResponse(string body)
{
	HttpResponse* response = new HttpResponse();
	response->SetBody(body);
	//stringstream stream;
	//stringstream response_body;
	//response_body << "<title>Test C++ HTTP Server</title>\n"
	//	<< "<h1>Test page</h1>\n"
	//	<< "<p>This is body of the test page...</p>\n"
	//	<< "<h2>Request headers</h2>\n"
	//	<< "<pre>" << buffer << "</pre>\n"
	//	<< "<em><small>Test C++ Http Server</small></em>\n";

	//// Формируем весь ответ вместе с заголовками
	//stream << "HTTP/1.1 200 OK\r\n"
	//	<< "Version: HTTP/1.1\r\n"
	//	<< "Content-Type: text/html; charset=utf-8\r\n"
	//	<< "Content-Length: " << response_body.str().length()
	//	<< "\r\n\r\n"
	//	<< response_body.str();
	return response;
}

HttpRequest* Session::GetRequest(stringstream& stream)
{
	return new HttpRequest();
}

Session::~Session()
{
	delete _connection;
}
