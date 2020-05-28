#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // setup the webcam in terms resolution
    
    // setup the cg objects
    // - cg objects has to set up the balls, i.e., fill the vector, etc.
    // - cg objects has to set up the plane (rectangle for the spotlight image)
    
    // to the ofApp project we need to add the class files
    // - balls class
    // - cg object manager class
    //  - cg object mgr members vector<balls>
    //  - cg object mgr members rectangle / plane
    // - image manipulation class

}

//--------------------------------------------------------------
void ofApp::update(){
    
    // check for a new frame of the webcam / videograbber
    
    // if (webCam.frameNew()) {
    //  retrieve the new frame as our webcam image to be further processed
    //  store it some how?
    //  what to store?
    // }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // cg object mgr member to draw the balls
    // cg object mgr member to take a screenshot
    // - where to store what kind of screenshot data?
    
    // image manipulation member to process both images
    // - handover the screenshot of balls & the latest webcam frame/image
    // (- returns the newly generated spotlight image)
    
    // image manipulation member to get the spotlight image
    // - inside of the image manip class add a getter function
    // - inside of the image manip class add a member for the spotlight image
    
    // handover the spotlight image to the cg object manager
    // - inside of the cg object manager class add a function that receives
    //   the spotlight image and maps it to the plane / rectangle
    
    // cg object mgr member to draw the plane with the texture mapped onto it

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
