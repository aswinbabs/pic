
#include <xc.h>
void delay()
{
    int i,j;
    for(i=0;i<=100;i++)
    {
       for(j=0;j<=100;j++); 
    }
}
void command(char a){
    PORTD=a;
    RC0=0;
    RC1=1;
    delay();
    RC1=0;
    
}
void main(void) {
    TRISC=0X00;
    TRISD=0X00;
    command(0X01);
    command(0X38);
    command(0X06);
    command(0X0F);
    command(0X80);
    
    
    while(1);
    return;
}
