/*
 * Timer0.h
 *
 *  Created on: Nov 27, 2019
 *      Author: Ahmed Magdy
 */

#ifndef TIMER0_H_
#define TIMER0_H_



#define RCGCTIMER (*((volatile unsigned long*)0x400FE604))
#define GPTMCTL (*((volatile unsigned long*)0x4003000C))
#define GPTMCFG (*((volatile unsigned long*)0x40030000))
#define GPTMTAMR (*((volatile unsigned long*)0x40030004))
#define GPTMTAILR (*((volatile unsigned long*)0x40030028))
#define GPTMRIS (*((volatile unsigned long*)0x4003001C))
#define GPTMICR (*((volatile unsigned long*)0x40030024))
#define GPTMIMR (*((volatile unsigned long*)0x40030018))
#define GPTMMIS (*((volatile unsigned long*)0x40030020))
#define EN0 (*((volatile unsigned long*)0xE000E100))
//********************************************************************

//void PLL_Initialize(void);
void Timer0_Initialize(void);
#endif /* TIMER0_H_ */
