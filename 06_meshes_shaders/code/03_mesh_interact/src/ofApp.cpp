#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


}

//--------------------------------------------------------------
void ofApp::update(){

    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    triangle.draw();
    
    if (inVertexProximity) {
        
        ofSetColor(255, 0,0);
        ofSetLineWidth(2.0);
        ofNoFill();
        ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 35);
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

    // if mouse x,y are in proximity of vertex draw circle
    // around vertex and set inVertexProximity var to true
    if (triangle.isMouseInProximity(x, y)) {
        
        inVertexProximity = true;
    }
    else {
        
        inVertexProximity = false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

    // if inVertexProximity is true
    // update the vertex position based on mouse x,y
    if (inVertexProximity) {
        
        triangle.updateVertex(glm::vec3(x,y, 0.0));
    }
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
