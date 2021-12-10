#include <stdio.h>
#include <mouse.h>
#include <graphics.h>
#include <stdlib.h>

void initialize_graphics();
void boton();

void main(void){
	initialize_graphics();
    setbkcolor(8);
    boton();

    closegraph();
}

void initialize_graphics(){
	int driver = 0, mode, result;
    initgraph(&driver, &mode, "C://TC20//BIN");
    result = graphresult();

    if(result !=grOk){
        getch();
        exit(0);
    }
}

void boton(){
    msituar(1,100,100);

    settextstyle(0,0,2);
	outtextxy(280,20,"Boton");

    mver();

    do{
		if(minlimit(1, 220,60,450-15,100) == 1 && mclick() == 1){
			setfillstyle(1,8);
            bar(220,60,450-15,100);

            settextstyle(0,0,2);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			setcolor(9);
            outtextxy(330,80,"Menu");

            setcolor(7);
            line(220,60,450-15,60);
            line(220,60,220,100);

            setcolor(13);
            line(220,100,450-15,100);
            line(450-15,60,-450-15,100);

        }
        else{
            delay(130);
            setfillstyle(1,7);
            bar(220,60,450-15,100);

            settextstyle(0,0,2);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
            setcolor(15);
            outtextxy(330,80,"Menu");

            setcolor(14);
            line(220,100,450-15,100);
            line(450-15,60,450-15,100);

        }
    } while (!kbhit());

}

