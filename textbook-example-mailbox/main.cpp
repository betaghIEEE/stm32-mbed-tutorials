#include "mbed.h"
#include "rtos.h"

Thread thread1, thread2;
Serial pc(USBTX, USBRX);

typedef struct {
    int no1;
    int no2;
} mymail;

Mail<mymail, 16> mailbox;

// 
// Generate data and put into mail
// 

void producer()
{
    mymail *mail = mailbox.alloc();     // Allocate memory and the mail
    mail->no1 = 5;              
    mail->no2 = 20;
    mailbox.put(mail);                  // Put into mail the structure
    Thread::wait(2000);                 // Wait 2 seconds 
    mailbox.free(mail);                 // Free the memory of the mailbox
}

//
// Get data from the mail and display it
//

void consumer()
{
    osEvent evt = mailbox.get();    //  Get mail
    if (evt.status == osEventMail )
    {
        mymail *mail = (mymail*) evt.value.p ;
        pc.print("No1=%d No2=%d\n\r", mail->no1, mail->no2);
    }
}


// main() runs in its own thread in the OS
// Create two threads: producer and consumer 
// 

int main()
{
    thread1.start(producer);
    thread2.start(consumer);


    while (true) {

    }
}

