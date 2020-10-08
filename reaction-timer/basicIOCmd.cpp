#include "basicIOCmd.h"

#include "mbed.h"

//
// Clear the screen
//


#define BLINKING_RATE_MS                                                    1000


extern void wait_seconds (int seconds){
    int wait_ms = seconds * BLINKING_RATE_MS;
    thread_sleep_for(wait_ms);
}


extern void wait_milliseconds (int ms){

	thread_sleep_for(ms);
}

void wait (float delay){
	int blinkValue = floor(delay * BLINKING_RATE_MS);
        
	//wait_us(blinkValue);

	thread_sleep_for(blinkValue);
}


void clrscr()
{
            char clrscr[] = {0x1B, '[', '2' , 'J',0};
            printf("%s", clrscr);
}
//
// Home the cursor
//
void homescr()
{
            char homescr[] = {0x1B, '[' , 'H' , 0};
            printf("%s", homescr);
}
//
// Goto specified line and column
//
void gotoscr(int line, int column)
{
            char scr[] = {0x1B, '[', 0x00, ';' ,0x00, 'H', 0};
            scr[2] = line;
            scr[4] = column;
            printf("%s", scr);
}