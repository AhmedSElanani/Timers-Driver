#ifndef __TIMER0CONFIG_H__
#define __TIMER0CONFIG_H__


/**************************************************************************************************
*   Configuring TIMER0
**************************************************************************************************/

//Select Frequency of Clock Used
#ifndef F_CPU 
#define F_CPU 1000000UL
#endif

//Select Mode of Operation for TIMER0
/*
	1 For Normal Mode
	2 For Phase Correct PWM Mode
	3 For CTC Mode	
	4 For Fast PWM Mode		
*/
#define TIMER0_MODE_OF_OPERATION				9													

//Select Clock in TIMER0
/*
	0 For No ClockSource
	1 For CLK/1
	2 For CLK/8
	3 For CLK/64
	4 For CLK/256
	5 For CLK/1024
	6 For ExternalClock on T0 PIN, On Falling Edge
	7 For ExternalClock on T0 PIN, On Rising Edge
*/	
#define TIMER0_CLOCKSOURCE						9				

//Select Compare Output Mode for NON PWM Mode for TIMER0
/*
	0 For OCO Disconnected
	1 For Toggle OC0 On Compare Match	
	2 For Clear OC0 On Compare Match	
	3 For Set OC0 On Compare Match
*/	 
#define TIMER0_OUTPUT_COMPARE_MODE_NONPWM	9							

//Select Compare Output Mode for Phase Correct PWM Mode for TIMER0
/*
	0 For OCO Disconnected
	1 For Clear OC0 on compare match when up-counting. Set OC0 on compare match when down-counting.	
	2 For Set OC0 on compare match when up-counting. Clear OC0 on compare match when down-counting.
*/		
#define TIMER0_OUTPUT_COMPARE_MODE_PHASECORRECTPWM		9							

//Select Compare Output Mode for Fast PWM Mode for TIMER0
/*
	0 For OCO Disconnected
	1 For Clear OC0 On Compare Match, Set OC0 at Bottom		
	2 For Set OC0 On Compare Match, Clear OC0 at Bottom
*/	 
#define TIMER0_OUTPUT_COMPARE_MODE_FASTPWM			9										

#endif
