#include "coreServer.h"

coreServer::coreServer(unsigned int port, std::string dir, unsigned short commandOffset) : dir(dir), commandOffset(commandOffset), shutdown(false), connId(0) {
	if (_wchdir(dir.c_str))
		std::cerr << "Dir could not be changed to " << dir << "!" << std::endl;

}
coreServer::~coreServer() {

}
void coreServer::buildSelectList() {

}
void coreServer::freeAllConnections() {

}
int coreServer::handleNewConnection() {

}
void coreServer::readSockets() {

}
int coreServer::start() {

}
void coreServer::setNonBlocking(int &sock) {

}
void coreServer::initSockets(int port) {

}