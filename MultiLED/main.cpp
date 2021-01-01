#include "mbed.h"
#include "rtos.h"
#include <chrono>
#include <ratio>

DigitalOut LEDA (PC_0);
DigitalOut LEDB(PC_1);
Thread thread1, thread2;

void LEDAControl()
{
    while(true){
        LEDA = !LEDA;
        std::chrono::seconds d(1);
        ThisThread::sleep_for(d);
    }
}



void LEDBControl()
{
    while(true){
        LEDB = !LEDB;
        std::chrono::milliseconds d(500);
        ThisThread::sleep_for(d);
    }
}

// main() runs in its own thread in the OS
int main()
{
    thread1.start(LEDAControl);
    thread2.start(LEDBControl);
    while (true) {
        ThisThread::sleep_for(10s);
    }
}

