/*********************************************
In this project, an RGB LED is connect. So are 3 buttons. 
Pressing a button toggles the corresponding color.

R button = PC_0
G button = PC_1
B button = PC_2

The RGB LED pin are connected as follows:
Red = PC_3
Green = PC_4
Blue = PC_5

Original Supplied by Dogan Ibrahim, August 2018 in 
"ARM-based Microcontroller Projects Using mBed"
Modified by Dan Beatty for use in mBed Studio 
mBed OS 6.x
	
*********************************************/


#include "mbed.h"
#include <cstdio>

BusOut RGB(PC_3, PC_4, PC_5);
DigitalIn R(PC_0, PullUp);
DigitalIn G(PC_1, PullUp);
DigitalIn B(PC_2, PullUp);

// main() runs in its own thread in the OS
int main()
{
	RGB = 0;
    while (true) {
		if (R == 0) {
			if ((RGB & 1) == 1)
				RGB = RGB & 6;
			else
				RGB = RGB | 1;

            printf("\n Red is pressed\n");
                while (R == 0);
		}
		if (G == 0) {
			if ((RGB & 2) == 2)
				RGB = RGB & 5;
			else
				RGB = RGB | 2;
            
            printf("\n Green is pressed\n");
                while (G == 0);
		}
		if (B == 0) {
			if ((RGB & 4) == 4)
				RGB = RGB & 3;
			else
				RGB = RGB | 4;
            printf("\n Blue is pressed\n");
            while (B == 0);
		}
    }
}

