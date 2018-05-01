#include "Session.h"
#include <iostream>
#include <sstream>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "Exception.h"

using namespace HttpServer::Infrustructure;
using namespace std;

Session::Session(int socketDescriptor)
{
	SocketDescriptor = socketDescriptor;
	InitializeConfigures();
}

void Session::InitializeConfigures()
{
	Timeout.tv_sec = _defaultSessionTimeout;
	Timeout.tv_usec = NULL;
	FD_ZERO(&SetForWaiting);
	FD_SET(SocketDescriptor, &SetForWaiting);
}

int Session::StartSession()
{
	while (true) {
		switch (select(NULL, &SetForWaiting, NULL, NULL, &Timeout))
		{
		case SOCKET_ERROR: printf("error in select\n"); return 1;
		case 0: printf("TimeOut\n"); return 0;
		default: break;
		}
		char buf[1024];

		int result = recv(SocketDescriptor, buf, _maxClientBufferSize, 0); // Считывает данные из сокета

		switch (result)
		{
		case SOCKET_ERROR:				// ошибка получения данных
			//cerr << "recv failed: " << result << "\n";
			return 1;
			//closesocket(_socketDescriptor);
			//break;
		case 0: 						// соединение закрыто клиентом
			/*cerr << "connection closed...\n";
			closesocket(_socketDescriptor);
			break;*/
			return 1;
		default:
			std::stringstream response; // сюда будет записываться ответ клиенту
										// Мы знаем фактический размер полученных данных, поэтому ставим метку конца строки в буфере запроса
			buf[result] = '\0';
			GetResponse(response, buf);

			// Отправляем ответ клиенту с помощью функции send
			if (send(SocketDescriptor, response.str().c_str(),
				response.str().length(), 0) == SOCKET_ERROR) {
				return 1;
				// произошла ошибка при отправле данных
				//cerr << "send failed: " << WSAGetLastError() << "\n";
			}
			break;
		}
	}
}

void Session::GetResponse(stringstream& stream, char* buffer)
{
	stringstream response_body; // тело ответа
								// Данные успешно получены
								// формируем тело ответа (HTML)
	response_body << "<title>Test C++ HTTP Server</title>\n"
		<< "<h1>Test page</h1>\n"
		<< "<p>This is body of the test page...</p>\n"
		<< "<h2>Request headers</h2>\n"
		<< "<pre>" << buffer << "</pre>\n"
		<< "<em><small>Test C++ Http Server</small></em>\n";

	// Формируем весь ответ вместе с заголовками
	stream << "HTTP/1.1 200 OK\r\n"
		<< "Version: HTTP/1.1\r\n"
		<< "Content-Type: text/html; charset=utf-8\r\n"
		<< "Content-Length: " << response_body.str().length()
		<< "\r\n\r\n"
		<< response_body.str();
}

Session::~Session()
{
	// Закрываем соединение к клиентом
	closesocket(SocketDescriptor);
}
