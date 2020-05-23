#pragma once

#include "ofMain.h"

class triangleMesh {


public:
    triangleMesh();
    
    void update();
    void draw();
    
    bool isMouseInProximity(int x, int y);
    void updateVertex(const glm::vec3& mousePos);

    
private:
    
    void setupMesh();
    bool checkVertexProximity(const glm::vec3& vertexA, const glm::vec3& vertexB);
    
    // The following functions for educational reasons:
    void noShaderDraw();
    void simpleShaderDraw();
    void uniformShaderDraw();
    void varyingShaderDraw();
    void textureShaderDraw();
    void textureMaskShaderDraw();

    ofMesh myMesh;
    
    ofImage myImage;
    ofImage myImageMask;
    ofTexture myTexture;
    ofTexture myTextureMask;
    
    ofShader shader;    //Shader

    int dragIndex{-1};
    float proximityDist{25};
};
