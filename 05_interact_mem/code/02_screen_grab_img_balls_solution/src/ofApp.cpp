// The code is based on/taken from an example presented in:
// Creative Coding: OpenFrameworks / "Algorithmic Vision"
// Parsons MFA Design and Technology, Fall 2017
// By [Tyler Henry](http://tylerhenry.com), tylerhenry@newschool.edu
// Original sources at https://github.com/tyhenry/dt_openframeworks_f17.


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    setupCGObjects();
    
    setupCamera();
    setupTextureQuad();
    setupFBO();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    cgObjectMgrPtr->update();
    
    webCam.update();
    
    if(webCam.isFrameNew()) {
        
        // TODO: Handover the webCam image (ofPixels or ofTexture?) to
        // TODO: the image manipulation object for further processing.
        
        fbo.begin();
        
        planeObject.rotateDeg(0.25, 0,1,0);   // spin 3D quad mesh
        
        // NOTE: The texturedPlane object has its origin at the center.
        // Therefore we need to translate the object in order to align
        // it with the fbo view.
        ofPushMatrix();
        ofTranslate(webCam.getWidth()/2.0, webCam.getHeight()/2.0);
        ofSetColor(255);
        
        webCam.getTexture().bind();
        planeObject.draw();        // draw shader on quad surface
        webCam.getTexture().unbind();

        ofPopMatrix();
        
        fbo.end();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    cgObjectMgrPtr->draw();
    
    grabAndSaveScreenImg(screenImage);     // Note: Handing over member variable for readability reasons!
        
    ofImage imgProcessed = imgManip.processImage(screenImage.getPixels(), webCam.getPixels());
    
    resizeAndSaveScreenImg(screenImage);
    
    float alpha = createAlphaRectOverlay();
    
    //drawPixelOverlay(alpha);
    
    ofSetColor(255);
    fbo.draw(0,0, webCamResolution.x / 2.0, webCamResolution.y / 2.0);
    
    imgProcessed.draw(glm::vec2(fbo.getWidth() + 10, fbo.getHeight() + 10), webCamResolution.x/2.0, webCamResolution.y/2.0);
}


void ofApp::setupCGObjects(){
    
    // What might be benetifial if we allocate memory for this
    // object dynamically? We make this thing more flexible.
    // Actually, we do not need to create this object unless
    // this function is called. We could further implement a request
    // for user input so that the objects would only be generated
    // (memory would only be allocated) when the user executes
    // this function, like for example:
    // if (the users wants to draw randomly colored balls)
    cgObjectMgrPtr = std::make_shared<CGObjectManager>(CGObjectManager::RANDOM_COL_BALLS);
    // else if (the user wants the app to draw rgb colored balls)
    // cgObjectMgrPtr = std::make_shared<CGObjectManager>(CGObjectManager::RGB_COL_BALLS);
    
}

//--------------------------------------------------------------
void ofApp::setupCamera() {
    
    // When this function is executed, an ofTexture object is
    // created into which the video grabber / webcam draws
    webCam.setup(webCamResolution.x, webCamResolution.y);
    
    // NOTE: Some useless local variables just for educational purposes
    
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
    
    // TODO: The texturedQuad is also a CG object and should be
    // TODO: moved into the cgObjectManager class.
    
    // We want to rotate an image. This is only possible if we map
    // the image to an computer generated object, e.g., a plane object.
    // To do so, we need a texture because a texture allows us to map
    // an image to an object. Therefore, texture coordinates have to
    // be calculated that associate the texture with the object vertices.
    
    // Specify the resolution of the plane object based on the webCam resolution
    // and specify the number of texture coordinates required (2 x 2)
    planeObject.set(webCam.getWidth(), webCam.getHeight(), 2, 2);
    
    // Calculate the texture coordinates for the plane.
    // Be careful, texture coordinates sometimes do not have their origin
    // in the top,left corner of the screen but at the bottom, right corner
    // of the screen resulting in a flipped image.
    planeObject.mapTexCoords(webCam.getWidth(),webCam.getHeight(), 0,0);
    //texturedPlane.mapTexCoordsFromTexture(webCam.getTexture());
}

//--------------------------------------------------------------
void ofApp::setupFBO() {
    
    // Allocate a frame buffer object for offscreen drawing.
    fbo.allocate(webCamResolution.x, webCamResolution.y, GL_RGBA);     // 4 channel color (RGBA)
    fbo.begin();
    ofClear(255, 0);     // clear the fbo to opaque black
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::grabAndSaveScreenImg(ofImage& img) {
    
    // Take a "screenshot" of the frame
    img.grabScreen(0,0,ofGetWidth(),ofGetHeight());  // original code
    
    // Take a screen shot and store it in a texture would be faster.
    //ofTexture texScreen;
    //texScreen.loadScreenData(0, 0, ofGetWidth(), ofGetHeight());
    
    if (savePicture) {
        img.save(ofToString(counter) + "screencap.png");
        img.save(ofToString(counter) + "screencap.jpg");
    }
    
    // NOTE: reference usage and pixels usage
//    ofPixels& pixels = screenImage.getPixels();
//    pixels.swapRgb();   // fix inverted R and B channels
}

//--------------------------------------------------------------
void ofApp::resizeAndSaveScreenImg(ofImage& img) {
    
    // resize the screenshot to 10x10 pixels
    img.resize(10,10); // original code
    
    if (savePicture) {
        img.save(ofToString(counter) + "screencap_resized.png");
        img.save(ofToString(counter) + "screencap_resized.jpg");

        // NOTE: reference usage and pixels usage
        ofPixels& pixels = img.getPixels();
        pixels.swapRgb();   // fix inverted R and B channels
        
        std::string pic1 = ofToString(counter) + "screencap_swapped.png";
        std::string pic2 = ofToString(counter++) + "screencap_swapped.jpg";
        ofSaveImage(pixels, pic1, OF_IMAGE_QUALITY_BEST);
        ofSaveImage(pixels, pic2, OF_IMAGE_QUALITY_BEST);
        
        savePicture = false;
    }
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
        cgObjectMgrPtr->keyPressedEvent(key);
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
