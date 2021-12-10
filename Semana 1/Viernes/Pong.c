#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<mouse.h>
#include<time.h>
#include<math.h>
#include<dos.h>
#include<recursos.h>
#define MAXNOM 12

/*Codigo hecho por Jurgen Francisco Bermudez Picado 1M1-CO 2020*/

/*Variables globales*/

int bolExit[3];
int bolVentana=0;
int i,bolMSelec[2];

char Nombre[MAXNOM];


/*Estructura*/

struct Rectangule
{
	int X1;
	int Y1;
	int X2;
	int Y2;
};

struct Top
{
	char Name[MAXNOM];
	int TopScore;

	
};

/*Funciones de tiempo*/

char *HoraFecha(void);

int Minutos(void);

/*Funcion para mostrar menu*/

void Menu(void);
	
/*Funciones para ejecucion de las opciones*/

void Presentacion(void);

/*Funcion para Juego*/

void Juego (void);

/*Funcion para Jugar*/

void Jugar (int Dificultad);

void Modo (void);

void Nombres(void);

void Equis(int Color1,int Color2);

char obte1(void);

/*Funcion para los registros*/

void Ayuda (void);

void Puntajes (void);

void Registros (void);

void main(void)
{

	int g_driver,g_mode;
	
	int Salir,Lectura,min,ocultar;
	
	int bolFondo,bolFecha,bolBoton;
	
	int bolMenu,bolMenuMostrar;

	int SeleccionM;
	
	float TraSound;
	
	char*Start;
	
	Salir = 0;
	bolExit[0]=bolExit[1]=bolExit[2]=0;
	min=0;
	bolFondo = 0 ;
	bolFecha = 0 ;
	bolBoton = 0 ;
	
	bolMenu = 0;
	bolMenuMostrar = 0;
	
	SeleccionM = 0;
	Lectura=0;
	
	if(!bolVentana)
	{
		/*Logo();
		Carga();*/
	}
	
	for(i=0;i<2;i++)
	{	
		bolMSelec[i]=0;
	}

	g_driver=DETECT;
	g_mode=DETECT;
	
	if(!bolVentana)
	{
		initgraph(&g_driver,&g_mode,"...\\bgi");
		bolVentana=1;
	}
	
	/*Interface*/
	
	/*Resolucion=640x480*/
		
	mver();
	
	while (Salir==0)
	{
		
		/*Fondo*/
		bolExit[0]=bolExit[1]=bolExit[2]=0;
		
		if (!bolFondo)
		{
			
			mocultar();
			
			/*Barra de tareas*/
			
			setfillstyle(SOLID_FILL,7);
			bar(0,480-30,640,480);
			
			setcolor(0);
			line(0,480-30,640,480-30);
			setcolor(15);
			line(0,480-29,640,480-29);
			setcolor(15);
			line(1,480-29,1,480);
			
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			settextjustify(LEFT_TEXT,TOP_TEXT);
			
			setcolor(0);
			outtextxy(24,480-17,"S T A R T");
			setcolor(15);
			outtextxy(25,480-18,"S T A R T");
			setcolor(15);
			
			
			/*Fondo Para fuera de servicio*/
			
			setfillstyle(SOLID_FILL,15);
			bar(0,0,92,350);
			setfillstyle(SOLID_FILL,14);
			bar(92,0,92*2,350);
			setfillstyle(SOLID_FILL,3);
			bar(92*2,0,92*3,350);
			setfillstyle(SOLID_FILL,2);
			bar(92*3,0,92*4,350);
			setfillstyle(SOLID_FILL,5);
			bar(92*4,0,92*5,350);
			setfillstyle(SOLID_FILL,4);
			bar(92*5,0,92*6,350);
			setfillstyle(SOLID_FILL,1);
			bar(92*6,0,92*7,350);
			
			setfillstyle(SOLID_FILL,9);
			bar(0,351,92,370);
			setfillstyle(SOLID_FILL,5);
			bar(92*2,351,92*3,370);
			setfillstyle(SOLID_FILL,11);
			bar(92*4,351,92*5,370);
			setfillstyle(SOLID_FILL,7);
			bar(92*6,351,92*7,370);
			
			setfillstyle(SOLID_FILL,1);
			bar(0,370,106,449);
			setfillstyle(SOLID_FILL,15);
			bar(106,370,106*2,449);
			setfillstyle(SOLID_FILL,1);
			bar(106*2,370,106*3,449);
			
			
			
			
			settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			setcolor(0);
			outtextxy((640/2),100,"FUERA DE SERVICIO");
			setcolor(15);
			outtextxy((640/2)+3,100+3,"FUERA DE SERVICIO");
			settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			setcolor(0);
			
			Start=(char*) calloc(15,sizeof(char));
			memset(Start,0,15);
			sprintf(Start,"%c PULSA START %c",25,25);
			outtextxy((640/2),200,Start);
			setcolor(15);
			outtextxy((640/2)+3,200+3,Start);
			
			free(Start);
			mver();
			bolFondo=1;
			
		}
		
		/*Fecha*/
		
		if (!bolFecha)
		{
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			settextjustify(LEFT_TEXT,TOP_TEXT);
			mocultar();
			setcolor(0);
			Start=(char*) calloc(26,sizeof(char));
			memset(Start,0,26);
			strcpy(Start,HoraFecha());
			Start[strlen(Start)-1]='\0';
			outtextxy((640/2)+99,480-17,Start);
			setcolor(15);
			outtextxy((640/2)+100,480-18,Start);
			setfillstyle(SOLID_FILL,7);
			bar((640/2)+227,480-28,640-65,480);
			mver();
			
			bolFecha=1;
		}

		while(kbhit())
		{
			Lectura=getch();

		}

		/*Boton 1*/
		
		if(!bolBoton)
		{
			mocultar();
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			settextjustify(LEFT_TEXT,TOP_TEXT);

			setcolor(0);
			outtextxy(24,480-17,"S T A R T");
			setcolor(15);
			outtextxy(25,480-18,"S T A R T");
			
			setcolor(15);
			line(18,480-18-6,18,480-18+12);
			setcolor(15);
			line(18,480-18-6,18+83,480-18-6);
			setcolor(0);
			line(18+83,480-18-6,18+83,480-18+12);
			setcolor(0);
			line(18+83,480-18+12,18,480-18+12);
			
			mver();
			bolBoton=1;
			
		}
		
		if(mclick())
		{
			if(bolMenu)
			{
				if(minlimit(1,19,370,19+103,370+26))
				{
					sound(207.65);
					delay(25);
					nosound();
					delay(25);
					sound(277.18);
					delay(25);
					nosound();
					
					if (bolMenu==1)
					{
						bolMenu=0;
						mocultar();
						setfillstyle(SOLID_FILL,1);
						bar(0,370,106,449);
						setfillstyle(SOLID_FILL,15);
						bar(106,370,(106*2)-1,449);
						mver();

					}
					
					SeleccionM=1;
					
				}
				
				if (minlimit(1,19,371+26,19+103,370+(26*2)))
				{
					sound(207.65);
					delay(25);
					nosound();
					delay(25);
					sound(277.18);
					delay(25);
					nosound();
		
					if (bolMenu==1)
					{
						bolMenu=0;
						mocultar();
						setfillstyle(SOLID_FILL,1);
						bar(0,370,106,449);
						setfillstyle(SOLID_FILL,15);
						bar(106,370,(106*2)-1,449);
						mver();

					}
					
					SeleccionM=2;
					
				}
				
				if (minlimit(1,19,373+(26*2),19+103,370+(26*3)))
				{
					sound(207.65);
					delay(25);
					nosound();
					delay(25);
					sound(277.18);
					delay(25);
					nosound();
			
					if (bolMenu==1)
					{
						bolMenu=0;
						mocultar();
						setfillstyle(SOLID_FILL,1);
						bar(0,370,106,449);
						setfillstyle(SOLID_FILL,15);
						bar(106,370,(106*2)-1,449);
						mver();

					}
					
					SeleccionM=3;
					
				}
			}
			
			if(minlimit(1,18,480-18-6,18+83,480-18+12))
			{
				mocultar();
				setfillstyle(SOLID_FILL,8);
				bar(18,480-18-6,18+83,480-18+12);
				
				setcolor(0);
				settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
				settextjustify(LEFT_TEXT,TOP_TEXT);
				outtextxy(24,480-17,"S T A R T");
				setcolor(15);
				outtextxy(25,480-18,"S T A R T");
				setcolor(15);
				
				
				line(18,480-18-6,18,480-18+12);
				setcolor(15);
				line(18,480-18-6,18+83,480-18-6);
				setcolor(0);
				line(18+83,480-18-6,18+83,480-18+12);
				setcolor(0);
				line(18+83,480-18+12,18,480-18+12);
				
				delay(100);
				
				setfillstyle(SOLID_FILL,7);
				bar(18,480-18-6,18+83,480-18+12);
				
				mver();
				bolBoton=0;
				
				if(bolMenu==0)
				{
					bolMenu=1;
					bolMenuMostrar=0;
					for(i=0;i<2;i++)
						bolMSelec[i]=0;
				}
				else if (bolMenu==1)
				{
					bolMenu=0;
					mocultar();
					setfillstyle(SOLID_FILL,1);
					bar(0,370,106,449);
					setfillstyle(SOLID_FILL,15);
					bar(106,370,(106*2)-1,449);
					mver();

				}
				
				sound(207.65);
				delay(25);
				nosound();
				delay(25);
				sound(277.18);
				delay(25);
				nosound();
				
			}
			
			
			
		}
		
		if(mclick()==1 && !minlimit(1,19,370,19+103,370+(26*3)) && bolMenu)
		{
			bolMenu=0;
			mocultar();
			setfillstyle(SOLID_FILL,1);
			bar(0,370,106,449);
			setfillstyle(SOLID_FILL,15);
			bar(106,370,(106*2)-1,449);
			mver();
		}
		
		if(!bolMenuMostrar && bolMenu)
		{
			mocultar();
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			settextjustify(LEFT_TEXT,TOP_TEXT);
			setfillstyle(SOLID_FILL,7);
			bar(18,370,18+106,449);
			setcolor(15);
			line(18,370,18+106,370);
			setcolor(15);
			line(18,370,18,449);
			setcolor(0);
			line(18,449,18+106,449);
			setcolor(0);
			line(18+106,370,18+106,449);
			setcolor(0);
			outtextxy(18+5+1,370+10+1,"Presentacion");
			setcolor(15);
			outtextxy(18+5,370+10,"Presentacion");
			setcolor(0);
			outtextxy(18+5+1,370+10+1 + 25,"Juego");
			setcolor(15);
			outtextxy(18+5,370+10 + 25,"Juego");
			setcolor(0);
			outtextxy(18+5+1,370+10+1 + 50,"Cerrar");
			setcolor(15);
			outtextxy(18+5,370+10 + 50,"Cerrar");
			bolMenuMostrar=1;
			mver();
			
		}
		
		/*Seleccionar en el menu*/
		
		if(bolMenu)
			Menu();
			
		/*Comprobacion de min*/
		
		if(min!=Minutos())
		{
			
			mocultar();
			setfillstyle(SOLID_FILL,7);
			bar((640/2)+90,480-28,640,480);
			
			mver();
			bolFecha=0;
			min=Minutos();
		}
		
		if(SeleccionM)
		{	
	
			if(SeleccionM==1)
			{
				mocultar();
				
				/*Barra de tareas*/
				
				setfillstyle(SOLID_FILL,7);
				bar(0,480-30,640,480);
				
				setcolor(0);
				line(0,480-30,640,480-30);
				setcolor(15);
				line(0,480-29,640,480-29);
				setcolor(15);
				line(1,480-29,1,480);
				
				/*Fondo Para fuera de servicio*/
				
				setfillstyle(SOLID_FILL,15);
				bar(0,0,92,350);
				setfillstyle(SOLID_FILL,14);
				bar(92,0,92*2,350);
				setfillstyle(SOLID_FILL,3);
				bar(92*2,0,92*3,350);
				setfillstyle(SOLID_FILL,2);
				bar(92*3,0,92*4,350);
				setfillstyle(SOLID_FILL,5);
				bar(92*4,0,92*5,350);
				setfillstyle(SOLID_FILL,4);
				bar(92*5,0,92*6,350);
				setfillstyle(SOLID_FILL,1);
				bar(92*6,0,92*7,350);
				
				setfillstyle(SOLID_FILL,9);
				bar(0,351,92,370);
				setfillstyle(SOLID_FILL,5);
				bar(92*2,351,92*3,370);
				setfillstyle(SOLID_FILL,11);
				bar(92*4,351,92*5,370);
				setfillstyle(SOLID_FILL,7);
				bar(92*6,351,92*7,370);
				
				setfillstyle(SOLID_FILL,1);
				bar(0,370,106,449);
				setfillstyle(SOLID_FILL,15);
				bar(106,370,106*2,449);
				setfillstyle(SOLID_FILL,1);
				bar(106*2,370,106*3,449);
				
				
				
				
				settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
				settextjustify(CENTER_TEXT,CENTER_TEXT);
				setcolor(0);
				outtextxy((640/2),100,"PRESENTACION");
				setcolor(15);
				outtextxy((640/2)+3,100+3,"PRESENTACION");
				settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
				settextjustify(CENTER_TEXT,CENTER_TEXT);
				setcolor(0);
				outtextxy((640/2),200,"CARGANDO PRESENTACION");
				setcolor(15);
				outtextxy((640/2)+3,200+3,"CARGANDO PRESENTACION");
				
				delay(1000);
				
				ocultar=0;
				TraSound=207.65;
				while(ocultar<=640)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,0,ocultar,480);
					ocultar+=64;
					sound(TraSound);
					TraSound+=26.16;
					delay(100);
					
				}
				nosound();
				delay(500);
				
				Presentacion();
				
				mver();
				
			}
			else if (SeleccionM==2)
			{
				mocultar();
				
				/*Barra de tareas*/
				
				setfillstyle(SOLID_FILL,7);
				bar(0,480-30,640,480);
				
				setcolor(0);
				line(0,480-30,640,480-30);
				setcolor(15);
				line(0,480-29,640,480-29);
				setcolor(15);
				line(1,480-29,1,480);
				
				/*Fondo Para fuera de servicio*/
				
				setfillstyle(SOLID_FILL,15);
				bar(0,0,92,350);
				setfillstyle(SOLID_FILL,14);
				bar(92,0,92*2,350);
				setfillstyle(SOLID_FILL,3);
				bar(92*2,0,92*3,350);
				setfillstyle(SOLID_FILL,2);
				bar(92*3,0,92*4,350);
				setfillstyle(SOLID_FILL,5);
				bar(92*4,0,92*5,350);
				setfillstyle(SOLID_FILL,4);
				bar(92*5,0,92*6,350);
				setfillstyle(SOLID_FILL,1);
				bar(92*6,0,92*7,350);
				
				setfillstyle(SOLID_FILL,9);
				bar(0,351,92,370);
				setfillstyle(SOLID_FILL,5);
				bar(92*2,351,92*3,370);
				setfillstyle(SOLID_FILL,11);
				bar(92*4,351,92*5,370);
				setfillstyle(SOLID_FILL,7);
				bar(92*6,351,92*7,370);
				
				setfillstyle(SOLID_FILL,1);
				bar(0,370,106,449);
				setfillstyle(SOLID_FILL,15);
				bar(106,370,106*2,449);
				setfillstyle(SOLID_FILL,1);
				bar(106*2,370,106*3,449);
				
				
				
				
				settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
				settextjustify(CENTER_TEXT,CENTER_TEXT);
				setcolor(0);
				outtextxy((640/2),100,"JUEGO");
				setcolor(15);
				outtextxy((640/2)+3,100+3,"JUEGO");
				settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
				settextjustify(CENTER_TEXT,CENTER_TEXT);
				setcolor(0);
				outtextxy((640/2),200,"CARGANDO JUEGO");
				setcolor(15);
				outtextxy((640/2)+3,200+3,"CARGANDO JUEGO");
				
				delay(1000);
				
				ocultar=0;
				TraSound=207.65;
				while(ocultar<=640)
				{
					setfillstyle(SOLID_FILL,0);
					bar(640,0,640-ocultar,480);
					ocultar+=64;
					sound(TraSound);
					TraSound+=26.16;
					delay(100);
				}
				
				nosound();
				delay(500);
				
				Juego();
				
				mver();
				
			}
			else if (SeleccionM==3)
			{
					
				mocultar();
				
				/*Barra de tareas*/
				
				setfillstyle(SOLID_FILL,7);
				bar(0,480-30,640,480);
				
				setcolor(0);
				line(0,480-30,640,480-30);
				setcolor(15);
				line(0,480-29,640,480-29);
				setcolor(15);
				line(1,480-29,1,480);
				
				/*Fondo Para fuera de servicio*/
				
				setfillstyle(SOLID_FILL,15);
				bar(0,0,92,350);
				setfillstyle(SOLID_FILL,14);
				bar(92,0,92*2,350);
				setfillstyle(SOLID_FILL,3);
				bar(92*2,0,92*3,350);
				setfillstyle(SOLID_FILL,2);
				bar(92*3,0,92*4,350);
				setfillstyle(SOLID_FILL,5);
				bar(92*4,0,92*5,350);
				setfillstyle(SOLID_FILL,4);
				bar(92*5,0,92*6,350);
				setfillstyle(SOLID_FILL,1);
				bar(92*6,0,92*7,350);
				
				setfillstyle(SOLID_FILL,9);
				bar(0,351,92,370);
				setfillstyle(SOLID_FILL,5);
				bar(92*2,351,92*3,370);
				setfillstyle(SOLID_FILL,11);
				bar(92*4,351,92*5,370);
				setfillstyle(SOLID_FILL,7);
				bar(92*6,351,92*7,370);
				
				setfillstyle(SOLID_FILL,1);
				bar(0,370,106,449);
				setfillstyle(SOLID_FILL,15);
				bar(106,370,106*2,449);
				setfillstyle(SOLID_FILL,1);
				bar(106*2,370,106*3,449);
				
				
				
				
				settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
				settextjustify(CENTER_TEXT,CENTER_TEXT);
				setcolor(0);
				outtextxy((640/2),100,"SALIENDO");
				setcolor(15);
				outtextxy((640/2)+3,100+3,"SALIENDO");
				settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
				settextjustify(CENTER_TEXT,CENTER_TEXT);
				setcolor(0);
				outtextxy((640/2),200,"CERRANDO PROCESOS");
				setcolor(15);
				outtextxy((640/2)+3,200+3,"CERRANDO PROCESOS");
				
				delay(1000);
				
				ocultar=0;
				TraSound=469.25;
				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,0,640,ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound-=26.16;
					delay(100);
				}
				
				Salir=1;	
				nosound();
				delay(500);
				
			}
			
			bolFondo=0;
			SeleccionM=0;
			bolFecha=0;
			bolBoton=0;
		}
	}
	/*closegraph();*/
	exit(0);
}

