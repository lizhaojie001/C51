
#include "reg52.h"
#include <stdio.h>
	  
typedef unsigned char u8;
typedef unsigned int u16;

unsigned int cols[8] = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
unsigned int rows[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

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
	//P0 join  J12
	//col light green led
 /*   for( ; i < 3 ; i++) {
       for(; j < 8 ; j++) {
         P0 = 0xff;
         P2 = cols[j];
         delay_10us(20000);
       }
    }
    */
   
     P2=0xFF;
      hc595_a_write_data(0x00);
    //write hc595   left to right
      i= 0;
      for( ; i < 3 ; i++) {
         j = 0;
         for(; j < 8 ; j++) {
             hc595_a_write_data(0xff); 
             P2 = cols[j];           
             delay_10us(50000);
       
         }
      }
       
    
    //bottom to top
      i= 0;  
      hc595_a_write_data(0xFF);  
      for( ; i < 3 ; i++) {
         j = 0;
         for(; j < 8 ; j++) {
        
             P2=0x00;
             P0=rows[7-j];
             hc595_a_write_data(rows[j]); 
             delay_10us(50000);
         }
      }
     
      /*
       P0 = 0; 
       i= 0;
       for( ; i < 3 ; i++) {
            j = 0;
            for(; j < 8 ; j++) {
             P0=rows[j];
             hc595_a_write_data(0);
             delay_10us(20000);
            }
       }
      */
    
}