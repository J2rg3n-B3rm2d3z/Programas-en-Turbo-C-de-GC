#include <alloc.h>
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <mouse.h>
#include <dos.h>
#include <16image.h>
#include <ctype.h>
#include <string.h>

#define NUMBOTON 4
#define MAXCHAR 50

void inicializar(void);

int boton(int x1,int y1,int x2,int y2, int *dibujado, char *texto, int dibujar);	/*Te dibuja un boton en las dimensiones dada
																	y se retorna 1 o 0 en caso de que se presione o no*/

void despla_menu(int x1,int y1,int x2,int y2, int *dibujado); /*Te dibuja un conjunto de opciones en las dimensiones dada
																			y se retorna 1 o 0 en caso de este activo o no*/

char obte1(void);
int ObteDireccion(int x,int y);
char Direccion[MAXCHAR]="C:\\ImageC\\Fondos\\Avalon.bmp";

void main(void)
{
	
	int Salir=0,boolmostrar=0,SelecMenu=0,boolChangeBack=0;
	char DireccionUso[MAXCHAR];
	int Dboton[NUMBOTON];						/*Arreglo para el dibujo de los botones*/
	int i=0;									/*Variable para reiniciar el arreglo anterior*/
	void far *Buffer = 0;						/*Puntero para la lectura del rasterop*/
	
	inicializar(); 								/*Inicio del modo grafico*/
	
	strcpy(DireccionUso,Direccion);				/*Se copia la direccion preedeterminada global a la variable declarada anteriormente*/
	
	while(!Salir)
	{
		cleardevice();
		
		for(i=0;i<NUMBOTON;i++)
		{
			Dboton[i]=0;
		}
	
		muestraBMP(0,0,Direccion);	/*Cargar una imagen de fondo*/
		
		
		/*Dibujo de la barra de tareas*/
		
		setfillstyle(SOLID_FILL,LIGHTGRAY);
		setcolor(WHITE);
		bar(0,getmaxy()-20,getmaxx(),getmaxy());
		line(0,getmaxy()-20,getmaxx(),getmaxy()-20);
		
		/*Dejar las propiedades predeterminadas*/
		
		settextstyle(0,0,1);
		setcolor(15);
		boolChangeBack=0;
		mver();
		
		while(!boolChangeBack)
		{		
			/*Para capturar teclas que se presiona incesesariamente y que no queden guardado en la memoria*/
			
			while(kbhit())
			{
				getch();
			}
			
			/*Boton para salir del programa*/
			
			if(boton(getmaxx()-100,getmaxy()-17,getmaxx()-10,getmaxy()-2,&Dboton[0],"Salir",1))
			{
				Salir = 1;
				boolChangeBack = 1;
			}
			
			/*Boton para abrir el menu*/
			
			if(boton(10,getmaxy()-17,100,getmaxy()-2,&Dboton[1],"Menu",1))
			{
				
				
				if(boolmostrar==0)
				{	
					/*Si se presiona una vez se guarda el fondo y se dibuja el menu*/
					
					mocultar();
					
					Buffer=farmalloc(imagesize(10,getmaxy()-74,130,getmaxy()-22));
					
					getimage(10,getmaxy()-74,130,getmaxy()-22, Buffer);
					
					despla_menu(10,getmaxy()-74,130,getmaxy()-22, &Dboton[2]);
					
					
					
					/*Se Pone en texto la informacion necesaria*/
					settextjustify(LEFT_TEXT,CENTER_TEXT);
					
					setcolor(BLACK);
					outtextxy(14,((getmaxy()-73+getmaxy()-48)/2)+2,"Cambiar Fondo");
					setcolor(WHITE);
					outtextxy(14+1,((getmaxy()-73+getmaxy()-48)/2)+2-1,"Cambiar Fondo");
					
					
					setcolor(BLACK);
					outtextxy(14,((getmaxy()-47+getmaxy()-24)/2)+2,"Mostrar Imagen");
					setcolor(WHITE);
					outtextxy(14+1,((getmaxy()-47+getmaxy()-24)/2)+2-1,"Mostrar Imagen");
					
					mver();
					
					boolmostrar=1;
				}
				else
				{
					/*Si se presiona de nuevo se oculta*/
					
					mocultar();
					
					putimage(10,getmaxy()-74,Buffer,COPY_PUT);
					
					free(Buffer);
					
					Dboton[2]=0; /*Se reinicia la variable para que pueda ser dibujado de nuevo*/
					
					SelecMenu=0;
					boolmostrar=0;
					mver();
				}
				
			}
			
			/*Variable en caso que el menu este abierto*/
			
			if(boolmostrar==1)
			{
				
				if(minlimit(1,11,getmaxy()-73,129,getmaxy()-48) && SelecMenu!=1)
				{
					SelecMenu=1;
					Dboton[3]=1;
				}
				
				if(minlimit(1,11,getmaxy()-47,129,getmaxy()-24) && SelecMenu!=2)
				{
					SelecMenu=2;
					Dboton[3]=1;
				}
				
				if(Dboton[3])
				{
					if(SelecMenu==1)
					{
						mocultar();
						setfillstyle(SOLID_FILL,BLUE);
						bar(11,getmaxy()-73,129,getmaxy()-48);
						setcolor(BLACK);
						outtextxy(14,((getmaxy()-73+getmaxy()-48)/2)+2,"Cambiar Fondo");
						setcolor(WHITE);
						outtextxy(14+1,((getmaxy()-73+getmaxy()-48)/2)+2-1,"Cambiar Fondo");
						mver();
						
					}
					else
					{
						mocultar();
						setfillstyle(SOLID_FILL,LIGHTGRAY);
						bar(11,getmaxy()-73,129,getmaxy()-48);
						setcolor(BLACK);
						outtextxy(14,((getmaxy()-73+getmaxy()-48)/2)+2,"Cambiar Fondo");
						setcolor(WHITE);
						outtextxy(14+1,((getmaxy()-73+getmaxy()-48)/2)+2-1,"Cambiar Fondo");
						mver();
						
						
					}
					
					if(SelecMenu==2)
					{
						mocultar();
						setfillstyle(SOLID_FILL,BLUE);
						bar(11,getmaxy()-47,129,getmaxy()-24);
						setcolor(BLACK);
						outtextxy(14,((getmaxy()-47+getmaxy()-24)/2)+2,"Mostrar Imagen");
						setcolor(WHITE);
						outtextxy(14+1,((getmaxy()-47+getmaxy()-24)/2)+2-1,"Mostrar Imagen");
						mver();
						
					}
					else
					{
						mocultar();
						setfillstyle(SOLID_FILL,LIGHTGRAY);
						bar(11,getmaxy()-47,129,getmaxy()-24);
						setcolor(BLACK);
						outtextxy(14,((getmaxy()-47+getmaxy()-24)/2)+2,"Mostrar Imagen");
						setcolor(WHITE);
						outtextxy(14+1,((getmaxy()-47+getmaxy()-24)/2)+2-1,"Mostrar Imagen");
						mver();
					}
					
					Dboton[3]=0;
				}
				
				
				if(boton(11,getmaxy()-73,129,getmaxy()-48,NULL,"",0))
				{
					mocultar();
					putimage(10,getmaxy()-74,Buffer,COPY_PUT);
					free(Buffer);
					mver();
					
					Buffer=farmalloc(imagesize(15-5-2,getmaxy()-47-20-30,15+400+2,getmaxy()-47+20+2));
					mocultar();
					getimage(15-5-2,getmaxy()-47-20-30,15+400+2,getmaxy()-47+20+2, Buffer);
					
					
					if(ObteDireccion(15,getmaxy()-47))
					{
						strcpy(DireccionUso,Direccion);
						boolChangeBack=1;
						putimage(15-5-2,getmaxy()-47-20-30,Buffer,COPY_PUT);
						free(Buffer);
					}
					else
					{
						putimage(15-5-2,getmaxy()-47-20-30,Buffer,COPY_PUT);
						free(Buffer);
						mver();
						
					}
					
					boolmostrar=0;
					SelecMenu=0;
					Dboton[2]=0;
					
				}
				
				if(boton(11,getmaxy()-47,129,getmaxy()-24,NULL,"",0))
				{
					
					mocultar();
					putimage(10,getmaxy()-74,Buffer,COPY_PUT);
					free(Buffer);
					mver();
					
					boolmostrar=0;
					SelecMenu=0;
					Dboton[2]=0;
				}
				
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

int boton(int x1,int y1,int x2,int y2, int *dibujado, char *texto, int dibujar)
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
	
	if(dibujar)
	{
		
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
			outtextxy(((x1+x2)/2),((y1+y2)/2)+2,texto);
			setcolor(WHITE);
			outtextxy(((x1+x2)/2)+1,((y1+y2)/2)+2-1,texto);
			
			mver();
			
			*dibujado=1;
			
			/*Se modifica el valor dentro de puntero para cambiar la variable de origen y que de esta forma
			No vuelva a dibujarse inecesariamente*/
		}
	}
	
	/*Se verifica el lugar y si se presiono el boton*/
	
	
	
	if(minlimit(1,x1,y1,x2,y2) && (mclick()==1))
	{
		/*Animacion de presion de boton*/
		
		if(dibujar)
		{
			mocultar();
			
			setfillstyle(SOLID_FILL,DARKGRAY);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			bar(x1+1,y1+1,x2-1,y2-1);

			setcolor(BLACK);
			outtextxy(((x1+x2)/2),((y1+y2)/2)+2,texto);
			setcolor(WHITE);
			outtextxy(((x1+x2)/2)+1,((y1+y2)/2)+2-1,texto);
			
			delay(100);
			
			setfillstyle(SOLID_FILL,LIGHTGRAY);
			bar(x1+1,y1+1,x2-1,y2-1);
			
			
			setfillstyle(SOLID_FILL,BLACK);
			
			setcolor(BLACK);
			outtextxy(((x1+x2)/2),((y1+y2)/2)+2,texto);
			setcolor(WHITE);
			outtextxy(((x1+x2)/2)+1,((y1+y2)/2)+2-1,texto);
			
			
			mver();	
		}
		
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

char obte1()
{
	char a, b;
	
	fflush(stdin);
	
	a=getch();
	
	if(a==0)
	{
		b=getch();
	}
	
	return a;
	
}

int ObteDireccion(int x, int y)
{
	int Lector,i,largo,bolretorno;
	char Temporal[MAXCHAR];
	fflush(stdin);
	Temporal[0]='\0';
	largo=MAXCHAR-1;
	
	bolretorno=0;
	i=0;
	
	
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(x-5-2,y-20-30,x+400+2,y+20+2);
	setcolor(WHITE);
	rectangle(x-5-2,y-20-30,x+400+2,y+20+2);
	setcolor(BLACK);
	line(x+400+2,y-20-30,x+400+2,y+20+2);
	line(x-5-2,y+20+2,x+400+2,y+20+2);
	
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	settextjustify(LEFT_TEXT,CENTER_TEXT);
	setcolor(BLACK);
	outtextxy(x-2,y-20-15+2,"Escriba el directorio de la imagen. Salir(ESC)");
	setcolor(WHITE);
	outtextxy(x-2+1,y-20-15+2-1,"Escriba el directorio de la imagen. Salir(ESC)");
	
	setfillstyle(SOLID_FILL,BLACK);
	bar(x-5,y-20,x+400,y+20);
	
	
	/*
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setcolor(15);
	outtextxy((640/2),(480/2)-100,"Ingrese su nombre");*/
	
	
	while ((bolretorno==0)||(Direccion[0]==NULL))
	{
		
		Lector=obte1();
		
		
		if(Lector==27)
		{
			
			memset(Direccion,'\0',largo);
			return 0;
			
		}
		
		if((65<=Lector && 90>=Lector ) ||(97<=Lector && 122>=Lector )||isgraph(Lector))
		{
			if(i<largo)
			{
				settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
				settextjustify(LEFT_TEXT,CENTER_TEXT);
				setcolor(0);
				mocultar();
				outtextxy(x,y,Temporal);
				mver();
				
				Temporal[i]=Lector;
				Temporal[i+1]='\0';
				
				settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
				settextjustify(LEFT_TEXT,CENTER_TEXT);
				
				setcolor(15);
				mocultar();
				outtextxy(x,y,Temporal);
				mver();
				
				Direccion[i]=Lector;
				i++;
				
			}
			bolretorno=0;
		}
		if (Lector==8)
		{
			if(i>0)
			{
				settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
				settextjustify(LEFT_TEXT,CENTER_TEXT);
				setcolor(0);
				mocultar();
				outtextxy(x,y,Temporal);
				mver();
				
				
				Temporal[i-1]='\0';
				
				settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
				settextjustify(LEFT_TEXT,CENTER_TEXT);
				setcolor(15);
				mocultar();
				outtextxy(x,y,Temporal);
				mver();
			
				Direccion[i-1]=NULL;
				
				i--;
			}
			bolretorno=0;
		}
		if (Lector==13)
		{	
				Direccion[i]='\0';
				bolretorno=1;
				
				return 1;
			
		}
		
		/*fflush(stdin);*/
	}

}