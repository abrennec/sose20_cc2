#include "triangleMesh.h"

//--------------------------------------------------------------
triangleMesh::triangleMesh(){

    //shader.load("shaders/0_simple_vert.glsl", "shaders/0_simple_frag.glsl");
    //shader.load("shaders/1_uniform_vert.glsl", "shaders/1_uniform_frag.glsl");
    //shader.load("shaders/2_varying_vert.glsl", "shaders/2_varying_frag.glsl");
    //shader.load("shaders/3_texture_vert.glsl", "shaders/3_texture_frag.glsl");
    //shader.load("shaders/4_texture_mask_vert.glsl", "shaders/4_texture_mask_frag.glsl");
    
    myImage.load("lions2.png");
    myTexture = myImage.getTexture();
    myImageMask.load("lions2_mask.png");
    myTextureMask = myImageMask.getTexture();
    
    setupMesh();
}

//--------------------------------------------------------------
void triangleMesh::update(){

}

//--------------------------------------------------------------
void triangleMesh::draw(){

    noShaderDraw();
//    simpleShaderDraw();
//    uniformShaderDraw();
//    varyingShaderDraw();
//    textureShaderDraw();
//    textureMaskShaderDraw();
      
    myMesh.drawWireframe();
}

//--------------------------------------------------------------
void triangleMesh::setupMesh() {
    
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
    
    
    // order is important!
    myMesh.addIndex(0); // indicate a line from vertex 0 to 1 (top to left)
    myMesh.addIndex(1); // indicate a line from vertex 1 to 2 (left to right)
    myMesh.addIndex(2); // indicate a line from vertex 2 to 0 (right to top)

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
void triangleMesh::noShaderDraw() {

    myTexture.bind();
    
    myMesh.draw(); // draws the mesh "filled" with color

    myTexture.unbind();
}

//--------------------------------------------------------------
void triangleMesh::simpleShaderDraw() {

    // These calls have no effect because the shader takes care
    // of the drawing and does not yet use any texture.
    myTexture.bind();
    
    shader.begin();

    myMesh.draw(); // draws the mesh "filled" with color

    shader.end();
    
    myTexture.unbind();

}

//--------------------------------------------------------------
void triangleMesh::uniformShaderDraw() {

    // myTexture.bind();
     
    shader.begin();

    // Specify some variables to be used / changed in the shader.
    // In this example, color and scale are local variables. However,
    // you could turn them into member variables and use them to
    // interactively change them.
    glm::vec4 color{0.75, 0.5, 0.75, 1.0};
    glm::vec4 scale{1.0, 0.75, 0.75, 1.0};

    // Specify the variables as uniform variables inside the shader
    // object so the shader is aware of there existence and values.
    shader.setUniform4f("scale", scale);
    shader.setUniform4f("color", color);

    myMesh.draw(); // draws the mesh "filled" with color

    shader.end();
     
    //myTexture.unbind();
}

//--------------------------------------------------------------
void triangleMesh::varyingShaderDraw() {
    
    // myTexture.bind();
     
    shader.begin();

    // Specify some variables to be used / changed in the shader.
    // In this example, color and scale are local variables. However,
    // you could turn them into member variables and use them to
    // interactively change them.
    glm::vec4 color{0.75, 0.5, 0.75, 1.0};
    glm::vec4 scale{1.0, 0.75, 0.75, 1.0};

    // Specify the variables as uniform variables inside the shader
    // object so the shader is aware of there existence and values.
    shader.setUniform4f("scale", scale);
    shader.setUniform4f("color", color);

    myMesh.draw(); // draws the mesh "filled" with color

    shader.end();
     
    //myTexture.unbind();
}

//--------------------------------------------------------------
void triangleMesh::textureShaderDraw() {
    
    // If we bind the texture around a shader begin() and end() context,
    // in the shader the texture will be available as "tex0" by default.
    // We can just go ahead and access it there.
    myTexture.bind();
    
    shader.begin();

    // Specify some variables to be used / changed in the shader.
    // In this example, color and scale are local variables. However,
    // you could turn them into member variables and use them to
    // interactively change them.
    glm::vec4 scale{1.0, 0.75, 0.75, 1.0};

    // Specify the variables as uniform variables inside the shader
    // object so the shader is aware of there existence and values.
    shader.setUniform4f("scale", scale);

    myMesh.draw(); // draws the mesh "filled" with color

    shader.end();
    
    myTexture.unbind();
}

//--------------------------------------------------------------
void triangleMesh::textureMaskShaderDraw() {
    
    // If we bind the texture around a shader begin() and end() context,
    // in the shader the texture will be available as "tex0" by default.
    // We can just go ahead and access it there.
    myTexture.bind(); // binds the texture to the identifier tex0 at position 0
    
    shader.begin();

    // Specify some variables to be used / changed in the shader.
    // In this example, color and scale are local variables. However,
    // you could turn them into member variables and use them to
    // interactively change them.
    glm::vec4 scale{1.0, 0.75, 0.75, 1.0};

    // Specify the variables as uniform variables inside the shader
    // object so the shader is aware of there existence and values.
    shader.setUniform4f("scale", scale);
    
    // If you want to process more than one texture,
    // set a uniform texture variable called "texture1", hand over the
    // texture object and inform the shader about the texture's position > 0.
    shader.setUniformTexture("texture1", myTextureMask, 1);

    myMesh.draw();

    shader.end();
    
    myTexture.unbind();
}

//--------------------------------------------------------------
void triangleMesh::updateVertex(const glm::vec3& mousePos) {
    
    if (dragIndex >= 0 && dragIndex < 3) {
        
        // myMesh.getVertex(dragIndex); // returns a copy only!
        myMesh.getVertices().at(dragIndex) = mousePos; // copy operation!
    }
}
