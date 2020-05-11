// The code is based on/taken from an example presented in:
// Creative Coding: OpenFrameworks / "Algorithmic Vision"
// Parsons MFA Design and Technology, Fall 2017
// By [Tyler Henry](http://tylerhenry.com), tylerhenry@newschool.edu
// Original sources at https://github.com/tyhenry/dt_openframeworks_f17.


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);
    
    // TODO: The balls are cg objects that have to be managed
    // TODO: by the cgObjectManager.
    //setupRandomColorBalls();
    setupRGBColorBalls();
    
    setupCamera();
    setupTextureQuad();
    
    // TODO: These should become the only two setup functions called here.
    // setupCGObjects();
    // setupImageManipulation();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // TODO: Turn this into a function call to cgObjectManager.update()
    // NOTE: using reference for variable
    for (auto& ball : balls) {
        
        ball.update();
    }
    
    
    webCam.update();
    
//    if(webCam.isFrameNew()) {
//
//    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    // TODO: Turn this into cgObjectManager.draw()
    // NOTE: range-based for loop with reference
    for (auto& ball : balls) {

        ball.draw();
    }
    
    // TODO: Take a screen image and hand it over to the imgManipulation object
    // TODO: for further processing.
    
    // TODO: Move the image manipulation functinality to the imgManipulation object.
    takeAPicture();
    
    
	// overlay opacity based on mouse x
	float alpha = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);

    
    // Draw a black rectangle with the alpha value defined by mouse x
    // this rectangle separates the balls from the balls visualization below
    // based on the alpha value.
    ofSetColor(0, alpha);
	ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());	// draw black rect to clear screen
    
    // Note that calling ofSetColor( r, g, b ) or ofSetColor( r, g, b, a )
    // before, e.g., an image.draw() implies that the red, green, blue, and alpha
    // components of each image's pixel will be multiplied by
    // r' = r / 255.0, g' = g / 255.0, b' = b / 255.0, and a' = a / 255.0 respectively.
    // ("Mastering openFrameworks", p.90).
    ofSetColor(255, alpha);
    
    
    webCam.draw(0, 500, 500, 200);
    
    
    // TODO: Move this functionality into the imgManipulation object.
    drawPixelOverlay(alpha);
    
    
    // TODO: Move this functionality into the cgObjectManager object.
    {
        if (!stopRotating)
            planeObject.rotateDeg(0.25, 0,1,0);   // spin 3D quad mesh
        
        // NOTE: The planeObject object has its origin at the center.
        // Therefore we need to translate the object in order to align
        // it with the fbo view.
        ofPushMatrix();
        ofTranslate(webCam.getWidth()/2.0, webCam.getHeight()/2.0);
        ofSetColor(255, alpha);
        
        // TODO: You have to "bind()" and "unbind()" the texture to
        // TODO: and from the plane. How could that work?
        
        planeObject.draw();        // draw the plane gemoetry

        ofPopMatrix();
    }
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
void ofApp::setupCamera() {
    
    // When this function is executed, an ofTexture object is
    // created into which the video grabber / webcam draws
    webCam.setup(640,480);
    
    // TODO: Checkout the following function calls.
    
    // This function call rertrieves the orginial ofTexture object
    // of the video grabber and copies it to the grabTex variable.
    ofTexture grabTex = webCam.getTexture();

    // This function call rertrieves the orginial ofTexture object
    // of the video grabber and uses grabTexRef to refer to the original
    // object - no copy! Any manipulation of grabTexRef will change
    // the video grabber's texture object!
    ofTexture& grabTexRef = webCam.getTexture();
    
    // This function call rertrieves the orginial ofTexture object
    // of the video grabber and uses grabTexRefC to refer to the original
    // object - no copy! However, the const keyword forbids any
    // manipulation of the original texture.
    const ofTexture& grabTexRefC = webCam.getTexture();

    // All of the function calls work for pixels as well
    //const ofPixels& grabPixels = webCam.getPixels();

    // Check and compare the address values of the texture variable
//    std::cout << &grabTex << std::endl;
//    std::cout << &grabTexRef << std::endl;
//    std::cout << &grabber.getTexture() << std::endl;

}


//--------------------------------------------------------------
void ofApp::setupTextureQuad() {
    
    // TODO: The planeObject is also a CG object and should be
    // TODO: moved into the cgObjectManager class.
    
    // We want to rotate an image. This is only possible if we map
    // the image to an computer generated object, e.g., a plane object.
    // To do so, we need a texture because a texture allows us to map
    // an image to an object. Therefore, texture coordinates have to
    // be calculated that associate the texture with the object vertices.
    
    // Specify the resolution of the plane object based on the webCam resolution
    // and specify the number of texture coordinates required (2 x 2)
    
    // TODO: adapt the function call
    planeObject.set(320 , 240, 2, 2);
    
    
    // TODO: Ensure that the texture coordinates are calculated.
    // TODO: The functions at the bottom take care of that. Use one of them.
    // Calculate the texture coordinates for the plane.
    // Be careful, texture coordinates sometimes do not have their origin
    // in the top,left corner of the screen but at the bottom, right corner
    // of the screen resulting in a flipped image.
    
    // checkout the function mapTexCoords( ??? );
    // checkout the function mapTexCoordsFromTexture( ??? );
}


//--------------------------------------------------------------
void ofApp::takeAPicture() {
    
    // Take a "screenshot" of the frame
    screenImage.grabScreen(0,0,ofGetWidth(),ofGetHeight());  // original code
    
    // Take a screen shot and store it in a texture would be faster.
    //ofTexture texScreen;
    //texScreen.loadScreenData(0, 0, ofGetWidth(), ofGetHeight());
    
    if (savePicture) {
        screenImage.save(ofToString(counter) + "screencap.png");
        screenImage.save(ofToString(counter) + "screencap.jpg");
    }
    
    // NOTE: reference usage and pixels usage
    ofPixels& pixels = screenImage.getPixels();
    pixels.swapRgb();   // fix inverted R and B channels

    // resize the screenshot to 10x10 pixels
    screenImage.resize(10,10); // original code
    
    if (savePicture) {
        screenImage.save(ofToString(counter) + "screencap_resized.png");
        screenImage.save(ofToString(counter) + "screencap_resized.jpg");

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
    else if (key == 'r')
    {
        stopRotating = !stopRotating;
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
