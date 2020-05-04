#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofClear(255);
    ofSetBackgroundAuto(false);
    
    // you have to allocate the buffer size that you want to draw into
    fbo.allocate(ofGetWidth()/2, ofGetHeight()/2);
    
    // you have to clearly indicate that you will draw into the fbo
    // instead of drawing directly to screen by using the two ofFBO
    // functions begin() and end():
    fbo.begin();
    ofClear(255, 255, 255, 127);
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //ofBackground(127);
    
    // draw the fbo at a certain position to the screen
    fbo.draw(0, 0);
    
//    ofSetColor(0, 255, 0);
//    ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    fbo.begin();
    //ofSetColor(255,0,0);
    ofDrawCircle(x, y, 30);
    fbo.end();
    
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
