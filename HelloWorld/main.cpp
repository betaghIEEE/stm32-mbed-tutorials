#include "mbed.h"
#include <cstdio>
#include <string>
#include <iostream>
#include "helloWorld.hpp"

// main() runs in its own thread in the OS
int main()
{
    HelloWorld alpha(5);
    std::string message = "Don't disassember ";
    HelloWorld beta(5, 5.0, message);


    std::cout  <<endl;
    std::cout << "Try 1" << endl;
    std::cout << message << " = number " << std::to_string(5) << endl;

    std::cout << endl;
    std::cout << "Try alpha " << endl;
    std::cout << alpha.marshal() ;


    std::cout << endl;
    std::cout << "Try beta " << endl;
    std::cout << beta.getUnits() << endl;
    std::cout << beta.marshal() ;

    return 0;
}

