#include "DigitalOut.h"
#include "PortOut.h"
#include "Thread.h"
#include "mbed.h"

#include "rtos.h"



/*****************
2-Digit Multiplexed LED Refreshing 
Modified for Mbed Studios

This program is made for the Nucleo-F413ZH
We build an example with UNO R3 Starter Kit made by RexQualis.


*****************/

PortOut Segments(PortC, 0xFF);
int LEDS[] = {0x3f, 0x06, 0x58, 0x4f, 0x66, 0x6d, 0x7D, 0x07, 0x7f, 0x6f};

Thread thread1, thread2;

DigitalOut MSDEnable(PC_8);
DigitalOut LSDEnable(PC_9);

#define Enable 1
#define Disable 0
int CNT;

// 
// This is the display refreshing thread which runs as an independent task.
// 

void Refresh() 
{
    int MSDValue , LSDValue;
    MSDEnable = Disable;
    LSDEnable = Disable;

    // Note: We need a class to handle common Thread operations, like wait.

    while (1){
        MSDValue = CNT / 10;
        LSDValue = CNT % 10;
        Segments = LEDS[MSDValue];
        MSDEnable = Enable;
        //MyThread.wait(5);

        MSDEnable = Disable;
        Segments = LEDS[LSDValue];
        LSDEnable = Enable;
        //MyThread.wait(5);
        LSDEnable = Disable;

    }
}


// The main program increments the Count (CNT) variable every second. 

// main() runs in its own thread in the OS
int main()
{
    CNT = 0;
    thread1.start(Refresh);

    while (true) {
        CNT++; 
        if (CNT == 100) CNT = 0; 
        // MyThread.wait(1000);

    }
}

