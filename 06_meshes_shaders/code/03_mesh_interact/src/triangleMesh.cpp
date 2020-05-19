#include "triangleMesh.h"

//--------------------------------------------------------------
triangleMesh::triangleMesh(){

    // turn this into a new object
    
    myImage.load("lions2.png");
    myTexture = myImage.getTexture();
    
    myMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    myMesh.enableColors();      // every vertex that we add to the mesh will have its own color
    myMesh.enableTextures();    // every vertex that we add to the mesh will have its own texture coordinate
    myMesh.enableIndices();     // the vertex order will be specified by their indicies
    
    ofVec3f top(250.0, 50.0, 0.0);
    ofVec3f left(50.0, 450.0, 0.0);
    ofVec3f right(450.0, 450.0, 0.0);
    
    myMesh.addVertex(top);      // vertex at index 0
    myMesh.addVertex(left);     // 1 vertex
    myMesh.addVertex(right);    // 2 vertex
        
    myMesh.addColor(ofFloatColor(1.0, 0.0, 0.0)); // Red
    myMesh.addColor(ofFloatColor(0.0, 1.0, 0.0)); // Green
    myMesh.addColor(ofFloatColor(0.0, 0.0, 1.0)); // Blue
    
    myMesh.addTexCoord(myTexture.getCoordFromPercent(0.5,0));
    myMesh.addTexCoord(myTexture.getCoordFromPercent(0,1));
    myMesh.addTexCoord(myTexture.getCoordFromPercent(1,1));
    
    myMesh.addIndex(0); // indicate a line from vertex 0 to 1 (top to left)
    myMesh.addIndex(1); // indicate a line from vertex 1 to 2 (left to right)
    myMesh.addIndex(2); // indicate a line from vertex 2 to 0 (right to top)

}

//--------------------------------------------------------------
void triangleMesh::update(){

}

//--------------------------------------------------------------
void triangleMesh::draw(){
    
    myTexture.bind();
    myMesh.draw();
    myTexture.unbind();
    
    //myTexture.draw(200, 200, 100, 100);
}

//--------------------------------------------------------------
bool triangleMesh::isMouseInProximity(int x, int y) {
    
    // check whether the mouse position is in close proximity
    // of the three different vertices
    bool isInProximity{false};
    glm::vec3 mouseVec(x, y, 0.0);
    std::vector<glm::vec3> vertexVector = myMesh.getVertices();
    
    for (int i = 0; i < vertexVector.size(); ++i) {
        
        auto vec = vertexVector.at(i);
        
        if (checkVertexProximity(vec, mouseVec)) {
            
            dragIndex = i;
            isInProximity = true;
        }
    }
    
    return isInProximity;
}

//--------------------------------------------------------------
bool triangleMesh::checkVertexProximity(const glm::vec3& vertexA, const glm::vec3& vertexB) {
    
    glm::vec3 vec = vertexA - vertexB;
    float distance = glm::length(vec);
    
    return (distance <= proximityDist) ? true : false;
}

//--------------------------------------------------------------
void triangleMesh::updateVertex(const glm::vec3& mousePos) {
    
    if (dragIndex >= 0 && dragIndex < 3) {
        
        // myMesh.getVertex(dragIndex); // returns a copy only!
        myMesh.getVertices().at(dragIndex) = mousePos; // copy operation!
    }
}
