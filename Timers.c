/*
 * CFile1.c
 *
 * Created: 20-Aug-19 4:37:16 PM
 *  Author: Ahmed Salah
 */ 

#include "Timers.h"

/**************************************************************************************************
*   Global Variables
**************************************************************************************************/
uint64_t t1_ms = 0;			
uint64_t t2_ms = 0;			
uint64_t t1_us = 0;			
uint64_t t2_us = 0;			
uint8_t TimerSelect = 0;	

/**************************************************************************************************
*   Functions' Definitions
**************************************************************************************************/
void Timer0_Init()
{
	//Select Mode of Operation for TIMER0
	#if (TIMER0_MODE_OF_OPERATION == 1)
	TCCR0 &= ~(1<<WGM00); 
	TCCR0 &= ~(1<<WGM01);
	#elif (TIMER0_MODE_OF_OPERATION == 2)
	TCCR0 |= (1<<WGM00); 
	TCCR0 &= ~(1<<WGM01);
	#elif (TIMER0_MODE_OF_OPERATION == 3)
	TCCR0 |= (1<<WGM01);
	TCCR0 &= ~(1<<WGM00);
	#elif (TIMER0_MODE_OF_OPERATION == 4)
	TCCR0 |= (1<<WGM01);
	TCCR0 |= (1<<WGM00);
	#endif
	
	//Select Clock in TIMER0
	#if (TIMER0_CLOCKSOURCE == 0)
	TCCR0 &= ~(1<<CS00);
	TCCR0 &= ~(1<<CS01);
	TCCR0 &= ~(1<<CS02);
	#elif (TIMER0_CLOCKSOURCE == 1)
	TCCR0 |= (1<<CS00);
	TCCR0 &= ~(1<<CS01);
	TCCR0 &= ~(1<<CS02);
	#elif (TIMER0_CLOCKSOURCE == 2)
	TCCR0 &= ~(1<<CS00);
	TCCR0 |= (1<<CS01);
	TCCR0 &= ~(1<<CS02);
	#elif (TIMER0_CLOCKSOURCE == 3)
	TCCR0 |= (1<<CS00);
	TCCR0 |= (1<<CS01);
	TCCR0 &= ~(1<<CS02);
	#elif (TIMER0_CLOCKSOURCE == 4)
	TCCR0 &= ~(1<<CS00);
	TCCR0 &= ~(1<<CS01);
	TCCR0 |= (1<<CS02);
	#elif (TIMER0_CLOCKSOURCE == 5)
	TCCR0 |= (1<<CS00);
	TCCR0 &= ~(1<<CS01);
	TCCR0 |= (1<<CS02);
	#elif (TIMER0_CLOCKSOURCE == 6)
	TCCR0 &= ~(1<<CS00);
	TCCR0 |= (1<<CS01);
	TCCR0 |= (1<<CS02);
	#elif (TIMER0_CLOCKSOURCE == 7)
	TCCR0 |= (1<<CS00);
	TCCR0 |= (1<<CS01);
	TCCR0 |= (1<<CS02);
	#endif

	//Select Compare Output Mode for NON PWM Mode for TIMER0
	#if ( (TIMER0_MODE_OF_OPERATION == 1) || (TIMER0_MODE_OF_OPERATION == 3) )
		#if (TIMER0_OUTPUT_COMPARE_MODE_NONPWM == 0)
		TCCR0 &= ~(1<<COM00);
		TCCR0 &= ~(1<<COM01);
		#elif (TIMER0_OUTPUT_COMPARE_MODE_NONPWM == 1)
		TCCR0 |= (1<<COM00);
		TCCR0 &= ~(1<<COM01);
		#elif (TIMER0_OUTPUT_COMPARE_MODE_NONPWM == 2)
		TCCR0 &= ~(1<<COM00);
		TCCR0 |= ~(1<<COM01);
		#elif (TIMER0_OUTPUT_COMPARE_MODE_NONPWM == 3)
		TCCR0 |= (1<<COM00);
		TCCR0 |= (1<<COM01);
		#endif
		
	#endif
	
	//Select Compare Output Mode for Phase Correct PWM Mode for TIMER0
	#if ( TIMER0_MODE_OF_OPERATION == 2 )
		#if (TIMER0_OUTPUT_COMPARE_MODE_PHASECORRECTPWM == 0)
		TCCR0 &= ~(1<<COM00);
		TCCR0 &= ~(1<<COM01);
		#elif (TIMER0_OUTPUT_COMPARE_MODE_PHASECORRECTPWM == 1)
		TCCR0 &= ~(1<<COM00);
		TCCR0 |= (1<<COM01);
		#elif (TIMER0_OUTPUT_COMPARE_MODE_PHASECORRECTPWM == 2)
		TCCR0 |= (1<<COM00);
		TCCR0 |= (1<<COM01);
		#endif
	#endif
	
	//Select Compare Output Mode for Fast PWM Mode for TIMER0
	#if ( TIMER0_MODE_OF_OPERATION == 4 )
		#if (TIMER0_OUTPUT_COMPARE_MODE_FASTPWM == 0)
		TCCR0 &= ~(1<<COM00);
		TCCR0 &= ~(1<<COM01);
		#elif (TIMER0_OUTPUT_COMPARE_MODE_FASTPWM == 1)
		TCCR0 &= ~(1<<COM00);
		TCCR0 |= (1<<COM01);
		#elif (TIMER0_OUTPUT_COMPARE_MODE_FASTPWM == 2)
		TCCR0 |= (1<<COM00);
		TCCR0 |= (1<<COM01);
		#endif
	#endif
	
}

