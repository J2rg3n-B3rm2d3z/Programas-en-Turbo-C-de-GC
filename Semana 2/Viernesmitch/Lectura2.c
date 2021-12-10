#include <alloc.h>
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <256image.h>
#include <16image.h>
#include <mouse.h>

void InicioGrafico();

void main()
{


InicioGrafico();

bar(0,0,getmaxx(),getmaxy());

mostrar_imagen(0,0,"C:\\1080.bmp",1);/*Copia la direcccion del fichero donde se guardo la imagen bmp*/
										/*Recuerde que el nombre del archivo tiene que tener menos de 8 caracteres*/
										/*En el ultimo parametro ubique 0 si quiere ver la paleta de colores original o
											1 si quiere ver la paleta de colores de la imagen
										*/
mver();

mlimit(1,0,0,getmaxx(),getmaxy());


getch();
closegraph();


}


int huge DetectVGA256()
{
	return 4;
}

void InicioGrafico()
{
	 int a=DETECT,b;
	 installuserdriver("Svga256",DetectVGA256);
	 initgraph(&a,&b,"c:\\tc20\\bin");
}
