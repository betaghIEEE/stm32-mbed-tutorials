
#include <iostream>
#include <cstdio>
#include <string>

#ifndef HELLO_WORLD
#define HELLO_WORLD

class HelloWorld
{
    std::string message;
    int units;
	float cost;
    public:
        HelloWorld();
        HelloWorld(int units = 0);
        HelloWorld(int units, std::string &message );
        HelloWorld(int units, std::string &message, float cost );
        std::string getMessage();
        int getUnits ();
		std::string marshal();

} ;

#endif 