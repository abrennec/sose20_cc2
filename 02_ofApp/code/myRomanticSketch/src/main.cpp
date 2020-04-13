

#include "ofMain.h"     // brings all of the necessary information of openFrameworks
#include "ofApp.h"      // brings all of the necessary information required to build an ofApplication

//========================================================================
int main( ){
    
    ofGLWindowSettings settings;
    settings.setGLVersion(4,1);
    ofCreateWindow(settings);
    
    // by default OpenGL version 2.1
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
