#include <stdio.h>
#include <graphics.h>
#include <mouse.h>

void initialize_graphics();
void boton();
void pintar_boton(int presionado);
void main(void)
{
    initialize_graphics();

    setbkcolor(3);

    boton();

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

void boton()
{
    msituar(1,100,100);

    settextstyle(0,0,2);
    outtextxy(280,20,"Boton");

    
    
    pintar_boton(0);
    mver();
    
    do
    {
        if (minlimit(1, 220,60,450-15,100) == 1 && mclick() == 1)
        {
            mocultar();

            pintar_boton(1);
            mver();
            delay(150);
            mocultar();
            pintar_boton(0);
            mver();
        }

    } while (!kbhit());
}

void pintar_boton(int presionado)
{
    if(presionado)
    {
        setfillstyle(1,8);
            bar(220,60,450-15,100);

            settextstyle(0,0,2);
            settextjustify(CENTER_TEXT,CENTER_TEXT);
            setcolor(15);
            outtextxy(330,80,"Menu");

            setcolor(8);
            line(220,60,450-15,60);
            line(220,60,220,100);

            setcolor(15);
            line(220,100,450-15,100);
            line(450-15,60,450-15,100);

    }
    else
    {
        setfillstyle(1,7);
            bar(220,60,450-15,100);

            settextstyle(0,0,2);
            settextjustify(CENTER_TEXT,CENTER_TEXT);
            setcolor(15);
            outtextxy(330,80,"Menu");

            setcolor(15);
            line(220,60,450-15,60);
            line(220,60,220,100);

            setcolor(8);
            line(220,100,450-15,100);
            line(450-15,60,450-15,100);
    }
    
}