void Timer0_OutputCompareMatch_Interrupt_Enable(void)
{
	
	TIFR |= (1<<OCF0);										//Clear Output Compare flag 1 Channel B
	TIMSK |= (1<<OCIE0);
	sei();
}


void Timer0_OverFlow_Interrupt_Enable(void)
{
	TIFR |= (1<<TOV0);										//Clear Output Compare flag 1 Channel B
	TIMSK |= (1<<TOIE0);
	sei();
}


void Timer1_Init()
{
	//Select Mode of Operation for TIMER1
	#if (TIMER1_MODE_OF_OPERATION == 1)
	#elif (TIMER1_MODE_OF_OPERATION == 2)
	#elif (TIMER1_MODE_OF_OPERATION == 3)
	#elif (TIMER1_MODE_OF_OPERATION == 4)
	#elif (TIMER1_MODE_OF_OPERATION == 5)
	#endif
	
	//Select Compare Output Mode for Non PWM for TIMER1 Channel A
	#if ( (TIMER1_MODE_OF_OPERATION == 1) || (TIMER1_MODE_OF_OPERATION == 2) )
		#if (TIMER1_CHANNEL_A_OUTPUT_COMPARE_MODE_NONPWM == 0)
		TCCR1A &= ~(1<<COM1A0);
		TCCR1A &= ~(1<<COM1A1);
		#elif (TIMER1_CHANNEL_A_OUTPUT_COMPARE_MODE_NONPWM == 1)
		TCCR1A |= (1<<COM1A0);
		TCCR1A &= ~(1<<COM1A1);
		#elif (TIMER1_CHANNEL_A_OUTPUT_COMPARE_MODE_NONPWM == 2)
		TCCR1A &= ~(1<<COM1A0);
		TCCR1A |= (1<<COM1A1);
		#elif (TIMER1_CHANNEL_A_OUTPUT_COMPARE_MODE_NONPWM == 3)
		TCCR1A |= (1<<COM1A0);
		TCCR1A |= (1<<COM1A1);
		#endif
	#endif

	//Select Compare Output Mode for Non PWM for TIMER1 Channel B
	#if ( (TIMER1_MODE_OF_OPERATION == 1) || (TIMER1_MODE_OF_OPERATION == 2) )
		#if (TIMER1_CHANNEL_B_OUTPUT_COMPARE_MODE_NONPWM == 0)
		TCCR1A &= ~(1<<COM1B0);
		TCCR1A &= ~(1<<COM1B1);
		#elif (TIMER1_CHANNEL_B_OUTPUT_COMPARE_MODE_NONPWM == 1)
		TCCR1A |= (1<<COM1B0);
		TCCR1A &= ~(1<<COM1B1);
		#elif (TIMER1_CHANNEL_B_OUTPUT_COMPARE_MODE_NONPWM == 2)
		TCCR1A &= ~(1<<COM1B0);
		TCCR1A |= (1<<COM1B1);
		#elif (TIMER1_CHANNEL_B_OUTPUT_COMPARE_MODE_NONPWM == 3)
		TCCR1A |= (1<<COM1B0);
		TCCR1A |= (1<<COM1B1);
		#endif
	#endif
	
	//Select Compare Output Mode for Fast PWM Mode for TIMER1 Channel A
	#if ( TIMER1_MODE_OF_OPERATION == 3 )
		#if (TIMER1_CHANNEL_A_OUTPUT_COMPARE_MODE_FASTPWM == 0)
		TCCR1A &= ~(1<<COM1A0);
		TCCR1A &= ~(1<<COM1A1);
		#elif (TIMER1_CHANNEL_A_OUTPUT_COMPARE_MODE_FASTPWM == 1)
		TCCR1A |= (1<<COM1A0);
		TCCR1A &= ~(1<<COM1A1);
		#elif (TIMER1_CHANNEL_A_OUTPUT_COMPARE_MODE_FASTPWM == 2)
		TCCR1A &= ~(1<<COM1A0);
		TCCR1A |= (1<<COM1A1);
		#elif (TIMER1_CHANNEL_A_OUTPUT_COMPARE_MODE_FASTPWM == 3)
		TCCR1A |= (1<<COM1A0);
		TCCR1A |= (1<<COM1A1);
		#endif
	#endif
	
	//Select Compare Output Mode for Fast PWM Mode for TIMER1 Channel B
	#if ( TIMER1_MODE_OF_OPERATION == 3 )

		#if (TIMER1_CHANNEL_B_OUTPUT_COMPARE_MODE_FASTPWM == 0)
		TCCR1A &= ~(1<<COM1B0);
		TCCR1A &= ~(1<<COM1B1);
		#elif (TIMER1_CHANNEL_B_OUTPUT_COMPARE_MODE_FASTPWM == 1)
		TCCR1A |= (1<<COM1B0);
		TCCR1A &= ~(1<<COM1B1);
		#elif (TIMER1_CHANNEL_B_OUTPUT_COMPARE_MODE_FASTPWM == 2)
		TCCR1A &= ~(1<<COM1B0);
		TCCR1A |= (1<<COM1B1);
		#elif (TIMER1_CHANNEL_B_OUTPUT_COMPARE_MODE_FASTPWM == 3)
		TCCR1A |= (1<<COM1B0);
		TCCR1A |= (1<<COM1B1);
		#endif
	#endif
	
	//Select Compare Output Mode for Phase Correct and Phase and Frequency Correct PWM for TIMER1 Channel A
	#if ( (TIMER1_MODE_OF_OPERATION == 4) || (TIMER1_MODE_OF_OPERATION == 5) )
		#if (TIMER1_CHANNEK_A_OUTPUT_COMPARE_MODE_PHASECORRECTANDFREQUENCYCORRECTPWM == 0)
		TCCR1A &= ~(1<<COM1A0);
		TCCR1A &= ~(1<<COM1A1);
		#elif (TIMER1_CHANNEK_A_OUTPUT_COMPARE_MODE_PHASECORRECTANDFREQUENCYCORRECTPWM == 1)
		TCCR1A |= (1<<COM1A0);
		TCCR1A &= ~(1<<COM1A1);
		#elif (TIMER1_CHANNEK_A_OUTPUT_COMPARE_MODE_PHASECORRECTANDFREQUENCYCORRECTPWM == 2)
		TCCR1A &= ~(1<<COM1A0);
		TCCR1A |= (1<<COM1A1);
		#elif (TIMER1_CHANNEK_A_OUTPUT_COMPARE_MODE_PHASECORRECTANDFREQUENCYCORRECTPWM == 3)
		TCCR1A |= (1<<COM1A0);
		TCCR1A |= (1<<COM1A1);
		#endif
	#endif
	
	//Select Compare Output Mode for Phase Correct and Phase and Frequency Correct PWM for TIMER1 Channel B
	#if ( (TIMER1_MODE_OF_OPERATION == 4) || (TIMER1_MODE_OF_OPERATION == 5) )
		#if (TIMER1_CHANNEK_B_OUTPUT_COMPARE_MODE_PHASECORRECTANDFREQUENCYCORRECTPWM == 0)
		TCCR1A &= ~(1<<COM1B0);
		TCCR1A &= ~(1<<COM1B1);
		#elif (TIMER1_CHANNEK_B_OUTPUT_COMPARE_MODE_PHASECORRECTANDFREQUENCYCORRECTPWM == 1)
		TCCR1A |= (1<<COM1B0);
		TCCR1A &= ~(1<<COM1B1);
		#elif (TIMER1_CHANNEK_B_OUTPUT_COMPARE_MODE_PHASECORRECTANDFREQUENCYCORRECTPWM == 2)
		TCCR1A &= ~(1<<COM1B0);
		TCCR1A |= (1<<COM1B1);
		#elif (TIMER1_CHANNEK_B_OUTPUT_COMPARE_MODE_PHASECORRECTANDFREQUENCYCORRECTPWM == 3)
		TCCR1A |= (1<<COM1B0);
		TCCR1A |= (1<<COM1B1);
		#endif
	#endif

	//Select Clock for TIMER1
	#if (TIMER1_CLOCKSOURCE == 0)
	TCCR1B &= ~(1<<CS10);
	TCCR1B &= ~(1<<CS11 );
	TCCR1B &= ~(1<<CS12);
	#elif (TIMER1_CLOCKSOURCE == 1)
	TCCR1B |= (1<<CS10);
	TCCR1B &= ~(1<<CS11 );
	TCCR1B &= ~(1<<CS12);
	#elif (TIMER1_CLOCKSOURCE == 2)
	TCCR1B &= ~(1<<CS10);
	TCCR1B |= (1<<CS11 );
	TCCR1B &= ~(1<<CS12);
	#elif (TIMER1_CLOCKSOURCE == 3)
	TCCR1B |= (1<<CS10);
	TCCR1B |= (1<<CS11 );
	TCCR1B &= ~(1<<CS12);
	#elif (TIMER1_CLOCKSOURCE == 4)
	TCCR1B &= ~(1<<CS10);
	TCCR1B &= ~(1<<CS11 );
	TCCR1B |= (1<<CS12);
	#elif (TIMER1_CLOCKSOURCE == 5)
	TCCR1B |= (1<<CS10);
	TCCR1B &= ~(1<<CS11 );
	TCCR1B |= (1<<CS12);
	#elif (TIMER1_CLOCKSOURCE == 6)
	TCCR1B &= ~(1<<CS10);
	TCCR1B |= (1<<CS11 );
	TCCR1B |= (1<<CS12);
	#elif (TIMER1_CLOCKSOURCE == 7)
	TCCR1B |= (1<<CS10);
	TCCR1B |= (1<<CS11 );
	TCCR1B |= (1<<CS12);
	#endif
	
	//Select Wave Form Generation Mode for TIMER1
	#if (TIMER1_MODE_OF_OPERATION == 1)
		#if (TIMER1_WaveForm_Generation_Mode == 1)	
		TCCR1A &= ~(1<<WGM10);
		TCCR1A &= ~(1<<WGM11);
		TCCR1B &= ~(1<<WGM12);
		TCCR1B &= ~(1<<WGM13);
		#endif
	#endif
	
	#if (TIMER1_MODE_OF_OPERATION == 2)
		#if (TIMER1_WaveForm_Generation_Mode == 5)
		TCCR1A &= ~(1<<WGM10);
		TCCR1A &= ~(1<<WGM11);
		TCCR1B |= (1<<WGM12);
		TCCR1B &= ~(1<<WGM13);
		#elif (TIMER1_WaveForm_Generation_Mode == 14)
		TCCR1A &= ~(1<<WGM10);
		TCCR1A &= ~(1<<WGM11);
		TCCR1B |= (1<<WGM12);
		TCCR1B |= (1<<WGM13);
		#endif
	#endif
	
	#if (TIMER1_MODE_OF_OPERATION == 3)
		#if (TIMER1_WaveForm_Generation_Mode == 6)
		TCCR1A |= (1<<WGM10);
		TCCR1A &= ~(1<<WGM11);
		TCCR1B |= (1<<WGM12);
		TCCR1B &= ~(1<<WGM13);
		#elif (TIMER1_WaveForm_Generation_Mode == 7)
		TCCR1A &= ~(1<<WGM10);
		TCCR1A |= (1<<WGM11);
		TCCR1B |= (1<<WGM12);
		TCCR1B &= ~(1<<WGM13);
		#elif (TIMER1_WaveForm_Generation_Mode == 8)
		TCCR1A |= (1<<WGM10);
		TCCR1A |= (1<<WGM11);
		TCCR1B |= (1<<WGM12);
		TCCR1B &= ~(1<<WGM13);
		#elif (TIMER1_WaveForm_Generation_Mode == 14)
		TCCR1A &= ~(1<<WGM10);
		TCCR1A |= (1<<WGM11);
		TCCR1B |= (1<<WGM12);
		TCCR1B |= (1<<WGM13);		
		#elif (TIMER1_WaveForm_Generation_Mode == 15)
		TCCR1A |= (1<<WGM10);
		TCCR1A |= (1<<WGM11);
		TCCR1B |= (1<<WGM12);
		TCCR1B |= (1<<WGM13);
		#endif
	#endif
	
	#if (TIMER1_MODE_OF_OPERATION == 4)
		#if (TIMER1_WaveForm_Generation_Mode == 2)
		TCCR1A |= (1<<WGM10);
		TCCR1A &= ~(1<<WGM11);
		TCCR1B &= ~(1<<WGM12);
		TCCR1B &= ~(1<<WGM13);
		#elif (TIMER1_WaveForm_Generation_Mode == 3)
		TCCR1A &= ~(1<<WGM10);
		TCCR1A |= (1<<WGM11);
		TCCR1B &= ~(1<<WGM12);
		TCCR1B &= ~(1<<WGM13);
		#elif (TIMER1_WaveForm_Generation_Mode == 4)
		TCCR1A |= (1<<WGM10);
		TCCR1A |= (1<<WGM11);
		TCCR1B &= ~(1<<WGM12);
		TCCR1B &= ~(1<<WGM13);
		#elif (TIMER1_WaveForm_Generation_Mode == 11)
		TCCR1A &= ~(1<<WGM10);
		TCCR1A |= (1<<WGM11);
		TCCR1B &= ~(1<<WGM12);
		TCCR1B |= (1<<WGM13);
		#elif (TIMER1_WaveForm_Generation_Mode == 12)
		TCCR1A |= (1<<WGM10);
		TCCR1A |= (1<<WGM11);
		TCCR1B &= ~(1<<WGM12);
		TCCR1B |= (1<<WGM13);
		#endif
	#endif
	
	#if (TIMER1_MODE_OF_OPERATION == 5)
		#if (TIMER1_WaveForm_Generation_Mode == 9)
		TCCR1A &= ~(1<<WGM10);
		TCCR1A &= ~(1<<WGM11);
		TCCR1B &= ~(1<<WGM12);
		TCCR1B |= (1<<WGM13);
		#elif (TIMER1_WaveForm_Generation_Mode == 10)
		TCCR1A |= (1<<WGM10);
		TCCR1A &= ~(1<<WGM11);
		TCCR1B &= ~(1<<WGM12);
		TCCR1B |= (1<<WGM13);
		#endif
	#endif

	//Select Wave Form Generation Mode for TIMER1
	#if ( InputCapture_EdgeSelect == 0)							//Falling Edge
	TCCR1B &= ~(1<<ICES1);
	#elif ( InputCapture_EdgeSelect == 1)						//Rising Edge
	TCCR1B |= (1<<ICES1);
	#endif	
}
void Timer1_InputCapture_NoiseCanceler_Activate(void)
{
	TCCR1B |= (1<<ICNC1);	
}

