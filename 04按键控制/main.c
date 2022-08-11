
//C51  P0 接 JP3
//CL5611BH  共阳极 	   http://www.xlitx.com/datasheet/CL5611BH.pdf
//CL3641AH  共阴极 
#include "reg52.h"
#include <stdio.h>
	  
typedef unsigned char u8;
typedef unsigned int u16;

unsigned int gsmg_code[15] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
							0x7f,0x6f,0x77,0x39,0x5e,0x79,0x71};
sbit KEY1 = P3^4;						
sbit KEY2 = P3^1;			  
sbit KEY3 = P3^2;
sbit KEY4 = P3^3;


#define KEY1_PRESS 1
#define KEY2_PRESS 2
#define KEY3_PRESS 3
#define KEY4_PRESS 4
#define KEY_UNPRESS 0

sbit LED1 = P2^4;
sbit LED2 = P2^1;
sbit LED3 = P2^2;
sbit LED4 = P2^3;


void delay_10us(unsigned int ten_us) 
{
 	while(ten_us--);
}
  u8  key_scan(u8 mode) {
    static key=1;
    if(mode) key=1;
    if(KEY1==0||KEY2==0||KEY3==0||KEY4==0) {
        delay_10us(1000);
        key=0;
        if(KEY1==0) return KEY1_PRESS;
        else if(KEY2==0) return KEY2_PRESS;
        else if(KEY3==0) return KEY3_PRESS;
        else if(KEY4==0) return KEY4_PRESS;
    }else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1){
        key=1;
    } 

    return  KEY_UNPRESS;
    
}
 
 void main() 
{
    u8 key=0;
    P2 = 0;
    while(1) {
         key = key_scan(0);
         if(key == KEY4_PRESS) LED4 = !LED4;
         
	}			 
}