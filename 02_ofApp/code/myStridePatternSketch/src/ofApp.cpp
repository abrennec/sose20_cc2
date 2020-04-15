// This example is taken from the Book "openFrameworks Essentials"




//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    auto myWindowWidth;
    auto myWindowHeight;

    myWindowWidth = ofGetWidth() / 2;
    myWindowHeight = ofGetHeight() / 2;

    ofPushMatrix();
    ofTranslate( myWindowWidth, myWindowHeight );
    
    ofSetColor( ofColor::white );
    ofSetLineWidth( 3.0 );
    ofNoFill();
    
    for (auto i{-50}; i<50; ++i) {
        
        ofPushMatrix();
        ofTranslate( i*20, 0 );
        ofRotateDeg( i*5 );
        ofScale( 6, 6 );
        ofDrawTriangle( 0, 0, -50, 100, 50, 100 );
        ofPopMatrix();
    }
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

