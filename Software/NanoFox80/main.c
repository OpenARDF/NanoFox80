#include <atmel_start.h>



ISR(TCA0_OVF_vect)
{
    if(TCA0.SINGLE.INTFLAGS & TCA_SINGLE_OVF_bm)
	{
		PORTA_toggle_pin_level(7);
		TCA0.SINGLE.INTFLAGS |= TCA_SINGLE_OVF_bm; /* Clear the interrupt flag */
	}
}

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Replace with your application code */
	while (1) {
	}
}
