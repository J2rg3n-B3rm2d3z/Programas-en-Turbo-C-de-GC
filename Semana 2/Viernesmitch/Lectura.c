#include <alloc.h>
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <256image.h>
#include <16image.h>
#include <mouse.h>


void main()
{


int gd , gm ;

gd = 0; gm = 0;
initgraph(&gd,&gm,"");


muestraBMP(0,0,"C:\\ImageC\\Wave1.bmp");/*Copia la direcccion del fichero donde se guardo la imagen bmp*/
										/*Recuerde que el nombre del archivo tiene que tener menos de 8 caracteres
										*/

mver();

mlimit(1,0,0,getmaxx(),getmaxy());


getch();
closegraph();


}

