/*
 * File:   adc.c
 * Author: smec
 *
 * Created on 3 May, 2024, 3:10 PM
 */


#include <xc.h>

//void main(void) {
//    TRISC=0X00;
//    T2CON=0X7D;                  //25% DUTY CYCLE
//    
//    
//    CCP1CON=0X3F;
//    CCPR1L=0X3F;
//    
//    while(1);
//    return;
//}





//void main(void) {
//    TRISC=0X00;
//    T2CON=0X7D;                  //50% DUTY CYCLE
//    
//    
//    CCP1CON=0X0F;
//    CCPR1L=0X80;
//    
//    while(1);
//    return;
//}


void main(void) {
    TRISC=0X00;
    T2CON=0X7D;                  //75% DUTY CYCLE
    
    
    CCP1CON=0X3F;
    CCPR1L=0XBF;
    
    while(1);
    return;
}
