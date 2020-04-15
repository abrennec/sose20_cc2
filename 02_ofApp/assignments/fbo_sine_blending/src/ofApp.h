#pragma once

#include "ofMain.h"
#include <iostream>

class ofApp : public ofBaseApp{

	public:

		void setup();
		void draw();
		void draw_fbo1();
		void draw_sine2();
		

		ofFbo fbo_sine1;
		ofFbo fbo_sine2; 
		ofPolyline line_sine1;
		ofPolyline line_sine2;
		
		int width;
		int height;
};
