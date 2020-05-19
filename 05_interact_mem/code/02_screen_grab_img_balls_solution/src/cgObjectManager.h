#pragma once

// Any computer generated objects (CG objects) generation and management
// should be executed in this class. This includes the generation and
// management of the Balls objects and any additional cg object that
// might be added.


#include "Ball.h"


class CGObjectManager {
    

public:
    
    enum ballType {
        
        RGB_COL_BALLS,
        RANDOM_COL_BALLS
    };

	CGObjectManager();
    CGObjectManager(ballType type);
    ~CGObjectManager();

    //void setup();
    void update();
    void draw();
    void keyPressedEvent(int key);

private:
    
    void setupRGBColorBalls();
    void setupRandomColorBalls();
    
    std::vector<Ball> balls;

    bool drawRGBColorBalls{true};

};
