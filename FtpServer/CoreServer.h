#pragma once
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <winsock2.h>
#include <sys/types.h>
#include <fcntl.h>
#include <vector>
#include <WS2tcpip.h>
#include "ServerConnection.h"
class coreServer {
public:
	coreServer(unsigned int port, std::string dir, unsigned short commandOffset = 1);
	~coreServer();
private:
	int start();
	void initSockets(int port);
	void setNonBlocking(int &sock);
	void buildSelectList();
	void readSockets();
	int handleNewConnection();
	void freeAllConnections();
	unsigned int maxConnectionsInQuery;
	int s;
	int sflags;
	int highSock; 
	fd_set socks; 
	std::string dir;
	unsigned int connId;
	bool shutdown;
	sockaddr_in addr;
	struct sockaddr_storage addrStorage;
	std::vector<ServerConnection*> connections;
	socklen_t addrLength;
	sockaddr_in cli;
	socklen_t cli_size;
	unsigned short commandOffset;
};
