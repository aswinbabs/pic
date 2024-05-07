


#include <xc.h>
timer(){
    while(TMR1IF==0);
    TMR1L=0X96;
    TMR1H=0XE7;
    TMR1IF=0;
}
void main(void) {
    
    TRISD=0X00;
    T1CON=0X7D;
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
