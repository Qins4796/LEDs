#ifndef TIMER_H
#define TIMER_H

#include "unity.h"

uint32_t getCurrentTime();
int delay(uint32_t delayCycle, uint32_t previousTime);

#endif // TIMER_H