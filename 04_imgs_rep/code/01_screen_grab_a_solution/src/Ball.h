// Ball.h

#pragma once

// ofMain.h lets our Ball "see" openFrameworks
// This means you can use openFrameworks functionality and objects
#include "ofMain.h"

class Ball {

public:		// other classes can access the following functions & variables:

    Ball(int r, int g, int b);
	Ball();				// "constructor" function - required for every class
						// this is automatically called whenever we create a new ball

	void update();
	void draw();

	float radius;		// size
	float x, y;			// position
	float dirX, dirY;	// "direction" (a.k.a. velocity or speed)

	ofColor color;

};
