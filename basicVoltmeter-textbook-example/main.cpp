#include "mbed.h"
#include "basicIOCmd.h"
#include <cstdio>

AnalogIn ain(PA_3);

// main() runs in its own thread in the OS
int main()
{

    homescr();
    clrscr();
    float voltage = 0.0;
    unsigned short adcValue = 0;
    float voltReadValue = 0.0;

    printf("\n\r Voltmeter.");
    printf("\n\r =========");

    while (true) {

        // Read the analog input voltage as a digital value
        adcValue = ain.read_u16();
        printf("\nThe value at A0 = %x. \n", adcValue);
        fflush(stdout);
        // Convert the reading into voltage in mV
        voltage = ain.read();
        voltReadValue = ain.read();


        // Display the voltage in mV
        printVoltage(voltage);
        printf(" -------   ");


        wait_seconds(1);
    }
}

