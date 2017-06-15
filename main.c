//#include <lpc122x.h>					//we use lpc122x
#include "gpio.h"					//we use F_CPU + gpio functions
#include "delay.h"					//we use software delays
#include "coretick.h"					//we use dwt
//#include "dhry.h"					//we use dhrystone benchmark

//hardware configuration
#define LED_PORT		GPIOC
#define LED			(1<<8)
#define LED_DLY			100				//counts
//end hardware configuration

//global defines

//global variables

int main(void) {
	uint32_t time0, time1;

	mcu_init();							//reset the  mcu
	coretick_init();						//reset systick
	IO_OUT(LED_PORT, LED);						//led3/4 as output
	//tmp=F_CPU;							//read f_cpu - for debugging
	//ei();								//enable global interrupt
	while (1) {
		IO_FLP(LED_PORT, LED);					//flip led

		time0=ticks();						//time stamp time0
		//dhrystone();						//benchmark
		coretick_delayms(LED_DLY);				//waste some time
		time1=ticks() - time0;					//time stamp time1
		if (time1>10) NOP();					//break point
	};
}
