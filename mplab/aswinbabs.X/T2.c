/*
 * File:   T2.c
 * Author: smec
 *
 * Created on 2 May, 2024, 3:15 PM
 */


#include <xc.h>
timer(){
    while(TMR2IF==0);
    PR2=0XC3;
    TMR2IF=0;
}
void main(void) {
    
    TRISD=0X00;
    T2CON=0X7F;
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
