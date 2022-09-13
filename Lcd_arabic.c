/*
 * Lcd_arabic.c
 *
 *  Created on: Jul 18, 2018
 *      Author: mahmoued
 */
#include <avr/io.h>
#include <avr/delay.h>
#include "Lcd_arabic.h"

void LCD_voidInitialize(void){
	/* Initialization for LCD */
    PORTC &= ~(1<<7) & ~(1<<6); /* Clear bit c7 and c6 in portC */
	_delay_ms(35); /* 35 ms delay for voltage stability*/
	LCD_voidWriteCmd(0b00011000); /* Function set command */
	_delay_ms(1); /* 1 ms delay for command processing */
	LCD_voidWriteCmd(0b00001100); /* Display ON/OFF command */
    _delay_ms(1); /* 1 ms delay for command processing */
    LCD_voidWriteCmd(0b00000001); /* clear screen */
    _delay_ms(2); /* 2 ms delay for command processing */
}
void LCD_voidWriteData(char data) {
	PORTC |= (1 << 7); /* set pin C7 = 1 -- Rs */
	PORTC &= ~(1 << 6); /*clear pin c6 = 0 -- R/W */
    PORTD = data;
    PORTC |= (1 << 5); //* set E pin to high */
    _delay_ms(1);
    PORTC &= ~(1 << 5); /*clear E pin to loiw*/
    _delay_ms(1);
}
void LCD_voidWriteCmd(char command) {
	PORTC &= ~(1 << 7); /* set pin C7 = 1 -- Rs */
	PORTC &= ~(1 << 6); /*clear pin c6 = 0 -- R/W */
    PORTD = command;
    PORTC |= (1<<5); //* set E pin to high */
    _delay_ms(1);
    PORTC &= ~(1<<5); /*clear E pin to low*/
    _delay_ms(1);
}