void Timer1_InputCapture_Interrupt_Enable(void)
{
	TIMSK |= (1<<TICIE1);
	sei();
}

void Timer1_OutputCompare_A_Match_Interrupt_Enable(void)
{
	TIFR |= (1<<OCF1A);										//Clear Output Compare flag 1 Channel A
	TIMSK |= (1<<OCIE1A);
	sei();	
}

void Timer1_OutputCompare_B_Match_Interrupt_Enable(void)
{
	TIFR |= (1<<OCF1B);										//Clear Output Compare flag 1 Channel B
	TIMSK |= (1<<OCIE1B);
	sei();
}

void Timer1_OverFlow_Interrupt_Enable(void)
{
	TIFR |= (1<<TOV1);										//Clear Timer Overflow flag 1
	TIMSK |= (1<<TOIE1);
	sei();
}

void Reset_Prescaler_For_Timer0_AND_Timer1(void)
{
	SFIOR |= (1<<PSR10);
}


void Timer2_Init()
{
	//Select Mode of Operation for TIMER2
	#if (TIMER2_MODE_OF_OPERATION == 1)
	TCCR2 &= ~(1<<WGM20);
	TCCR2 &= ~(1<<WGM21);
	#elif (TIMER2_MODE_OF_OPERATION == 2)
	TCCR2 |= (1<<WGM20);
	TCCR2 &= ~(1<<WGM21);
	#elif (TIMER2_MODE_OF_OPERATION == 3)
	TCCR2 &= ~(1<<WGM20);
	TCCR2 |= (1<<WGM21);
	#elif (TIMER2_MODE_OF_OPERATION == 4)
	TCCR2 |= (1<<WGM20);
	TCCR2 |= (1<<WGM21);
	#endif
	
	//Select Compare Output Mode for Non PWM for TIMER2
	#if ( (TIMER2_MODE_OF_OPERATION == 1) || (TIMER2_MODE_OF_OPERATION == 3) )
		#if (TIMER2_OUTPUT_COMPARE_MODE_NONPWM == 0)
		TCCR2 &= ~(1<<COM20);
		TCCR2 &= ~(1<<COM21);
		#elif (TIMER2_OUTPUT_COMPARE_MODE_NONPWM == 1)
		TCCR2 |= (1<<COM20);
		TCCR2 &= ~(1<<COM21);
		#elif (TIMER2_OUTPUT_COMPARE_MODE_NONPWM == 2)
		TCCR2 &= ~(1<<COM20);
		TCCR2 |= (1<<COM21);
		#elif (TIMER2_OUTPUT_COMPARE_MODE_NONPWM == 3)
		TCCR2 |= (1<<COM20);
		TCCR2 |= (1<<COM21);
		#endif
	#endif	
	
	#if ( TIMER2_MODE_OF_OPERATION == 4 )
		#if (TIMER2_OUTPUT_COMPARE_MODE_FASTPWM == 0)
		TCCR2 &= ~(1<<COM20);
		TCCR2 &= ~(1<<COM21);
		#elif (TIMER2_OUTPUT_COMPARE_MODE_FASTPWM == 1)
		TCCR2 &= ~(1<<COM20);
		TCCR2 |= (1<<COM21);
		#elif (TIMER2_OUTPUT_COMPARE_MODE_FASTPWM == 2)
		TCCR2 |= (1<<COM20);
		TCCR2 |= (1<<COM21);
		#endif
	#endif
	
	#if ( TIMER2_MODE_OF_OPERATION == 2 )
		#if (TIMER2_OUTPUT_COMPARE_MODE_PHASECORRECTPWM == 0)
		TCCR2 &= ~(1<<COM20);
		TCCR2 &= ~(1<<COM21);		
		#elif (TIMER2_OUTPUT_COMPARE_MODE_PHASECORRECTPWM == 1)
		TCCR2 &= ~(1<<COM20);
		TCCR2 |= (1<<COM21);
		#elif (TIMER2_OUTPUT_COMPARE_MODE_PHASECORRECTPWM == 2)
		TCCR2 |= (1<<COM20);
		TCCR2 |= (1<<COM21);
		#endif
	#endif
	
	//Select Clock for	TIMER2
	#if (TIMER2_CLOCKSOURCE == 0)
	TCCR2 &= ~(1<<CS20);
	TCCR2 &= ~(1<<CS21);
	TCCR2 &= ~(1<<CS22);
	#elif (TIMER2_CLOCKSOURCE == 1)
	TCCR2 |= (1<<CS20);
	TCCR2 &= ~(1<<CS21);
	TCCR2 &= ~(1<<CS22);
	#elif (TIMER2_CLOCKSOURCE == 2)
	TCCR2 &= ~(1<<CS20);
	TCCR2 |= (1<<CS21);
	TCCR2 &= ~(1<<CS22);
	#elif (TIMER2_CLOCKSOURCE == 3)
	TCCR2 |= (1<<CS20);
	TCCR2 |= (1<<CS21);
	TCCR2 &= ~(1<<CS22);
	#elif (TIMER2_CLOCKSOURCE == 4)
	TCCR2 &= ~(1<<CS20);
	TCCR2 &= ~(1<<CS21);
	TCCR2 |= (1<<CS22);
	#elif (TIMER2_CLOCKSOURCE == 5)
	TCCR2 |= (1<<CS20);
	TCCR2 &= ~(1<<CS21);
	TCCR2 |= (1<<CS22);
	#elif (TIMER2_CLOCKSOURCE == 6)
	TCCR2 &= ~(1<<CS20);
	TCCR2 |= (1<<CS21);
	TCCR2 |= (1<<CS22);
	#elif (TIMER2_CLOCKSOURCE == 7)
	TCCR2 |= (1<<CS20);
	TCCR2 |= (1<<CS21);
	TCCR2 |= (1<<CS22);
	#endif
		
}


