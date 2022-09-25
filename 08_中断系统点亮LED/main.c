
#include "reg52.h"
#include <stdio.h>
	  
typedef unsigned char u8;
typedef unsigned int u16;

#define S1 0x09
sbit LED = P0^0;
 
void delay_10us(unsigned int ten_us) 
{
 	while(ten_us--);
}
 
void init_exit0() {
    EA=1;
    EX0=1;
    IT0=1;
}


void check_s1() {
   if(P1 == S1) {
      INT0 = 1;
   }
}

 void main() 
{
     init_exit0();
     while(1) {
        check_s1();
     }
    
}

void exit0() interrupt 0 {
       delay_10us(1000);
       LED = !LED;
}
