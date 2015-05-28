#include "unity.h"
#include "LED.h"
#include "init.h"
#include <stdio.h>

uint32_t currentTime = 0;
int FAST_BLINKS = 20;

void blink_LED3(State *state)
{
	//static State state = LED_INITIAL;
  State s = *state;
  Status LEDStat;
	static uint32_t previousTime = 0;
	static uint32_t count;

	if(switchControl() == 1)
	{
		FAST_BLINKS = 5;
		count = 5;
	}
	else
	{
		FAST_BLINKS = 20;
	}

		switch(s)
		{
			case LED_INITIAL:   if(switchControl() == 1)
                          {
                            //turnOnLED4();
                            LEDStat.stat = LED_ON;
                            s = LED_ON_STATE;
                            previousTime = currentTime;
                          }
                          break;

			case LED_ON_STATE:  if(delay(FAST_BLINKS,previousTime))
                          {
                            //turnOnLED4();
                            LEDStat.stat = LED_ON;
                            count--;
                            s = LED_OFF_STATE;
                            previousTime = currentTime;

                          }
                          if(count == 0)
                          {
                            s = LED_INITIAL;
                          }
                          break;

			case LED_OFF_STATE: if(delay(FAST_BLINKS,previousTime))
                          {
                            //turnOffLED4();
                            LEDStat.stat = LED_OFF;
                            s = LED_INITIAL;
                            previousTime = currentTime;
                          }
                          break;
		}
}