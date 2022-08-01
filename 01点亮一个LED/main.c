
//C51  P2 ½Ó J12
#include "reg52.h"	  
 
void delay_10us(unsigned int ten_us) 
{
 	while(ten_us--);
}
 void main() 
 {

  int i = 1;
  while(i) {
	   P2 = ~(0x1<<((i-1)%8));
	   delay_10us(50000);	
	   i++;
  }
 }