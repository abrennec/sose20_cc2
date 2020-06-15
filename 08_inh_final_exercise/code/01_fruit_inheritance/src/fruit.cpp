//
//  main.cpp
//  Inheritance01
//
//  Created by abrennec on 24.06.18.
//  Copyright © 2018 abrennec. All rights reserved.
//

#include "fruit.h"

fruit::fruit()
:
myType{"fruity_fruit"},
myColor("generic")
{

}

fruit::fruit(std::string theName, std::string theColor)
:
myType{theName},
myColor(theColor)
{

}


std::string fruit::printType() {

    return ("FRUIT's type is: " + myType);
}


std::string fruit::printColor() {

    return ("FRUIT's color is: " + myColor);
}


std::string fruit::printMyOrigin() {

    return ("FRUIT's origin is " + overseas());
}



// overseas is a protected function and can only be used inside of the class.
// protected members can also be used inside of derived classes!
std::string fruit::overseas() {

    return (".. I am from a land down under ..");
}


//std::string fruit::getColor() {
//    
//    return myColor;
//}
