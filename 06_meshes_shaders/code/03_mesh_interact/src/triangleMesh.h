#pragma once

#include "ofMesh.h"
#include "ofTexture.h"
#include "ofImage.h"

class triangleMesh {


public:
    triangleMesh();
    
    void update();
    void draw();
    
    bool isMouseInProximity(int x, int y);
    void updateVertex(const glm::vec3& mousePos);

    
private:
    
    bool checkVertexProximity(const glm::vec3& vertexA, const glm::vec3& vertexB);

    ofMesh myMesh;
    
    ofImage myImage;
    ofTexture myTexture;

    int dragIndex{-1};
    float proximityDist{25};
};
