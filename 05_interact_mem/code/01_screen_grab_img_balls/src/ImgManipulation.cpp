#include "ImgManipulation.h"


// constructor
ImageManipulation::ImageManipulation() {


}

void ImageManipulation::processImage(const ofImage& image) {
    
    // TODO: Why have these variable types been chosen?
    const ofPixels& pixels = image.getPixels();
    const int imageWidth = image.getWidth();
    const int imageHeight = image.getHeight();
    
    for (int i = 0; i < imageWidth; ++i){
        for (int j = 0; j < imageHeight; ++j){
            
            float brightness = pixels.getColor(i,j).getBrightness();
            
            // TODO: Your processing code could come here.
        }
    }
    
}
