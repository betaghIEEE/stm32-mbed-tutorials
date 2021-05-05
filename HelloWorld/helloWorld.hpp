#include <iostream>
#include <cstdio> 
#include <string>

#ifndef HELLO_WORLD
#define HELLO_WORLD

class HelloWorld 
{
    private:
        std::string message;
        int unit;
        float cost;

    public:
        HelloWorld();
        HelloWorld(int daUnit);
        HelloWorld(int daUnit, float doCost);
        HelloWorld(int daUnit, float doCost, const std::string &daMessage);

        std::string& getMessage();
        int getUnits();
        std::string marshal ();
};

#endif 