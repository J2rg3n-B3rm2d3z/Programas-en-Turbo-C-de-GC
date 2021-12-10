#include <alloc.h>
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <mouse.h>
#include <dos.h>
#include <16image.h>

#define NUMBOTON 3

void inicializar(void);

int boton(int x1,int y1,int x2,int y2, int *dibujado, char *texto);	/*Te dibuja un boton en las dimensiones dada
																	y se retorna 1 o 0 en caso de que se presione o no*/

void despla_menu(int x1,int y1,int x2,int y2, int *dibujado); /*Te dibuja un conjunto de opciones en las dimensiones dada
																			y se retorna 1 o 0 en caso de este activo o no*/

void main(void)
{
	
	int Salir=0,boolmostrar=-1; 								/*Variable boleana para salir del programa*/
	int Dboton[NUMBOTON];						/*Arreglo para el dibujo del boton*/
	int i=0;									/*Variable para reiniciar el arreglo anterior*/
	void far *Buffer = 0;
	
	for(i=0;i<NUMBOTON;i++)
	{
		Dboton[i]=0;
	}
	
	inicializar(); 								/*Inicio del modo grafico*/
	muestraBMP(0,0,"C:\\ImageC\\Fondo.bmp");	/*Cargar una imagen de fondo*/
	
	
	/*Dibujo de la barra de tareas*/
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	setcolor(WHITE);
	bar(0,getmaxy()-20,getmaxx(),getmaxy());
	line(0,getmaxy()-20,getmaxx(),getmaxy()-20);
	
	settextstyle(0,0,1);
	setcolor(15);

	
	
	mver();
	
	while(!Salir)
	{		

		if(boton(100,480-200,20,480-300,&Dboton[0],"Salir"))
		{
			Salir = 1;
		}
		/**/
		if(boton(10,getmaxy()-17,100,getmaxy()-2,&Dboton[1],"Menu"))
		{
			boolmostrar*=-1;
			
			if(boolmostrar==1)
			{	
				mocultar();
				
				Buffer=farmalloc(imagesize(10,getmaxy()-72,100,getmaxy()-22));
				
				getimage(10,getmaxy()-72,100,getmaxy()-22,Buffer);
				
				despla_menu(10,getmaxy()-72,100,getmaxy()-22, &Dboton[2]);
				
				mver();
				
				
			}
			else
			{
				mocultar();
				
				putimage(10,getmaxy()-72,Buffer,COPY_PUT);
				
				free(Buffer);
				
				Dboton[2]=0;
				
				mver();
			}
			
		}
		
	}
	
	closegraph();
}



void inicializar(void)
{
	int drive=DETECT,modo;
	initgraph(&drive,&modo,"c:\\tc20\\bin");
}

int boton(int x1,int y1,int x2,int y2, int *dibujado, char *texto)
{
	int Change; /*Variable para reordenar las coordenadas*/
	
	/*Se reordenan las coordenadas en caso de que esten mal dadas, debido a conflictos posteriores con mclick*/
	
	if(x1>x2)
	{
		Change=x1;
		x1=x2;
		x2=Change;
	}
	if(y1>y2)
	{
		
		Change=y1;
		y1=y2;
		y2=Change;
		
	}
	
	/*Se usa la variable dibujado para que solo se dibuje el boton una sola vez*/
	
	if(!(*dibujado))
	{
		
		mocultar();
		
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(x1,y1,x2,y2);
		rectangle(x1,y1,x2,y2);
		setcolor(BLACK);
		line(x2,y1,x2,y2);
		line(x1,y2,x2,y2);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		setcolor(BLACK);
		outtextxy(((x1+x2)/2),((y1+y2)/2),texto);
		setcolor(WHITE);
		outtextxy(((x1+x2)/2)+1,((y1+y2)/2)-1,texto);
		
		mver();
		
		*dibujado=1;
		
		/*Se modifica el valor dentro de puntero para cambiar la variable de origen y que de esta forma
		No vuelva a dibujarse inecesariamente*/
	}
	
	
	/*Se verifica el lugar y si se presiono el boton*/
	
	
	
	if(minlimit(1,x1,y1,x2,y2) && (mclick()==1))
	{
		/*Animacion de presion de boton*/
		
		mocultar();
		
		setfillstyle(SOLID_FILL,DARKGRAY);
		bar(x1+1,y1+1,x2-1,y2-1);

		setcolor(BLACK);
		outtextxy(((x1+x2)/2),((y1+y2)/2),texto);
		setcolor(WHITE);
		outtextxy(((x1+x2)/2)+1,((y1+y2)/2)-1,texto);
		
		delay(100);
		
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(x1+1,y1+1,x2-1,y2-1);
		
		
		setfillstyle(SOLID_FILL,BLACK);
		
		setcolor(BLACK);
		outtextxy(((x1+x2)/2),((y1+y2)/2),texto);
		setcolor(WHITE);
		outtextxy(((x1+x2)/2)+1,((y1+y2)/2)-1,texto);
		
		
		mver();	
		
		return 1;

	}
	else
	{
		return 0;
	}
}

void despla_menu(int x1,int y1,int x2,int y2, int *dibujado)
{
	
	int Change;
	
	if(x1>x2)
	{
		Change=x1;
		x1=x2;
		x2=Change;
	}
	if(y1>y2)
	{
		
		Change=y1;
		y1=y2;
		y2=Change;
		
	}
	
	if(!(*dibujado))
	{
		
		mocultar();
		
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		bar(x1,y1,x2,y2);
		rectangle(x1,y1,x2,y2);
		setcolor(BLACK);
		line(x2,y1,x2,y2);
		line(x1,y2,x2,y2);
		mver();
		
		*dibujado=1;
		
		/*Se modifica el valor dentro de puntero para cambiar la variable de origen y que de esta forma
		No vuelva a dibujarse inecesariamente*/
	}
}