void Timer2_Asynchronous_ClockSource_Select(void)			//More functions could be added for Asynchronous operation
{
	#if (TIMER2_CLOCKSOURCE == 1)
	ASSR &= ~(1<<AS2);
	#elif (TIMER2_CLOCKSOURCE == 0)
	ASSR |= (1<<AS2);
	#endif
}

void Timer2_OutputCompareMatch_Interrupt_Enable(void)
{
	TIFR |= (1<<OCF2);										//Clear Output Compare flag 2
	TIMSK |= (1<<OCIE2);
	sei();
}
void Timer2_OverFlow_Interrupt_Enable(void)
{
	TIFR |= (1<<TOV2);										//Clear Timer Overflow flag 2
	TIMSK |= (1<<TOIE2);
	sei();	
}

void Reset_Prescaler_For_Timer2(void)
{
	SFIOR |= (1<<PSR2);
}

/**************************************************************************************************
*   Delay Function using Timer1
**************************************************************************************************/
void delay_ms_timer1(uint16_t delay_ms)
{
	TCCR1A = 0x00;
	TCCR1B = (1<<WGM12);								// set CTC mode
	TCNT1 = 0;											// reset TCNT counter register

	if ( delay_ms < (double)((65535U)/(F_CPU/(double)1000U)))
	{
		//Set the value of OCR1
		OCR1A = ((delay_ms * F_CPU)/1000U) - 1;
		//Prescaler 1
		TCCR1B |= (1<<CS10);
		// wait till compare flag goes up
		while( !(TIFR & (1<<OCF1A)) );
		timer1_stop();  	  								// stop timer to save energy
		TIFR |= (1 << OCF1A);								// reset compare flag
		return;
	}
	
	if ( delay_ms < (double)((65535U)/(F_CPU/(double)8000U)))
	{
		//Set the value of OCR1
		OCR1A = ((delay_ms * F_CPU)/8000U) - 1 ;
		//Prescaler 8
		TCCR1B |= (1<<CS11);
		// wait till compare flag goes up
		while( !(TIFR & (1<<OCF1A)) );
		timer1_stop();  	  								// stop timer to save energy
		TIFR |= (1 << OCF1A);								// reset compare flag
		return;
	}
	if ( delay_ms < (double)((65535U)/(F_CPU/(double)64000U)))
	{
		//Set the value of OCR1
		OCR1A = ((delay_ms * (F_CPU/1000U))/64U) - 1 ;
		//Prescaler 64
		TCCR1B |= (1<<CS10) | (1<<CS11);
		// wait till compare flag goes up
		while( !(TIFR & (1<<OCF1A)) );
		timer1_stop();  	  								// stop timer to save energy
		TIFR |= (1 << OCF1A);								// reset compare flag
		return;
	}
	if ( delay_ms < (double)((65535U)/(F_CPU/(double)256000U)))
	{
		//Set the value of OCR1
		OCR1A = ((delay_ms * (F_CPU/1000U))/256U) - 1 ;
		//Prescaler 256
		TCCR1B |= (1<<CS12);
		// wait till compare flag goes up
		while( !(TIFR & (1<<OCF1A)) );
		timer1_stop();  	  								// stop timer to save energy
		TIFR |= (1 << OCF1A);								// reset compare flag
		return;
	}
	if ( delay_ms < (double)((65535U)/(F_CPU/(double)1024000U)))
	{
		//Set the value of OCR1
		OCR1A = ((delay_ms * (F_CPU/1000U))/1024U) - 1 ;
		//Prescaler 1024
		TCCR1B |= (1<<CS10) | (1<<CS12);
		// wait till compare flag goes up
		while( !(TIFR & (1<<OCF1A)) );
		timer1_stop();  	  								// stop timer to save energy
		TIFR |= (1 << OCF1A);								// reset compare flag
		return;
	}
}


