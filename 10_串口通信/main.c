
#include <reg52.h>
#include <stdio.h>
	  
typedef unsigned char u8;
typedef unsigned int u16;
 
 
void delay_10us(unsigned int ten_us) 
{
 	while(ten_us--);
}

void delay_ms(u16 ms) {
    u16 i , j;
    for(i=ms;i>0;i--) 
        for(j=110;j>0;j--); 
}
 

//初始化数据
void uart_init(u8 baud) {
 TMOD |= 0x20;//定时器方式2工作方式,自动重载
 SCON = 0x50; //串口方式1,打开串行允许位
 PCON = 0x80; //串口工作方式
 TH1 = baud;
 TL1 = baud;
 ES = 1; //打开接收中断
 EA = 1;//打开总中断
 TR1 = 1;//开启计数器

}

 
 void main() 
{
    uart_init(0x30);
    while(1);
}

void uart() interrupt 4
{
    u8 rec_data = 0;
    RI = 0;
    rec_data = SBUF;
    SBUF = rec_data;
    while(!T1);
    T1 = 0;

}
 

