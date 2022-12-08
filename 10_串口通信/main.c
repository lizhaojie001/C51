
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
 

//��ʼ������
void uart_init(u8 baud) {
 TMOD |= 0x20;//��ʱ����ʽ2������ʽ,�Զ�����
 SCON = 0x50; //���ڷ�ʽ1,�򿪴�������λ
 PCON = 0x80; //���ڹ�����ʽ
 TH1 = baud;
 TL1 = baud;
 ES = 1; //�򿪽����ж�
 EA = 1;//�����ж�
 TR1 = 1;//����������

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
 

