#ifndef INIT_H
#define INIT_H

typedef enum{
	LED_INITIAL,
	LED_ON_STATE,
	LED_OFF_STATE
	//LED_FINAL
}State;

typedef enum{
  LED_ON,
  LED_OFF
}LED_S;

typedef struct{
  LED_S stat;
}Status;

#endif // INIT_H