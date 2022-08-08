
//C51  P2 ½Ó J12
#include "reg52.h"	  
#include "intrins.h"
#define LED_PORT P2
sfr XXX = 0xFF;
void delay_10us(unsigned int ten_us) 
{
 	while(ten_us--);
}
 void main() 
 {

 /* int i = 1;
  LED_PORT = 0x03;
  while(i) {
	   LED_PORT =_irol_(LED_PORT,1);
	   delay_10us(50000);	
	   i++;
	 
  }*/
_push_(XXX);

XXX = 1;
XXX = 2;
XXX = 3;

_pop_(XXX);
	
while (1);
 }