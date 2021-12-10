#include <stdio.h>
#include <graphics.h>
#include <mouse.h>
#include <dos.h>
/*#define n 2*/

void initialize_graphics();
void desplay_menu();
void buttoms();
int button(int x1, int y1, int x2, int y2, char *name, int x, int y);
void click_button(int x1, int y1, int x2, int y2, int col1, int col2, int col3);

void main(void)
{
    initialize_graphics();

    setbkcolor(3);

    buttoms();

    closegraph();
}

void initialize_graphics()
{
    int driver = 0, mode, result;

    initgraph(&driver, &mode, "C://TC20//BIN");

    result = graphresult();

    if (result != grOk)
    {
        getch();
        exit(0);
    }
}

void buttoms()
{
    int finish = 0;
    int i = 0;
    /*int numbutton[n];*/

    msituar(1,100,100);

    settextstyle(0,0,2);
    outtextxy(280,20,"Boton");

    mver();

    do
    {
        if(button(220, 250, 435, 300,"Salir", 327, 275))
        {
            finish = 1;
        }

        if (button(220, 60, 450-15, 100,"Menu", 330, 80))
        {
            desplay_menu(220,100,435,200,8,8,15);
        }

	} while (!finish);
}

int button(int x1, int y1, int x2, int y2, char *name, int x, int y)
{

    /*mocultar();*/

    setfillstyle(1,7);
    bar(x1,y1,x2,y2);

    settextstyle(0,0,2);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    setcolor(15);
    outtextxy(x,y,name);

    setcolor(15);
    line(x1,y1,x2,y1);
    line(x1,y1,x1,y2);

    setcolor(8);
    line(x1,y2,x2,y2);
    line(x2,y1,x2,y2);

    /*mver();*/

    if (minlimit(1, x1,y1,x2,y2) == 1 && mclick() == 1)
    {
        mocultar();
        delay(100);
        click_button(x1,y1,x2,y2,8,8,15);
        mver();

		return 1;
    }
    else
    {
		return 0;
    }

}

void click_button(int x1, int y1, int x2, int y2, int col1, int col2, int col3)
{

    /* Se pinta la barra de otro color para simular resaltado*/
    setfillstyle(1,col1);
    bar(x1,y1,x2,y2);

    /* Los bordes del lado superior del boton se pintan en plomo oscuro para darle el efecto de presionado*/
    setcolor(col2);
    line(x1,y1,x2,y2);
    line(x1,y1,x1,y2);

    setcolor(col3);
    line(x1,y2,x1,y2);
    line(x2,y1,x2,y2);
}

void desplay_menu(int x1, int y1, int x2, int y2, int col1, int col2, int col3)
{
    setfillstyle(1,col1);
    bar(x1,y1,x2,y2);

	setcolor(col2);
    rectangle(x1,y1,x2,y2);

    setcolor(col3);
	line(x1,y1,x2,y1);
	line(x2,y1,x2,y2);
}