/*Funciones para el tiempo*/

char *HoraFecha(void)
{
	
	time_t Presente;
	struct tm *Tempo;
	
	time(&Presente);
	
	Tempo=localtime(&Presente);
	
	return(asctime(Tempo));
}

int Minutos(void)
{
	int min;
	time_t Presente;
	struct tm *Tempo;
	
	time(&Presente);
	
	Tempo=localtime(&Presente);
	
	min=(Tempo->tm_min);
	
	return min;
}

/*Funciones para impresion del primer menu*/

void Menu(void)
{
	
	
	if(minlimit(1,19,370,19+103,370+(26*3)))
	{
				
		if(minlimit(1,19,370,19+103,370+26)==1 && bolMSelec[0]!=1)
		{
			bolMSelec[0]=1;
			bolMSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}	
		if (minlimit(1,19,371+26,19+103,370+(26*2))==1 && bolMSelec[0]!=2)
		{
			bolMSelec[0]=2;
			bolMSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}
		 if (minlimit(1,19,373+(26*2),19+103,370+(26*3))==1 && bolMSelec[0]!=3)
		{
			bolMSelec[0]=3;
			bolMSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}
	}
	
	
	
	if(bolMSelec[1]==1)
	{
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		settextjustify(LEFT_TEXT,TOP_TEXT);
		if(bolMSelec[0]==1)
		{
			mocultar();
			setfillstyle(SOLID_FILL,1);
			bar(19,371,19+103,370+26);
			setcolor(15);
			outtextxy(18+5,370+10,"Presentacion");
			mver();
			
		
		}
		else
		{
			mocultar();
			setfillstyle(SOLID_FILL,7);
			bar(19,371,19+103,370+26);
			setcolor(0);
			outtextxy(18+5+1,370+10+1,"Presentacion");
			setcolor(15);
			outtextxy(18+5,370+10,"Presentacion");
			mver();

		
		}
		
		if(bolMSelec[0]==2)
		{
			mocultar();
			setfillstyle(SOLID_FILL,1);
			bar(19,370+26,19+103,370+(26*2));
			setcolor(15);
			outtextxy(18+5,370+10 + 25,"Juego");
			mver();
		
		}
		else 
		{
			mocultar();
			setfillstyle(SOLID_FILL,7);
			bar(19,370+26,19+103,370+(26*2));
			setcolor(0);
			outtextxy(18+5+1,370+10+1 + 25,"Juego");
			setcolor(15);
			outtextxy(18+5,370+10 + 25,"Juego");
			mver();
		}
		
		if(bolMSelec[0]==3)
		{
			mocultar();
			setfillstyle(SOLID_FILL,1);
			bar(19,370+(26*2),19+103,369+(26*3));
			setcolor(15);
			outtextxy(18+5,370+10 + 50,"Cerrar");
			mver();
		}
		else
		{
			mocultar();
			setfillstyle(SOLID_FILL,7);
			bar(19,370+(26*2),19+103,370+(26*3));
			setcolor(0);
			outtextxy(18+5+1,370+10+1 + 50,"Cerrar");
			setcolor(15);
			outtextxy(18+5,370+10 + 50,"Cerrar");
			mver();
			
		}
	
	
		bolMSelec[1]=0;
	}

}

