#pragma once

#include "ofMain.h"

// Any image manipulation should be executed inside of this class.
// This includes also any data transfer from the ofApp object to
// the image manipulation object and vice versa.

class ImageManipulation {

    public:

        ImageManipulation();


    private:

    void processImage(const ofImage& image);

};
