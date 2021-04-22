/*
 * File:   main.c
 * Author: 20185074
 *
 * Created on 16 de Abril de 2021, 16:42
 */

#include "config.h"
#include <xc.h>

#define _XTAL_FREQ 4000000
#define DADOS PORTB
#define EN    PORTDbits.RD7
#define RS    PORTDbits.RD6

void LCD_init (void)
{
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD6 = 0;
    ANSELH = 0;
    TRISB = 0x00;
    
    DADOS = 0x00;
    EN = 1;
    RS = 0;
}
void LCD_on ( void )
{   
    // ligar o Display LCD
    RS = 0;
    EN = 1;
    DADOS = 0x0F;
    EN = 0;
    __delay_us(40);
    EN = 1;
    
}
void LCD_printChar (char c)
{
    RS = 1;                
    DADOS = c;
    EN = 0;
    __delay_us(40);
    EN = 1;         
}

void LCD_print (char * str)
{
    char i = 0; 
    
    while( *(str+i) != 0 )
    {
        LCD_printChar( *(str+i) );
        ++i;
    }    
}

void main(void)
{
    
    
    LCD_init();
    LCD_on();
    LCD_print("cosme");
  
    while(1)
    {
        
    }    
    
}