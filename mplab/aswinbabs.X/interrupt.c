/*
 * File:   interrupt.c
 * Author: smec
 *
 * Created on 7 May, 2024, 4:02 PM
 */


#include <xc.h>
delay(){
    int i,j;
    for(i=0;i<300;i++){
        for(j=0;j<300;j++);
    }
}
void main(void) {
    TRISC=0X00;
    TRISD=0X00;
    TRISB=0XFF;
    ADCON1=0X0F;
    GIE=1;
    PEIE=1;
    INT0IE=1;
    
    while(1){
        
        
        PORTD=0X00;
        delay();
        PORTD=0X01;
        delay();
        PORTD=0X02;
        delay();
        PORTD=0X04;
        delay();
        PORTD=0X08;
        delay();
        PORTD=0X10;
        delay();
        PORTD=0X20;
        delay();
        PORTD=0X40;
        delay();
        PORTD=0X80;
        delay();
    
    }
    return;
}
void interrupt _isr(){
    int i;
    if(INT0IF==1){
        for(i=0;i<20;i++){
        PORTC=~PORTC;
        delay();
        }
        
        INT0IF=0;
    }}