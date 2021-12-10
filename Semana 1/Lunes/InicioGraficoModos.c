#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main (void)
{
	
	int g_driver, g_mode, i, Gresult;
	
	
	g_driver=DETECT;
	g_mode=DETECT;
	
	/*detectgraph(&g_driver,&g_mode);*/
	
	initgraph(&g_driver,&g_mode,"...\\bgi");
	
	Gresult = graphresult();
	
	if(Gresult != grOk)
    {

              printf(grapherrormsg(Gresult));

              getch();


    }
	else
	{
		cleardevice();
		
		for(i=0;i<16;i++)
		{
			setfillstyle(1,i);
			bar(0+(i*40),0,40+(i*40),480);
			
		}
		
		setcolor(15);
		
		circle(40,240,5);
		
		getch();
		
		
		closegraph();
	}
}
