#include "DigitalOut.h"
#include "PinNames.h"
#include "mbed.h"
#include "rtos.h"

Thread thread1;

DigitalOut led(LED1);
DigitalIn button(BUTTON1);

void Flash()
{
    Thread::signal_wait(0x1);
    while(1){
        led = !led;
        Thread::wait(1000);
    }
}

// main() runs in its own thread in the OS
int main()
{

    thread1.start(Flash);
    while(button == 1);
    thread1.signal_set(0x1);
    
    while (true) {

    }
}

