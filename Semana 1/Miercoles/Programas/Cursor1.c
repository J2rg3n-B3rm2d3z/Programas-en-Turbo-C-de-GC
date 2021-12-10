#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>

#define arriba 72
#define abajo 80
#define derecha 77
#define izquierda 75
#define NEGRO 0
#define BLANCO 15

#define PonerCursor(x,y) dib_cursor(x,y,BLANCO);
#define BorrarCursor(x,y) dib_cursor(x,y,NEGRO);
#define TAM_CURS 5

void dib_cursor(int x, int y, int color);
void logo(void);
void main()
{
	char c;
	int driver=DETECT,modo,n=100,b=200;
	initgraph(&driver,&modo,"C:\\tc20\\bin");
	logo();
	setbkcolor(DARKGRAY);
	do
	{
		c=getch();
		switch(c)
		{
		case arriba:
		dib_cursor(n,b,BLANCO);
		dib_cursor(n,b,NEGRO);
		b=b-1;
		dib_cursor(n,b,BLANCO);

		break;
		case abajo:
		dib_cursor(n, b,BLANCO);
		dib_cursor(n,b,NEGRO);
		b=b+1;
		dib_cursor(n,b,BLANCO);
		break;

		case derecha:
		dib_cursor(n, b, BLANCO);
		dib_cursor(n,b,NEGRO);
		n=n+1;
		dib_cursor(n, b, BLANCO);

		break;
		case izquierda:
		dib_cursor(n, b, BLANCO);
		dib_cursor(n,b,NEGRO);
		n=n-1;
		dib_cursor(n, b, BLANCO);

		break;
		
		default:
		break;
		}
		if(c==27)
		exit(0);
	}
	while(c!=27);
	
getch();
}

void dib_cursor(int x, int y, int color)
{
	int col_ant;
	col_ant= getcolor();
	setcolor(color);
	line(x- TAM_CURS, y, x + TAM_CURS, y);
	line(x, y - TAM_CURS, x, y + TAM_CURS);
	setcolor(col_ant);
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
	outtextxy(60,9,"Cursor destructivo no-Acelerado precione ESC para salir...");
}