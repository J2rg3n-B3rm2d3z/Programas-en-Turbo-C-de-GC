#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<process.h>

#define COLCURS 8
#define TAM_CURS 5

#define poner_cursor(x,y) dib_cursor(x,y);
#define borrar cursor(x,y) dib_cursor(x,y);

#define arriba 72
#define abajo 80
#define izquierda 75
#define derecha 77

void xor_pixel(int x, int y);
void dib_cursor(int x, int y);
void logo(void);

void main(void)
{
    char r;
	int adaptador=DETECT,modo,c=100,e=200;
	initgraph (&adaptador,&modo,"C:\\tc20\\bin");

	logo();

do{
	r=getch();
	 switch(r)
		{
			case arriba:
						dib_cursor(c, e);
						dib_cursor(c, e);
						e=e-16;
						dib_cursor(c,e);
						break;
						
			case abajo:
						dib_cursor(c, e);
						dib_cursor(c, e);
						e=e+16;
						dib_cursor(c, e);
						break;

			case derecha:
						dib_cursor(c, e);
						dib_cursor(c, e);
						c=c+16;
						dib_cursor(c, e);
						break;
						
			case izquierda:
						dib_cursor(c, e);
						dib_cursor(c, e);
						c=c-16;
						dib_cursor(c, e);
						break;
			default:    break;
		}
			if(r==27)
			exit(0);
  }while(r!=27);
getch();
}
/*Fin del programa principal*/

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
	setfillstyle(1,CYAN);
	bar(0,0,640,480);
		/* Barra de titulo */
	setfillstyle(1,CYAN);
	bar(0,0,640,480);
	setlinestyle(SOLID_LINE,1,2);
	setcolor(LIGHTGRAY);
	line(10,1,630,1);
	setcolor(WHITE);
	line(10,2,630,2);
	setcolor(LIGHTGRAY);
	line(10,3,630,3);
	setcolor(DARKGRAY);
	line(10,4,630,4);
	setfillstyle(1,BLUE);
	bar(11,5,629,20);

	/*Barra lateral izquierda */
	setcolor(LIGHTGRAY);
	line(10,2,10,470);
	setcolor(WHITE);
	line(11,3,11,469);
	setcolor(LIGHTGRAY);
	line(12,4,12,469);
	setcolor(DARKGRAY);
	line(13,4,13,467);

	/*Barra lateral derecha*/
	setcolor(LIGHTGRAY);
	line(628,5,628,467);
	setcolor(WHITE);
	line(629,4,629,469);
	setcolor(LIGHTGRAY);
	line(630,3,630,469);
	setcolor(DARKGRAY);
	line(631,2,631,470);

	/*Border inferior*/
	setcolor(LIGHTGRAY);
	line(14,467,627,467);
	setcolor(WHITE);
	line(13,468,628,468);
	setcolor(LIGHTGRAY);
	line(12,469,629,469);
	setcolor(DARKGRAY);
	line(11,470,630,470);

	/*Cuerpo*/
	setfillstyle(1,WHITE);
	bar(14,21,627,466);

	/*Dibujo payaso*/
	setcolor(BLACK);
	setfillstyle(1,RED);
	circle(320,240,45);
	floodfill(320,240,BLACK);

	/*Titulo*/
	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(33,9,"Cursor destructivo Acelerado  precione ESC para salir...");
}