/*Presentacion*/

void Presentacion(void)
{
	int Lectura,x,y,bolSalir,ocultar,UnidadD;
	float TraSound;
	x=166;
	y=10;
	bolSalir=0;
	UnidadD=44;
	
		
			setfillstyle(SOLID_FILL,1);
			bar(x,y,x+UnidadD,y+(UnidadD*4)+(UnidadD/2));
			sound(311.13);
			delay(500);
			bar(x+UnidadD,y+(UnidadD*3)+(UnidadD/2),x+(UnidadD*3),y+(UnidadD*4)+(UnidadD/2));
			sound(369.99);
			delay(500);
			bar(x+(UnidadD*3),y+(UnidadD)+(UnidadD/2),x+(UnidadD*4),y+(UnidadD*4)+(UnidadD/2));
			sound(415.30);
			delay(500);
			bar(x+(UnidadD)+(UnidadD/2),y,x+(UnidadD*2)+(UnidadD/2),y+(UnidadD*3));
			sound(466.16);
			delay(500);
			bar(x+(UnidadD*2)+(UnidadD/2),y,x+(UnidadD*4)+(UnidadD/2),y+(UnidadD));
			sound(554.37);
			delay(500);
			bar(x+(UnidadD*4)+(UnidadD/2),y,x+(UnidadD*5)+(UnidadD/2),y+(UnidadD*4)+(UnidadD/2));
			sound(466.16);
			delay(500);
			bar(x+(UnidadD*5)+(UnidadD/2),y+(UnidadD*3)+(UnidadD/2),x+(UnidadD*6),y+(UnidadD*4)+(UnidadD/2));
			sound(415.30);
			delay(500);
			bar(x+(UnidadD*6),y+(UnidadD)+(UnidadD/2),x+(UnidadD*7),y+(UnidadD*4)+(UnidadD/2));
			sound(369.99);
			delay(500);
			bar(x+(UnidadD*6),y,x+(UnidadD*7),y+(UnidadD));
			sound(311.13);
			delay(500);
			nosound();
			settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			setcolor(15);
			outtextxy(640/2,y+(55*4)+20,"UNIVERSIDAD NACIONAL DE INGENIERIA");
			delay(10);
			outtextxy(640/2,y+(55*4)+60,"INGENIERIA EN COMPUTACION");
			delay(10);
			outtextxy(640/2,y+(55*4)+100,"PROYECTO DE PING PONG");
			delay(10);
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			outtextxy(640/2,y+(55*4)+120,"Aula");
			delay(10);
			outtextxy(640/2,y+(55*4)+140,"1M1-CO");
			delay(10);
			outtextxy(640/2,y+(55*4)+160,"Alumno");
			delay(10);
			outtextxy(640/2,y+(55*4)+180,"Jurgen Francisco Bermudez Picado 2020-0290U");
			delay(10);
			outtextxy(640/2,y+(55*4)+200,"Docente");
			delay(10);
			outtextxy(640/2,y+(55*4)+220,"Nelson Alejandro Barrios Gonzales");
			delay(10);
			outtextxy(640/2,y+(55*4)+240,"Pulsa (ESC) para salir.");
	
	
	while (!bolSalir)
	{
		

		
		Lectura=0;
		
		while(kbhit())
		{
			Lectura=getch();
			if(Lectura==27)
				bolSalir=1;
			
		}

	}
	
	delay(1000);
	
	ocultar=0;
	TraSound=469.25;
	while(ocultar<=640)
	{
		setfillstyle(SOLID_FILL,0);
		bar(640,0,640-ocultar,480);
		ocultar+=64;
		sound(TraSound);
		TraSound-=26.16;
		delay(100);
	}
	
	nosound();
	
	setfillstyle(SOLID_FILL,0);
	bar(0,0,640,480);
	
}

/*Juego Ping Pong*/

