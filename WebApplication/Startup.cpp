#include "../HttpServer/Server.h"

using HttpServer::Server;

int main()
{
	Server::GetInstance().Start();
}