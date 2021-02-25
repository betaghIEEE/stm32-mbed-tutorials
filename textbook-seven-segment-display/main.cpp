/*
	This 7-Segment Counter is based on a textbook 
example from Dogan Ibrahim's ARM-based Microcontroller Projects Using mbed.

	Modifications were made by Dan Beatty to adjust to mBed Studio and mBedOS 6.x.
*/


#include "mbed.h"
#include "rtos.h"

PortOut Segments(PortC, 0xFF);
int LEDS[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

// main() runs in its own thread in the OS
int main()
{
	int count = 0;
	
    while (true) {
		Segments = LEDS[count];
		wait_us(1000000);
		count++;
		if (count >= 10) count = 0;
        printf("%d \n", count);

    }
}

