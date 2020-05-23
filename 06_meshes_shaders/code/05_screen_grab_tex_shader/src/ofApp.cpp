// The code is based on/taken from an example presented in:
// Creative Coding: OpenFrameworks / "Algorithmic Vision"
// Parsons MFA Design and Technology, Fall 2017
// By [Tyler Henry](http://tylerhenry.com), tylerhenry@newschool.edu
// Original sources at https://github.com/tyhenry/dt_openframeworks_f17.


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);
    
    webCam.setup(640, 480);
    
    glm::vec2 webCamRes{webCam.getWidth(), webCam.getHeight()};
    setupCGObjects(webCamRes);

}

//--------------------------------------------------------------
void ofApp::update(){
        
    webCam.update();
    
    if(webCam.isFrameNew()) {
        
        cgObjectMgrPtr->setWebCamTexture(webCam.getTexture());
    }
    
    cgObjectMgrPtr->update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    cgObjectMgrPtr->drawBalls();
    
    imgManip.grabAndSaveScreenImg(screenImage, savePicture);
    imgManip.createSpotlightImage(screenImage.getPixels(), webCam.getPixels());
    
    cgObjectMgrPtr->createSpotlightTexture(screenImage);
    
    float alpha = createAlphaRectOverlay();
    
    imgManip.createPixelOverlay(screenImage, alpha);
    imgManip.drawPixelOverlay();
    
    ofSetColor(255);
    
    imgManip.drawSpotlightImg();
    
    cgObjectMgrPtr->drawPlaneObjects();
}

//--------------------------------------------------------------
void ofApp::setupCGObjects(glm::vec2 webCamResolution) {
    
    cgObjectMgrPtr = std::make_shared<CGObjectManager>();
    
    cgObjectMgrPtr->setupRGBColorBalls();
    //cgObjectMgrPtr->setupRandomColorBalls();
    cgObjectMgrPtr->setupTextureQuad(webCamResolution);
    cgObjectMgrPtr->setupShaderQuad(webCamResolution);
}


float ofApp::createAlphaRectOverlay() {
    
    // overlay opacity based on mouse x
    float alpha = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);

    
    // Draw a black rectangle with the alpha value defined by mouse x
    // this rectangle separates the balls from the balls visualization below
    // based on the alpha value.
    ofSetColor(0, alpha);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());    // draw black rect to clear screen
    
    // Note that calling ofSetColor( r, g, b ) or ofSetColor( r, g, b, a )
    // before, e.g., an image.draw() implies that the red, green, blue, and alpha
    // components of each image's pixel will be multiplied by
    // r' = r / 255.0, g' = g / 255.0, b' = b / 255.0, and a' = a / 255.0 respectively.
    // ("Mastering openFrameworks", p.90).
    ofSetColor(255, alpha);
    
    return alpha;
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

    savePicture = false;//!savePicture;
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
