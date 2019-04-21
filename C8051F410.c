#include "C8051F410.h"
#define uchar unsigned char
#define uint  unsigned int
sbit RS=P1^3;			
sbit RW=P1^4;
sbit EN=P1^5;		
sbit PSB=P1^6;
sbit RET=P0^7;

unsigned char opinion[]={"Worked?"};
unsigned char yes_no[]={" YES     No "};


unsigned char number[]={"               "};
int yesCount=0;
int noCount=0;

int no[10]={48,49,50,51,52,53,54,55,56,57};
void PCA_Init(){ 
   PCA0MD&=~0x40; //WDTE = 0 (clear watchdog timer enable)                                    
}

void SYSCLK_Init(){
   
   OSCICN=0x84;;

}

void   GPIO_Init(){
		  XBR1=0x40;
		  P2MDOUT=0xff;
}

void Interrupt_Init(){

   IT01CF=0x10;	  
   TCON=0x05;	//trigger mode   
   EX0=1;  
   EX1=1;  
   EA=1;    // Enable global interrupts 

}

void Ext_Interrupt_Configuration(){
	PCA_Init();
	SYSCLK_Init();
	GPIO_Init();
	Interrupt_Init();

}


void Port_IO_Init()
{
    XBR1      = 0x40;
}

void Oscillator_Init()
{
    OSCICN    = 0x86;
}
void Init_Device(void)
{
    PCA_Init();
    Port_IO_Init();
    Oscillator_Init();
}
void delay_50us(uint t)					 
{	
	uchar i=2;
	while(t--)
	while(i--);	
}

void delay_50ms(uint t)					 
{
	uint i,j,k;
	for (i=t;i>0;i--)
		for (j=57;j>0;j--)
			for(k=100;k>0;k--);
}

void wr_command(uchar com)			 
{
	  RS=0;								
	  RW=0;								
	  delay_50us(1);
	  P2=com;
	  EN=1;								 
	  delay_50us(1);
	  EN=0;
	  delay_50us(1);
}

void wr_data(uchar dat)
{
	RS=1;
	RW=0;
	delay_50us(1);
	P2=dat;
	EN=1;
	delay_50us(1);
	EN=0;
	delay_50us(1);
}

void re_data(uchar *dat)  
{
	while(*dat != '\0')
		wr_data(*dat++);	 
}

void wr_address(uchar x,uchar y) 
{
	uchar temp = 0;
	switch(x)
	{
		case 1:
			temp = 0x7f;
			break;
		case 2:
			temp = 0x8f;
			break;
		case 3:
			temp = 0x87;
			break;
		case 4:
			temp = 0x97;
			break;
	} 
	temp = temp + y;
	wr_command(temp);
}

void display(char q[],int x,int y)   
{
	
	wr_address(x,y);
	delay_50us(3);
	re_data(q);
	delay_50us(4);
}

void init_12864( )
{
	PSB=1;
	wr_command(0x30);	  
	delay_50us(2);
	wr_command(0x30);
	delay_50us(2);
	wr_command(0x0c);	 
	delay_50us(1);
	wr_command(0x01);	 
	delay_50us(20);
	wr_command(0x06);  
	delay_50us(2);		
}

void INT0_ISR() interrupt 0
{
	yesCount++;
	number[2]=no[(yesCount/10)%10];
	number[3 ]=no[yesCount%10];
	display(number,3,1);
}

void INT1_ISR() interrupt 2
{
	noCount++;
	number[9]=no[(noCount/10)%10];
	number[10]=no[noCount%10];
	display(number,3,1);

}


void main(){

	Init_Device();
	init_12864();
	Ext_Interrupt_Configuration();
	display(opinion,1,4);
	display(yes_no,2,1);
	
	while(1);   // Wait forever



}
