#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void main()
{
	int driver=DETECT,modo,i=1;
	initgraph(&driver,&modo,"c:\\tc20\\bin");

    /*setfillstyle(SOLID_FILL,3);
    bar(50,100,600,150);
    setfillstyle(SOLID_FILL,WHITE);
    bar3d(200,200,150,300,10,1);*/

    /*setcolor(WHITE);
    line(100,20,300,20);*/

    putpixel(25, 50, WHITE);
	putpixel(26, 50, WHITE);
	i=5;
    putpixel(27, 50, WHITE);

    /*setcolor(WHITE);
    rectangle(100,150,300,200);*/

    /*CIRCULO*/
    setcolor(WHITE);
	circle(300,250,100);
	circle(300,250,100);
    circle(300,250,100);

    getch();
	closegraph();

}