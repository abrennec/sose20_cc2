#include "ofApp.h"



ofApp::ofApp()
:
aFruit{},
anApple{},
aBanana{}
{
    
    
}


//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    fruit aSpecialFruit{"frutta_speciale_d\'_italia", "pink"    };
    
    ofDrawBitmapString( aSpecialFruit.printType(), 20, 50);
    ofDrawBitmapString( aFruit.printType(), 20, 75);
    ofDrawBitmapString( anApple.printType(), 20, 100);
    ofDrawBitmapString( aBanana.printType(), 20, 125);
    
//    // overriding an inherited function
//    ofDrawBitmapString( aFruit.printColor(), 20, 175);
//    ofDrawBitmapString( anApple.printColor(), 20, 200);
//    ofDrawBitmapString( aBanana.printColor(), 20, 225);
//       
//    // using a private function
//    ofDrawBitmapString( aFruit.printMyOrigin(), 20, 275);
//    ofDrawBitmapString( anApple.printMyOrigin(), 20, 300);
//    ofDrawBitmapString( aBanana.printMyOrigin(), 20, 325);
//    
//    ofDrawBitmapString( anApple.appleComesFrom(), 20, 375);
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

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//{
//int yPos = 50;
//
//for (auto i{0}; i < fruitVec.size(); ++i) {
//
//    fruit* fruitPtr = fruitVec.at(i);
//    //ofDrawBitmapString( aSpecialFruit.printType(), 20, 50);
//    ofDrawBitmapString( fruitPtr->printType(), 20, yPos += 25);
//    ofDrawBitmapString( fruitPtr->printColor(), 20, yPos += 25);
//    ofDrawBitmapString( fruitPtr->printMyOrigin(), 20, yPos += 25);
//
//    yPos += 25;
//}
//}
