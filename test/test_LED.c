#include "unity.h"
#include "init.h"
#include "LED.h"
#include "mock_timer.h"
#include "mock_switchControl.h"

void setUp(void){}
void tearDown(void){}

void test_blink_LED3_should_go_to_initial_state(void)
{
	State state = LED_INITIAL;

  switchControl_IgnoreAndReturn(0);
  blink_LED3(&state);

  TEST_ASSERT_EQUAL(LED_INITIAL, state);
}

void test_blink_LED3_should_go_to_ON_state(void)
{
	State state = LED_INITIAL;

  switchControl_IgnoreAndReturn(0);
  getCurrentTime_IgnoreAndReturn(20);
  blink_LED3(&state);

  TEST_ASSERT_EQUAL(LED_INITIAL, state);
}