void Juego (void)
{
	int bolSalir,Lectura,bolSelec[2];
	
	int ocultar,bolTitulo;
	
	float TraSound;
	
	bolSalir= 0 ;
	
	Lectura= 0 ; 
	
	bolTitulo=0;
	
	bolSelec[0]=0;
	bolSelec[1]=0;
	
	/*Menu del juego*/
	mver();
	
	while(!bolSalir)
	{
		
		if(!bolTitulo)
		{
			mocultar();
			setcolor(15);
			setfillstyle(SOLID_FILL,15);
			circle(0,0,100);
			floodfill(0,0,15);
			circle(640,480,100);
			floodfill(639,479,15);
			circle(640,0,100);
			floodfill(639,0,15);
			circle(0,480,100);
			floodfill(0,479,15);
			circle(640/2,480+50,100);
			floodfill((640/2),479,15);
			settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			setcolor(15);
			outtextxy((640/2),(480/2)-200,"PING PONG");
			settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			setcolor(15);
			outtextxy((640/2),(480/2)-100,"Jugar");
			outtextxy((640/2),(480/2)-40,"Ayuda");
			outtextxy((640/2),(480/2)+20,"Puntaje");
			outtextxy((640/2),(480/2)+80,"Registro");
			outtextxy((640/2),(480/2)+140,"Salir");
			mver();
			bolTitulo=1;
			
		}
		
		Equis(0,RED);
		
		if(minlimit(1,(640/2)-50,(480/2)-100-10,(640/2)+50,(480/2)-100+10) && bolSelec[0]!=1)
		{
			bolSelec[0]=1;
			bolSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}	
		else if (minlimit(1,(640/2)-50,(480/2)-40-10,(640/2)+50,(480/2)-40+10) && bolSelec[0]!=2)
		{
			bolSelec[0]=2;
			bolSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}
		else if (minlimit(1,(640/2)-50,(480/2)+20-10,(640/2)+50,(480/2)+20+10) && bolSelec[0]!=3)
		{
			bolSelec[0]=3;
			bolSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}
		else if (minlimit(1,(640/2)-50,(480/2)+80-10,(640/2)+50,(480/2)+80+10) && bolSelec[0]!=4)
		{
			bolSelec[0]=4;
			bolSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}
		else if (minlimit(1,(640/2)-50,(480/2)+140-10,(640/2)+50,(480/2)+140+10) && bolSelec[0]!=5)
		{
			bolSelec[0]=5;
			bolSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}
		
		
		
		if(bolSelec[1])
		{
			
			settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			
			if(bolSelec[0]==1)
			{
				mocultar();
				setcolor(14);
				outtextxy((640/2),(480/2)-100,"Jugar");
				mver();
			
			
			}
			else
			{
				mocultar();
				setcolor(15);
				outtextxy((640/2),(480/2)-100,"Jugar");
				mver();
				
				
			}
			
			if(bolSelec[0]==2)
			{
				mocultar();
				setcolor(14);
				outtextxy((640/2),(480/2)-40,"Ayuda");
				mver();
			
			
			}
			else
			{
				mocultar();
				setcolor(15);
				outtextxy((640/2),(480/2)-40,"Ayuda");
				mver();
				
				
			}
			
			if(bolSelec[0]==3)
			{
				mocultar();
				setcolor(14);
				outtextxy((640/2),(480/2)+20,"Puntaje");
				mver();
			
			
			}
			else
			{
				mocultar();
				setcolor(15);
				outtextxy((640/2),(480/2)+20,"Puntaje");
				mver();
				
				
			}
			
			if(bolSelec[0]==4)
			{
				mocultar();
				setcolor(14);
				outtextxy((640/2),(480/2)+80,"Registro");
				mver();
			
			
			}
			else
			{
				mocultar();
				setcolor(15);
				outtextxy((640/2),(480/2)+80,"Registro");
				mver();
				
				
			}
			
			if(bolSelec[0]==5)
			{
				mocultar();
				setcolor(14);
				outtextxy((640/2),(480/2)+140,"Salir");
				mver();
				
			}
			else
			{
				mocultar();
				setcolor(15);
				outtextxy((640/2),(480/2)+140,"Salir");
				mver();
				
				
			}
			
			
			bolSelec[1]=0;
			
		}
		
		if(mclick())
		{
			
			if(minlimit(1,(640/2)-50,(480/2)-100-10,(640/2)+50,(480/2)-100+10))
			{
				sound(415.30);
				delay(25);
				nosound();
				delay(25);
				sound(554.37);
				delay(25);
				nosound();
				
				mocultar();
				
				delay(1000);
				
				ocultar=0;
				TraSound=207.65;
				
				bolExit[2]=0;
				bolExit[0]=0;
				

				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,480,640,480-ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound+=26.16;
					delay(100);
				}
							
				nosound();
				
				
				

				setfillstyle(SOLID_FILL,0);
				bar(0,0,640,480);
				
				Modo();
				
				bolExit[2]=0;
				mocultar();
				
				delay(1000);
				
				ocultar=0;
				TraSound=469.25;
				bolExit[2]=0;
				bolExit[0]=0;
				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,0,640,ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound-=26.16;
					delay(100);
				}
				nosound();
				
				mver();
				
				bolTitulo=0;
				
			}	
			else if (minlimit(1,(640/2)-50,(480/2)-40-10,(640/2)+50,(480/2)-40+10))
			{
				sound(415.30);
				delay(25);
				nosound();
				delay(25);
				sound(554.37);
				delay(25);
				nosound();
				
				mocultar();
				
				delay(1000);
				
				ocultar=0;
				TraSound=207.65;
				bolExit[2]=0;
				bolExit[0]=0;

				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,480,640,480-ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound+=26.16;
					delay(100);
				}
							
				nosound();
				
				
				

				setfillstyle(SOLID_FILL,0);
				bar(0,0,640,480);
				
				mver();
				
				Ayuda();
				
				bolExit[2]=0;
				bolExit[0]=0;
				mocultar();
				
				delay(1000);
				
				ocultar=0;
				TraSound=469.25;
				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,0,640,ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound-=26.16;
					delay(100);
				}
				nosound();
				
				mver();
				
				bolTitulo=0;
				
				
			}
			else if (minlimit(1,(640/2)-50,(480/2)+20-10,(640/2)+50,(480/2)+20+10))
			{
				sound(415.30);
				delay(25);
				nosound();
				delay(25);
				sound(554.37);
				delay(25);
				nosound();
				
				mocultar();
				
				delay(1000);
				
				ocultar=0;
				TraSound=207.65;
				bolExit[2]=0;
				bolExit[0]=0;

				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,480,640,480-ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound+=26.16;
					delay(100);
				}
							
				nosound();
				
				
				

				setfillstyle(SOLID_FILL,0);
				bar(0,0,640,480);
				
				mver();
				
				bolExit[2]=0;
				
				Puntajes();
				
				bolExit[2]=0;
				bolExit[0]=0;
				mocultar();
				
				delay(1000);
				
				ocultar=0;
				TraSound=469.25;
				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,0,640,ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound-=26.16;
					delay(100);
				}
				nosound();
				
				mver();
				
				bolTitulo=0;
				
				
			}
			else if (minlimit(1,(640/2)-50,(480/2)+80-10,(640/2)+50,(480/2)+80+10))
			{
				sound(415.30);
				delay(25);
				nosound();
				delay(25);
				sound(554.37);
				delay(25);
				nosound();
				
				mocultar();
				
				delay(1000);
				
				ocultar=0;
				TraSound=207.65;
				bolExit[2]=0;
				bolExit[0]=0;

				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,480,640,480-ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound+=26.16;
					delay(100);
				}
							
				nosound();
				
				
				

				setfillstyle(SOLID_FILL,0);
				bar(0,0,640,480);
				mver();
				
				bolExit[2]=0;
				bolExit[0]=0;
				Registros();
				
				bolExit[2]=0;
				
				mocultar();
				
				delay(1000);
				
				ocultar=0;
				TraSound=469.25;
				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,0,640,ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound-=26.16;
					delay(100);
				}
				nosound();
				
				mver();
				
				bolTitulo=0;
				
				
			}
			else if (minlimit(1,(640/2)-50,(480/2)+140-10,(640/2)+50,(480/2)+140+10))
			{
				bolSalir=1;
				sound(415.30);
				delay(25);
				nosound();
				delay(25);
				sound(554.37);
				delay(25);
				nosound();
				
				
				
			}
			
		}
		
		while(kbhit())
		{
			Lectura=getch();
			
		}
		
		
	}
	mocultar();
	delay(1000);
	
	ocultar=0;
	TraSound=469.25;
	

	while(ocultar<=640)
	{
		setfillstyle(SOLID_FILL,0);
		bar(0,0,ocultar,480);
		ocultar+=64;
		sound(TraSound);
		TraSound-=26.16;
		delay(100);
	}
				
	nosound();

	setfillstyle(SOLID_FILL,0);
	bar(0,0,640,480);
	
	mver();

}

