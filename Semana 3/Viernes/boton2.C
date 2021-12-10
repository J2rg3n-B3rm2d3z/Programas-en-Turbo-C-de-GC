#include <conio.h>  
#include <stdlib.h> 
#include <mouse.h>
#include <graphics.h> /*Esta es la librería que nos permite usar graficos.*/

void main()
{
 int gdriver=DETECT, gmode;
 initgraph(&gdriver,&gmode,"C:\\tc20\\bin");  /*Iniciamos el modo grafico.*/

 setbkcolor(12); /*  color de fondo */
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
    outtextxy(92,60,"boton");
 do
   {
    mver();
        if(minlimit(1,73,50,207,97)==1 && mclick()==1){
            setcolor(8);
            line(73,50,207,50);
            line(73,50,73,97);
            setcolor(15);
            line(73,97,207,97);
            line(207,50,207,97);
            settextstyle(2,0,7);
            outtextxy(250,280,"esto es lo unico que hace el boton :C con orgullo ");

        }
   }
 while(!kbhit());
 closegraph();

}
