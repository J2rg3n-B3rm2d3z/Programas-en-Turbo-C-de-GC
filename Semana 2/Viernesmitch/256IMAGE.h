#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

#define VAR 0

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


void setpal(char col,char r,char g,char b);
void mostrar_imagen(int x,int y,char* NomArchivo,int pal);
void cambiar_pal(struct valor_rgb *pal);


void mostrar_imagen(int x,int y,char* NomArchivo,int pal)
{
	struct cabecera bmp_cab;
	struct info_general bmp_info;
	struct valor_rgb *rgb;
	FILE *f;
	char *linea;
	int resto;
	unsigned long int posicion;
	int i;
	
	f = fopen(NomArchivo,"rb");
	
	if (!f)
	{
		 printf("\n  ERROR FATAL: el archivo no existe o esta protegido...");
		 exit(0);
	}
 
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
	
	if (!(bmp_cab.ident[0] == 'B' && bmp_cab.ident[1] == 'M'))
	{
		printf("\n  ERROR FATAL: el archivo no existe o esta protegido...");
		exit(0);
	}
	
	posicion = ftell(f); /* tomamos la posicion del puntero del archivo */
	if(pal)
	{
		cambiar_pal(rgb);
	}
	
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

	fseek(f, posicion, SEEK_SET); /* restauramos la posicion inicial del puntero */
	
	free(rgb);
	free(linea);
	fclose(f);
	
	
}

void cambiar_pal(struct valor_rgb *pal)
{
register int i;

for (i = 0; i < 256; i++)
 setpal( i, pal[i-VAR].rojo / 4, pal[i-VAR].verde / 4, pal[i-VAR].azul / 4);
}

void setpal(char col,char r,char g,char b)
{
	 outportb(0x3c8,col);
	 outportb(0x3c9,r);
	 outportb(0x3c9,g);
	 outportb(0x3c9,b);
}