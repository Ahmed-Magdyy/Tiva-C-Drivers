/*
 * SPI.h
 *
 *  Created on: ?? —»Ì⁄ «·¬Œ—° ???? Â‹
 *      Author: Ahmed Magdy
 * SDA / CS / FSS ------------ PB5
 * SCK  / CLK     ------------ PB4
 * MOSI / TX      ------------ PB7
 * MISO /  RX     ------------ PB6
 *
 * RST            ------------ PF0 *
 */

#ifndef SPI_H_
#define SPI_H_


#define RCGCSSI (*((volatile unsigned long*)0x400FE61C))
#define SSICR0_2 (*((volatile unsigned long*)0x4000A000))
#define SSICR1_2 (*((volatile unsigned long*)0x4000A004))
#define SSICC_2 (*((volatile unsigned long*)0x4000AFC8))
#define SSICPSR_2 (*((volatile unsigned long*)0x4000A010))
#define SSISR_2 (*((volatile unsigned long*)0x4000A00C))
#define SSIDR_2 (*((volatile unsigned long*)0x4000A008))
void SPI_intialize(void);
u8 SPI_transfer(u8 data);
u8 sendAfterWaiting(u8 code);
#endif /* SPI_H_ */
