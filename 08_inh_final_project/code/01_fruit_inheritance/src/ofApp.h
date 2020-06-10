#pragma once

#include "ofMain.h"
#include "fruit.h"
#include "apple.h"
#include "banana.h"


class ofApp : public ofBaseApp{

	public:
    
    // adding the constructor so we can explicitly
    // initialize the member variables 
    ofApp();
    
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
    
    fruit aFruit;
    fruit aSpecialFruit;
    apple anApple;
    banana aBanana;
    
    //std::vector<fruit*> fruitVec;
		
};
