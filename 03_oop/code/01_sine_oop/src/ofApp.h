#pragma once

#include "ofMain.h"

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
    
    ofPolyline line;
    
    // Assignment: Add a sineCircle object to this class
    // - Create a header file and a definition file for the sineCircle class.
    // - Add both files to your ofApp project, i.e., put the into the src folder
    //      of 01_sine_oop and add them to the project in your IDE.
    // - Add a class specification to the header file.
    // - In the header file, declare all member variables and member functions
    //      that you need to describe your sineCircle - or to achieve the same
    //      rendering as in this original version.
    // - In the definition file, define the functions that you have declared.
    // - Take care of including the header files that you need.
    // - Good luck!
    
		
};
