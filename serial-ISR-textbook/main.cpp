#include "mbed.h"
#include "basicIOCmd.h"

float delay;

#define     BUFFER_SIZE  100
//BufferedSerial myPC(USBTX,USBRX,9600);
UnbufferedSerial myPC(USBTX, USBRX, 9600);



void ioInterupt();

// main() runs in its own thread in the OS
int main()
{
    DigitalIn button(BUTTON1);
    DigitalOut led(PC_10);
    //buffer = {0};
    homescr();
    clrscr();
    myPC.attach(ioInterupt, SerialBase::RxIrq);

    delay = 0.1;
    while (true) {
        led = 1;
        wait(delay);
        printFloat(delay);
        led = 0;
        wait(delay);
    }
}


void ioInterupt(){
    //uint32_t bufferCatch; 

    int i = 0;
    char c; 
    char buffer[BUFFER_SIZE] = {0};
    bool isPlus = false;


    if (uint32_t bufferCatch = myPC.read(buffer , BUFFER_SIZE)) {
        for (i = 0; i < bufferCatch; i++){
            c = buffer[i];
            if (c == '+'){
                isPlus = true;
            }
        }
    }
    
    if (isPlus){

        delay += 0.1;
            if (delay > 1) {
                delay = 0.1;
            }
    }

}