#include "Semaphore.h"
#include "mbed.h"
#include "rtos.h"
#include <cstdio>

Thread thread1, thread2, thread3, thread4;

Semaphore sema(2);
//Serial pc(USBTX, USBRX);

void task(const char *text){
    while(1){
        //sema.wait();
        wait_seconds(2);                    // We have to make fix.  Semaphore does not have a wait method any more.
        printf("%s\n\r", (char *) text);
        wait_seconds(2);
        sema.release();
    }
}

// main() runs in its own thread in the OS
int main()
{
    thread1.start(callback(task, "First"));     // Start thread1
    thread2.start(callback(task, "Second"));  // Start thread2
    thread3.start(callback(task, "Third"));  // Start thread3
    thread4.start(callback(task, "Fourth")); // Start thread4
}

