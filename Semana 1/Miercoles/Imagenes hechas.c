#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main (void)
{
	
	int g_driver, g_mode;
	
	int Tri1[] = {40,400,640-40,400,320,100,40,400};
	int Tri2[] = {40+20,400-10,640-40-20,400-10,320,100+10,40+20,400-10};
	
	int Tri3[] = {40,50,640-40,50,320,420,40,50};
	int Tri4[] = {40+20,50+10,640-40-20,50+10,320,420-10,40+20,50+10};
	
	detectgraph(&g_driver,&g_mode);
	
	initgraph(&g_driver,&g_mode,"...\\bgi");
	
	cleardevice();
	
	setcolor(14);
	setfillstyle(1,14);
	
	drawpoly(4,Tri1);
	drawpoly(4,Tri2);
	floodfill(40+10,400-5,14);
	
	setcolor(15);
	setfillstyle(1,15);
	drawpoly(4,Tri3);
	drawpoly(4,Tri4);	
	floodfill(40+20,50+10-5,15);
	
	setcolor(1);
	
	line(0,getmaxy()/2,getmaxx()/2,0);
	line(getmaxx()/2,0,getmaxx(),getmaxy()/2);
	line(getmaxx(),getmaxy()/2,getmaxx()/2,getmaxy());
	line(getmaxx()/2,getmaxy(),0,getmaxy()/2);
	
	setcolor(2);
	line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	
	getch();
	
	closegraph();
	
}
