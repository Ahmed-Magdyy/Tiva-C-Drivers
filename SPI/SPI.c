/*
 * SPI.c
 *
 *  Created on: ?? ÑÈíÚ ÇáÂÎÑ¡ ???? åÜ
 *      Author: Ahmed Magdy
 */
#include"util.h"
#include"stdtypes.h"
#include "GPIO.h"
#include "SPI.h"
void SPI_intialize(void)
{

    SET_BIT(RCGCSSI,2); //enabling spi module 2
    SET_BIT(RCGCGPIO,1); //enabling clock to port B
    unsigned long delay1_B=RCGCGPIO;
    GPIOLOCK_B=0x4C4F434B; //UNLOCK PORTB
    SET_BIT(GPIOCR_B,4);   //Enable PB4,6,7 TO CONTROL ALTERNTIVE FUNC
    SET_BIT(GPIOCR_B,6);
    SET_BIT(GPIOCR_B,7);
    SET_BIT(GPIOAFSEL_B,4); //enabling alternative function
    SET_BIT(GPIOAFSEL_B,6);
    SET_BIT(GPIOAFSEL_B,7);
    SET_BIT(GPIOPCTL_B,17); // configuring the alternative function to SPI
    SET_BIT(GPIOPCTL_B,21);
    SET_BIT(GPIOPCTL_B,25);
    SET_BIT(GPIOPCTL_B,29);
    CLR_BIT(GPIOPCTL_B,16); // configuring the alternative function to SPI
    CLR_BIT(GPIOPCTL_B,20);
    CLR_BIT(GPIOPCTL_B,24);
    CLR_BIT(GPIOPCTL_B,28);
    SET_BIT(GPIODEN_B,4); // digital enable
    SET_BIT(GPIODEN_B,5);
    SET_BIT(GPIODIR_B,5);
    SET_BIT(GPIODEN_B,6);
    SET_BIT(GPIODEN_B,7);
    CLR_BIT(SSICR1_2,1); //disabling the ssi before config.
    SSICR1_2=0x00000000; // configuring the tiva c as master
    SSICC_2=0x00; //clock=system clock
    SSICPSR_2=16; //config prescaler to 16 to operate at 1MHz
    SET_BIT(SSICR0_2,6);//steady state high
    SET_BIT(SSICR0_2,7);//Data is captured on the second clock edge transition.
    CLR_BIT(SSICR0_2,4);//free scale ssi mode
    CLR_BIT(SSICR0_2,5);
    SET_BIT(SSICR0_2,0);//setting the data bits=8
    SET_BIT(SSICR0_2,1);
    SET_BIT(SSICR0_2,2);
    SET_BIT(SSICR1_2,1);//enabling SPI 2


}
u8 SPI_transfer(u8 data){
    u8 data_read,i;
    GPIO_Write_Pin(PB, PIN5, LOWV); // CS = 0

    data_read= sendAfterWaiting(data);      // send command
    for(i=0;i<15;i++);
    GPIO_Write_Pin(PB, PIN5, HIGHV); // !CS = 1

    return data_read;
}

u8 sendAfterWaiting(u8 code)
{

    while(GET_BIT(SSISR_2,0)==0);  // wait until FIFO empty
    SSIDR_2 = code;                                                   // push data out

    while(GET_BIT(SSISR_2,2)==0);                         // wait for response
    return (u8)SSIDR_2;
}