void Jugar (int Dificultad)
{
	FILE *Archivo;
	int stop,Au,Mul,Score,ScoreN,Color,Colorball,bolOcultar;
	int x,y,x1,y1,Movix,Moviy,Lectura[2],xm,ym;
	int Vx,Vy,VEn,Final,i,j;
	char Puntaje[15],Nivel[15],Tempo[27],Next[20],Cuenta[5];
	struct Rectangule Movi;
	struct Rectangule MoviEn;
	struct Rectangule MoviCle;
	struct Rectangule MoviCleEn;
	
	
	bolOcultar=0;
	
	Nombres();

	stpcpy(Tempo,HoraFecha());
	
	srand(time(NULL));
	
	xm=ym=0;
	
	Movix=rand()%2;
	Moviy=rand()%2;

	if(Movix==0)
		Vx=1;
	else
		Vx=-1;

	if(Moviy==0)
		Vy=1;
	else
		Vy=-1;


	Lectura[0]=0;
	Lectura[1]=0;
	Mul=1;
	Color=15;
	Colorball=15;
	stop=1;
	Final=0;
	Score=0;
	ScoreN=Score;
	Au=0;
	
	mver();
	
	VEn=5;
	x=(640/2);
	y=(480/2);

	

	mocultar();

	MoviEn.X1=(640/2)-(160/2);
	MoviEn.X2=(640/2)+(160/2);

	Movi.Y1=400;
	Movi.Y2=400+10;

	MoviEn.Y1=50;
	MoviEn.Y2=50+10;
	
	settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	
	for (i=3;i>0;i--)
	{
		setcolor(15);
		sprintf(Cuenta,"%d",i);
		outtextxy(640/2,480/2,Cuenta);
		delay(1000);
		setcolor(0);
		outtextxy(640/2,480/2,Cuenta);
		
	}
	
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	fflush(stdin);
	setcolor(15);
	
	if(Dificultad==1)
	{
		outtextxy(10,15,"Facil");
	}
	if(Dificultad==2)
	{
		outtextxy(10,15,"Medio");
	}
	if(Dificultad==3)
	{
		outtextxy(10,15,"Dificil");
	}
	else if (Dificultad==4)
	{
		
		sprintf(Puntaje,"Puntaje: %d", Score);
		outtextxy(10,15,Puntaje);
		fflush(stdin);
	}
	
	sprintf(Nivel,"Nivel: %d", Mul);
	outtextxy(640-100,15, Nivel);
	fflush(stdin);
	setcolor(15);
	outtextxy(10,480-30,"Pausa (Esc)");
	
	outtextxy(640-100,480-30,Nombre);
	
	settextjustify(CENTER_TEXT,TOP_TEXT);
	sprintf(Next,"Next: %d / %d",Au,Mul*5);
	outtextxy(640/2,15, Next);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	
	while(stop==1)
	{
		
		
		if(Dificultad==1)
		{
			VEn=4;
		}
		else if(Dificultad==2)
		{
			VEn=8;
		}
		else if(Dificultad==3)
		{
			VEn=12;
		}
		else if(Dificultad==4)
		{
			VEn=abs(Vx)+17;
		}
		
		setcolor(Colorball);
		setfillstyle(SOLID_FILL,Colorball);
		
		x1=x;
		y1=y;
		
		mocultar();
		
		circle(x,y,5);
		floodfill(x,y,Colorball);
		mver();
		
		setcolor(Color);
		setfillstyle(SOLID_FILL,Color);
		
		
		MoviCle.X1=Movi.X1;
		MoviCle.Y1=Movi.Y1;
		MoviCle.X2=Movi.X2;
		MoviCle.Y2=Movi.Y2;
		mocultar();
		
		bar(Movi.X1,Movi.Y1,Movi.X2,Movi.Y2);
		
		mver();
		
		MoviCleEn.X1=MoviEn.X1;
		MoviCleEn.Y1=MoviEn.Y1;
		MoviCleEn.X2=MoviEn.X2;
		MoviCleEn.Y2=MoviEn.Y2;
		
		mocultar();
		bar(MoviEn.X1,MoviEn.Y1,MoviEn.X2,MoviEn.Y2);
		mver();	
		
		if(x+5+Vx>=640)
		{
			
			Vx*=-1;
			if((y<Movi.Y2)&&(y>MoviEn.Y1))
			{
				setcolor(0);
				settextjustify(CENTER_TEXT,TOP_TEXT);
				sprintf(Next,"Next: %d / %d",Au,Mul*5);
				outtextxy(640/2,15, Next);
				Au++;
				setcolor(Color);
				sprintf(Next,"Next: %d / %d",Au,Mul*5);
				outtextxy(640/2,15, Next);
				settextjustify(LEFT_TEXT,TOP_TEXT);
				sound(277.18);
				delay(25);
				nosound();
			}
		}
		else if(x-5+Vx<=0)
		{
			
			
			Vx*=-1;
			if((y<Movi.Y2)&&(y>MoviEn.Y1))
			{
				setcolor(0);
				settextjustify(CENTER_TEXT,TOP_TEXT);
				sprintf(Next,"Next: %d / %d",Au,Mul*5);
				outtextxy(640/2,15, Next);
				Au++;
				setcolor(Color);
				sprintf(Next,"Next: %d / %d",Au,Mul*5);
				outtextxy(640/2,15, Next);
				settextjustify(LEFT_TEXT,TOP_TEXT);
				sound(277.18);
				delay(25);
				nosound();
			}
		}
		else if(y-10+Vy<=0)
		{
			Final=-1;
			stop=0;
		}
		else if(y+5+Vy>=480)
		{
			Final=1;
			stop=0;
		}
		
		
		
		if(y+5+Vy>=Movi.Y1 && x>=Movi.X1 && x<=Movi.X2 && (y+5+Vy<=Movi.Y2) && (y+5-Vy<Movi.Y1))
		{
			
			
			Vy*=-1;
			sound(329.73);
			delay(25);
			nosound();
			
			if (Dificultad==4)
			{
				
				if (Score<32000)
				{ 
					Score+=10;
				}
				setcolor(0);
				sprintf(Puntaje, "Puntaje: %d", ScoreN);
				outtextxy(10,15,Puntaje);
				fflush(stdin);
				setcolor(Color);
				sprintf(Puntaje, "Puntaje: %d", Score);
				outtextxy(10,15, Puntaje);
				fflush(stdin);
				ScoreN=Score;
			}
			
			
		}
		
		if(y-5+Vy<=MoviEn.Y2 && x>=MoviEn.X1 && x<=MoviEn.X2 && (y-5+Vy>=MoviEn.Y1)&& (y-5-Vy<Movi.Y1))
		{
			
			
			Vy*=-1;
			sound(329.73);
			delay(25);
			nosound();
		}
	
	
		if (Au==5*Mul)
		{
			if(Vx>0)
			{
				Vx++;
				
			}
			else
			{
				Vx--;
							
			}
			if(Vy>0)
			{
				Vy++;
							
			}
			else
			{
				
				Vy--;
				
			}
			
			
			if(Color<15)
			{
				Color++;
			}
			else if (Color==15)
			{
				Color=1;
			}
			
			fflush(stdin);
			setcolor(0);
			sprintf(Nivel,"Nivel: %d", Mul);
			outtextxy(640-100,15, Nivel);
			settextjustify(CENTER_TEXT,TOP_TEXT);
			sprintf(Next,"Next: %d / %d",Au,Mul*5);
			outtextxy(640/2,15, Next);
			settextjustify(LEFT_TEXT,TOP_TEXT);
			fflush(stdin);
			Mul++;
			Au=0;
			setcolor(Color);
			sprintf(Nivel,"Nivel: %d", Mul);
			outtextxy(640-100,15, Nivel);
			settextjustify(CENTER_TEXT,TOP_TEXT);
			sprintf(Next,"Next: %d / %d",Au,Mul*5);
			outtextxy(640/2,15, Next);
			settextjustify(LEFT_TEXT,TOP_TEXT);
			fflush(stdin);
			
			setcolor(Color);
			outtextxy(10,480-30,"Pausa (Esc)");
	
			outtextxy(640-100,480-30,Nombre);
			
			if(Dificultad==1)
			{
				outtextxy(10,15,"Facil");
			}
			else if(Dificultad==2)
			{
				outtextxy(10,15,"Medio");
			}
			else if(Dificultad==3)
			{
				outtextxy(10,15,"Dificil");
			}
			else if(Dificultad==4)
			{
				setcolor(0);
				sprintf(Puntaje, "Puntaje: %d", ScoreN);
				outtextxy(10,15,Puntaje);
				fflush(stdin);
				setcolor(Color);
				sprintf(Puntaje, "Puntaje: %d", Score);
				outtextxy(10,15, Puntaje);
				fflush(stdin);
			}
			
			
			
		}
		
		
		Movi.X1=mxpos(1)-(160/2);
		Movi.X2=mxpos(1)+(160/2);
	
		
		x+=Vx;
		y+=Vy;
		
		if((Vy<0) && (MoviEn.X1>x-75 || MoviEn.X2<x+75))
		{
			if((x>(MoviEn.X2+MoviEn.X1)/2))
			{
				MoviEn.X2+=VEn;
				MoviEn.X1+=VEn;
			}
			else if(x<(MoviEn.X2+MoviEn.X1)/2)
			{
				MoviEn.X2-=VEn;
				MoviEn.X1-=VEn;
			}
		}
		
		
		while(kbhit())
		{ 
	
			Lectura[0]=getch();
			

		}
		
		
		
		while(Lectura[0]==27 && Lectura[1]!=13 && Lectura[1]!=27)
		{	
				xm=mxpos(1);
				ym=mypos(1);
				setcolor(0);
				outtextxy(10,480-30,"Pausa (Esc)");
				setcolor(14);
				outtextxy(10,480-30,"Salir (Esc) Continuar (Enter)");
				Lectura[1]=getch();
				setcolor(0);
				outtextxy(10,480-30,"Salir (Esc) Continuar (Enter)");
				setcolor(Color);
				outtextxy(10,480-30,"Pausa (Esc)");
				msituar(1,xm,ym);
				if(Lectura[1]==27)
				{
					stop=0;
				}
				
		}
		Lectura[0]=0;
		Lectura[1]=0;
		
		setcolor(0);
		setfillstyle(SOLID_FILL,0);
		mocultar();	
		circle(x1,y1,5);
		floodfill(x1,y1,0);
		mver();	
		setcolor(0);
		setfillstyle(SOLID_FILL,0);
		
		if(MoviCle.X1!=Movi.X1 || MoviCle.X2!=Movi.X2)
		{
			mocultar();	
			bar(MoviCle.X1,MoviCle.Y1,MoviCle.X2,MoviCle.Y2);
			mver();	
		}
		
		if(MoviCleEn.X1!=MoviEn.X1 || MoviCleEn.X2!=MoviEn.X2)
		{
			mocultar();	
			bar(MoviCleEn.X1,MoviCleEn.Y1,MoviCleEn.X2,MoviCleEn.Y2);
			mver();	
		}
		
		
		if(Colorball<15)
		{
			Colorball++;
		}
		else if(Colorball==15)
		{
			Colorball=1;
		}
		
		if((!bolOcultar)&&((y>Movi.Y2)||(y<MoviEn.Y1)))
		{
			bolOcultar=1;
			setfillstyle(SOLID_FILL,0);
			bar(0,480-50,640,480);
			bar(0,40,640,0);
			setfillstyle(SOLID_FILL,Color);
		}
	}
	
	if (Dificultad!=4)
	{
		if(Final==1)
		{
			for(j=0;j<2;j++)
			{
				for(i=1;i<16;i++)
				{
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
					setcolor(i);
					outtextxy(640/2,480/2,"PERDISTE");
					delay(50);
				}
			}
			Score=-1;
			
		}
		else if (Final==-1)
		{
			for(j=0;j<2;j++)
			{
				for(i=1;i<16;i++)
				{
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
					setcolor(i);
					outtextxy(640/2,480/2,"GANASTE");
					delay(50);
				}
			}
			Score=-2;
			
		}
		else
		{
			Score=-1;
			
		}
	}
	else
	{
		for(j=0;j<3;j++)
		{
			for(i=1;i<16;i++)
			{
				settextjustify(CENTER_TEXT,CENTER_TEXT);
				settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
				setcolor(i);
				sprintf(Puntaje, "%d", Score);
				outtextxy(640/2,480/2,Puntaje);
				delay(50);
			}
		}
		
	}
	

	Archivo=fopen("C:\\FICHEROS\\REGISTRO.txt","a");
	
	if(Archivo)
	{
		
		fprintf(Archivo,"%s %d %d %s",Nombre,Dificultad,Score,Tempo);
		
		fclose(Archivo);
		
	}
	
}