/**************************************************************************************************
*   General Use Timer Functions
**************************************************************************************************/
void timer0_stop(void) 
{
	// Set Prescaler to None, Disabling timer 0
	TCCR0 &= ~(1<<CS00);
	TCCR0 &= ~(1<<CS01);
	TCCR0 &= ~(1<<CS02);							
}

void timer1_stop(void)
{
	// Set Prescaler to None, Disabling timer 1
	TCCR1B &= ~(1<<CS10);
	TCCR1B &= ~(1<<CS11 );
	TCCR1B &= ~(1<<CS12);
}

void timer2_stop(void)
{
	// Set Prescaler to None, Disabling timer 2
	TCCR2 &= ~(1<<CS20);
	TCCR2 &= ~(1<<CS21);
	TCCR2 &= ~(1<<CS22);
}

/**************************************************************************************************
*   General Use Delay Functions
**************************************************************************************************/
void timer0_ms_init(void)
{
	TCCR0 = (1<<CS00);
	TCCR0 |= (1<<FOC0);
	TIFR = (1<<TOV0);										//clear timer0 overflow flag
	TIMSK = (1<<TOIE0);
	TimerSelect = 'm';
	sei();
}

uint64_t timer0_ms(void)
{
	return ( t1_ms * 0.256);								// 1 MHZ  ==>   256 / 1 * 10^-3
}

