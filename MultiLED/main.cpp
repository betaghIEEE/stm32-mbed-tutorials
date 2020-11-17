#include "DigitalOut.h"
#include "ThisThread.h"
#include "Thread.h"
#include "mbed.h"
//#include <mbed-os/rtos/include/rtos.h>
#include "mbed_wait_api.h"
#include "rtos.h"

DigitalOut LEDA (PC_0);
DigitalOut LEDB(PC_1);
Thread thread1, thread2;

void LEDAControl()
{
    while(true){
        LEDA = !LEDA;
        ThisThread::sleep_for(1000);
    }
}



void LEDBControl()
{
    while(true){
        LEDB = !LEDB;
        ThisThread::sleep_for(500);
    }
}

// main() runs in its own thread in the OS
int main()
{
    thread1.start(LEDAControl);
    thread2.start(LEDBControl);
    while (true) {

    }
}

