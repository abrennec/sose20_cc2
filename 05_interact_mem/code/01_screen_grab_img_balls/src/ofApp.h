#pragma once

#include "ofMain.h"
#include "Ball.h"
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
    
    void setupRGBColorBalls();
    void setupRandomColorBalls();
    void setupCamera();
    void setupTextureQuad();
    
    void takeAPicture();
    void drawPixelOverlay(const float& alpha);

	std::vector<Ball> balls;
    
    // If you do not want to work with a video grabber, you can use
    // an ofImage instead. Generally, it will offer you the same
    // functionality that we need in this example, i.e., access to
    // ofPixel and ofTexture.
    ofVideoGrabber webCam;
    ofPlanePrimitive texturedPlane;
	
    // TODO: Turn this member variable into a local variable
    // TODO: and adapt the affected functions.
	ofImage screenImage; // store a "screenshot" of each frame
    
    bool savePicture{false};
    bool drawRGBColorBalls{true};
    bool stopRotating{false};
    int counter{0};
};
