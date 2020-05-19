#include "cgObjectManager.h"


// constructor
CGObjectManager::CGObjectManager() {

    // By default, random colored balls will be created.
    setupRandomColorBalls();
}


CGObjectManager::CGObjectManager(ballType type) {
    
    // Nevertheless, a user defined constructor allows to
    // specialize what type of objects are going to be drawn.
    
    switch (type) {
        case ballType::RANDOM_COL_BALLS:
            setupRandomColorBalls();
            break;
            
        case ballType::RGB_COL_BALLS:
            setupRGBColorBalls();
            break;
    }
}


CGObjectManager::~CGObjectManager() {
    
    balls.clear();
}


void CGObjectManager::update() {
    
    for (auto& ball : balls) {
        
        ball.update();
    }
}


void CGObjectManager::draw() {
    
    for (auto& ball : balls) {
        
        ball.draw();
    }
}


void CGObjectManager::keyPressedEvent(int key) {
    
    if (key == 'd')
    {
        drawRGBColorBalls ? setupRGBColorBalls() : setupRandomColorBalls();
        drawRGBColorBalls = !drawRGBColorBalls;
    }
}

//--------------------------------------------------------------
void CGObjectManager::setupRandomColorBalls() {
    
    balls.clear();
    
    constexpr int numBalls{4};
    
    // fill our vector
    for (int i = 0; i < numBalls; ++i) {
        
        balls.push_back(Ball());
    }
}

//--------------------------------------------------------------
void CGObjectManager::setupRGBColorBalls() {
    
    balls.clear();
    
    balls.push_back(Ball(255,0,0));
    balls.push_back(Ball(0,255,0));
    balls.push_back(Ball(0,0,255));
    balls.push_back(Ball(0,255,255));
    balls.push_back(Ball(255,255,0));
    balls.push_back(Ball(255,0,255));
}
