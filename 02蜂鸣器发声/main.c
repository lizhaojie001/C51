
//C51  P1.5 ½Ó J8

#include "reg52.h"
	  
sbit XXX = P1^5;
void delay_10us(unsigned int ten_us) 
{
 	while(ten_us--);
}
 void main() 
{
 	int i = 2000;
    while(1) {
		while(i--){

			XXX = 0x01;		
			delay_10us(10000);
				delay_10us(10000);
					delay_10us(10000);
						delay_10us(10000);
			XXX = 0x00;	
			delay_10us(100);
		}		
		XXX = 0;

	}			 
}