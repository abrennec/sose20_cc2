#pragma once

#include "ofMain.h"

// Any image manipulation should be executed inside of this class.
// This includes also any data transfer from the ofApp object to
// the image manipulation object and vice versa.

class ImageManipulation {

public:

    ImageManipulation();
    
    void drawSpotlightImg();
    void drawPixelOverlay();
    
    void grabAndSaveScreenImg(ofImage& img, bool savePic);
    void createSpotlightImage(const ofPixels& screenPix, const ofPixels& videoPix);
    void createPixelOverlay(ofImage screenImg, const float& alpha);
    
    void setWebCamPixels(const ofPixels& pix);
    
private:

    void setupFBO();
    void alignPixelResolutions(ofPixels& screenGrab, const ofPixels& videoGrab);
    void generateSpotlightImg(const ofPixels& screenGrab, ofPixels& videoGrab);
    void resizeAndSaveScreenImg(ofImage& img);
    
    bool savePicture{false};
    
    ofImage spotlightImg;
    ofImage pixelOverlay;
    ofFbo overlayFbo;
    ofPixels webCamPixels;
    
    int counter{0};
};
