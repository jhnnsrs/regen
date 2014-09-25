#pragma once

#include "ofMain.h"
#include <iostream>
#include "ofxOsc.h"

#define PORT 12345
#define NUM_MSG_STRINGS 20

class oPoint
{
	
private:
	
	ofVec3f	m_location;
	oPoint();

public:
	int x;
	int y;
	int z;
	oPoint(int _x, int _y, int _z) : x(_x) , y(_y) , z(_z), m_location(_x,_y,_z) {};
	~oPoint();
	int draw();
	void update();
	ofVec3f getLocation() { return m_location; };


};

class Canvas
{
public:
	int m_nPoints;
	ofMesh mesh;
	Canvas(int nPoints);
	~Canvas();
	void Init();
	void setBackground();
	void randomColor();
	void addPointstoMesh();
	void newPoints(int seed);
	oPoint* getPoint(int index);
	oPoint** m_points;


private:
	ofColor m_background;
	

};

class OSCServer : public ofxOscReceiver
{
public:
	OSCServer(int port);
	~OSCServer();
	ofxOscMessage getMessage()

private:
	int m_iport;
	ofxOscMessage actualmessage;

};

class ofApp : public ofBaseApp{

	private:
	Canvas myWindow;
	ofEasyCam easyCam;
	OSCServer Serve;
	bool fullscreen;

	public:
		ofApp() : myWindow(30),fullscreen(false),Serve(PORT) {};

		void setup();
		void update();
		void draw();



		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		int mouseX, mouseY;
		
};






