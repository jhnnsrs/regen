#include "ofApp.h"


Canvas::Canvas(int _nPoints) : m_background(255,255,0), m_nPoints(_nPoints)
{
	float x = ofGetWindowWidth();
	float y = ofGetWindowHeight();
	std::cout << "Hello";
	m_points = new oPoint*[_nPoints];
	for (int i = 0; i < _nPoints; i++)
	{
		m_points[i] = new oPoint(ofRandom(0,x),ofRandom(0,y),ofRandom(0,255));

	};
}

void Canvas::newPoints(int seed) {

	float x = ofGetWindowWidth();
	float y = ofGetWindowHeight();
	delete m_points;
	m_points = new oPoint*[m_nPoints];
	for (int i = 0; i < m_nPoints; i++)
	{
		m_points[i] = new oPoint(ofRandom(0,x),ofRandom(0,y),ofRandom(0,600));

	};


}

void Canvas::Init() {

	ofEnableDepthTest();
	mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	mesh.enableColors();

}

void Canvas::addPointstoMesh() {
	for (int i = 0; i < m_nPoints; i++)
	{
		mesh.addVertex(m_points[i]->getLocation());
		mesh.addColor(ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
	}

}

void Canvas::setBackground()
{
	
	ofBackgroundGradient(m_background,ofColor(0,0,0),OF_GRADIENT_CIRCULAR);

}
void Canvas::randomColor()
{
	m_background = ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
}

oPoint* Canvas::getPoint(int _nIndex) {

	return m_points[_nIndex];

}

Canvas::~Canvas()
{
	delete m_points;
	std::cout << "Bye";
}



