
#include "DigitalIn.h"
#include "mbed.h"
#include "rtos.h"
#include "carPark.hpp"
#include "display.hpp"
#include "basicIOCmd.hpp"
#include "DigitalOut.h"
#include "PinNames.h"

// This product is based off the Textbook "ARM-based Microcontroller Projects Using mbed"
//  The editor modified this code to work with Mbed Studio (Theia, 2020).  
//  The editor has made some YouTube videos demonstrating how to make these changes and
//  useful fixes to help fellow developers in their own code.

Serial pc(USBTX, USBRX);

DigitalOut LockEntryBarrier(PC_2);
DigitalIn StartButton(PC_3);

Thread thread1, thread2;



// main() runs in its own thread in the OS
// This is the main program.  The program locks the barrier to start 
// with and displays the messages CLOSED.  When the StartButton is 
// pressed flags 1 and 2 are set and therefore threads CarPartk and 
// Display start running.


int main()
{
    Spaces = carCapacity;
    LockEntryBarrier = 1;
    clrscr();
    homescr();
    pc.printf("Closed.");

    thread1.start(CarPark);
    thread2.start(Display);

    while(StartButton == 1) ;  // Wait until the start button is pressed

    thread1.signal_set(0x1);
    thread2.signal_set(0x2);


    while (true) {

    }
}

