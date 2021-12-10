#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<mouse.h>

void main(void)
{
	int g_driver,g_mode,x,y,Salir;
	g_driver=DETECT;
	g_mode=DETECT;
	initgraph(&g_driver,&g_mode,"...\\bgi");
	
	mver();
	
	Salir=0;
	
	x=640/2;
	y=480;
	
	setcolor(15);
	
	while (Salir!=1)
	{
		
		if (mclick()==1)
		{
			
			x=mxpos(1);
			y=mypos(1);
			setcolor(15);
			mocultar();
			line(640/2,480,x,y);
			delay(50);
			setcolor(0);
			line(640/2,480,x,y);
			mver();			
			delay(100);
		}
		
		setcolor(15);
		rectangle(60,60,70,70);

		
		if (minlimit(1,60,60,70,70)==1 &&(mclick()==1))
			Salir=1;
		
		
	}
	closegraph();
}
