
#include <reg52.h>
#include <stdio.h>
	  
typedef unsigned char u8;
typedef unsigned int u16;

sbit S1 = P1^0;
sbit S2 = P1^1;
sbit LED = P0^0;

 
void delay_10us(unsigned int ten_us) 
{
 	while(ten_us--);
}

void delay_ms(u16 ms) {
    u16 i , j;
    for(i=ms;i>0;i--) 
        for(j=110;j>0;j--); 
}
 
void time0_init(void) {

 TMOD |= 0x01;
 TH0 = 0xFC;
 TL0 = 0x18;
 ET0 = 1;
 EA = 1;
 TR0 = 1;
}
 
 void main() 
{
  time0_init();
  while(1) {

  }
    
}

void time0() interrupt 1 {

     static u16 i = 0;
     //溢出后重新赋初值
     TH0 = 0xFC;
     TL0 = 0x18;

     if(i == 1000) {
         LED = !LED;
         i = 0;
     }
     i++;
}

