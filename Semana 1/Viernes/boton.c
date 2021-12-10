#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<mouse.h>

void main()
{
	int adap=DETECT,modo;

	initgraph(&adap,&modo,"c://tc20//bin");
	setbkcolor(LIGHTGRAY);
	msituar(1,200,100);
	setfillstyle(1,9);
	bar(73,50,207,97);
	setcolor(15);
	line(73,50,207,50);
	line(73,50,73,97);
	setcolor(8);
	line(73,97,207,97);
	line(207,50,207,97);

	settextstyle(2,0,9);
    
	outtextxy(92,60,"BOTON");
	do{
		mver();
		if(minlimit(1,73,50,207,97)==1 && mclick()==1)
		{
			setcolor(8);
			line(73,50,207,50);
			line(73,50,73,97);
			setcolor(15);
			line(73,97,207,97);
			line(207,50,207,97);
			settextstyle(2,0,7);
			outtextxy(250,280,"Logro desbloqueado XD");                                                                                                                                                                                 

		}
	}while(!kbhit());

}
