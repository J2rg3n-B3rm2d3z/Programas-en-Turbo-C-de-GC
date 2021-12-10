#include <stdio.h>
#include <graphics.h>
#include <mouse.h>
#include <conio.h>

#define true 1
#define false 0

void buttom(int bool, int x, int y);

main()
{
    int driver = DETECT, modo;
    initgraph(&driver, &modo, "");

    setfillstyle(SOLID_FILL, BLACK);
    bar(0, 0, getmaxx(), getmaxy());
    buttom(false,0,0);
    mver();

    while (!kbhit())
    {
        if (minlimit(1, 97, 52, 163, 77) == 1 && mclick() == 1)
        {
            mocultar();
            buttom(true,0,0);
            mver();
            delay(50);
            mocultar();
			buttom(false,0,0);
            buttom(true,100,0);
            buttom(false,100,100);
            mver();
        }
    }
    return 0;
}

void buttom(int bool, int x, int y)
{

    setfillstyle(SOLID_FILL, BLUE);
    bar(95 + x, 51 + y, 164 + x, 80 + y);
    setcolor(bool == false ? WHITE : BROWN);
    line(95 + x, 80 + y, 95 + x, 51 + y);
    line(95 + x, 51 + y, 164 + x, 51 + y);
    setcolor(bool == false ? BROWN : WHITE);
    line(164 + x, 51 + y, 164 + x, 80 + y);
    line(164 + x, 80 + y, 95 + x, 80 + y);
}