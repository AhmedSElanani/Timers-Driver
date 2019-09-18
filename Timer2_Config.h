#ifndef __TIMER2CONFIG_H__
#define __TIMER2CONFIG_H__


/**************************************************************************************************
*   Configuring TIMER2
**************************************************************************************************/

//Select Frequency of Clock Used
#ifndef F_CPU
#define F_CPU 1000000UL
#endif

//Select Mode of Operation for TIMER2
/*
	1 For Normal Mode
	2 For Phase Correct PWM Mode
	3 For CTC Mode	
	4 For Fast PWM Mode		
*/
#define TIMER2_MODE_OF_OPERATION																	1

//Select Compare Output Mode for Non PWM for TIMER2
/*
	0 For Normal port operation, OC2 disconnected
	1 For Toggle OC2 on compare match
	2 For Clear OC2 on compare match
	3 For Set OC2 on compare match
*/
#define TIMER2_OUTPUT_COMPARE_MODE_NONPWM															1						

//Select Compare Output Mode for Fast PWM Mode for TIMER2
/*
	0 For Normal port operation, OC2 disconnected
	1 Clear OC2 on compare match, set OC2 at BOTTOM, (non-inverting mode)
	2 Set OC2 on compare match, clear OC2 at BOTTOM, (inverting mode)
*/	 
#define TIMER2_OUTPUT_COMPARE_MODE_FASTPWM															1						


//Select Compare Output Mode for Phase Correct PWM for TIMER2
/*
	0 For Normal port operation, OC2 disconnected
	1 For Clear OC2 on compare match when up-counting. Set OC2 on compare match when down-counting.
	2 Set OC2 on compare match when up-counting. Clear OC2 on compare match when down-counting.
*/	 
#define TIMER2_OUTPUT_COMPARE_MODE_PHASECORRECTPWM													1
								

//Select Clock for	TIMER2
/*
	0 For No ClockSource
	1 For CLK/1
	2 For CLK/8
	3 For CLK/32	
	4 For CLK/64
	5 For CLK/128
	6 For CLK/256	
	7 For CLK/1024
*/
#define TIMER2_CLOCKSOURCE																			1

//Select whether the Clock for TIMER2 is Internal I/O Clock or External Crystal Oscillator 
/*
	 1 For I/O Clock		
	 0 For Crystal Oscillator connected to the Timer Oscillator 1 (TOSC1) pin
*/
#define TIMER2_CLOCKSELECT																			1				
 
#endif

