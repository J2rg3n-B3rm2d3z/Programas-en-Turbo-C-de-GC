#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>
#include <dos.h>
#include <mouse.h>
#include <graphics.h>

void EVA();
void PLANTA();
void Text3D(int x, int y, int depth, int bgcolor, int fcolor, char *str);
void main(void)
{
	int adap= DETECT,modo,x,y,on;
	int i=0;
	initgraph(&adap,&modo,"c:\\tc20\\bin");
	cleardevice();
	setfillstyle(SOLID_FILL,0);
	bar(0,0,640,480);
	EVA();
	PLANTA();
	for(i=0;i<2000;i++)
    {
      putpixel(rand()%640,rand()%480,rand()%256);
    }
	settextstyle(8,0,4);
	Text3D(240,400,2,3,2,"WALL-E...");
	getch();
}
void EVA()
{
	/*setlinestyle (SOLID_LINE, THICK_WIDTH, 3);
	setcolor(7);*/
	/*----DIBUJAR A EVA---*/
    setcolor(15);
    floodfill(320,172,WHITE);
	circle(320, 172, 50);/*Rostro*/
	arc(320,353,180,360,50);/*Parte inferior del currpo*/
    floodfill(320,353,WHITE);
	line(270,230,270,360);/*Linea lateral izquierda del cuerpo*/
	line(370,230,370,360);/*Linea lateral derecha del cuerpo*/
	setcolor(15);
	fillellipse(386,290,12,70);/*Brazo derecho*/
    fillellipse(253,290,12,70);/*Brazo izquierdo*/
    line(270,230,370,230);/*linea que cierra la forma del cuerpo*/

    /*fillellipse(319,168,40,25);*/
    arc(319,183,340,200,37);/*Parte interior de la cara(la parte negra)*/
    line(284,196,354,196);/*Linea que cierra la cara*/
	setfillstyle(SOLID_FILL,15);/*Relleno de figuras*/
	floodfill (387,285 , WHITE);
	floodfill (253,287 , WHITE);
	floodfill (320,350 , WHITE);
	floodfill (320,123 , WHITE);
	setfillstyle(SOLID_FILL,8);
	floodfill (286,194 , WHITE);
	/*Ojos de EVA*/
	setcolor(1);
	setlinestyle (SOLID_LINE, THICK_WIDTH,3);
	arc(301,180,0,180,10);
	setlinestyle (SOLID_LINE, THICK_WIDTH,3);
	arc(341,180,0,180,10);
   /*-----------------------------------------------------*/
}
void PLANTA()
{
	setlinestyle (SOLID_LINE, THICK_WIDTH, 3);
	setcolor(7);
	/*frasco*/
	line(517,405,517,449);
	line(519,451,527,451);
	line(528,454,581,454);
	line(582,451,590,451);
	line(592,449,592,405);
	line(589,404,589,402);
	line(586,405,586,406);
	line(586,408,582,408);
	line(586,401,586,400);
	line(584,399,584,397);
	line(582,396,582,388);
	line(580,398,572,398);
	line(580,386,529,386);
	line(527,388,527,396);
	line(525,397,525,399);
	line(523,400,523,401);
	line(520,402,520,404);
	line(523,405,523,406);
	line(525,408,530,408);
	line(529,398,537,398);
	/*tierra*/
	setcolor(0);
	setlinestyle (SOLID_LINE, THICK_WIDTH, 1);
	line(524,419,585,419);
	line(585,419,585,420);
	line(586,421,588,421);
	line(588,421,588,444);
	line(588,444,586,444);
	line(585,445,585,447);
	line(585,447,579,447);
	line(578,448,578,449);
	line(578,449,531,449);
	line(531,449,531,448);
	line(530,447,523,447);
	line(523,447,523,445);
	line(522,444,521,444);
	line(521,444,521,421);
	line(521,421,523,421);
	line(524,420,524,419);
	setfillstyle(SOLID_FILL,6);
	bar(525,420,584,446);
	bar(587,422,522,443);
	setcolor(6);
	line(531,447,578,447);
	line(532,448,577,448);
	putpixel(525,421,6);
	putpixel(585,421,6);
	putpixel(585,444,6);
	putpixel(523,444,6);
	line(524,444,524,446);
	setfillstyle(SOLID_FILL,0);
	bar(528,426,530,427);
	bar(533,431,535,432);
	bar(536,442,537,444);
	bar(550,431,552,432);
	bar(560,436,561,437);
	bar(562,442,564,444);
	bar(572,436,576,437);
	bar(574,440,576,441);
	bar(579,440,581,441);
	bar(577,428,578,430);
	bar(579,420,581,423);
	bar(574,420,576,425);
	bar(576,425,533,424);
	bar(570,420,571,423);
	/*planta*/
	setcolor(10);
	setlinestyle (SOLID_LINE, THICK_WIDTH,1);
	
	line(548,423,548,363);
	line(549,423,549,363);
	line(550,362,550,352);
	line(551,362,551,352);
	line(548,351,548,345);
	line(549,351,549,345);
	/*petalo superior*/
	setcolor(GREEN);
	setlinestyle (SOLID_LINE, THICK_WIDTH,3);
	line(547,343,538,343);
	line(534,339,534,335);
	line(536,333,544,333);
	line(545,336,547,336);
	setfillstyle(SOLID_FILL,GREEN);
	bar(548,337,549,341);
	bar(536,340,537,341);
	/**/
	bar(553,340,559,341);
	bar(560,342,561,346);
	bar(559,347,555,348);
	bar(554,346,553,345);
	bar(552,344,550,342);
	setfillstyle(SOLID_FILL,10);
	bar(536,335,544,339);
	bar(538,341,547,338);
	/**/
	bar(553,344,559,342);
	bar(559,342,555,346);
	setcolor(GREEN);
	setlinestyle (SOLID_LINE, THICK_WIDTH,3);
	line(547,367,545,367);
	line(544,364,543,364);
	setcolor(GREEN);
	setlinestyle (SOLID_LINE, THICK_WIDTH,1);
	line(542,362,540,362);
	line(547,357,545,357);
	setcolor(10);
	line(544,357,543,357);
	line(543,357,544,357);
	setfillstyle(SOLID_FILL,GREEN);
	bar(543,356,547,354);
	bar(542,357,541,358);
	bar(540,359,521,360);
	bar(525,357,537,358);
	bar(522,359,527,360);
	bar(543,359,544,360);
	setfillstyle(SOLID_FILL,10);
	bar(541,359,542,360);
	/**/
	setcolor(GREEN);
	line(548,407,548,418);
	line(548,363,548,389);
	line(548,345,548,351);
	line(550,352,550,362);
	setfillstyle(SOLID_FILL,GREEN);
	bar(550,359,551,362);
	/*petalo 3*/
	bar(549,376,552,377);
	bar(549,380,554,382);
	line(555,379,556,379);
	bar(553,374,556,375);
	bar(557,376,559,378);
	setfillstyle(SOLID_FILL,10);
	bar(550,378,554,379);
	bar(553,376,556,378);
	/*planta 2*/
	bar(562,411,564,423);
	bar(560,405,561,410);
	bar(553,400,561,401);
	bar(555,397,559,404);
	bar(560,402,569,404);
	bar(565,400,566,406);
	setcolor(GREEN);
	line(561,405,561,410);
	line(564,414,564,418);
	setlinestyle (SOLID_LINE, THICK_WIDTH,3);
}
void Text3D(int x, int y, int depth, int bgcolor, int fcolor, char *str)
{
  int i;
  setcolor(bgcolor);
  for(i = 0; i < depth; i++)
  {
	  outtextxy(x+i,y+i,str);
  }
  setcolor(fcolor);
  outtextxy(x+i,y+i,str);
	
}
