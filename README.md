# CoreTick
Measuring MCU cycles using DWT

Another Cortex-M feature can be used as well. That's DWT -> here is a link to the CM3 manual about DWT. 

In short, it is an always-on cycle counter that ticks away with execution, just like our SysTick does. So it can be repurposed to count cycles, through the same set of programming interface that we called CoreTick.

```
coretick(): initialize the DWT cycle counter; Unlock may be required. The code itself is otherwise fair straight forward.
tick(): return the current cycle count;
coretick_delayms(): delay a user-specified period, in ms. It mimics the systick_delayms() routine;
coretick_delayus(): delay a user-specified period, in us. It mimics the systick_delayus() routine;
```

Typical application:

```
	coretick_init();								//reset coretick
	while (1) {
		IO_FLP(LED_PORT, LED);				//flip led

		time0=ticks();                //time stamp time0
		coretick_delayms(LED_DLY);    //delay using coretick
		time1=ticks() - time0;        //time stamp time1
		if (time1>10) NOP();          //break point
	};
}
```
More details here: https://dannyelectronics.wordpress.com/2017/06/15/coretick-another-mcu-cycle-counter/
