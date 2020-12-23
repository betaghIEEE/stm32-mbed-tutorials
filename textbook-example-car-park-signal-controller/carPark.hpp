#include "Thread.h"
#include "mbed.h"
#include "rtos.h"

#ifndef EntrySwitchFamily
#define EntrySwitchFamily

DigitalIn EntrySwitch(PC_0);
DigitalIn ExitSwitch(PC_1);
int carCapacity;
int Spaces;
int lockEntryBarrier;

extern void CarPark();

#endif