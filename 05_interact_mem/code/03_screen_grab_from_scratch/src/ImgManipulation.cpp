#include "ImgManipulation.h"


// constructor
ImageManipulation::ImageManipulation() {


}

// adapt the parameter list ?!
void ImageManipulation::processImage(const ofImage& image) {
    
    // make sure that both images that you need to process are of the same size
    
    // TODO: Why have these variable types been chosen?
    const ofPixels& pixels = image.getPixels();
    const int imageWidth = image.getWidth();
    const int imageHeight = image.getHeight();
    
    for (int i = 0; i < imageWidth; ++i){
        for (int j = 0; j < imageHeight; ++j){
            
            // TODO: Check out ofPixel's functionality in order to
            // TODO: implement a pixel manipulation.
            //float brightness = pixels.getColor(i,j).getBrightness();
            
            // TODO: Your processing code could come here.
        }
    }
    
}
