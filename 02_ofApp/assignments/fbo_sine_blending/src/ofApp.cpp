// Code originally from Zach Lieberman
// ofZach - github repository "RTP_SFPC_FALL19"
// Modifications by abrennec, 2020, for Creative Coding 2

#include "ofApp.h"


//--------------------------------------------------------------

void ofApp::setup() {

	ofSetBackgroundAuto(false);
	width = ofGetWidth();
	height = ofGetHeight();
	fbo_sine1.allocate(width, height, GL_RGBA);

	fbo_sine1.begin();
	ofClear(255, 255, 255);

	fbo_sine1.end();

}

void ofApp::draw() {
	draw_fbo1();
	fbo_sine1.draw(0, 0);
}

void ofApp::draw_fbo1(){

	float xorig = 400;
	float yorig = 400;
	float radius = 200;
	float angle = ofGetElapsedTimef();
	float x = xorig + radius * cos(angle);
	float y = yorig + radius * sin(angle);

	fbo_sine1.begin();
		line_sine1.clear();

		ofNoFill();
		ofSetColor(255);
		ofDrawCircle(x, y, 3);


		ofPushMatrix();

		ofBeginShape();

			if (line_sine1.size() > 300) 
			{
				line_sine1.getVertices().erase(line_sine1.getVertices().begin());
			}
			line_sine1.addVertex(x, y);


		ofEndShape(true);

		line_sine1.draw();

		ofPopMatrix();

	fbo_sine1.end();
    
    
    
    
    
    
}

void ofApp::draw_sine2() {


	ofBackground(0);

	float xorig = 400;
	float yorig = 400;
	float radius = 200;
	float angle = ofGetElapsedTimef();
	float x = xorig + radius * cos(angle*1.0);
	float y = yorig + radius * sin(angle*3.0);

	ofDrawCircle(x, y, 5);

	if (line_sine2.size() > 300) {
		line_sine2.getVertices().erase(line_sine2.getVertices().begin());
	}
	line_sine2.addVertex(x, y);
	line_sine2.draw();

}