void Modo (void)
{
	
	int bolSalir,Lectura,bolSelec[2];
	
	int ocultar,bolTitulo;
	
	float TraSound;
	
	bolSalir= 0 ;
	
	Lectura= 0 ; 
	
	bolTitulo=0;
	
	bolSelec[0]=0;
	bolSelec[1]=0;

	mver();
	
	while(!bolSalir)
	{
		
		if(!bolTitulo)
		{
			mocultar();
			setcolor(15);
			
			setfillstyle(SOLID_FILL,15);
			circle(0,480/2,100);
			floodfill(1,480/2,15);
			circle(640,480/2,100);
			floodfill(639,480/2,15);
			circle(640/2,480+50,100);
			floodfill((640/2),479,15);
			
			settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			setcolor(15);
			outtextxy((640/2),(480/2)-200,"MODO DE JUEGO");
			settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			setcolor(15);
			outtextxy((640/2),(480/2)-100,"Facil");
			outtextxy((640/2),(480/2)-40,"Medio");
			outtextxy((640/2),(480/2)+20,"Dificil");
			outtextxy((640/2),(480/2)+80,"Arcade");
			outtextxy((640/2),(480/2)+140,"Regresar");
			mver();
			bolTitulo=1;
			
			
		}
		
		Equis(15,RED);
		
		if(minlimit(1,(640/2)-50,(480/2)-100-10,(640/2)+50,(480/2)-100+10) && bolSelec[0]!=1)
		{
			bolSelec[0]=1;
			bolSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}	
		else if (minlimit(1,(640/2)-50,(480/2)-40-10,(640/2)+50,(480/2)-40+10) && bolSelec[0]!=2)
		{
			bolSelec[0]=2;
			bolSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}
		else if (minlimit(1,(640/2)-50,(480/2)+20-10,(640/2)+50,(480/2)+20+10) && bolSelec[0]!=3)
		{
			bolSelec[0]=3;
			bolSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}
		else if (minlimit(1,(640/2)-50,(480/2)+80-10,(640/2)+50,(480/2)+80+10) && bolSelec[0]!=4)
		{
			bolSelec[0]=4;
			bolSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}
		else if (minlimit(1,(640/2)-50,(480/2)+140-10,(640/2)+50,(480/2)+140+10) && bolSelec[0]!=5)
		{
			bolSelec[0]=5;
			bolSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}
		
		
		if(bolSelec[1])
		{
			
			settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			
			if(bolSelec[0]==1)
			{
				mocultar();
				setcolor(11);
				outtextxy((640/2),(480/2)-100,"Facil");
				mver();
			
			
			}
			else
			{
				mocultar();
				setcolor(15);
				outtextxy((640/2),(480/2)-100,"Facil");
				mver();
				
				
			}
			
			if(bolSelec[0]==2)
			{
				mocultar();
				setcolor(10);
				outtextxy((640/2),(480/2)-40,"Medio");
				mver();
			
			
			}
			else
			{
				mocultar();
				setcolor(15);
				outtextxy((640/2),(480/2)-40,"Medio");
				mver();
				
				
			}
			
			if(bolSelec[0]==3)
			{
				mocultar();
				setcolor(12);
				outtextxy((640/2),(480/2)+20,"Dificil");
				mver();
			
			
			}
			else
			{
				mocultar();
				setcolor(15);
				outtextxy((640/2),(480/2)+20,"Dificil");
				mver();
				
				
			}
			
			if(bolSelec[0]==4)
			{
				mocultar();
				setcolor(13);
				outtextxy((640/2),(480/2)+80,"Arcade");
				mver();
			
			
			}
			else
			{
				mocultar();
				setcolor(15);
				outtextxy((640/2),(480/2)+80,"Arcade");
				mver();
				
				
			}
			
			if(bolSelec[0]==5)
			{
				mocultar();
				setcolor(14);
				outtextxy((640/2),(480/2)+140,"Regresar");
				mver();
				
			}
			else
			{
				mocultar();
				setcolor(15);
				outtextxy((640/2),(480/2)+140,"Regresar");
				mver();
				
				
			}
			
			bolSelec[1]=0;
			
		}
		
		if(mclick())
		{
			
			if(minlimit(1,(640/2)-50,(480/2)-100-10,(640/2)+50,(480/2)-100+10))
			{
				sound(415.30);
				delay(25);
				nosound();
				delay(25);
				sound(554.37);
				delay(25);
				nosound();
				
				mocultar();
				
				delay(1000);
				
				ocultar=0;
				TraSound=207.65;
				

				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,480,640,480-ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound+=26.16;
					delay(100);
				}
							
				nosound();
				
				
				

				setfillstyle(SOLID_FILL,0);
				bar(0,0,640,480);
				
				bolExit[2]=0;
				
				Jugar(1);
				
				delay(1000);
				
				ocultar=0;
				TraSound=469.25;
				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,0,640,ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound-=26.16;
					delay(100);
				}
				nosound();
				
				
				mver();
				
				bolTitulo=0;
				
			}	
			else if (minlimit(1,(640/2)-50,(480/2)-40-10,(640/2)+50,(480/2)-40+10))
			{
				sound(415.30);
				delay(25);
				nosound();
				delay(25);
				sound(554.37);
				delay(25);
				nosound();
				
				mocultar();
				
				delay(1000);
				
				ocultar=0;
				TraSound=207.65;
				

				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,480,640,480-ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound+=26.16;
					delay(100);
				}
							
				nosound();
				
				
				

				setfillstyle(SOLID_FILL,0);
				bar(0,0,640,480);
				
				bolExit[2]=0;
				
				Jugar(2);
				
				delay(1000);
				
				ocultar=0;
				TraSound=469.25;
				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,0,640,ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound-=26.16;
					delay(100);
				}
				nosound();
				
				
				mver();
				
				bolTitulo=0;
				
				
			}
			else if (minlimit(1,(640/2)-50,(480/2)+20-10,(640/2)+50,(480/2)+20+10))
			{
				sound(415.30);
				delay(25);
				nosound();
				delay(25);
				sound(554.37);
				delay(25);
				nosound();
				
				mocultar();
				
				delay(1000);
				
				ocultar=0;
				TraSound=207.65;
				

				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,480,640,480-ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound+=26.16;
					delay(100);
				}
							
				nosound();
				
				
				

				setfillstyle(SOLID_FILL,0);
				bar(0,0,640,480);
				
				bolExit[2]=0;
				
				Jugar(3);
				
				delay(1000);
				
				ocultar=0;
				TraSound=469.25;
				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,0,640,ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound-=26.16;
					delay(100);
				}
				nosound();
				
				
				mver();
				
				bolTitulo=0;
				
				
			}
			else if (minlimit(1,(640/2)-50,(480/2)+80-10,(640/2)+50,(480/2)+80+10))
			{
				sound(415.30);
				delay(25);
				nosound();
				delay(25);
				sound(554.37);
				delay(25);
				nosound();
				
				mocultar();
				
				delay(1000);
				
				ocultar=0;
				TraSound=207.65;
				

				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,480,640,480-ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound+=26.16;
					delay(100);
				}
							
				nosound();
				
				
				

				setfillstyle(SOLID_FILL,0);
				bar(0,0,640,480);
				
				bolExit[2]=0;
				
				Jugar(4);
				
				delay(1000);
				
				ocultar=0;
				TraSound=469.25;
				while(ocultar<=480)
				{
					setfillstyle(SOLID_FILL,0);
					bar(0,0,640,ocultar);
					ocultar+=48;
					sound(TraSound);
					TraSound-=26.16;
					delay(100);
				}
				nosound();
				
				
				mver();
				
				bolTitulo=0;
				
				
			}
			else if (minlimit(1,(640/2)-50,(480/2)+140-10,(640/2)+50,(480/2)+140+10))
			{
				bolSalir=1;
				sound(415.30);
				delay(25);
				nosound();
				delay(25);
				sound(554.37);
				delay(25);
				nosound();
				
				
				
			}
			
			
		}
		
		while(kbhit())
		{
			Lectura=getch();
			
			/*if(Lectura==27)
				bolSalir=1;*/

		}
		
		
	}
	
}

