#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<mouse.h>

int RealDrawColor(int color)
{
  if (getmaxcolor() > 256)
	 setrgbpalette(1024,(color>>10)&31,(color>>5)&31,color&31);
  return(color);
};

int WhitePixel()
{
  if (getmaxcolor() > 256)
	 return(32767);
  return(15);
}

int huge DetectVGA256()
{  /* 0 = 320x200x256  modo CGA  320(horizontal) con 200(vertical) pixeles(puntos) en 256colores
		1 = 640x400x256  modo ATT400
		2 = 640x480x256  modo VGA
		3 = 800x600x256  modo SVGA
		4 = 1024x768x256; modo XGA
		Todos son los modos graficos estandar  */
  return 4;
}

void main()
{		int modo = DETECT, tarj,TIPOLETRA;
		int color=0,x=180,y=50;
		
		/*Instalamos el driver SVGA.bgi para acceder a 256 colores*/
		installuserdriver("Svga256",DetectVGA256);

		/*Instalamos en nuestro proyecto el tipo de letra*/
		TIPOLETRA = installuserfont("LITT.CHR");
		/*Iniciamos el modo grafico*/
		initgraph(&modo,&tarj,"");

		setfillstyle(SOLID_FILL,WHITE);    /*elegimos el color de relleno para dibujar una barra*/
		bar(0 , 0, 1028, 768);             /*y asi simulamos que hemos elegido un color de fondo*/
		
		/*No se pueden utilizar los comandos cleardevice ni setbkcolor.*/
		/*setcolor(RealDrawColor(WhitePixel()));*/

		setcolor(7);
		while(color<256)
		{		rectangle(x ,y ,x + 40, y + 40);
				setfillstyle(SOLID_FILL,color);
				bar(x + 1, y + 1, x + 39, y + 39);
				x = x + 40;
				color++;
				if((color%16==0)&&(color!=0))
				{		x = 180;	y = y + 40;
				}
		}
		settextstyle(TIPOLETRA,0,9);  /*usamos el tipo de letra*/
		setcolor(41);   /*usamos el color numero 18, un gris oscuro*/
		outtextxy(40,10,"Prueba de Inicializacion del modo XGA 1024x768 pixeles");
		settextstyle(TIPOLETRA,0,6);
		setcolor(BLACK);
		outtextxy(12,690,"Como ves ahora si puedes usar el color negro en tus aplicaciones y usar una mayor resolucion: 1024x768");
		settextstyle(TIPOLETRA,0,7);
		setcolor(41);
		outtextxy(200,715,"Creado por: Grevin Silva");
		setcolor(55);
		outtextxy(425,740,"Granada - Nicaragua");
		/*delete &modo,&tarj,color,x,y,TIPOLETRA;*/ /*limpiamos la memoria*/

		gotoxy(2,2);printf("%d,%d",getmaxx(),getmaxy());
		mlimit(1,0,0,getmaxx(),getmaxy());
		mver();
		getch();
		closegraph();
}
