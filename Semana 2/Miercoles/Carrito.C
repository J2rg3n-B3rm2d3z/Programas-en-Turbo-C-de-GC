#include <graphics.h>
#include <dos.h>
#include <alloc.h>

void main(void)
{

void *p;
int size,x=0,xx=0,gm,gd=DETECT;

initgraph(&gd,&gm,"c:\\tc20\\bin");

/*se pinta un coche carro*/

setfillstyle(1,2);
setcolor(2);
bar(0,75,45,90);
fillellipse(23,75,15,13);
setfillstyle(1,1);
setcolor(1);
fillellipse(35,93,7,7);
fillellipse(11,93,7,7);

size = imagesize(0,50,50,110);   /*se guarda la imagen*/
p=malloc(size); /*se reserva memoria para guardar la imagen*/
getimage(0,50,50,110,p);/*se obtiene la imagen*/
cleardevice();

setfillstyle(1,1);
bar(0,0,getmaxx(),getmaxy());

 for(x=1;x<=110;x++)
  {
   xx+=5;
   putimage(550-xx,0,p,COPY_PUT);
   putimage(550-xx,400,p,COPY_PUT);
   putimage(0+xx,300,p,COPY_PUT);
   putimage(550-xx,200,p,COPY_PUT);
   putimage(0+xx,100,p,COPY_PUT);
   delay(90);
   putimage(550-xx,200,p,XOR_PUT);
   putimage(0+xx,100,p,XOR_PUT);
   putimage(0+xx,300,p,XOR_PUT);
   putimage(550-xx,400,p,XOR_PUT);
   putimage(550-xx,0,p,XOR_PUT);

  }

cleardevice();
closegraph();
}