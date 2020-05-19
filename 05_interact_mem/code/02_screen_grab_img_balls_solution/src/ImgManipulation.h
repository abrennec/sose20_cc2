#pragma once

#include "ofMain.h"

// Any image manipulation should be executed inside of this class.
// This includes also any data transfer from the ofApp object to
// the image manipulation object and vice versa.

class ImageManipulation {

    public:

        ImageManipulation();


    ofImage processImage(const ofPixels& screenPix, const ofPixels& videoPix);
    
    private:

    
    void alignPixelResolutions(ofPixels& screenGrab, const ofPixels& videoGrab);
    void adjustVideoGrab(const ofPixels& screenGrab, ofPixels& videoGrab);
};
