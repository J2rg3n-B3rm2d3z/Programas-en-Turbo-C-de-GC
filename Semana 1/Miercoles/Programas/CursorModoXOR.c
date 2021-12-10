#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<process.h>

#define arriba 72
#define abajo 80
#define izquierda 75
#define derecha 77
#define COLCURS 8
#define TAM_CURS 5

#define poner_cursor(x,y) dib_cursor(x,y);
#define borrar cursor(x,y) dib_cursor(x,y);

void xor_pixel(int x, int y);
void dib_cursor(int x, int y);
void logo(void);

void main(void)
{
	char r;
	int adapter=DETECT,modo,c=100,e=200;
	initgraph (&adapter,&modo,"C:\\tc20\\bin");

logo();

do{
	r=getch();
	switch(r)
	{
		case arriba:
		dib_cursor(c, e);
		dib_cursor(c, e);
		e=e-1;
		dib_cursor(c,e);

		break;
		case abajo:
		dib_cursor(c, e);
		dib_cursor(c, e);
		e=e+1;
		dib_cursor(c, e);
		break;

		case derecha:
		dib_cursor(c, e);
		dib_cursor(c, e);
		c=c+1;
		dib_cursor(c, e);

		break;
		case izquierda:
		dib_cursor(c, e);
		dib_cursor(c, e);
		c=c-1;
		dib_cursor(c, e);

		break;
		default: 
		outtextxy(5,5,"Cursor no destructivo");
		outtextxy(5,20,"presione Esc para salir");
		break;
	}
	if(r==27)
	exit(0);
	}
 while(r!=27);
getch();
}
void dib_cursor(int x, int y)
{
int i;
	for (i=0; i<TAM_CURS; i++)
	{
		xor_pixel(x-i,y);
		xor_pixel(x+i,y);
		xor_pixel(x,y-i);
		xor_pixel(x,y+i);
	}
	xor_pixel(x,y);
}

void xor_pixel(int x, int y)
{
	putpixel(x,y,COLCURS^getpixel(x,y));
}

void logo(void)
{
	/*Cuerpo*/
	setfillstyle(1,WHITE);
	bar(15,15,635,475);

	/*Dibujo circulo*/
	setcolor(BLACK);
	setfillstyle(1,RED);
	circle(320,240,45);
	floodfill(320,240,BLACK);

	/*Titulo*/
	setcolor(BLUE);
	settextstyle(2,0,6);
	/*outtextxy(60,9,"Cursor destructivo Acelerado  presione ESC para salir...");*/
}