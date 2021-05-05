#include "helloWorld.hpp"
#include <string>

HelloWorld::HelloWorld()
{
    this->message = "Hello World";
    this->unit = 0.0;
    this->cost = 0.0;
}


HelloWorld::HelloWorld(int daUnit)
{
    this->unit = daUnit;
    this->cost = 0.0;
    this->message = "Hello World";
}

HelloWorld::HelloWorld(int daUnit, float doCost)
{
    this->unit = daUnit;
    this->cost = doCost;
    this->message = "Hello World";
}

HelloWorld::HelloWorld(int daUnit, float doCost, const std::string &daMessage)
{
    this->unit = daUnit;
    this->cost = doCost;
    this->message = daMessage;
}

std::string HelloWorld::marshal()
{
    return (message + " = " + std::to_string(unit) + " I cost " + std::to_string(cost) + ".\n" );
}

std::string& HelloWorld::getMessage()
{
    return this->message;
}

int HelloWorld::getUnits(){
    return unit;
}