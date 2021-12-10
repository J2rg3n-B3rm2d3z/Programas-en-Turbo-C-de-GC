/**********Figuras de Hule************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>

#define ENTER 13

void lineahule();



void main()
{

		int adap=DETECT,mode;
		initgraph(&adap,&mode,"c:\\TC20\\BIN ");

	setbkcolor(LIGHTGRAY);
	lineahule();

	getch();
	closegraph();

}

/************ Linea de Hule********/

void lineahule()
{
		char a;
		int x2=getmaxx()/2, y2=getmaxy()/2;
		/*cleardevice();*/

	do
	{
		a=getch();

		switch(a)
			{

			case 77:  
				  setcolor(BLACK);

				  line(290,240,x2,y2);
				  setcolor(LIGHTBLUE);
				  x2=x2+5;
				  line(290,240,x2,y2);
				  break;

			case 75:  setcolor(BLACK);
				  line(290,240,x2,y2);
				  setcolor(LIGHTBLUE);
				  x2=x2-5;
				  line(290,240,x2,y2);
				  break;

			case 72:  setcolor(BLACK);
				  line(290,240,x2,y2);
				  setcolor(LIGHTBLUE);
				  y2-=5;
				  line(290,240,x2,y2);
				  break;

			case 80: setcolor(BLACK);
				 line(290,240,x2,y2);
				 setcolor(LIGHTBLUE);
				 y2+=5;
				 line(290,240,x2,y2);
				 break;

			}

		} while(a!=ENTER);
	exit(0);
}

