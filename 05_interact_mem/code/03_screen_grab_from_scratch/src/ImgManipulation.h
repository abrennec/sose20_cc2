#pragma once

#include "ofMain.h"

// Any image manipulation should be executed inside of this class.
// This includes also any data transfer from the ofApp object to
// the image manipulation object and vice versa.

class ImageManipulation {

    public:

        ImageManipulation();


    private:

    // How do we need to change this function potentially?
    // This function should receive as an input the screenshot of the cgobjects (balls only!!)
    // as well as an input the latest frame of the videograbber / webcam
    void processImage(const ofImage& image);

};
