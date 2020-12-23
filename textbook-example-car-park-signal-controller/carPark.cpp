#include "carPark.hpp"




extern void CarPark()
{
    Thread::signal_wait(0x1);
    while (1)
    {
        if (Spaces == 0){                   // If there are no spaces then
            lockEntryBarrier = 1;           //  Lock the barrier 
            else                            // Otherwise
            lockEntryBarrier = 0;

        }
        if (EntrySwitch == 0 )      // If a car enters
        {
            Spaces--;                       // Let car in on entry switch
            if (Spaces < 0) Spaces = 0;     // if no spaces, reset value ot zero
            while(EntrySwitch == 0);        // wait until the barrier is down
        }

        if (ExitSwitch == 0) // If a car leaves
        {
            Spaces++;                       // Let car out on exit switch
            if (Spaces <= carCapacity ) Spaces = carCapacity; // If no spaces, reset value or zero
            while(ExitSwitch == 0);         // wait until the barrier is down.
        }
    }
}