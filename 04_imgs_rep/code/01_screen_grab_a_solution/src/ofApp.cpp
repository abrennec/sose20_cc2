// The code is based on/taken from an example presented in:
// Creative Coding: OpenFrameworks / "Algorithmic Vision"
// Parsons MFA Design and Technology, Fall 2017
// By [Tyler Henry](http://tylerhenry.com), tylerhenry@newschool.edu
// Original sources at https://github.com/tyhenry/dt_openframeworks_f17.


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);
    
    // What happens if you call "ofDisableAlphaBlending() and why?
    //ofDisableAlphaBlending();
    //ofEnableAlphaBlending();
    
    savePicture=false;
    
    setupRandomColorBalls();

}

//--------------------------------------------------------------
void ofApp::update(){

//	for (int i = 0; i < balls.size(); i++) {
//
//		balls[i].update();
//	}
    
    // NOTE: using reference for variable
    for (auto& ball : balls) {
        
        ball.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    // NOTE: range-based for loop with reference
    for (auto& ball : balls) {
        
        ball.draw();
    }
    
//	for (int i = 0; i < balls.size(); i++) {
//		balls[i].draw();
//	}
	
    takeAPicture();
	
	// sample colors from the screenshot, and draw as a grid overlay:
    
	// overlay opacity based on mouse x
	float alpha = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);
	
    // Hint: to better understand how alpha value works
    // set this color to black or white and turn alpha off => ofSetColor(255, 255) or ofSetColor(0, 255)
    // What happens now? And why?
    
    // now draw a black rectangle with the alpha value defined by mouse x
    // this rectangle separates the balls from the balls visualization below
    // based on the alpha value
    ofSetColor(0, alpha);
	ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());	// draw black rect to clear screen

    drawPixelOverlay(alpha);
}

//--------------------------------------------------------------
void ofApp::setupRandomColorBalls() {
    
    balls.clear();
    
    constexpr int numBalls{4};
    
    // fill our vector
    for (int i = 0; i < numBalls; ++i) {
        
        balls.push_back(Ball());
    }
}

//--------------------------------------------------------------
void ofApp::setupRGBColorBalls() {
    
    balls.clear();
    balls.push_back(Ball(255,0,0));
    balls.push_back(Ball(0,255,0));
    balls.push_back(Ball(0,0,255));
    balls.push_back(Ball(0,255,255));
    balls.push_back(Ball(255,255,0));
    balls.push_back(Ball(255,0,255));
}

//--------------------------------------------------------------

void ofApp::takeAPicture() {
    
    // now, take a "screenshot" of the frame
    screenImage.grabScreen(0,0,ofGetWidth(),ofGetHeight());  // original code
    
    if (savePicture) {
        screenImage.save(ofToString(counter) + "screencap.png");
        screenImage.save(ofToString(counter) + "screencap.jpg");
    }

    // resize the screenshot to 10x10 pixels
    screenImage.resize(10,10); // original code
    
    if (savePicture) {
        screenImage.save(ofToString(counter) + "screencap_resized.png");
        screenImage.save(ofToString(counter) + "screencap_resized.jpg");

        // NOTE: reference usage and pixels usage
        ofPixels& pixels = screenImage.getPixels();
        pixels.swapRgb();   // fix inverted R and B channels

        std::string pic1 = ofToString(counter) + "screencap_swapped.png";
        std::string pic2 = ofToString(counter++) + "screencap_swapped.jpg";
        ofSaveImage(pixels, pic1, OF_IMAGE_QUALITY_BEST);
        ofSaveImage(pixels, pic2, OF_IMAGE_QUALITY_BEST);
        
        savePicture = false;
    }
}

//--------------------------------------------------------------
// NOTE const by-reference

void ofApp::drawPixelOverlay(const float& alpha) {
    
    // NOTE: constexpr
    constexpr int nCols = 10; // use a const variable
    constexpr int nRows = 10;
    
    // NOTE: const NOT constexpr
    // grid square size for drawing:
    const float width = ofGetWidth() / static_cast<float>(nCols);
    const float height = ofGetHeight() / static_cast<float>(nRows);

    
    for (int y=0; y<nRows; y++) {
        for (int x=0; x<nCols; x++) {
            
            // sample the color of the resized screenshot (10x10) at this grid pos
            ofColor color = screenImage.getColor(x,y);
            color.a = alpha;
            
            // draw a rectangle on screen
            ofSetColor(color);
            ofDrawRectangle(x * width, y * height, width, height);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'd')
    {
        drawRGBColorBalls ? setupRGBColorBalls() : setupRandomColorBalls();
        drawRGBColorBalls = !drawRGBColorBalls;
    }

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

    savePicture = true;
    
    //
    //    if (counter < 2) {
    //        ofImage img;
    //        //string imgPath = "somepath/";
    //        img.grabScreen( 0, 0, ofGetWidth(), ofGetHeight() );
    //        img.resize(10,10);
    //        ofPixels & pixels = img.getPixels();
    //        pixels.swapRgb();   // fix inverted R and B channels
    //        img.resize(ofGetWidth(), ofGetHeight());
    //
    //        string pic = "screenshot.jpg";
    //        ofSaveImage(pixels, pic, OF_IMAGE_QUALITY_BEST);
    //        img.clear();
    //        pixels.clear();
    //        counter++;
    //    }
        
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
