#include "gpio.h"

#define LED_PORT    GPIOC
#define LED_BIT   13

static void delay(void)
{
	volatile unsigned int count = 400000;
	while(count--) {}
}

void startup(void)
{
	RCC->ahb1_e |= GPIOC_ENABLE;
	GPIOC->mode = (GPIOC->mode & ~(3 << (2 * LED_BIT))) | (1 << (2 * LED_BIT));
	GPIOC->otype &= ~(1 << LED_BIT);
	for(;;)
	{
		GPIOC->bsrr = 1 << LED_BIT;
		delay();
		GPIOC->bsrr = 1 << (LED_BIT + 16);
		delay();
	}
}
