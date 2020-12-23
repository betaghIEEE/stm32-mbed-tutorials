#include "display.hpp"
#include "carPark.hpp"

void Display(){
    Thread::signal_wait(0x2);
    homescr();
    pc.printf("SPACES = ");
    while (1){
        gotoscr('0', '9');
        pc.printf("%d ", Spaces);
        Thread::wait(250);

    }
}