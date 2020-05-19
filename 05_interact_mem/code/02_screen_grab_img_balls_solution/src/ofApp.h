#pragma once

#include "ofMain.h"
#include "ImgManipulation.h"
#include "cgObjectManager.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
    
private:
    
    void setupCGObjects();
    
    void setupCamera();
    void setupTextureQuad();
    void setupFBO();
    
    void grabAndSaveScreenImg(ofImage& img);
    void resizeAndSaveScreenImg(ofImage& img);
    
    float createAlphaRectOverlay();
    void drawPixelOverlay(const float& alpha);

    ImageManipulation imgManip;
    
    // We will use a shared_ptr for this object to be more
    // flexible in terms of memory allocation and user interactivity.
    std::shared_ptr<CGObjectManager> cgObjectMgrPtr{nullptr};
    
    // If you do not want to work with a video grabber, you can use
    // an ofImage instead. Generally, it will offer you the same
    // functionality that we need in this example, i.e., access to
    // ofPixel and ofTexture.
    ofVideoGrabber webCam;
    ofPlanePrimitive planeObject;
    
    ofFbo fbo;
	ofImage screenImage; // store a "screenshot" of each frame
    
    bool savePicture{false};
    int counter{0};
    
    glm::vec2 webCamResolution{640, 480};
};
