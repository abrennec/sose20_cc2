#include "ImgManipulation.h"


// constructor
ImageManipulation::ImageManipulation() {

    setupFBO();
}


void ImageManipulation::drawSpotlightImg() {
    
    spotlightImg.draw(glm::vec2(0,300), ofGetWidth()/3, ofGetHeight()/3);
}


void ImageManipulation::drawPixelOverlay() {
    
    overlayFbo.draw(glm::vec2(0,0), ofGetWidth(), ofGetHeight());
}



void ImageManipulation::grabAndSaveScreenImg(ofImage& img, bool savePic) {
    
    savePicture = savePic;
    
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



void ImageManipulation::createSpotlightImage(const ofPixels& screenPix, const ofPixels& videoPix) {
    
    ofPixels screenGrab = screenPix;
    ofPixels videoGrab = videoPix;

    alignPixelResolutions(screenGrab, videoGrab);
    generateSpotlightImg(screenGrab, videoGrab);
    
    spotlightImg = videoGrab;
}



void ImageManipulation::createPixelOverlay(ofImage screenImg, const float& alpha) {
    
    resizeAndSaveScreenImg(screenImg);
    
    constexpr int nCols = 10; // use a const variable
    constexpr int nRows = 10;
    const float width = ofGetWidth() / static_cast<float>(nCols);
    const float height = ofGetHeight() / static_cast<float>(nRows);

    
    for (int y=0; y<nRows; y++) {
        for (int x=0; x<nCols; x++) {
            
            // sample the color of the resized screenshot (10x10) at this grid pos
            ofColor color = screenImg.getColor(x,y);
            color.a = alpha;
            
            overlayFbo.begin();
            // draw a rectangle on screen
            ofSetColor(color);
            ofDrawRectangle(x * width, y * height, width, height);
            overlayFbo.end();
        }
    }
}



void ImageManipulation::generateSpotlightImg(const ofPixels& screenGrab, ofPixels& videoGrab) {
    
    if (screenGrab.getWidth() != videoGrab.getWidth() ||
        screenGrab.getHeight() != videoGrab.getHeight()) {
        
        std::cout << "Image resolutions not equally aligned!" << std::endl;
        return;
    }
    
    const int imageWidth = screenGrab.getWidth();
    const int imageHeight = screenGrab.getHeight();
    
    for (int i = 0; i < imageWidth; ++i){
        for (int j = 0; j < imageHeight; ++j){
            
            float brightness = screenGrab.getColor(i,j).getBrightness();
            
            ofColor vgCol = videoGrab.getColor(i, j);
            float vgBright = vgCol.getBrightness();
            
            if (brightness < 0.25) {
                
                vgBright /= 5.0;
            }
            else {
                
                vgBright *= 2.0;
            }
            
            vgCol.setBrightness(vgBright);
            videoGrab.setColor(i, j, vgCol);
            
        }
    }
    
}


void ImageManipulation::alignPixelResolutions(ofPixels& screenGrab, const ofPixels& videoGrab) {
    
    if (screenGrab.getWidth() != videoGrab.getWidth() ||
        screenGrab.getHeight() != videoGrab.getHeight()) {
        
        screenGrab.resize(videoGrab.getWidth(), videoGrab.getHeight());
    }
}


void ImageManipulation::setupFBO() {
    
    // Allocate a frame buffer object for offscreen drawing.
    overlayFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);     // 4 channel color (RGBA)
    overlayFbo.begin();
    ofClear(255, 0);     // clear the fbo to opaque black
    overlayFbo.end();
}


void ImageManipulation::resizeAndSaveScreenImg(ofImage& img) {
    
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
