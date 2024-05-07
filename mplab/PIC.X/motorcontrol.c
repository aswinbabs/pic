/*
 * File:   motorcontrol.c
 * Author: smec
 *
 * Created on 22 April, 2024, 10:10 AM
 */


#include <xc.h>



void main(void) {
    
    TRISC=0X00;
    TRISD=0X00;
    
    PORTC=0XFF;
    PORTD=0X00;
    
    
    
    while(1);
    return;
}
