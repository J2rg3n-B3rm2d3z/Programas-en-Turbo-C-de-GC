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
int Bolboton(int x1, int x2, int y1, int y2, int c, int e);

void main(void)
{
	char r;
	int adapter=DETECT,modo,c=100,e=200,bolInicio=1,Movimientos=0;
	char Mensaje[35];
	initgraph (&adapter,&modo,"C:\\tc20\\bin");

logo();

do{
	
	r=getch();
	switch(r)
	{
		case arriba:
		dib_cursor(c, e);
		dib_cursor(c, e);
		e=e-10;
		dib_cursor(c,e);
		
		if(!bolInicio)
		dib_cursor(c,e+10);
		else
		bolInicio=0;
		
		Movimientos++;
		
		break;
		case abajo:
		dib_cursor(c, e);
		dib_cursor(c, e);
		e=e+10;
		dib_cursor(c, e);
		
		if(!bolInicio)
		dib_cursor(c,e-10);
		else
		bolInicio=0;
		
		Movimientos++;
		
		break;

		case derecha:
		dib_cursor(c, e);
		dib_cursor(c, e);
		c=c+10;
		dib_cursor(c, e);
		
		if(!bolInicio)
		dib_cursor(c-10,e);
		else
		bolInicio=0;
		
		Movimientos++;
		
		break;
		case izquierda:
		dib_cursor(c, e);
		dib_cursor(c, e);
		c=c-10;
		dib_cursor(c, e);
		
		if(!bolInicio)
		dib_cursor(c+10,e);
		else
		bolInicio=0;
		
		Movimientos++;
		
		break;
		
		default: 
		outtextxy(5,5,"Cursor no destructivo");
		outtextxy(5,20,"presione Esc para salir");
		break;
	}
	
	
	
	if(Bolboton(150,250,200,300, c,e) && r==13)
	{
		sprintf(Mensaje,"Usted se movio %d veces.",Movimientos);
		outtextxy(c,e,Mensaje);
		
		delay(1500);
		
		exit(0);
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
	
	setcolor(6);
	
	rectangle(150,250,200,300);
	
	setcolor(BLUE);
	
}

int Bolboton(int x1, int y1, int x2, int y2, int c, int e)
{
		if(c>x1 && c<x2 && e>y1 && e<y2)
			return 1;
		else
			return 0;
}
