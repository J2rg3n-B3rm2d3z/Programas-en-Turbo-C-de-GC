/*Un ejemplo clásico en el manejo gráfico es la generación de "ventanas", lo que permite realizar menús a
través de barras de selección corredizas. Por último, es posible realizar procedimiento para graficar señales.

Ej 11.3. Generación de Ventanas. Se pueden hacer en modo gráfico. La forma de hacer aparecer y desaparecer la
ventana (abrir y cerrar) es simple. Se debe almacenar el area en donde se va dibujar la ventana, luego se dibuja la
ventana y finalmente, para cerrar dicha ventana, se superpone al área almacenada previamente, sobre la ventana
dibujada.*/

#include <graphics.h>
#include <alloc.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

char far *dib_vent(int x1, int y1, int x2, int y2, int color_bk);
void borra_vent(int x1, int y1, char far *pvent);
void msg(int x,int y,char *mensaje, int color_msg);
int maxx, maxy;


void main(void)
{
char far *pvent;
int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode, "c:\\tc20\\bin"); /*inicia modo grafico */
cleardevice();

maxx=getmaxx();maxy=getmaxy();
setcolor(LIGHTGRAY);
rectangle(0,0,maxx,maxy);
msg(100,400,"<PRESIONE UNA TECLA>",GREEN);

getch();
pvent=dib_vent(0,0, 640,480,WHITE);
msg(100,400,"<PRESIONE UNA TECLA>", YELLOW);
getch();

if(pvent!=NULL) borra_vent(100,100,pvent);
msg(100,400,"<PRESIONE UN TECLA PARA SALIR>", RED);

getch();
closegraph();
}


char far *dib_vent(int x1, int y1, int x2, int y2, int color_bk)
{
char far *pvent;
unsigned tam;

tam = imagesize( x1, y1, x2, y2);
pvent=(char far *)farmalloc(tam);

if(pvent!=NULL)
{
  getimage(x1, y1, x2, y2, pvent);
  setfillstyle(1,color_bk);
  bar(x1,y1,x2,y2);
  setfillstyle(1,LIGHTBLUE);
  bar(x1+1,y1+1,x2-1,y1+15);
}
return(pvent);
}


void borra_vent(int x1, int y1, char far *pvent)
{
putimage(x1, y1,pvent ,COPY_PUT);
farfree(pvent);
}


void msg(int x,int y,char *mensaje, int color_msg)
{
int largo;
largo=strlen(mensaje);
setcolor(color_msg);
setfillstyle(1,BLACK);
bar(x,y,x+largo*8,y+8);
outtextxy(x,y,mensaje);
}