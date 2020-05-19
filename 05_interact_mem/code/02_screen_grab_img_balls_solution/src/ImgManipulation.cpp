#include "ImgManipulation.h"


// constructor
ImageManipulation::ImageManipulation() {


}


// What would be an alternative return value?
ofImage ImageManipulation::processImage(const ofPixels& screenPix, const ofPixels& videoPix) {
    
    ofPixels screenGrab = screenPix;
    ofPixels videoGrab = videoPix;

    alignPixelResolutions(screenGrab, videoGrab);
    
    adjustVideoGrab(screenGrab, videoGrab);
    
    return videoGrab;
}


void ImageManipulation::adjustVideoGrab(const ofPixels& screenGrab, ofPixels& videoGrab) {
    
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
