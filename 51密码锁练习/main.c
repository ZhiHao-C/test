#include <REGX52.H>
#include "lcd1602.h"
#include "delay.h"
unsigned char a[4]={0xf7,0xfb,0xfd,0xfe};
unsigned int key;
unsigned char i;
unsigned char n;
unsigned int num;
unsigned char c;
unsigned int keymode()//��ȡ������ֵ
{
	P1=a[i];//��ɨ��
		i++;
		if(i==4)
		{
			i=0;
		}
	if(P1==0x77)//��һ����������
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
		return 0;//û�а������·���0
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
		if(key)//���а������½���ѭ��
		{
			if (key<=10&&num<=9999)//��ȡ0~9�ļ�ֵ����Ҫ��õ��������ܴ���9999
			{
				num=num*10;
				num=num+key%10;    //�õ���Ļ�ϵ���ʾ��
				LCD_ShowNum(2,1,num,4);
			}
			else if(key>=14)
			{
				num=num/10;        //ɾ��һ����
				LCD_ShowNum(2,1,num,4);
			}
			if(num==2573&&key==11) //�����Ļ�ϵ���Ϊ2573 �Ұ���11���ȷ�ϼ���������ȷ
			{
				LCD_Init();
				LCD_ShowString(1,1,"Correct password");
			}
			else if(num!=2573&&key==11)//��ȷ�ϼ����벻�����֪���� 
			{
				
				LCD_ShowString(1,10,"error");
			}
		}
		
	}
}