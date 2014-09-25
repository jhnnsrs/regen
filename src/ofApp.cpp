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
