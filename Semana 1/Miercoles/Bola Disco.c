#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>
void InicioGrafico(void);
void Coloreado(int MitadAncho, int MitadAlto,int i);

void main()
{
	int i,MitadAncho,MitadAlto,lectura;
	
    InicioGrafico();/*Iniciar el modo grafico*/
	
	MitadAncho = getmaxx()/2;/*Obtencion de coordenadas del punto medio*/
	MitadAlto = getmaxy()/2;
	
	setcolor(15);
	
	/*Se dibuja la esfera*/
	
	circle(MitadAncho,MitadAlto,MitadAlto);
	
	line(MitadAncho,0,MitadAncho,MitadAlto*2);
	line(MitadAncho-MitadAlto,MitadAlto,MitadAncho+MitadAlto,MitadAlto);
	
	for(i=1;i<4;i++)
	{
		ellipse(MitadAncho,MitadAlto,90,-90,i*(MitadAlto/4),MitadAlto);
		ellipse(MitadAncho,MitadAlto,-90,90,i*(MitadAlto/4),MitadAlto);
		
		ellipse(MitadAncho,MitadAlto,90,-90,MitadAlto,i*(MitadAlto/4));
		ellipse(MitadAncho,MitadAlto,-90,90,MitadAlto,i*(MitadAlto/4));
	}
	
	
	/*Se entra en bucle para el cambio constante de color*/
	
	while(lectura!=27)
	{
		Coloreado(MitadAncho, MitadAlto,i);/*Se colorea*/
		
		while (kbhit()) 
        {
			lectura=getch();
		}			
		
		if(i!=11)
			i++;
		else
			i=0;
		
	}	
	/*getch();*/
    closegraph();
	
}

void InicioGrafico(void)
{
	int driver=DETECT,modo=DETECT;
	initgraph(&driver,&modo,"c:\\tc20\\bin");
	cleardevice();
}

