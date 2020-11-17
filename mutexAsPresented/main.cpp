#include "mbed.h"
#include "rtos.h"


Thread thread1, thread2;
Serial pc(USBTX, USBRX);
Mutex shr;

void Count(int i)
{
    shr.lock();
    pc.printf("Before %d\n\r", i);
    pc.printf("After %d\n\r",i);
    shr.unlock();
}

void task1()
{
    Count(1);
}


void task2()
{
    Count(2);
}

// main() runs in its own thread in the OS
int main()
{
    thread1.start(task1);
    thread2.start(task2);
    thread1.join();
    thread2.join();
}

