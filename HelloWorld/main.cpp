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


    std::cout  << std::endl;
    std::cout << "Try 1" << std::endl;
    std::cout << message << " = number " << std::to_string(5) << std::endl;

    std::cout << std::endl;
    std::cout << "Try alpha " << std::endl;
    std::cout << alpha.marshal() ;


    std::cout << std::endl;
    std::cout << "Try beta " << std::endl;
    std::cout << beta.getUnits() << std::endl;
    std::cout << beta.marshal() ;

    return 0;
}

