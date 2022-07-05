#include <REGX52.H>
#include "lcd1602.h"
#include "delay.h"
unsigned char a[4]={0xf7,0xfb,0xfd,0xfe};
unsigned int key;
unsigned char i;
unsigned char n;
unsigned int num;
unsigned char c;
unsigned int keymode()//获取案件的值
{
	P1=a[i];//列扫描
		i++;
		if(i==4)
		{
			i=0;
		}
	if(P1==0x77)//第一个按键按下
	{
		delay_ms(20);
		if(P1==0x77)
		{
			n=1;
			while(P1==0x77)
			{}
		}
		delay_ms(20);
	}
	else if(P1==0x7b)
	{
		delay_ms(20);
		if(P1==0x7b)
		{
			n=2;
			while(P1==0x7b)
			{}
		}
		delay_ms(20);
	}
	else if(P1==0x7d)
	{
		delay_ms(20);
		if(P1==0x7d)
		{
			n=3;
			while(P1==0x7d)
			{}
		}
		delay_ms(20);
	}
	else if(P1==0x7e)
	{
		delay_ms(20);
		if(P1==0x7e)
		{
			n=4;
			while(P1==0x7e)
			{}
		}
		delay_ms(20);
	}
	else if(P1==0xb7)
	{
		delay_ms(20);
		if(P1==0xb7)
		{
			n=5;
			while(P1==0xb7)
			{}
		}
		delay_ms(20);
	}
	else if(P1==0xbb)
	{
		delay_ms(20);
		if(P1==0xbb)
		{
			n=6;
			while(P1==0xbb)
			{}
		}
		delay_ms(20);
	}
	else if(P1==0xbd)
	{
		delay_ms(20);
		if(P1==0xbd)
		{
			n=7;
			while(P1==0xbd)
			{}
		}
		delay_ms(20);
	}
	else if(P1==0xbe)
	{
		delay_ms(20);
		if(P1==0xbe)
		{
			n=8;
			while(P1==0xbe)
			{}
		}
		delay_ms(20);
	}
	else if(P1==0xd7)
	{
		delay_ms(20);
		if(P1==0xd7)
		{
			n=9;
			while(P1==0xd7)
			{}
		}
		delay_ms(20);
	}
	else if(P1==0xdb)
	{
		delay_ms(20);
		if(P1==0xdb)
		{
			n=10;
			while(P1==0xdb)
			{}
		}
		delay_ms(20);
	}
	else if(P1==0xdd)
	{
		delay_ms(20);
		if(P1==0xdd)
		{
			n=11;
			while(P1==0xdd)
			{}
		}
		delay_ms(20);
	}
	else if(P1==0xde)
	{
		delay_ms(20);
		if(P1==0xde)
		{
			n=12;
			while(P1==0xde)
			{}
		}
		delay_ms(20);
	}
	else if(P1==0xe7)
	{
		delay_ms(20);
		if(P1==0xe7)
		{
			n=13;
			while(P1==0xe7)
			{}
		}
		delay_ms(20);
	}
	else if(P1==0xeb)
	{
		delay_ms(20);
		if(P1==0xeb)
		{
			n=14;
			while(P1==0xeb)
			{}
		}
		delay_ms(20);
	}
		else if(P1==0xed)
	{
		delay_ms(20);
		if(P1==0xed)
		{
			n=15;
			while(P1==0xed)
			{}
		}
		delay_ms(20);
	}
		else if(P1==0xee)
	{
		delay_ms(20);
		if(P1==0xee)
		{
			n=16;
			while(P1==0xee)
			{}
		}
		delay_ms(20);
	}
	else
	{
		return 0;//没有按键按下返回0
	}
	return n;
}
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"password");
	num=0;
	while (1)
	{
		
		key=keymode();
		if(key)//当有按键按下进入循环
		{
			if (key<=10&&num<=9999)//读取0~9的键值，且要求得到的数不能大于9999
			{
				num=num*10;
				num=num+key%10;    //得到屏幕上的显示数
				LCD_ShowNum(2,1,num,4);
			}
			else if(key>=14)
			{
				num=num/10;        //删除一个数
				LCD_ShowNum(2,1,num,4);
			}
			if(num==2573&&key==11) //如果屏幕上的数为2573 且按下11这个确认键则密码正确
			{
				LCD_Init();
				LCD_ShowString(1,1,"Correct password");
			}
			else if(num!=2573&&key==11)//按确认键密码不对则告知错误 
			{
				
				LCD_ShowString(1,10,"error");
			}
		}
		
	}
}