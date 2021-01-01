
#include "DigitalIn.h"
#include "cmsis_os.h"
#include "mbed.h"
#include "rtos.h"
//#include "carPark.hpp"
//#include "display.hpp"
#include "basicIOCmd.hpp"
#include "DigitalOut.h"
#include "PinNames.h"
#include <cstdio>

// This product is based off the Textbook "ARM-based Microcontroller Projects Using mbed"
//  The editor modified this code to work with Mbed Studio (Theia, 2020).  
//  The editor has made some YouTube videos demonstrating how to make these changes and
//  useful fixes to help fellow developers in their own code.

//Serial pc(USBTX, USBRX);

DigitalOut LockEntryBarrier(PC_2);
DigitalIn StartButton(PC_3);

DigitalIn EntrySwitch(PC_0);
DigitalIn ExitSwitch(PC_1);
int carCapacity;
int lockEntryBarrier;


Thread thread1, thread2;
int Spaces;

// Thread function for Parking the Car
void CarPark()
{
    //Thread::signal_wait(0x1);
    //run_release_signal_wait(0x1);   // I think we found a substitute.  Tests will tell.
    osSignalWait(0x1, osWaitForever);       // It looks like mbedOS 6 requires these defined osSignalWait ...

    // We need a work around for signal wait.  It has to exist in the RTOS library
    while (1)
    {
        if (Spaces == 0)                   // If there are no spaces then
            lockEntryBarrier = 1;           //  Lock the barrier 
            else                            // Otherwise
            lockEntryBarrier = 0;

        if (EntrySwitch == 0 )      // If a car enters
        {
            Spaces--;                       // Let car in on entry switch
            if (Spaces < 0) Spaces = 0;     // if no spaces, reset value ot zero
            while(EntrySwitch == 0);        // wait until the barrier is down
        }

        if (ExitSwitch == 0) // If a car leaves
        {
            Spaces++;                       // Let car out on exit switch
            if (Spaces <= carCapacity ) Spaces = carCapacity; // If no spaces, reset value or zero
            while(ExitSwitch == 0);         // wait until the barrier is down.
        }
    }
}

// Function for displaying info:

void Display(){
    //Thread::signal_wait(0x2);
    osSignalWait(0x2, osWaitForever);
    homescr();
    printf("SPACES = ");
    while (1){
        gotoscr('0', '9');
        printf("%d ", Spaces);
        wait(250);

    }
}


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
    printf("Closed.");

    thread1.start(CarPark);
    thread2.start(Display);

    while(StartButton == 1) ;  // Wait until the start button is pressed

    //thread1.signal_set(0x1);
    osSignalSet(thread1.get_id(), 0x1);
    //thread2.signal_set(0x2);
    osSignalSet(thread2.get_id(), 0x2);


    while (true) {

    }
}

