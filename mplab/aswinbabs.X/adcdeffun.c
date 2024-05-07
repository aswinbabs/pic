/*
 * File:   adcdeffun.c
 * Author: smec
 *
 * Created on 6 May, 2024, 4:19 PM
 */


#include <xc.h>
#include <stdio.h>
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
        int a;
        float b;
        a=ADRESL;
        a=a+(ADRESH<<8);
        char c[4];
        sprintf(c,"%4d",a);               //using default function
        command(0x80);
        
        b= (a*5)/1023.0;
        sprintf(c,"voltage:%0.2f",b);  
        display(c);
      
        
    }
    return;
}

