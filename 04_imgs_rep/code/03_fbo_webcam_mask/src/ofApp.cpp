// The code is based on/taken from an example presented in:
// # DM-GY-9103-Advanced-Creative-Coding
// Class repository for Advanced Creative Coding
// https://github.com/IDMNYU/DM-GY-9103-Advanced-Creative-Coding


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
	videoGrabber.setup(320, 240);
	videoGrabber.setVerbose(true);
	frameBufferObject.allocate(videoGrabber.getWidth(), videoGrabber.getHeight(), GL_RGBA);
	
	//now we add lines to our path
	pathShape.lineTo(videoGrabber.getWidth()/4, videoGrabber.getHeight());
	pathShape.lineTo(videoGrabber.getWidth()/2, videoGrabber.getHeight()/ 2);
	pathShape.lineTo(videoGrabber.getWidth(), 0);
	pathShape.close();
    
//    pathShape.circle(videoGrabber.getWidth()/2, videoGrabber.getHeight()/2, videoGrabber.getHeight()/ 2);
//    pathShape.close();
//    pathShape.setFillColor(ofColor::orangeRed);
	
	frameBufferObject.begin();
	ofClear(0);
	pathShape.draw();
	frameBufferObject.end();
	
}

//--------------------------------------------------------------
void ofApp::update(){
    
	videoGrabber.update();
    
	// we check whether the videoGrabber has a new frame
	if(videoGrabber.isFrameNew()){
        
		//if so we get the videoGrabber texture, and set an alpha mask on it from our fbo
		videoGrabber.
			getTexture().
			setAlphaMask(frameBufferObject.getTexture());
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
	//draw the webcam
	videoGrabber.draw(ofGetMouseX(), ofGetMouseY());
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
