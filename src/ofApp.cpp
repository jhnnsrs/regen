#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	std::cout << "ofApp setup";
	ofSetFrameRate(60);
	myWindow.Init();
	myWindow.addPointstoMesh();

}

//--------------------------------------------------------------
void ofApp::update(){
	while(Serve.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		Serve.getNextMessage(&m);
        
		std::cout << m.getAddress() <<std::endl;
		// check for mouse moved message
		if(m.getAddress() == "/live/beat"){
			myWindow.mesh.clear();
			myWindow.newPoints(3);
			myWindow.addPointstoMesh();
		}
		else{
			// unrecognized message: display on the bottom of the screen
			string msg_string;
			msg_string = m.getAddress();
			msg_string += ": ";
			for(int i = 0; i < m.getNumArgs(); i++){
				// get the argument type
				msg_string += m.getArgTypeName(i);
				msg_string += ":";
				// display the argument - make sure we get the right type
				if(m.getArgType(i) == OFXOSC_TYPE_INT32){
					msg_string += ofToString(m.getArgAsInt32(i));
				}
				else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT){
					msg_string += ofToString(m.getArgAsFloat(i));
				}
				else if(m.getArgType(i) == OFXOSC_TYPE_STRING){
					msg_string += m.getArgAsString(i);
				}
				else{
					msg_string += "unknown";
				}
			}
		}

	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofDrawBitmapString("Press F for Fullscreen, D and G to randomly change",14,14,4);
	ofDrawBitmapString("Left-Click: Rotate, Right-Click: Zoom",14,28,4);

	myWindow.setBackground();
	easyCam.begin();
        ofPushMatrix();
            ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
            myWindow.mesh.drawFaces();
        ofPopMatrix();
    easyCam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	std::cout << key << "pressed";
	if (key == 100) {
		myWindow.randomColor();
	}
	std::cout << myWindow.getPoint(4)->x <<endl;
	if (key == 103) {
		myWindow.mesh.clear();
		myWindow.newPoints(3);
		myWindow.addPointstoMesh();

	}
	if (key == 102) {
		fullscreen = !fullscreen;
		ofSetFullscreen(fullscreen);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}	

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
