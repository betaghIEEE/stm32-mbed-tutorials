#include "mbed.h"
#include <iostream>
#include <cstdio>
#include <string>
#include "helloWorldStruct.hpp"

// main() runs in its own thread in the OS
int main()
{
    HelloWorld alpha(5);
    std::string shortCircuit = "Don't disassemble ";
    HelloWorld beta(5, shortCircuit);
    //while (true) {
	printf("Message ");
    printf("%d, \n", alpha.getUnits());
    
    std::cout << "Try 1 " << std::endl;
    std::cout << alpha.getMessage() << " = " << std::to_string(alpha.getUnits()) << std::endl;


    std::cout << "Try 2 " << std::endl;
    std::cout << alpha.marshal() << std::endl;

    std::cout << "Try 3 " << std::endl;
    std::cout << beta.marshal() << std::endl; 
		//}
	return 0;
}

