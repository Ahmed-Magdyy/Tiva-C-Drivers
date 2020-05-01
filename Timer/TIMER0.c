/*
 * Timer0.c
 *
 *  Created on: Nov 27, 2019
 *      Author: Ahmed Magdy
 */
#include"stdtypes.h"
#include"util.h"
#include"GPIO.h"
#include"Timer0.h"
void Timer0_Initialize(void)
{
    SET_BIT(RCGCTIMER,0);    //Enable clock for timer0
    u8 delayX=0;                //delay
    CLR_BIT(GPTMCTL,0);     //Disable timer0 during configuration
    CLR_BIT(GPTMCFG,0);     //32-bit
    CLR_BIT(GPTMCFG,1);
    CLR_BIT(GPTMCFG,2);
    CLR_BIT(GPTMTAMR,0);   //Select periodic timer
    SET_BIT(GPTMTAMR,1);
    SET_BIT(GPTMTAMR,4);    //UPcount selection
    GPTMTAILR = 0x00F42400;     //Set clock to 16MHZ
    SET_BIT(GPTMIMR,0); //enabling interrupt
    SET_BIT(EN0,19);
    SET_BIT(GPTMICR,0);       //Clear flag
    SET_BIT(GPTMCTL,0);        //Enable timer0
}

