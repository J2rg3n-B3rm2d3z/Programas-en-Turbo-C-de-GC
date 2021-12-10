/**********Figuras de Hule************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>

#define ENTER 13

void rectanguloteclado(void);

void main(void)
	{

		int adap=DETECT,mode;
		initgraph(&adap,&mode,"c:\\TC20\\BIN ");

	setbkcolor(LIGHTGRAY);
	rectanguloteclado();
	closegraph();
}

/************ Rectangulo de Hule Teclado********/

void rectanguloteclado(void)
	{
	char a;
	int x2=60,y2=80;
	cleardevice();
	setlinestyle(1,1,2);
	setcolor(BLUE);
	rectangle(320,240,x2,y2);
do
{
a=getch();
switch(a)
{
case 77:                  
		cleardevice();
		 x2=x2+5;
		 setcolor(BLUE);
         rectangle(320,240,x2,y2);
		 if(x2>600)
		 x2=600;
		 break;

case 75:                   
		cleardevice();
		 x2=x2-5;
		 setcolor(BLUE);
         rectangle(320,240,x2,y2);
		 if(x2<60)
		 x2=60;
		 break;

case 80:                  
		cleardevice();
		 y2=y2+5;
		 setcolor(BLUE);
         rectangle(320,240,x2,y2);
		 if(y2>460)
		 y2=460;
		 break;

case 72:                  
		cleardevice();
		 y2=y2-5;
		 setcolor(BLUE);
         rectangle(320,240,x2,y2);
		 if(y2<80)
		 y2=80;
		 break;
}
}while(a!=13);

cleardevice();
}



