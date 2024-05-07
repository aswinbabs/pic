/*
 * File:   T3.c
 * Author: smec
 *
 * Created on 2 May, 2024, 4:00 PM
 */


#include <xc.h>

timer(){
    while(TMR3IF==0);
    TMR3L=0X96;
    TMR3H=0XE7;
    TMR3IF=0;
}
void main(void) {
    
    TRISD=0X00;
    T3CON=0XFD;
    int i;
    while(1){
        
        PORTD=0XFF;
        for(i=0;i<100;i++)
        {
            timer();
        }
        PORTD=0X00;
        for(i=0;i<100;i++)
        {
            timer();
        }
    }
    return;
}
