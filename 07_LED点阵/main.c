
#include "reg52.h"
#include <stdio.h>
	  
typedef unsigned char u8;
typedef unsigned int u16;

unsigned int cols[8] = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
unsigned int rows[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

unsigned int meng_rows[8] = {0x40,0x5F,0xF5,0x5F,0x40,0x5F,0xF6,0x5F}; // rows data
unsigned int meng_cols[8] = cols;

sbit SCLK = P3^5;
sbit SRCLK = P3^6;
sbit SER = P3^4;
 
void delay_10us(unsigned int ten_us) 
{
 	while(ten_us--);
}
 
void hc595_a_write_data(u8 data1) {
      
        u8 i= 0;
	    for( ; i < 8 ; i++) {
            SER= data1>>(7-i)&0x01;
            SRCLK=0;
            delay_10us(1);
            SRCLK=1;         
            }
                                                                                       
        SCLK=0;
        delay_10us(1);
        SCLK=1;
}


 
 void main() 
{
    int i = 0;
    int j = 0;
    for(i = 0 ; i < 8 ; i++ ) {
       P2= cols[i];
       P0= P2;
       hc595_a_write_data(meng_rows[i]); 
       delay_10us(1000);
         P0 = P2 = 0XFF;
       hc595_a_write_data(0x00);
     
       delay_10us(400);
    }
    
}