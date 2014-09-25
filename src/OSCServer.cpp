#include "ofApp.h"

OSCServer::OSCServer(int port) : m_iport(port) {

	setup(m_iport);

}

ofxOscMessage OSCServer::getMessage() {
	ofxOscMessage m;
	getNextMessage(&m);

	return m;

}


OSCServer::~OSCServer()
{
}