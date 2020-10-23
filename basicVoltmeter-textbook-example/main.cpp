#include "mbed.h"
#include "basicIOCmd.h"
#include <cstdio>

AnalogIn ain(PA_3);
AnalogIn temp(PA_0);

// main() runs in its own thread in the OS
int main()
{

    homescr();
    clrscr();
    float voltage = 0.0;
    unsigned short adcValue = 0;
    float voltReadValue = 0.0;
    unsigned short tempValue = 0;
    double mv, T, tf; 

    printf("\n\r Voltmeter.");
    printf("\n\r =========");

    while (true) {

        // Read the analog input voltage as a digital value
        adcValue = ain.read_u16();

        gotoscr(4, 3);
        printf("\nThe value at A3 = %x. A3 voltage = %5.3f  ", adcValue, voltage);
        fflush(stdout);
        // Convert the reading into voltage in mV
        voltage = ain.read() * 3300.0f;


        printf("\n -------   ");


        wait_seconds(1);
    }
}

