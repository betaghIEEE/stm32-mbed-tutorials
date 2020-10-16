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
    double mv, T; 

    printf("\n\r Voltmeter.");
    printf("\n\r =========");

    while (true) {

        // Read the analog input voltage as a digital value
        adcValue = ain.read_u16();
        tempValue = temp.read_u16();

        printf("\nThe value at A3 = %x.  A0 = %x  A0 = %5.3f\n  Temp at A0 = %5.3f.", adcValue, tempValue, mv, T);
        fflush(stdout);
        // Convert the reading into voltage in mV
        voltage = ain.read() * 3300.0f;
        voltReadValue = ain.read();
        mv = temp.read() * 3300.0f;
        T= (mv +225.0f ) / 10.0f;


        // Display the voltage in mV
        printVoltage(voltage);
        printf(" -------   ");


        wait_seconds(1);
    }
}

