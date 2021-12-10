#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <mouse.h>

#define VAR 0
#define INVALIDO -1
#define FALLA 0
#define EXITO 1
#define KB_ESC 27

/* MACROS PARA LAS FUNCIONES GRAFICAS 

#define SEG_VIDEO 0xA000
#define M320x200 0x13
#define MTexto 0x3*/

struct cabecera 
{
	 char ident[2];
	 unsigned long int tam;
	 char reservado[4];
	 unsigned long int offset;
};

struct info_general 
{
	 unsigned long int tam_cabecera;
	 unsigned long int anchura; /* en pixels */
	 unsigned long int altura; /* en pixels */
	 int planos;
	 int tam_pixel; /* tama¤o en bits de cada pixel */
	 unsigned long int compresion;
	 unsigned long int tam_imagen; /* en bytes */
	 unsigned long int h_resolution;
	 unsigned long int v_resolution;
	 unsigned long int num_color; /* numero de colores utilizados */
	 unsigned long int color_imp; /* numeros de colores importantes */
};

struct valor_rgb 
{
	 unsigned char azul;
	 unsigned char verde;
	 unsigned char rojo;
	 unsigned char reservado;
};


void modo_video();
void setpal(char col,char r,char g,char b);

/*void putpixel(unsigned int x, unsigned int y, unsigned char color);*/
/*-------------------------------------------------------------------------*/

char verifica(char *fname);
void mostrar_pal(void);
void carga(void);
void menu(void);
void presentacion(void);
void info_general(void);
void paleta(void);
void mostrar_imagen(void);
void cambiar_pal(struct valor_rgb *pal);
void despedida(void);

struct cabecera bmp_cab;
struct info_general bmp_info;
struct valor_rgb *rgb;
FILE *f;
char fname[50];


int main()
{
	presentacion();
	fclose(f);
	free(rgb); /* liberamos la memoria utilizada */

return 0;
}

void carga(void)
{
	register int i;

	/* leemos la cabecera del archivo */
	fread( &bmp_cab, sizeof(struct cabecera), 1, f);
	/* leemos la informacion general del archivo */
	fread( &bmp_info, sizeof(struct info_general), 1, f);

	/*leemos todos los colores que existen en la imagen */
	if (!bmp_info.num_color) /* si se usan todos los colores */
	 bmp_info.num_color = 1 << bmp_info.tam_pixel; /* calculamos dependiendo del numero de bits que ocupa cada pixel */

	/* reservamos memoria dinamica para la tabla de colores RGB */
	rgb = (struct valor_rgb *) malloc (bmp_info.num_color * sizeof(struct valor_rgb));

	fread(rgb, bmp_info.num_color * sizeof(struct valor_rgb), 1, f);
}

void presentacion(void)
{
	char control;

	clrscr();

	printf("%55s","---VISUALIZADOR DE IMAGENES BMP---");
	printf("\n\n\n  Introduzca el nombre y ruta de ser necesario");
	printf("\n  ARCHIVO: ");
	gets(fname);
	if (!fname[0])
	 exit(0);

	control = verifica(fname);

	if (control == FALLA)
	 {
		  printf("\n  ERROR FATAL: el archivo no existe o esta protegido...");
		  exit(1);
	 }
	if (control == INVALIDO)
	 {
		  printf("\n  ERROR FATAL: el archivo no es un BMP valido... ");
		  exit(1);
	 }

	/* llamamos al menu principal */
	menu();
}

char verifica(char *fname)
{
	f = fopen(fname,"rb");

	if (!f)
	 return (FALLA);

	carga(); /* leemos y almacenamos del archivo */

	/* comprobamos que sea un archivo valido BMP */
	if (bmp_cab.ident[0] == 'B' && bmp_cab.ident[1] == 'M')
	 return (EXITO);
	else
	 return (INVALIDO);

}

void menu(void)
{
char opcion;

for (;;)
 {
  clrscr();
  printf("\n\n   (1) INFORMACION GENERAL DEL ARCHIVO");
  printf("\n\n   (2) PALETA DE COLORES USADAS");
  printf("\n\n   (3) MOSTRAR PALETA");
  printf("\n\n   (4) VISUALIZAR IMAGEN");
  printf("\n\n   (5) SALIR");
  printf("\n\n   OPCION: ");
  opcion = getche();

  switch (opcion)
   {
    case '1': info_general(); break;
    case '2': paleta(); break;
    case '3': mostrar_pal(); break;
    case '4': mostrar_imagen(); break;
    case '5': despedida();
   }
  } /* termina bucle for(;;) */
}