void Coloreado(int MitadAncho, int MitadAlto, int i)
{
	
	setfillstyle(1,i+3);
	
	floodfill(MitadAncho-5,MitadAlto+5,15);
	floodfill(MitadAncho-5,MitadAlto+80,15);
	floodfill(MitadAncho-5,MitadAlto+130,15);
	floodfill(MitadAncho-5,MitadAlto+180,15);
	
	setfillstyle(1,i+2);
	
	floodfill(MitadAncho-(1*MitadAlto/4)-5,MitadAlto+5,15);
	floodfill(MitadAncho-(1*MitadAlto/4)-5,MitadAlto+80,15);
	floodfill(MitadAncho-(1*MitadAlto/4)-5,MitadAlto+130,15);
	floodfill(MitadAncho-(1*MitadAlto/4)-5,MitadAlto+180,15);
	
	setfillstyle(1,i+1);
	
	floodfill(MitadAncho-(3*MitadAlto/4)+5,MitadAlto+5,15);
	floodfill(MitadAncho-(3*MitadAlto/4)+50,MitadAlto+80,15);
	floodfill(MitadAncho-(3*MitadAlto/4)+50,MitadAlto+100,15);
	floodfill(MitadAncho-(3*MitadAlto/4)+50,MitadAlto+150,15);
	
	setfillstyle(1,i);
	
	floodfill(MitadAncho-MitadAlto+5,MitadAlto+5,15);
	floodfill(MitadAncho-MitadAlto+5,MitadAlto+15,15);
	floodfill(MitadAncho-MitadAlto+10,MitadAlto+35,15);
	floodfill(MitadAncho-MitadAlto+10,MitadAlto+60,15);
	
	
	
	setfillstyle(1,i+3);
	
	floodfill(MitadAncho+5,MitadAlto+5,15);
	floodfill(MitadAncho+5,MitadAlto+80,15);
	floodfill(MitadAncho+5,MitadAlto+130,15);
	floodfill(MitadAncho+5,MitadAlto+180,15);
	
	setfillstyle(1,i+2);

	floodfill(MitadAncho+(1*MitadAlto/4)+5,MitadAlto+5,15);
	floodfill(MitadAncho+(1*MitadAlto/4)+5,MitadAlto+80,15);
	floodfill(MitadAncho+(1*MitadAlto/4)+5,MitadAlto+130,15);
	floodfill(MitadAncho+(1*MitadAlto/4)+5,MitadAlto+180,15);
	
	setfillstyle(1,i+1);
	
	floodfill(MitadAncho+(3*MitadAlto/4)-5,MitadAlto+5,15);
	floodfill(MitadAncho+(3*MitadAlto/4)-50,MitadAlto+80,15);
	floodfill(MitadAncho+(3*MitadAlto/4)-50,MitadAlto+100,15);
	floodfill(MitadAncho+(3*MitadAlto/4)-50,MitadAlto+150,15);
	
	setfillstyle(1,i);
	
	floodfill(MitadAncho+MitadAlto-5,MitadAlto+5,15);
	floodfill(MitadAncho+MitadAlto-5,MitadAlto+15,15);
	floodfill(MitadAncho+MitadAlto-10,MitadAlto+35,15);
	floodfill(MitadAncho+MitadAlto-10,MitadAlto+60,15);
	
	
	
	setfillstyle(1,i+3);
	
	floodfill(MitadAncho+5,MitadAlto-5,15);
	floodfill(MitadAncho+5,MitadAlto-80,15);
	floodfill(MitadAncho+5,MitadAlto-130,15);
	floodfill(MitadAncho+5,MitadAlto-180,15);
	
	setfillstyle(1,i+2);

	floodfill(MitadAncho+(1*MitadAlto/4)+5,MitadAlto-5,15);
	floodfill(MitadAncho+(1*MitadAlto/4)+5,MitadAlto-80,15);
	floodfill(MitadAncho+(1*MitadAlto/4)+5,MitadAlto-130,15);
	floodfill(MitadAncho+(1*MitadAlto/4)+5,MitadAlto-180,15);
	
	setfillstyle(1,i+1);
	
	floodfill(MitadAncho+(3*MitadAlto/4)-5,MitadAlto-5,15);
	floodfill(MitadAncho+(3*MitadAlto/4)-50,MitadAlto-80,15);
	floodfill(MitadAncho+(3*MitadAlto/4)-50,MitadAlto-100,15);
	floodfill(MitadAncho+(3*MitadAlto/4)-50,MitadAlto-150,15);
	
	setfillstyle(1,i);
	
	floodfill(MitadAncho+MitadAlto-5,MitadAlto-5,15);
	floodfill(MitadAncho+MitadAlto-5,MitadAlto-15,15);
	floodfill(MitadAncho+MitadAlto-10,MitadAlto-35,15);
	floodfill(MitadAncho+MitadAlto-10,MitadAlto-60,15);
	
	
	
	setfillstyle(1,i+3);
	
	floodfill(MitadAncho-5,MitadAlto-5,15);
	floodfill(MitadAncho-5,MitadAlto-80,15);
	floodfill(MitadAncho-5,MitadAlto-130,15);
	floodfill(MitadAncho-5,MitadAlto-180,15);
	
	setfillstyle(1,i+2);
	
	floodfill(MitadAncho-(1*MitadAlto/4)-5,MitadAlto-5,15);
	floodfill(MitadAncho-(1*MitadAlto/4)-5,MitadAlto-80,15);
	floodfill(MitadAncho-(1*MitadAlto/4)-5,MitadAlto-130,15);
	floodfill(MitadAncho-(1*MitadAlto/4)-5,MitadAlto-180,15);
	
	setfillstyle(1,i+1);
	
	floodfill(MitadAncho-(3*MitadAlto/4)+5,MitadAlto-5,15);
	floodfill(MitadAncho-(3*MitadAlto/4)+50,MitadAlto-80,15);
	floodfill(MitadAncho-(3*MitadAlto/4)+50,MitadAlto-100,15);
	floodfill(MitadAncho-(3*MitadAlto/4)+50,MitadAlto-150,15);
	
	setfillstyle(1,i);
	
	floodfill(MitadAncho-MitadAlto+5,MitadAlto-5,15);
	floodfill(MitadAncho-MitadAlto+5,MitadAlto-15,15);
	floodfill(MitadAncho-MitadAlto+10,MitadAlto-35,15);
	floodfill(MitadAncho-MitadAlto+10,MitadAlto-60,15);
	
}
