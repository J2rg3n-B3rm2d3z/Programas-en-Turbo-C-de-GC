#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void funcion(void);
void main()
{
    int driver=DETECT,modo;
	initgraph(&driver,&modo,"c:\\tc20\\bin");

    funcion();
    getch();
    closegraph();
}

void funcion(void)
{
    int edificio1[] = {0,310,0,278,24,278,24,310,0,310};

    int edif2[] = {2,277,2,271,30,271,30,308,25,308,25,277,2,277};

    int edif3[] = {5,271,5,227,15,227,15,220,25,220,25,204,28,204,28,220,38,220,38,227,50,227,50,252,31,252,31,271,5,271};

    int edif4[] = {31,252,74,252,74,278,49,278,49,310,31,310,31,252};

    int edif5[] = {49,310,49,278,75,278,75,275,77,275,77,278,81,278,81,310,49,310};

    int edif6[] = {81,310,81,278,88,278,88,275,89,275,89,271,90,271,90,260,93,260,93,271,94,271,94,275,96,275,96,278,112,278,112,310,81,310};

    int edif7[] = {100,278,100,209,103,209,103,206,131,206,131,208,133,208,142,213,142,253,117,253,117,310,112,310,112,278,100,278};

    int edif8[] = {116,310,116,253,154,253,154,256,133,256,133,274,130,274,130,310,116,310};

    int edif9[] = {133,274,133,256,163,256,171,263,171,265,145,265,145,274,133,274};

    int edif10[] = {144,274,144,265,174,265,174,274,144,274};

    int edif11[] = {130,310,130,274,175,274,175,270,220,270,220,310,130,310};

    fillpoly(5,edificio1);
    drawpoly(7,edif2);
    fillpoly(15,edif3);
    drawpoly(7,edif4);
    setfillstyle(HATCH_FILL,WHITE);
    fillpoly(9,edif5);
    drawpoly(17,edif6);
    fillpoly(14,edif7);
    drawpoly(9,edif8);
    drawpoly(8,edif9);
    fillpoly(5,edif10);
    drawpoly(7,edif11);
}