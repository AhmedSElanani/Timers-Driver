#ifndef __TIMER1CONFIG_H__
#define __TIMER1CONFIG_H__


/**************************************************************************************************
*   Configuring TIMER1
**************************************************************************************************/

//Select Frequency of Clock Used
#ifndef F_CPU
#define F_CPU 1000000UL
#endif

//Select Mode of Operation for TIMER1
/*
	1 For Normal Mode
	2 For CTC Mode
	3 For Fast PWM Mode
	4 For Phase Correct PWM Mode
	5 For Phase and Frequency Correct PWM Mode
*/
#define TIMER1_MODE_OF_OPERATION													1												


//Select Compare Output Mode for Non PWM for TIMER1 Channel A
/*
	0 For Normal port operation, OC1A disconnected
	1 For Toggle OC1A on compare match
	2 For Clear OC1A on compare match (Set output to low level)
	3 For Set OC1A on compare match (Set output to high level)
*/
#define TIMER1_CHANNEL_A_OUTPUT_COMPARE_MODE_NONPWM									1							

//Select Compare Output Mode for Non PWM for TIMER1 Channel B
/*
	0 For Normal port operation, OC1B disconnected
	1 For Toggle OC1B on compare match
	2 For Clear OC1B on compare match (Set output to low level)
	3 For Set OC1B on compare match (Set output to high level)
*/
#define TIMER1_CHANNEL_B_OUTPUT_COMPARE_MODE_NONPWM									1							


//Select Compare Output Mode for Fast PWM Mode for TIMER1 Channel A
/*
	0 For Normal port operation, OC1A disconnected
	1 For WGM13:0 = 15: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
	  For all other WGM13:0 settings, normal port operation, OCnA disconnected.
	2 For Clear OC1A on compare match, set OC1A at BOTTOM, (non-inverting mode)
	3 For Set OC1A on compare match, clear OC1A at BOTTOM, (inverting mode)
*/	 
#define TIMER1_CHANNEL_A_OUTPUT_COMPARE_MODE_FASTPWM								1							

//Select Compare Output Mode for Fast PWM Mode for TIMER1 Channel B
/*
	0 For Normal port operation, OC1B disconnected
	1 For WGM13:0 = 15: Toggle OC1A on Compare Match, OC1B disconnected (normal port operation).
	  For all other WGM13:0 settings, normal port operation, OCnB disconnected.
	2 For Clear OC1B on compare match, set OC1B at BOTTOM, (non-inverting mode)
	3 For Set OC1B on compare match, clear OC1B at BOTTOM, (inverting mode)
*/	 
#define TIMER1_CHANNEL_B_OUTPUT_COMPARE_MODE_FASTPWM								1							


//Select Compare Output Mode for Phase Correct and Phase and Frequency Correct PWM for TIMER1 Channel A
/*
	0 For Normal port operation, OC1A disconnected
	1 For WGM13:0 = 9 or 14: Toggle OCnA on Compare Match, OCnB disconnected (normal port operation).
	  For all other WGM13:0 settings, normal port operation, OC1A disconnected.
	2 For  Clear OC1A on compare match when up-counting. Set OC1A on compare match when down-counting.
	3 For Set OC1A on compare match when up-counting. Clear OC1A on compare match when down-counting.
*/	 
#define TIMER1_CHANNEK_A_OUTPUT_COMPARE_MODE_PHASECORRECTANDFREQUENCYCORRECTPWM		1

//Select Compare Output Mode for Phase Correct and Phase and Frequency Correct PWM for TIMER1 Channel B
/*
	0 For Normal port operation, OC1B disconnected
	1 For WGM13:0 = 9 or 14: Toggle OCnA on Compare Match, OCnB disconnected (normal port operation).
	  For all other WGM13:0 settings, normal port operation, OC1B disconnected.
	2 For  Clear OC1B on compare match when up-counting. Set OC1B on compare match when down-counting.
	3 For Set OC1B on compare match when up-counting. Clear OC1B on compare match when down-counting.
*/	 
#define TIMER1_CHANNEK_B_OUTPUT_COMPARE_MODE_PHASECORRECTANDFREQUENCYCORRECTPWM		1

//Select Clock for TIMER1
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
#define TIMER1_CLOCKSOURCE															1			


//Select Wave Form Generation Mode for TIMER1
/*
	1 For Normal Mode
	2 For PWM, Phase Correct, 8-bit
	3 For PWM, Phase Correct, 9-bit
	4 For PWM, Phase Correct, 10-bit
	5 For CTC with TOP OCR1A
	6 For Fast PWM, 8-bit
	7 For Fast PWM, 9-bit
	8 For Fast PWM, 10-bit
	9 For PWM, Phase and Frequency Correct with TOP ICR1
	10 For PWM, Phase and Frequency Correct with TOP OCR1A
	11 For PWM, Phase Correct with TOP ICR1
	12 For PWM, Phase Correct with TOP OCR1A
	13 For CTC with TOP ICR1
	14 For Fast PWM, with TOP ICR1	
	15 For Fast PWM, with TOP OCR1A 
*/
#define TIMER1_WaveForm_Generation_Mode												1						

#define InputCapture_EdgeSelect														1	// 0 For a Falling edge is used as trigger, and 1 For a rising edge to trigger the capture


#endif

