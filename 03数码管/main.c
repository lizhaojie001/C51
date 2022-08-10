
//C51  P0 接 JP3
//CL5611BH  共阳极 	   http://www.xlitx.com/datasheet/CL5611BH.pdf
//CL3641AH  共阴极 
#include "reg52.h"
	  

unsigned int gsmg_code[15] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
							0x7f,0x6f,0x77,0x39,0x5e,0x79,0x71};
sbit P22 = P2^2;						
sbit P23 = P2^3;			  
sbit P24 = P2^4;
void delay_10us(unsigned int ten_us) 
{
 	while(ten_us--);
}

void display() {
     int i = 0;
    for(; i < 8 ; i++) {
         switch(i){
            case 0: P22 = 0; P23 = 0; P24 = 0; break;  
            case 1: P22 = 1; P23 = 0; P24 = 0; break;
            case 2: P22 = 0; P23 = 1; P24 = 0; break;
            case 3: P22 = 1; P23 = 1; P24 = 0; break;
            case 4: P22 = 0; P23 = 0; P24 = 1; break;
            case 5: P22 = 1; P23 = 0; P24 = 1; break;
            case 6: P22 = 0; P23 = 1; P24 = 1; break;
            case 7: P22 = 1; P23 = 1; P24 = 1; break;
         }
        P0 = gsmg_code[i];
        delay_10us(20000);
        P0 = 0x00;
    }
}
 void main() 
{
//	int a = 2;
//	P0 =(gsmg_code[a]);
//	P24=1;
//	P23=1;
//	P22=0;
    while(1) {
         display();
	}			 
}