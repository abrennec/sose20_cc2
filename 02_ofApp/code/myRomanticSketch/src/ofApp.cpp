


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    int myMouseX = ofGetMouseX();
    int myMouseY = ofGetMouseY();
    
    // std -> C++ standard library
    // std::cout -> console output
    // << operator -> "piping" data to console output
    // std::endl -> end the output and add a newline 
    std::cout << "mouse x   " << myMouseX << std::endl;
    
    ofBackground(0);
    ofSetColor(255);
    ofDrawCircle(myMouseX, myMouseY, 45);
    
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
