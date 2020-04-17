#pragma once

#include "ofMain.h"
#include <iostream>

class ofApp : public ofBaseApp{

	public:

		void setup();
        void update();
		void draw();
		void draw_fbo1();
		void draw_sine2();
		

		ofFbo fbo_sine1;
		ofFbo fbo_sine2; 
		ofPolyline line_sine1;
		ofPolyline line_sine2;
		
		int width;
		int height;
    
    
        void keyPressed(int key);
//        void keyReleased(int key);
//        void mouseMoved(int x, int y );
//        void mouseDragged(int x, int y, int button);
//        void mousePressed(int x, int y, int button);
//        void mouseReleased(int x, int y, int button);
//        void mouseEntered(int x, int y);
//        void mouseExited(int x, int y);
//        void windowResized(int w, int h);
//        void dragEvent(ofDragInfo dragInfo);
//        void gotMessage(ofMessage msg);
        
        ofBlendMode blendMode;
        string eventString;
};
