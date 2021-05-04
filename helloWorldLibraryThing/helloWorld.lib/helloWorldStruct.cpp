#include "helloWorldStruct.hpp"
#include <string>
using std::string;

int HelloWorld::getUnits() {
    return units;
}

HelloWorld::HelloWorld()
{
    this->units = 0;
    this->message = "Hello World";
	this->cost = 0.0;
}

HelloWorld::HelloWorld(int units)
{
    this->units = units;
    this->message = "Hello World";
	this->cost = 0.0;
}

HelloWorld::HelloWorld(int units, std::string &message )
{
    this->units = units;
    this->message = message;
	this->cost = 0.0;
}

HelloWorld::HelloWorld(int units, std::string &message, float cost )
{
    this->units = units;
    this->message = message;
	this->cost = cost;
}


std::string HelloWorld::getMessage()
{
    return this->message;
}


std::string HelloWorld::marshal()
{
	//std::string workingString = this->message;
	//workingString += " = " + std::to_string(this->units);
    return (this->message + " = " + std::to_string(this->units) + " I cost " + std::to_string(cost) +".") ;
}