void Nombres(void)
{
	int Lector,i,largo,bolretorno;
	char Temporal[MAXNOM];
	fflush(stdin);
	Temporal[0]='\0';
	largo=MAXNOM-1;
	bolretorno=0;
	i=0;
	
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setcolor(15);
	outtextxy((640/2),(480/2)-100,"Ingrese su nombre");
	
	while ((bolretorno==0)||(Nombre[0]==NULL))
	{
		
		Lector=obte1();
		
		if((65<=Lector && 90>=Lector ) ||(97<=Lector && 122>=Lector ))
		{
			if(i<largo)
			{
				settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
				settextjustify(CENTER_TEXT,CENTER_TEXT);
				setcolor(0);
				outtextxy((640/2),(480/2),Temporal);
				
				
				Temporal[i]=Lector;
				Temporal[i+1]='\0';
				
				settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
				settextjustify(CENTER_TEXT,CENTER_TEXT);
				setcolor(15);
				outtextxy((640/2),(480/2),Temporal);
				
				Nombre[i]=Lector;
				i++;
				
			}
			bolretorno=0;
		}
		if (Lector==8)
		{
			if(i>0)
			{
				settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
				settextjustify(CENTER_TEXT,CENTER_TEXT);
				setcolor(0);
				outtextxy((640/2),(480/2),Temporal);
				
				
				Temporal[i-1]='\0';
				
				settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
				settextjustify(CENTER_TEXT,CENTER_TEXT);
				setcolor(15);
				outtextxy((640/2),(480/2),Temporal);
			
				Nombre[i-1]=NULL;
				
				i--;
			}
			bolretorno=0;
		}
		if (Lector==13)
		{	
				Nombre[i]='\0';
				bolretorno=1;
			
		}
		fflush(stdin);
	}

	cleardevice();
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

void Registros (void)
{
	int Lectura,x,y,bolSalir,bolMostrar,j,k,ContCar,bolSelec[2];
	char Car,RegisMos[30];
	
	int Modo,Score,Dia,Anyo;
	char *NombreL,DiaS[4],Mes[4],Hora[10];
	
	int Limite,Tandas,Muestra;
	
	FILE *Lect;
	
	x=40;
	y=20;
	bolSalir=0;
	bolMostrar=0;
	ContCar=0;
	
	Limite=15;
	Muestra=0;
	
	bolSelec[0]=0;
	bolSelec[1]=0;
	
	
	while (!bolSalir)
	{
		if(!bolMostrar)
		{
			NombreL=(char*) calloc(15,sizeof(char));
			memset(NombreL,0,15);
			
			Lect=fopen("C:\\FICHEROS\\REGISTRO.txt","r");
			ContCar=0;
			do
			{
				Car=fgetc(Lect);
				
				if(Car=='\n')
					ContCar++;
				
			}while(Car!=EOF);
			
			rewind(Lect);
			
			Tandas=floor(ContCar/Limite);
		
			mocultar();
			setcolor(15);
			setfillstyle(SOLID_FILL,15);
			circle(0,0,100);
			floodfill(0,0,15);
			circle(640,0,100);
			floodfill(639,0,15);
			/*
			circle(640/2,480+50,100);
			floodfill((640/2),479,15);*/
			
			
			settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			outtextxy(50+20,480-20,"Anterior");
			outtextxy(640-50-30,480-20,"Siguiente");
			outtextxy(640/2,480-20,"Salir");
			setcolor(15);
			settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			outtextxy((640/2),(480/2)-200,"REGISTRO");
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			settextjustify(LEFT_TEXT,CENTER_TEXT);
			setcolor(15);
		
			
			for(k=0;k<Tandas;k++)
			{
				if(((k*Limite)<=Muestra) && (Muestra<((1+k)*Limite)))
				{
					for(i=Muestra;i<(1+k)*Limite;i++)
					{
						
						rewind(Lect);
						
						for(j=0;j<ContCar-i;j++)
						{
							fscanf(Lect,"%s %d %d %s %s %d %s %d\n",NombreL,&Modo,&Score,DiaS,Mes,&Dia,Hora,&Anyo);
						}
						
						
						sprintf(RegisMos,"%s",NombreL);
						outtextxy(x,100+y*(i-Muestra+1),RegisMos);
						
						if(Modo==1)
						{
							setcolor(11);
							sprintf(RegisMos,"Facil");
							outtextxy(x+150,100+y*(i-Muestra+1),RegisMos);
							
							if(Score==-1)
							{
								setcolor(15);
								sprintf(RegisMos,"Derrota");
								outtextxy(x+150+70,100+y*(i-Muestra+1),RegisMos);
							}
							else
							{
								setcolor(14);
								sprintf(RegisMos,"Victoria");
								outtextxy(x+150+70,100+y*(i-Muestra+1),RegisMos);
							}
						}
						else if(Modo==2)
						{
							setcolor(10);
							sprintf(RegisMos,"Medio");
							outtextxy(x+150,100+y*(i-Muestra+1),RegisMos);
							
							if(Score==-1)
							{
								setcolor(15);
								sprintf(RegisMos,"Derrota");
								outtextxy(x+150+70,100+y*(i-Muestra+1),RegisMos);
							}
							else
							{
								setcolor(14);
								sprintf(RegisMos,"Victoria");
								outtextxy(x+150+70,100+y*(i-Muestra+1),RegisMos);
							}
						}
						else if(Modo==3)
						{
							setcolor(12);
							sprintf(RegisMos,"Dificil");
							outtextxy(x+150,100+y*(i-Muestra+1),RegisMos);
							
							if(Score==-1)
							{
								setcolor(15);
								sprintf(RegisMos,"Derrota");
								outtextxy(x+150+70,100+y*(i-Muestra+1),RegisMos);
							}
							else
							{
								setcolor(14);
								sprintf(RegisMos,"Victoria");
								outtextxy(x+150+70,100+y*(i-Muestra+1),RegisMos);
							}
						}
						else if(Modo==4)
						{
							setcolor(13);
							sprintf(RegisMos,"Arcade");
							outtextxy(x+150,100+y*(i-Muestra+1),RegisMos);
							setcolor(13);
							sprintf(RegisMos,"%d pts",Score);
							outtextxy(x+150+70,100+y*(i-Muestra+1),RegisMos);
							
						}
						setcolor(15);
						sprintf(RegisMos,"%s  %s  %d  %s  %d",DiaS,Mes,Dia,Hora,Anyo);
						outtextxy(x+150+100+100,100+y*(i-Muestra+1),RegisMos);
						
						
					}
				}
			}
			if (Muestra<ContCar && Muestra>=(Tandas*Limite))
			{
				for(i=Muestra;i<ContCar;i++)
				{
						
					rewind(Lect);
					for(j=0;j<ContCar-i;j++)
					{
						fscanf(Lect,"%s %d %d %s %s %d %s %d\n",NombreL,&Modo,&Score,DiaS,Mes,&Dia,Hora,&Anyo);
					}
						
				
					sprintf(RegisMos,"%s",NombreL);
					outtextxy(x,100+y*(i-Muestra+1),RegisMos);
						
					if(Modo==1)
					{
						setcolor(11);
						sprintf(RegisMos,"Facil");
						outtextxy(x+150,100+y*(i-Muestra+1),RegisMos);
							
						if(Score==-1)
						{
							setcolor(15);
							sprintf(RegisMos,"Derrota");
							outtextxy(x+150+70,100+y*(i-Muestra+1),RegisMos);
						}
						else
						{
							setcolor(14);
							sprintf(RegisMos,"Victoria");
							outtextxy(x+150+70,100+y*(i-Muestra+1),RegisMos);
						}
					}
					else if(Modo==2)
					{
						setcolor(10);
						sprintf(RegisMos,"Medio");
						outtextxy(x+150,100+y*(i-Muestra+1),RegisMos);
						
						if(Score==-1)
						{
							setcolor(15);
							sprintf(RegisMos,"Derrota");
							outtextxy(x+150+70,100+y*(i-Muestra+1),RegisMos);
						}
						else
						{
							setcolor(14);
							sprintf(RegisMos,"Victoria");
							outtextxy(x+150+70,100+y*(i-Muestra+1),RegisMos);
						}
					}
					else if(Modo==3)
					{
						setcolor(12);
						sprintf(RegisMos,"Dificil");
						outtextxy(x+150,100+y*(i-Muestra+1),RegisMos);
						
						if(Score==-1)
						{
							setcolor(15);
							sprintf(RegisMos,"Derrota");
							outtextxy(x+150+70,100+y*(i-Muestra+1),RegisMos);
						}
						else
						{
							setcolor(14);
							sprintf(RegisMos,"Victoria");
							outtextxy(x+150+70,100+y*(i-Muestra+1),RegisMos);
						}
					}
					else if(Modo==4)
					{
						setcolor(13);
						sprintf(RegisMos,"Arcade");
						outtextxy(x+150,100+y*(i-Muestra+1),RegisMos);
						setcolor(13);
						sprintf(RegisMos,"%d pts",Score);
						outtextxy(x+150+70,100+y*(i-Muestra+1),RegisMos);
							
					}
					
					setcolor(15);
					sprintf(RegisMos,"%s  %s  %d  %s  %d",DiaS,Mes,Dia,Hora,Anyo);
					outtextxy(x+150+100+100,100+y*(i-Muestra+1),RegisMos);
					
						
				}
				
			}
			
			mver();
			
			fclose(Lect);
			free(NombreL);
			bolMostrar=1;
			
			/*sprintf(mos,"%d %d %d %d",Limite,Tandas,Muestra,ContCar);
			stpcpy(RegisMos,mos);
			outtextxy(640/2,480-50,RegisMos);*/
			
		
		}
	
		Equis(0,RED);
		
		if(minlimit(1,50+20-50,480-20-10,50+20+50,480-20+10) && bolSelec[0]!=1)
		{
			bolSelec[0]=1;
			bolSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}	
		else if (minlimit(1,640-50-30-50,480-20-10,640-50-30+50,480-20+10) && bolSelec[0]!=2)
		{
			bolSelec[0]=2;
			bolSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}
		else if (minlimit(1,640/2-50,480-20-10,640/2+50,480-20+10) && bolSelec[0]!=3)
		{
			bolSelec[0]=3;
			bolSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}
		
		if(bolSelec[1])
		{
			
			settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			
			if(bolSelec[0]==1)
			{
				mocultar();
				setcolor(14);
				outtextxy(50+20,480-20,"Anterior");
				mver();
			
			
			}
			else
			{
				mocultar();
				setcolor(15);
				outtextxy(50+20,480-20,"Anterior");
				mver();
				
				
			}
			
			if(bolSelec[0]==2)
			{
				mocultar();
				setcolor(14);
				outtextxy(640-50-30,480-20,"Siguiente");
				mver();
			
			
			}
			else
			{
				mocultar();
				setcolor(15);
				outtextxy(640-50-30,480-20,"Siguiente");
				mver();
				
				
			}
			
			if(bolSelec[0]==3)
			{
				mocultar();
				setcolor(14);
				outtextxy(640/2,480-20,"Salir");
				mver();
			
			
			}
			else
			{
				mocultar();
				setcolor(15);
				outtextxy(640/2,480-20,"Salir");
				mver();
				
				
			}
			
			bolSelec[1]=0;
			
		}
		
		
		if(mclick())
		{
			if(minlimit(1,50+20-50,480-20-10,50+20+50,480-20+10)&&(Muestra>0))
			{
				sound(415.30);
				delay(25);
				nosound();
				delay(25);
				sound(554.37);
				delay(25);
				nosound();
				
				
				Muestra-=Limite;
				bolMostrar=0;
				mocultar();
				setfillstyle(SOLID_FILL,0);
				bar(0,80+20,640,420);
				mver();
				
			}
			else if (minlimit(1,640-50-30-50,480-20-10,640-50-30+50,480-20+10)&&(Muestra+Limite<ContCar))
			{
				sound(415.30);
				delay(25);
				nosound();
				delay(25);
				sound(554.37);
				delay(25);
				nosound();
				
				
				Muestra+=Limite;
				bolMostrar=0;
				mocultar();
				setfillstyle(SOLID_FILL,0);
				bar(0,80+20,640,420);
				mver();
				
			}
			else if (minlimit(1,640/2-50,480-20-10,640/2+50,480-20+10))
			{
				sound(415.30);
				delay(25);
				nosound();
				delay(25);
				sound(554.37);
				delay(25);
				nosound();
				
				bolSalir=1;
				
			}
		}
		
		
		Lectura=0;
		
		while(kbhit())
		{
			Lectura=getch();
			
		}

	}
	
	
	
	
	
}

void Puntajes (void)
{
	int Lectura,x,y,bolSalir,l,j,k,n,ContCarr,ContLetras,bolNombre,bolSelec[2];
	char Car,PRegisMos[30];
	
	int Modo,Score,Dia,Anyo;
	char DiaS[4],Mes[4],Hora[10];
	char *NombreLL;
	
	/*NombreLL =(char*)calloc(15,sizeof(char));*/
	
	
	
	struct Top Mejores[15];
	
	FILE *Lectu;
	
	x=100;
	y=20;
	bolSalir=0;
	ContCarr=0;
	ContLetras=0;
	bolSelec[0]=0;
	bolSelec[1]=0;
	bolNombre=0;
	
	for(i=0;i<15;i++)
	{
		
		Mejores[i].TopScore=0;
		stpcpy(Mejores[i].Name,"Vacio");
		
	}
	

		
			NombreLL=(char*) calloc(15,sizeof(char));
			memset(NombreLL,0,15);
			Lectu=fopen("C:\\FICHEROS\\REGISTRO.txt","r+");
			ContCarr=0;
			do
			{
				Car=fgetc(Lectu);
				
				if(Car=='\n')
					ContCarr++;
				
			}while(Car!=EOF);
			
			rewind(Lectu);
			
			
			for(j=0;j<ContCarr;j++)
			{
				
				
				fscanf(Lectu,"%s %d %d %s %s %d %s %d\n",NombreLL,&Modo,&Score,DiaS,Mes,&Dia,Hora,&Anyo);
				

				
				if(Modo==4)
				{
					if(Mejores[0].TopScore<Score)
					{
						Mejores[0].TopScore=Score;
						stpcpy(Mejores[0].Name,NombreLL);
						
						
					}
				}
			}
			

			for(i=1;i<15;i++)
			{
				rewind(Lectu);
				
				for(j=0;j<ContCarr;j++)
				{
					
					
					fscanf(Lectu,"%s %d %d %s %s %d %s %d\n",NombreLL,&Modo,&Score,DiaS,Mes,&Dia,Hora,&Anyo);
						
					if(Modo==4)
					{
						
						if(Mejores[i].TopScore<=Score && Mejores[i-1].TopScore>=Score)
						{
							bolNombre=0;
							
							for(k=0;k<i;k++)
							{
								ContLetras=0;
								
								if(strlen(Mejores[k].Name)==strlen(NombreLL))
								{
									n=0;
									while(n<strlen(Mejores[k].Name))
									{
										if(Mejores[k].Name[n]!=NombreLL[n])
										{
											ContLetras++;
										}
										
										n++;
									}
								}
								else
								{
									ContLetras++;
								}
								
								if(!ContLetras)
								{
									if(Mejores[k].TopScore<Score)
									{
										Mejores[k].TopScore=Score;
										stpcpy(Mejores[k].Name,NombreLL);
										
									}
									bolNombre=1;
									
								}
								
							}
							
							if(!bolNombre)
							{
								Mejores[i].TopScore=Score;
								stpcpy(Mejores[i].Name,NombreLL);
									
							}
							
						}
					}
				}
				
				
				
			}
			
			fclose(Lectu);
			free(NombreLL);
			
			mocultar();
			setcolor(15);
			setfillstyle(SOLID_FILL,15);
			circle(0,0,100);
			floodfill(0,0,15);
			circle(640,0,100);
			floodfill(639,0,15);
			circle(640,480,100);
			floodfill(639,480-1,15);
			circle(0,480,100);
			floodfill(1,480-1,15);
			
			
			settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			outtextxy(640/2,480-20,"Salir");
			settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			outtextxy((640/2),(480/2)-200,"TOP 15");
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			settextjustify(LEFT_TEXT,CENTER_TEXT);
			setcolor(15);
		
			for(l=0;l<15;l++)
			{
				
				if(l==0)
					setcolor(14);
				else if(l==1)
					setcolor(15);
				else if(l==2)
					setcolor(15);
				else if(l<10)
					setcolor(7);
				else 
					setcolor(8);
				
				sprintf(PRegisMos,"%d.",l+1);
				outtextxy(x,100+y*l,PRegisMos);
				
				outtextxy(x+50,100+y*l,Mejores[l].Name);
				
				sprintf(PRegisMos,"%d pts",Mejores[l].TopScore);
				outtextxy(x+400,100+y*l,PRegisMos);
	
			}	
			
			mver();
	
	while (!bolSalir)
	{
		Equis(0,RED);
		
		if (minlimit(1,640/2-50,480-20-10,640/2+50,480-20+10) && bolSelec[0]!=3)
		{
			bolSelec[0]=3;
			bolSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}
		
		if(bolSelec[1])
		{
			
			settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			
			if(bolSelec[0]==3)
			{
				mocultar();
				setcolor(14);
				outtextxy(640/2,480-20,"Salir");
				mver();
			
			
			}
			else
			{
				mocultar();
				setcolor(15);
				outtextxy(640/2,480-20,"Salir");
				mver();
				
				
			}
			
			bolSelec[1]=0;
			
		}
		
		
		if(mclick())
		{
			if (minlimit(1,640/2-50,480-20-10,640/2+50,480-20+10))
			{
				sound(415.30);
				delay(25);
				nosound();
				delay(25);
				sound(554.37);
				delay(25);
				nosound();
				
				bolSalir=1;
				
			}
		}
		
		
		Lectura=0;
		
		while(kbhit())
		{
			Lectura=getch();
			
		}

	}
	
	
	
}

void Ayuda (void)
{
	
	int Lectura,x,y,bolSalir,bolMostrar,bolSelec[2];
	
	char *Ayudar;
	
	FILE *Abrir;
	
	x=30;
	y=100;
	bolSalir=0;
	
	mocultar();
	setcolor(15);
	
	setfillstyle(SOLID_FILL,15);
	circle(640,480,100);
	floodfill(639,480-1,15);
	circle(0,480,100);
	floodfill(1,480-1,15);
			
			
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(640/2,480-20,"Regresar");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy((640/2),(480/2)-200,"AYUDA");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	settextjustify(LEFT_TEXT,CENTER_TEXT);
	setcolor(15);
	
	Abrir = fopen("C:\\FICHEROS\\AYUDA.txt","r+");
	
	Ayudar=(char*) calloc(100,sizeof(char));
	
	fflush(stdin);
	
	fgets(Ayudar,100,Abrir);
	Ayudar[strlen(Ayudar)-1]='\0';
	outtextxy(x,y+20,Ayudar);
	
	fgets(Ayudar,100,Abrir);
	Ayudar[strlen(Ayudar)-1]='\0';
	outtextxy(x,y+40,Ayudar);
	
	fgets(Ayudar,100,Abrir);
	Ayudar[strlen(Ayudar)-1]='\0';
	outtextxy(x,y+60,Ayudar);
	
	
	fgets(Ayudar,100,Abrir);
	Ayudar[strlen(Ayudar)-1]='\0';
	outtextxy(x,y+90,Ayudar);
	
	fgets(Ayudar,100,Abrir);
	Ayudar[strlen(Ayudar)-1]='\0';
	outtextxy(x,y+110,Ayudar);
	
	fgets(Ayudar,100,Abrir);
	Ayudar[strlen(Ayudar)-1]='\0';
	outtextxy(x,y+130,Ayudar);
	
	
	fgets(Ayudar,100,Abrir);
	Ayudar[strlen(Ayudar)-1]='\0';
	outtextxy(x,y+160,Ayudar);
	
	fgets(Ayudar,100,Abrir);
	Ayudar[strlen(Ayudar)-1]='\0';
	outtextxy(x,y+180,Ayudar);
	
	fgets(Ayudar,100,Abrir);
	Ayudar[strlen(Ayudar)-1]='\0';
	outtextxy(x,y+200,Ayudar);
	
	
	fgets(Ayudar,100,Abrir);
	Ayudar[strlen(Ayudar)-1]='\0';
	outtextxy(x,y+230,Ayudar);
	
	fgets(Ayudar,100,Abrir);
	Ayudar[strlen(Ayudar)-1]='\0';
	outtextxy(x,y+250,Ayudar);
	
	free(Ayudar);
	fclose(Abrir);
	
	mver();
	
	while (!bolSalir)
	{
		Equis(15,RED);
		
		if (minlimit(1,640/2-50,480-20-10,640/2+50,480-20+10) && bolSelec[0]!=3)
		{
			bolSelec[0]=3;
			bolSelec[1]=1;
			sound(987.77);
			delay(25);
			nosound();
		}
		
		if(bolSelec[1])
		{
			
			settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			
			if(bolSelec[0]==3)
			{
				mocultar();
				setcolor(14);
				outtextxy(640/2,480-20,"Regresar");
				mver();
			
			
			}
			else
			{
				mocultar();
				setcolor(15);
				outtextxy(640/2,480-20,"Regresar");
				mver();
				
				
			}
			
			bolSelec[1]=0;
			
		}
		
		
		if(mclick())
		{
			if (minlimit(1,640/2-50,480-20-10,640/2+50,480-20+10))
			{
				sound(415.30);
				delay(25);
				nosound();
				delay(25);
				sound(554.37);
				delay(25);
				nosound();
				
				bolSalir=1;
				
			}
		}
		
		while(kbhit())
		{
			Lectura=getch();
			/*
			if(Lectura==27)
				bolSalir=1;*/

		}
		
	}
	
	
}

void Equis(int Color1,int Color2)
{
	int ocultar,TraSound;
	
	
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	
	if(!bolExit[2])
	{
		setcolor(Color1);
		mocultar();
		outtextxy(640-15,15,"X");
		mver();
		bolExit[2]=1;
	}
	
	
	if(minlimit(1,640-15-15,15-15,640-15+15,15+15)&& bolExit[0]!=1)
	{	
		
		bolExit[0]=1;
		bolExit[1]=1;
		sound(987.77);
		delay(25);
		nosound();
	}
	
	if(bolExit[1])
	{
		if(bolExit[0])
		{
			setcolor(Color2);
			mocultar();
			outtextxy(640-15,15,"X");
			mver();
			
		}
		else
		{
			setcolor(Color1);
			mocultar();
			outtextxy(640-15,15,"X");
			mver();
			
				
		}
		
		bolExit[1]=0;
		
	}
	
	
	
	if(mclick()&& minlimit(1,640-15-15,15-15,640-15+15,15+15))
	{
		sound(207.65);
		delay(25);
		nosound();
		delay(25);
		sound(277.18);
		delay(25);
		nosound();
		
		mocultar();
		delay(1000);
			
		ocultar=0;
		TraSound=469.25;
			

		while(ocultar<=640)
		{
			setfillstyle(SOLID_FILL,0);
			bar(0,0,ocultar,480);
			ocultar+=64;
			sound(TraSound);
			TraSound-=26.16;
			delay(100);
		}
						
		nosound();

		setfillstyle(SOLID_FILL,0);
		bar(0,0,640,480);
			
		mver();
			
		main();
	}
		
		
	
}


