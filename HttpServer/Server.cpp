#include "Server.h"

#include <iostream>
#include <sstream>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>

using std::cerr;
using namespace HttpServer;

int Server::Start()
{
	this->ServerConfigurations = new Configuration();	
	this->ServerConfigurations->OpenNewSocket();
	int listen_socket = ServerConfigurations->GetSocketFileDescriptor();

	int result;
	const int max_client_buffer_size = 1024;
	char buf[max_client_buffer_size];
	int client_socket = INVALID_SOCKET;

	for (;;) {
		// Принимаем входящие соединения
		client_socket = accept(listen_socket, NULL, NULL);

		if (client_socket == INVALID_SOCKET) {
			cerr << "accept failed: " << WSAGetLastError() << "\n";
			closesocket(listen_socket);
			WSACleanup();
			return 1;
		}

		result = recv(client_socket, buf, max_client_buffer_size, 0);

		std::stringstream response; // сюда будет записываться ответ клиенту
		std::stringstream response_body; // тело ответа

		if (result == SOCKET_ERROR) {
			// ошибка получения данных
			cerr << "recv failed: " << result << "\n";
			closesocket(client_socket);
		}
		else if (result == 0) {
			// соединение закрыто клиентом
			cerr << "connection closed...\n";
		}
		else if (result > 0) {
			// Мы знаем фактический размер полученных данных, поэтому ставим метку конца строки
			// В буфере запроса.
			buf[result] = '\0';

			// Данные успешно получены
			// формируем тело ответа (HTML)
			response_body << "<title>Test C++ HTTP Server</title>\n"
				<< "<h1>Test page</h1>\n"
				<< "<p>This is body of the test page...</p>\n"
				<< "<h2>Request headers</h2>\n"
				<< "<pre>" << buf << "</pre>\n"
				<< "<em><small>Test C++ Http Server</small></em>\n";

			// Формируем весь ответ вместе с заголовками
			response << "HTTP/1.1 200 OK\r\n"
				<< "Version: HTTP/1.1\r\n"
				<< "Content-Type: text/html; charset=utf-8\r\n"
				<< "Content-Length: " << response_body.str().length()
				<< "\r\n\r\n"
				<< response_body.str();

			// Отправляем ответ клиенту с помощью функции send
			result = send(client_socket, response.str().c_str(),
				response.str().length(), 0);

			if (result == SOCKET_ERROR) {
				// произошла ошибка при отправле данных
				cerr << "send failed: " << WSAGetLastError() << "\n";
			}
			// Закрываем соединение к клиентом
			closesocket(client_socket);
		}
	}
}

Server::Server() = default;

Server::~Server()
{
	delete ServerConfigurations;
}

Server& Server::GetInstance()
{
	static Server server;
	return server;
}

