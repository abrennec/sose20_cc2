#include "cgObjectManager.h"


// constructor
CGObjectManager::CGObjectManager() {

    shader.load("shaders/mask_vert.glsl", "shaders/mask_frag.glsl");
}


CGObjectManager::~CGObjectManager() {
    
    balls.clear();
}


void CGObjectManager::update() {
    
    updateBalls();
    updatePlaneObject();
}


void CGObjectManager::drawBalls() {
    
    for (auto& ball : balls) {
        
        ball.draw();
    }
}


void CGObjectManager::drawPlaneObjects() {
    
    glm::vec2 fboRes{320, 240};
    
    fbo.draw(0,0, fboRes.x, fboRes.y);
    fboSpotlight.draw(fboRes.x + 20, 0, fboRes.x, fboRes.y);
}


void CGObjectManager::setupRandomColorBalls() {
    
    balls.clear();
    
    constexpr int numBalls{4};
    
    // fill our vector
    for (int i = 0; i < numBalls; ++i) {
        
        balls.push_back(Ball());
    }
}


void CGObjectManager::setupRGBColorBalls() {
    
    balls.clear();
    
    balls.push_back(Ball(255,0,0));
    balls.push_back(Ball(0,255,0));
    balls.push_back(Ball(0,0,255));
    balls.push_back(Ball(0,255,255));
    balls.push_back(Ball(255,255,0));
    balls.push_back(Ball(255,0,255));
}



void CGObjectManager::setupTextureQuad(glm::vec2 webCamResolution) {

    planeObjectWebCam.set(webCamResolution.x, webCamResolution.y, 2, 2);
    planeObjectWebCam.mapTexCoords(webCamResolution.x, webCamResolution.y, 0,0);
    //planeObject.mapTexCoordsFromTexture(webCam.getTexture()); // alternative
    
    // Allocate a frame buffer object for offscreen drawing.
    fbo.allocate(webCamResolution.x, webCamResolution.y, GL_RGBA);     // 4 channel color (RGBA)
    fbo.begin();
    ofClear(255, 0);     // clear the fbo to opaque black
    fbo.end();
}


void CGObjectManager::setupShaderQuad(glm::vec2 webCamResolution) {

    planeObjectSpotlight.set(webCamResolution.x, webCamResolution.y, 2, 2);
    planeObjectSpotlight.mapTexCoords(webCamResolution.x, webCamResolution.y, 0, 0); // u1, v1, u2, v2
    
    // Allocate a frame buffer object for offscreen drawing.
    fboSpotlight.allocate(webCamResolution.x, webCamResolution.y, GL_RGBA);     // 4 channel color (RGBA)
    fboSpotlight.begin();
    ofClear(255, 0);     // clear the fbo to opaque black
    fboSpotlight.end();
}



void CGObjectManager::updateBalls() {
    
    for (auto& ball : balls) {
        
        ball.update();
    }
}



void CGObjectManager::updatePlaneObject() {
    
    // Check if the texture has already been set. If not,
    // do not execute the subsequent calls.
    if (!webCamTexture.isAllocated()) return;
    
    
    fbo.begin();

    planeObjectWebCam.rotateDeg(0.25, 0,1,0);   // spin 3D quad mesh
    
    // NOTE: The planeObjectWebCam object has its origin at the center.
    // Therefore we need to translate the object in order to align
    // it with the fbo view.
    ofPushMatrix();
    ofTranslate(planeObjectWebCam.getWidth()/2.0, planeObjectWebCam.getHeight()/2.0);
    ofSetColor(255);
    
    webCamTexture.bind();
    planeObjectWebCam.draw();        // draw shader on quad surface
    webCamTexture.unbind();

    ofPopMatrix();
    
    fbo.end();
}



void CGObjectManager::setWebCamTexture(const ofTexture& tex) {
    
    webCamTexture = tex;
}


void CGObjectManager::createSpotlightTexture(const ofImage& screenImg) {
    
    if (!webCamTexture.isAllocated()) return;
    
    // TODO: Take care of resizing the images and creating the required texture objects.
    // TODO: Hint: Checkout the ofTexture "allocate" function in combination with ofPixels.

    // Make use of the fboSpotlight and draw into it. You might want to use ofClear(...).
    fboSpotlight.begin();
    
    
    // TODO: Take care of positioning the planeObjectSpotlight correctly.
    
    // TODO: Take care of binding and using the textures in the shader.
    
    // TODO: Don't forget to draw the actual vertices (plane object).
    
    
    fboSpotlight.end();
    
}