void info_general(void)
{

 clrscr();
 printf("%35s%s>\n","<",fname);
 printf("\n  Tama¤o del archivo: %ld bytes",bmp_cab.tam);
 printf("\n  Offset del archivo: %ld",bmp_cab.offset);
 printf("\n  Tama¤o de la cabecera: %d bytes",bmp_info.tam_cabecera);
 printf("\n  Anchura: %d pixels",bmp_info.anchura);
 printf("\n  Altura: %d pixels",bmp_info.altura);
 printf("\n  Numero de planos: %d",bmp_info.planos);
 printf("\n  Numero de bits por pixel: %d bits",bmp_info.tam_pixel);
 printf("\n  Compresion: %d ",bmp_info.compresion);
 printf("\n  Tama¤o de la imagen: %ld bytes",bmp_info.tam_imagen);
 printf("\n  Resolucion horizontal: %d pixels/metros",bmp_info.h_resolution);
 printf("\n  Resolucion vertical: %d pixels/metros",bmp_info.v_resolution);
 printf("\n  Numero de colores utilizados: %d colores",bmp_info.num_color);
 printf("\n  Numero de colores importantes: %d colores",bmp_info.color_imp);

 printf("\n\n\n  PRESIONE CUALQUIER TECLA PARA CONTINUAR...");

 getch();
}

void cambiar_pal(struct valor_rgb *pal)
{
register int i;

for (i = 0; i < 256; i++)
 setpal( i, pal[i-VAR].rojo / 4, pal[i-VAR].verde / 4, pal[i-VAR].azul / 4);
}

void paleta(void)
{
	register int i,j;
	char opcion;

	clrscr();

	printf("\n %10s    %10s     %10s     %10s\n\n","Color","Rojo","Verde","Azul");
	for (i = 0, j = 1; i <= (bmp_info.num_color); i++, j++)
	 {
		  if (j == 20 || i == (bmp_info.num_color) )
		   {
				j = 0;
				i--;
				gotoxy(1,25);
				printf(" Presione [ESC] para salir o cualquier tecla para continuar....");
				opcion = getch();

				if (opcion == KB_ESC)
				 break;
				if (i+1 == (bmp_info.num_color))
				 break;

				clrscr();
				printf("\n %10s    %10s    %10s    %10s\n\n","Color","Rojo","Verde","Azul");
				continue;
		   }
		  printf("\n %10d   %10d    %10d    %10d", i, rgb[i].rojo, rgb[i].verde, rgb[i].azul);
	 }
}

void mostrar_imagen(void)
{
	register int x,y;
	char *linea;
	int resto;
	unsigned long int posicion;
	posicion = ftell(f); /* tomamos la posicion del puntero del archivo */

	modo_video();
	cambiar_pal(rgb);
	
	
	/* reservamos memoria suficiente para albergar una linea de pixeles */
	linea = (char *) malloc (bmp_info.anchura);

	/* calculamos la cantidad de bytes necesario que sumado con la anchura
	   sea un multiplo de cuatro */
	resto = (4 * ((bmp_info.anchura + 3) >> 2)) - bmp_info.anchura;

	for (y = bmp_info.altura - 1; y >= 0; y--)
	 {
		 fread(linea, bmp_info.anchura, 1, f);
		  for (x = 0; x < bmp_info.anchura; x++)
			putpixel(x,y,linea[x]);
		 fseek(f, resto, SEEK_CUR);
	 }
	 
	mver();
	mlimit(1,0,0,getmaxx(),getmaxy());
	 
	getch();

	fseek(f, posicion, SEEK_SET); /* restauramos la posicion inicial del puntero */

	closegraph();
}

void mostrar_pal(void)
{
	register int i,j;

	modo_video();

	cambiar_pal(rgb);

	for (i = 0; i < 256; i++)
	 for (j = 0; j <= 50; j++)
	  putpixel(i,j,i);
	  
	mver();
	mlimit(1,0,0,getmaxx(),getmaxy());
	getch();

	closegraph();
}

void despedida(void)
{
	 clrscr();
	 gotoxy(20,13);
	 printf("ESPERO QUE HAYA DISFRUTADO DEL PROGRAMA...");
	 getch();
	 exit(0);
}

/* ----FUNCIONES GRAFICAS ESCRITAS EN ENSAMBLADOR PARA SU MAYOR RAPIDEZ---- */

int huge DetectVGA256()
{
	return 4;
}
void modo_video()
{
	 int a=DETECT,b;
	 installuserdriver("Svga256",DetectVGA256);
	 initgraph(&a,&b,"c:\\tc20\\bin");
}



void setpal(char col,char r,char g,char b)
{
	 outportb(0x3c8,col);
	 outportb(0x3c9,r);
	 outportb(0x3c9,g);
	 outportb(0x3c9,b);
}

