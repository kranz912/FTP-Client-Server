#pragma once

#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <algorithm>

class ServerConnection {
public:
	ServerConnection(int filedescriptor, unsigned int connId, std::string defaultDir, std::string hostId, unsigned short commandOffset = 1);
	std::string commandParser(std::string cmd);
	std::vector<std::string> extractParameters(std::string cmd);
	virtual ~ServerConnection();
	void run();
	void respondToQuery();
	int getFD();
	bool getCloseRequestStatus();
	unsigned int getConnectionId();

private:
	int fd; // Filedescriptor per each threaded object
	int fdflags;
	bool closureRequested;
	std::vector<std::string> directories;
	std::vector<std::string> files;
	unsigned int connectionId;
	std::string dir;
	std::string hostAddress;
	bool uploadCommand;
	bool downloadCommand;
	std::string parameter;
	//fileoperator* fo; // For browsing, writing and reading
	void sendToClient(char* response, unsigned long length);
	void sendToClient(std::string response);
	bool commandEquals(std::string a, std::string b);
	std::string filterOutBlanks(std::string inString);
	static void getAllParametersAfter(std::vector<std::string> parameterVector, unsigned int currentParameter, std::string& theRest);
	unsigned short commandOffset;
	unsigned long receivedPart;
};