void Reset_timer0_ms(void)
{
	t1_ms = 0;
}


void timer0_ms_ocr_init(uint8_t OCR0_Value)
{
	TCCR0 = (1<<CS00) | (1<<FOC0) | (1<<WGM01) ;		// no prescaler
	TIFR = (1<<OCF0);									//clear timer0 Output Compare flag
	TIMSK = (1<<OCIE0);									// enable interrupt for ocr
	OCR0 = OCR0_Value;
	TimerSelect = 'm';
	sei();
}

uint64_t timer0_ms_ocr(void)
{
	return ( t2_ms * (OCR0/1000));  // 1 MHZ ==>   OCR0 / 1 * 10^-3
}

void Reset_timer0_ms_ocr(void)
{
	t2_ms = 0;
}


void timer0_us_init(void)
{
	TCCR0 = (1<<CS00);
	TCCR0 |= (1<<FOC0);
	TIFR = (1<<TOV0);										//clear timer0 overflow flag
	TIMSK = (1<<TOIE0);
	TimerSelect = 'u' ;
	sei();
}

uint64_t timer0_us(void)
{
	return ( t1_us * 256);  // 1 MHZ  ==>   256 / 1 
}

void Reset_timer0_us(void)
{
	t1_us = 0;
}


void timer0_us_ocr_init(uint8_t OCR0_Value)
{
	TCCR0 = (1<<CS00) | (1<<FOC0) | (1<<WGM01) ;		// no prescaler
	TIFR = (1<<OCF0);									//clear timer0 Output Compare flag
	TIMSK = (1<<OCIE0);
	OCR0 = OCR0_Value;
	TimerSelect = 'u' ;
	sei();
}

uint64_t timer0_us_ocr(void)
{
	return ( t2_us * OCR0);  // 1 MHZ ==>   OCR0 / 1  
}

void Reset_timer0_us_ocr(void)
{
	t2_us = 0;
}


ISR (TIMER0_OVF_vect)
{
	if (TimerSelect == 'm')
	{
			t1_ms++;

	} 
	
	if ( TimerSelect == 'u' )
	{
			t1_us++;

	}
}

ISR(TIMER0_COMP_vect)
{
	if (TimerSelect == 'm')
	{
		t2_ms ++;
	}
	
	if ( TimerSelect == 'u' )
	{
		t2_us ++;
	}
}


/**************************************************************************************************
*   General Use PWM Functions
**************************************************************************************************/
void FastPWM_init(uint8_t duty_cycle)
{
	TCCR0 = (1<<CS00) ;											// no prescaler
	TCCR0 |= (1<<WGM00) | (1<<WGM01) | (1<<COM01);
 	DDRB|=(1<<PB3);												//Set OC0 PIN as output. It is  PB3 on ATmega16 ATmega32
	OCR0 = duty_cycle * 2.55 ;									// OCR0 = (255/100 ) * duty cycle 
}