#include "cmsis_os.h"
#include "mbed.h"
#include "rtos.h"

Thread thread1, thread2;
Serial pc(USBTX, USBRX);

typedef struct 
{
    int no1; 
    int no2;
} msg;

MemoryPool<msg, 16> mpool;
Queue<msg, 16> queue;

// 
// Generate data and put into a queue
// 

void producer()
{
    msg *message = mpool.alloc();
    message->no1 = 10;
    message->no2 = 20;
    queue.put(message);
}

// 
//  Get data from the queue and display
//  
void consumer() 
{
    osEvent evt = queue.get();
    if(evt.status == osEventMessage)
    {
        msg *message = (msg*) evt.value.p;
        pc.printf("No1=%d No2=%d\n\r", message->no1, message->no2);
    }
}

//
// Create two threads: producer and consumer
//

// main() runs in its own thread in the OS
int main()
{

    thread1.start(producer);
    thread2.start(consumer);

    while (true) {

    }
}

