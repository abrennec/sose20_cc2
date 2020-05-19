#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // turn this into a new object
    
    myImage.load("lions2.png");
    myTexture = myImage.getTexture();
    
    myMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    myMesh.enableColors();
    myMesh.enableTextures();
    myMesh.enableIndices();
    
    glm::vec3 top(100.0, 50.0, 0.0);
    glm::vec3 left(50.0, 150.0, 0.0);
    glm::vec3 right(150.0, 150.0, 0.0);
    
    myMesh.addVertex(top);
    myMesh.addVertex(left);
    myMesh.addVertex(right);
    
    myMesh.addColor(ofFloatColor(1.0, 0.0, 0.0)); // Red top
    myMesh.addColor(ofFloatColor(0.0, 1.0, 0.0)); // Green left
    myMesh.addColor(ofFloatColor(0.0, 0.0, 1.0)); // Blue right

    myMesh.addTexCoord(myTexture.getCoordFromPercent(0.5,0));
    myMesh.addTexCoord(myTexture.getCoordFromPercent(0,1));
    myMesh.addTexCoord(myTexture.getCoordFromPercent(1,1));
    
    myMesh.addIndex(0);
    myMesh.addIndex(1);
    myMesh.addIndex(2);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    myTexture.bind();
    myMesh.draw();
    myTexture.unbind();
    
    myTexture.draw(200, 200, 100, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

    // if mouse x,y are in proximity of vertex draw circle
    // around vertex and set inVertexProximity var to true
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

    // if inVertexProximity is true
    // update the vertex position based on mouse x,y
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
