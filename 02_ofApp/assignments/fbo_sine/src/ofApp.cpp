// Code originally from Zach Lieberman
// ofZach - github repository "RTP_SFPC_FALL19"
// Modifications by abrennec, 2020, for Creative Coding 2

#include "ofApp.h"


//--------------------------------------------------------------

void ofApp::setup() {

//	ofSetBackgroundAuto(false);
	width = ofGetWidth();
	height = ofGetHeight();
	//fbo_sine1.allocate(width, height, GL_RGBA32F_ARB);
    fbo_sine1.allocate(width, height, GL_RGBA);

	fbo_sine1.begin();
	ofClear(255, 255, 255, 100);
	fbo_sine1.end();
    
    blendMode = OF_BLENDMODE_ALPHA;
}

void ofApp::update() {
    
}

void ofApp::draw() {
      
    ofEnableAlphaBlending();    // turn on alpha blending
    ofSetColor(255,0,0,127);    // red, 50% transparent
    ofDrawRectangle(20,20,100,100);      // draws the rect with alpha
    ofDisableAlphaBlending();   // turn off alpha
    ofDrawRectangle(120,20,100,100); // draws the rect without alpha
    
    ofEnableAlphaBlending();
    ofFill();
    ofSetColor(255, 0, 0, ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255));
    ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 15);
    ofDisableAlphaBlending();   // turn off alpha
    
    ofBackground(0);
    ofSetColor(255,255,255);
    
    //ofEnableBlendMode(blendMode);
    ofEnableAlphaBlending();
    fbo_sine1.begin();
    draw_fbo1();
    fbo_sine1.end();
    
	fbo_sine1.draw(0, 0);
//    draw_sine2();
}

void ofApp::draw_fbo1(){

	float xorig = 400;
	float yorig = 400;
	float radius = 200;
	float angle = ofGetElapsedTimef();
	float x = xorig + radius * cos(angle);
	float y = yorig + radius * sin(angle);

    line_sine1.clear();

    ofFill();
    ofSetColor(255, 255, 255, 40);
    //ofSetColor(0, ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255));
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

    ofNoFill();
    ofSetColor(100, 0, 0);
    ofDrawCircle(x, y, 3);

    ofPushMatrix();
    ofBeginShape();

    if (line_sine1.size() > 150)
    {
        line_sine1.getVertices().erase(line_sine1.getVertices().begin());
    }
    line_sine1.addVertex(x, y);

    ofEndShape(true);
    line_sine1.draw();
    ofPopMatrix();
}

void ofApp::draw_sine2() {


	//ofBackground(0, 100);

	float xorig = 400;
	float yorig = 400;
	float radius = 200;
	float angle = ofGetElapsedTimef();
	float x = xorig + radius * cos(angle*1.0);
	float y = yorig + radius * sin(angle*3.0);

    ofFill();
    ofSetColor(255, 255, 255, 100);
	ofDrawCircle(x, y, 5);

	if (line_sine2.size() > 300) {
		line_sine2.getVertices().erase(line_sine2.getVertices().begin());
	}
	line_sine2.addVertex(x, y);
	line_sine2.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){

    switch (key) {
        case 49:
            blendMode = OF_BLENDMODE_ALPHA;
            eventString = "Alpha";
            break;
        case 50:
            blendMode = OF_BLENDMODE_ADD;
            eventString = "Add";
            break;
        case 51:
            blendMode = OF_BLENDMODE_MULTIPLY;
            eventString = "Multiply";
            break;
        case 52:
            blendMode = OF_BLENDMODE_SUBTRACT;
            eventString = "Subtract";
            break;
        case 53:
            blendMode = OF_BLENDMODE_SCREEN;
            eventString = "Screen";
            break;
        default:
            break;
    }
}
