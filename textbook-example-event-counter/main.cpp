/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "basicIOCmd.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

void displayHeading(){

}

int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);
    DigitalIn button(BUTTON1);

    clrscr();
    homescr();
    displayHeading();
    int count = 0;
    printf("The count is %d", count);
    fflush(stdout);
    while (true) {
        if (button == 1 ){
            count++;
            gotoscr(4, 3);
            printf("The count is %d", count);
            fflush(stdout);
        }
        
        wait_milliseconds(130);
    }
}
