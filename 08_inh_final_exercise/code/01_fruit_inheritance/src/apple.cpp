//
//  apple.cpp
//  Inheritance01
//
//  Created by abrennec on 24.06.18.
//  Copyright © 2018 abrennec. All rights reserved.
//

#include "apple.h"


apple::apple()
:
fruit("apple", "green")  // calling the base class constructor
//,myColor{"red"}
{
    
}


//std::string apple::printColor() {
//
//    //return ("APPLE's color is: " + getColor());
//    return ("APPLE's color is: " + myColor);
//}


//std::string apple::appleComesFrom() {
//
//    // since overseas() is declared under protected in the base class
//    // we can use it here.
//    return (overseas() + ".. and that is italia!");
//}
