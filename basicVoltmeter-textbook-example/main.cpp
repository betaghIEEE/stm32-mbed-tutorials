#include "mbed.h"
#include "basicIOCmd.h"

AnalogIn ain(PA_0);

// main() runs in its own thread in the OS
int main()
{

    homescr();
    clrscr();
    float voltage = 0.0;
    int adcValue = 0;
    float voltReadValue = 0.0;

    printf("\n\r Voltmeter.");
    printf("\n\r =========");

    while (true) {

        // Read the analog input voltage as a digital value
        adcValue = ain.read_u16();
        printf("\nThe value at A0 = %d. \n", adcValue);
        fflush(stdout);
        // Convert the reading into voltage in mV
        voltage = ain.read_voltage();
        voltReadValue = ain.read();


        // Display the voltage in mV
        printVoltage(voltReadValue);

        wait_seconds(1);
    }
}

