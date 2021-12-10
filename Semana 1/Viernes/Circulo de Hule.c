/**********Figuras de Hule************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>

#define ARRIBA      72
#define ABAJO       80
#define DER         75
#define IZQ         77
#define ENTER       13

int leercar(void);
void CirculoDeHule(int x,int y,int radio);



void main()
	{

		int adap=DETECT,mode;
		initgraph(&adap,&mode,"c:\\TC20\\BIN ");

	setbkcolor(LIGHTGRAY);
	CirculoDeHule(getmaxx()/2,getmaxy()/2,30);

	closegraph();
	exit(0);
	}

/****Funcion leer caracter********/

int leercar()
{
	int tecla;
	while((tecla=getch())!=0)
	if(tecla==ENTER)
	return(tecla);
	return(getch());
}

/************ Circulo de Hule********/

void CirculoDeHule(int x,int y,int radio)
	{
		int direccion,caracter;
	   do
	    {
			setcolor(RED);
			circle(x,y,abs(radio));
			direccion=0;

			switch(caracter=leercar())
			{
				case ARRIBA:
					direccion++;
					break;
				case ABAJO:
					direccion--;
					break;
				case DER:
					direccion++;
					break;
				case IZQ:
					direccion--;
					break;
			}
			setcolor(0);
			circle(x,y,abs(radio));
			radio+=direccion;

	    }while(direccion);

	radio=abs(radio);
	return(caracter);

	}

