/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "basicIOCmd.h"
#include "Timer.h"
//#include "SerialBase.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms


int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);
    DigitalIn button(BUTTON1);
    //SerialBase myPC(USBTX, USBRX);
    Timer time;
    int randomSeconds = 0;
    int reactionMilliseconds = 0;


    while (true) {
        time.reset();
        homescr();
        clrscr();
        randomSeconds = rand() % 10 + 1;
        printf("\n\rWe are going to wait %d seconds.", randomSeconds);
        fflush(stdout);
        wait_seconds(randomSeconds);
        time.start();
        led = 1;
        //wait_milliseconds(50);
        reactionMilliseconds = time.elapsed_time().count();
        printf("\n\rOk, start at %d milliseconds. Button equals %d", reactionMilliseconds, button.read() ) ;
        fflush(stdout);

        while (button == 0);

        time.stop();
        reactionMilliseconds = time.elapsed_time().count();

        printf("\n\rIt took you %d microseconds to press the button after the blink.", reactionMilliseconds);
        fflush(stdout);
        led = 0;

        wait_seconds(10);
    }
}
