#include <CONIO.H>
#include <GRAPHICS.H>
#include <MOUSE.H>

#define Esc 27

void main()
{
	int g_adap=DETECT,g_modo, PosX = 0, PosY = 0,i=0;

	initgraph(&g_adap,&g_modo,"");

	PosX = getmaxx()/2;
	PosY = getmaxy()/2;

	mver();

	setfillstyle(1,DARKGRAY);
	bar(PosX-70,PosY,PosX+70,PosY+55);

	setcolor(1);
	line(PosX-70,PosY,PosX+70,PosY);
	line(PosX-70,PosY,PosX-70,PosY+55);

	setcolor(2);
	line(PosX-70,PosY+55,PosX+70,PosY+55);
	line(PosX+70,PosY,PosX+70,PosY+55);

	mver();

	do{
		if(minlimit(1,PosX-70,PosY,PosX+70,PosY+55)==1 && mclick()==1)
		{
			mocultar();

			setfillstyle(1,i==8?LIGHTGRAY:DARKGRAY);

			bar(PosX-70,PosY,PosX+70,PosY+55);

			setcolor(i+1);
			line(PosX-70,PosY,PosX+70,PosY);
			line(PosX-70,PosY,PosX-70,PosY+55);

			setcolor(i+2);
			line(PosX-70,PosY+55,PosX+70,PosY+55);
			line(PosX+70,PosY,PosX+70,PosY+55);
							
			delay(100);

			setcolor(i==15?i=1:i+1);
			settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
			outtextxy(265,100,"Hola Mundo");

			mver();

			setbkcolor(i==1?BLACK:i);
			i++;

		}
	}while(!kbhit());

}
