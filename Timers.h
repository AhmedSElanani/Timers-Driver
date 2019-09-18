/*
 * IncFile1.h
 *
 * Created: 20-Aug-19 4:37:23 PM
 *  Author: Ahmed Salah
 */ 


#ifndef __TIMERS_H__
#define __TIMERS_H__

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Timer0_Config.h"
#include "Timer1_Config.h"
#include "Timer2_Config.h"

/**************************************************************************************************
*   Functions prototypes
**************************************************************************************************/
void Timer0_Init();
void Timer0_OutputCompareMatch_Interrupt_Enable(void);
void Timer0_OverFlow_Interrupt_Enable(void);

void Timer1_Init();
void Timer1_InputCapture_NoiseCanceler_Activate(void);
void Timer1_InputCapture_Interrupt_Enable(void);
void Timer1_OutputCompare_A_Match_Interrupt_Enable(void);
void Timer1_OutputCompare_B_Match_Interrupt_Enable(void);
void Timer1_OverFlow_Interrupt_Enable(void);
void Reset_Prescaler_For_Timer0_AND_Timer1(void);

void Timer2_Init();
void Timer2_Asynchronous_ClockSource_Select(void);										//More functions could be added for Asynchronous operation
void Timer2_OutputCompareMatch_Interrupt_Enable(void);
void Timer2_OverFlow_Interrupt_Enable(void);
void Reset_Prescaler_For_Timer2(void);

void timer0_stop(void);
void timer1_stop(void);
void timer2_stop(void);

void delay_ms_timer1(uint16_t delay_ms);

void timer0_ms_init(void);
uint64_t timer0_ms(void);
void Reset_timer0_ms(void);

void timer0_ms_ocr_init(uint8_t OCR0_Value);
uint64_t timer0_ms_ocr(void);
void Reset_timer0_ms_ocr(void);

void timer0_us_init(void);
uint64_t timer0_us(void);
void Reset_timer0_us(void);

void timer0_us_ocr_init(uint8_t OCR0_Value);
uint64_t timer0_us_ocr(void);
void Reset_timer0_us_ocr(void);

void FastPWM_init(uint8_t duty_cycle);

#endif /* __TIMERS_H__ */