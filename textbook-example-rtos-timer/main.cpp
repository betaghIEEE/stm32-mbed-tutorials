#include "mbed.h"
#include "rtos.h"
#include "rtos/RtosTimer.h"

DigitalOut led(LED1);

void Flash(){
    led = !led;
}

// main() runs in its own thread in the OS
int main()
{
    RtosTimer timer(&Flash);
    timer.start(500);
    wait(5);
    timer.stop();
    while (true) {

    }
}

