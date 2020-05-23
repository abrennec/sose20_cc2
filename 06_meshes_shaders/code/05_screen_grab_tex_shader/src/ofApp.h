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
    
    void setupCGObjects(glm::vec2 webCamResolution);
    
    float createAlphaRectOverlay();

    
    ImageManipulation imgManip;
    
    // We will use a shared_ptr for this object to be more
    // flexible in terms of memory allocation and user interactivity.
    std::shared_ptr<CGObjectManager> cgObjectMgrPtr{nullptr};
    
    ofVideoGrabber webCam;
    
	ofImage screenImage; // store a "screenshot" of each frame
    
    bool savePicture{false};
};
