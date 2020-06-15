//
//  fruit.h
//  Inheritance01
//
//  Created by abrennec on 24.06.18.
//  Copyright © 2018 abrennec. All rights reserved.
//

#pragma once

#include <iostream>

class fruit
{
public:
    // constructors
    fruit();
    fruit(std::string theName, std::string theColor);
    
    std::string printType();
    std::string printColor();
    std::string printMyOrigin();
    
protected:
    
    // Any member variable declared under protected access
    // can be used inside of this class as well as inside
    // of any derived classes as well! These functions cannot
    // be access from outside of the classes or objects.
    std::string overseas();
    
//    std::string getColor();
    
private:
    
    std::string myType;
    std::string myColor;
};
