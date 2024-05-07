/*
 * File:   newmain.c
 * Author: smec
 *
 * Created on 6 May, 2024, 2:17 PM
 */


#include <xc.h>
void delay(){
    int i,j;
    for(i=0;i<100;i++){
        for(j=0;j<100;j++);
    }
}
void command(char a){
    PORTD=a;
    RC0=0;
    RC1=1;
    delay();
    RC1=0;
    
}
void data(char a){
    PORTD=a;
    RC0=1;
    RC1=1;
    delay();
    RC1=0;
}
void display(const char *a){
    while(*a!='\0'){
        data(*a);
        a++;
    }
}
void main(void) {
    
    TRISC=0X00;
    TRISD=0X00;
    TRISA=0XFF;
    ADCON0=0X01;
    ADCON1=0X00;
    ADCON2=0X86;
    
    command(0X01);
    command(0X38);
    command(0X06);
    command(0X0F);
    command(0X80);
   // display("hello world");
    while(1)
    {
        GODONE=1;
        while(GODONE==1);
        int a,i;
        a=ADRESL;
        a=a+(ADRESH<<8);
        int c[4];
        for(i=0;i<4;i++){
            c[3-i]=(a%10)+48;
            a=a/10;                              //it prints ascii in lcd without inbuilt fun
            command(0X80);
        }
        for(i=0;i<4;i++){
            data(c[i]);
        }
    }
    return;
}
