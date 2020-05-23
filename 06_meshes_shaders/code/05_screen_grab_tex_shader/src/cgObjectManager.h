#pragma once

// Any computer generated objects (CG objects) generation and management
// should be executed in this class. This includes the generation and
// management of the Balls objects and any additional cg object that
// might be added.


#include "ofMain.h"
#include "Ball.h"


class CGObjectManager {
    

public:

	CGObjectManager();
    ~CGObjectManager();

    void update();
    
    void drawBalls();
    void drawPlaneObjects();
    
    void setupRGBColorBalls();
    void setupRandomColorBalls();
    void setupTextureQuad(glm::vec2 webCamResolution);
    void setupShaderQuad(glm::vec2 webCamResolution);
    
    void setWebCamTexture(const ofTexture& tex);
    void createSpotlightTexture(const ofImage& screenImg);

private:
    
    void updatePlaneObject();
    void updateBalls();
    
    std::vector<Ball> balls;
    
    ofFbo fbo;
    ofFbo fboSpotlight;
    ofPlanePrimitive planeObjectWebCam;
    ofPlanePrimitive planeObjectSpotlight;
    ofTexture webCamTexture;
    ofShader shader;

    bool drawRGBColorBalls{true};

};
