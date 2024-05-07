/*
 * File:   PROJECT.c
 * Author: smec
 *
 * Created on 3 May, 2024, 4:44 PM
 */


#include <xc.h>
dt25(){
   
    CCP1CON=0X3F;
    CCPR1L=0X3F;
    

}
dt50(){
  
    
    CCP1CON=0X0F;
    CCPR1L=0X80;
  
}
dt75(){
   
    CCP1CON=0X3F;
    CCPR1L=0XBF;
}
void main(void) {
    ADCON1=0X0F;
    TRISC=0X00;
    TRISA=0XFF;
    T2CON=0X7D;

    int count=0;
 
   while(1){ 
        
     if(RA0==0){
         
         count++;
         
         if(count>3){
             count=0;
         }
         while(RA0==0);
     } 
       
       
       
    switch(count)
            
    {
        case 1:
            dt25();
            
            break;
        case 2:
            dt50();
            break;
        case 3:
            dt75();
            break;
    }
    
   }
}
