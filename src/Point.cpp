#include "ofApp.h"


int oPoint::draw() {

	return 1;
}

void oPoint::update() {
	m_location = ofVec3f(x,y,z);
}

