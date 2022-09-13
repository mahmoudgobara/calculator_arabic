/*
 * main.c
 *
 *  Created on: Jul 18, 2018
 *      Author: mahmoued
 */
#define F_CPU 12000000
#include <avr/io.h>
#include <avr/delay.h>
#include "Lcd_arabic.h"
void main() {

	int num1;
    int num2;
    int result;
    int operator;
    int operatorEntered=0;
    DDRA = 0b11111000; //configure pins of portA
    DDRD = 0b11111111; //configure pins of portD
    DDRC = 0b11111111; //configure pins of portC
    PORTA = 0b11111111; //configure A0->A2 to be connected pull up resistance
    LCD_voidInitialize();
    /* Initialize of LCD */
    LCD_voidWriteCmd(0b01000000);//AC moved to CGRAM

    //Output rakam wa7ed to LCD
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x04);
    LCD_voidWriteData(0x04);
    LCD_voidWriteData(0x04);
    LCD_voidWriteData(0x04);
    LCD_voidWriteData(0x04);
    LCD_voidWriteData(0x00);

    //Output rakam 2 to LCD
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x07);
    LCD_voidWriteData(0x04);
    LCD_voidWriteData(0x04);
    LCD_voidWriteData(0x04);
    LCD_voidWriteData(0x04);
    LCD_voidWriteData(0x00);

    //Output rakam talata to LCD
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x15);
    LCD_voidWriteData(0x15);
    LCD_voidWriteData(0x1F);
    LCD_voidWriteData(0x10);
    LCD_voidWriteData(0x10);
    LCD_voidWriteData(0x10);

    //Output rakam arba3a to LCD
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x02);
    LCD_voidWriteData(0x04);
    LCD_voidWriteData(0x02);
    LCD_voidWriteData(0x04);
    LCD_voidWriteData(0x08);
    LCD_voidWriteData(0x04);

    //Output rakam 5amsa to LCD
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x0F);
    LCD_voidWriteData(0x09);
    LCD_voidWriteData(0x09);
    LCD_voidWriteData(0x0F);
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0X00);

    //Output rakam setta to LCD
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x0E);
    LCD_voidWriteData(0x02);
    LCD_voidWriteData(0x02);
    LCD_voidWriteData(0x02);
    LCD_voidWriteData(0x02);
    LCD_voidWriteData(0x00);

    //Output rakam sab3a to LCD
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x11);
    LCD_voidWriteData(0x0A);
    LCD_voidWriteData(0x04);
    LCD_voidWriteData(0x04);
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x00);

    //Output rakam tamanya to LCD
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x04);
    LCD_voidWriteData(0x04);
    LCD_voidWriteData(0x0A);
    LCD_voidWriteData(0x11);
    LCD_voidWriteData(0x00);
    LCD_voidWriteData(0x00);

   LCD_voidWriteCmd(0b10000000);//move AC to DDRAM


          while (1) {

    		//Enable coloumn one (C0)
    		PORTA &= ~(0b00001000);
    		if ((PINA & (0b00000001)) == 0) {
    		_delay_ms(250);
    		//Output rakam wa7ed to LCD
    		LCD_voidWriteData(0);
    		if (operatorEntered == 0) {
    						num1 = 1;

    					} else {
    						num2 = 1;
    					}
    		}


    		else if ((PINA & (0b00000010)) == 0) {
    	   _delay_ms(250);
    					 //Output rakam talata to LCD
    					LCD_voidWriteData(2);
    					if (operatorEntered == 0) {
    						num1 = 3;

    					} else {
    						num2 = 3;
    					}
    				}
    else if ((PINA & (0b00000100)) == 0) {
    					_delay_ms(250);
    					//Output rakam 5amsa to LCD
    					LCD_voidWriteData(4);
    					if (operatorEntered == 0) {
    						num1 = 5;

    					} else {
    						num2 = 5;
    					}
    				}

  //Disable coloumn one (c0)
    PORTA |= (0b00001000);
  //Enable coloumn two (c1)
    PORTA &= ~(0b00010000);
    if ((PINA & (1 << 0)) == 0) {
    			_delay_ms(250);
    			//Output rakam 2 to LCD
    			LCD_voidWriteData(1);
    			if (operatorEntered == 0) {
    				num1 = 2;

    			} else {
    				num2 = 2;
    			}
    		}

    else if ((PINA & (0b00000010)) == 0) {
    			_delay_ms(250);
    			 //Output rakam arba3a to LCD
    			LCD_voidWriteData(3);
    			if (operatorEntered == 0) {
    				num1 = 4;

    			} else {
    				num2 = 4;
    			}
    		}
    else if ((PINA & (0b00000100)) == 0) {
    			_delay_ms(250);
    			 //Output rakam setta to LCD
    			LCD_voidWriteData(5);
    			if (operatorEntered == 0) {
    				num1 = 6;

    			} else {
    				num2 = 6;
    			}

    		}
    //Disable coloumn two (c1)
    		PORTA |= (0b00010000);
    //Enable coloumn three (c2)
    		PORTA &= ~(0b00100000);

    		if ((PINA & (1 << 0)) == 0) {
    			_delay_ms(250);
    			LCD_voidWriteData('+'); //Output character '+' to LCD
    			operator = '+';
    			operatorEntered = 1;

    		}

    		else if ((PINA & (0b00000010)) == 0) {
    			_delay_ms(250);
    			LCD_voidWriteData('-'); //Output character '-' to LCD
    			operator = '-';
    			;
    			operatorEntered = 1;
    		}

    		else if ((PINA & (0b00000100)) == 0) {
    			_delay_ms(250);
    			LCD_voidWriteData('='); //Output character '=' to LCD
    			switch (operator) {
    			case '-':
    				result = num1 - num2;
    				break;
    			case '+':
    				result = num1 + num2;
    				break;
    			}
    			switch (result) {
    			case 1:
    				LCD_voidWriteData(0);

    		    break;
    			case 2:
    				LCD_voidWriteData(1);


    			break;

    			case 3:
    				LCD_voidWriteData(2);

               break;
    			case 4:
    				LCD_voidWriteData(3);

    		  break;

    			case 5:
    				LCD_voidWriteData(4);

             break;

    			case 6:

    				LCD_voidWriteData(5);

    			break;

    			case 7:
    				LCD_voidWriteData(6);

    		break;

    			case 8:
    			   LCD_voidWriteData(7);


    		break;
    			}


    			}

    		//Disable coloumn three (c2)
    PORTA |= (0b00100000);


          }



    	}




