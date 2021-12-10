#include<stdio.h>
#include<graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void castillo (void);
void montana();
void pesca();
void nubes();
void main (void)
{
int adap= DETECT,modo,codigo, maxcol=3 ,  blue=1 ;
initgraph(&adap,&modo,"c:\\tc20\\bin");

cleardevice();

castillo();
nubes();
getch();
closegraph();
}
void nubes(){
		/*nubes*/
setfillstyle(SOLID_FILL, 15);
/*
bar(20,9,26,11);
bar(18,12,28,14);
bar(20,15,26,17);

bar(35,8,48,11);
bar(33,12,50,15);
bar(35,16,48,19);*/

bar(60,11,80,14);
bar(56,15,83,18);
bar(54,19,85,22);
bar(56,23,83,26);
bar(60,27,80,30);


bar(160,13,180,17);
bar(156,18,183,21);
bar(154,21,185,25);
bar(156,26,183,29);
bar(160,30,180,34);


bar(260,11,280,14);
bar(256,15,283,18);
bar(254,19,285,22);
bar(256,23,283,26);
bar(260,27,280,30);


bar(360,13,380,17);
bar(356,18,383,21);
bar(354,21,385,25);
bar(356,26,383,29);
bar(360,30,380,34);


bar(460,11,480,14);
bar(456,15,483,18);
bar(454,19,485,22);
bar(456,23,483,26);
bar(460,27,480,30);


bar(560,13,580,17);
bar(556,18,583,21);
bar(554,21,585,25);
bar(556,26,583,29);
bar(560,30,580,34);

bar(660,11,680,14);
bar(656,15,683,18);
bar(654,19,685,22);
bar(656,23,683,26);
bar(660,27,680,30);
settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
setcolor(0);
outtextxy(42,175, "Castillo");
setcolor(15);
outtextxy(46,177, "Castillo");

	}






void castillo (void){
	int tri [] = {463,459, 484,347, 500,459};
	int tris [] = {13,456, 53,337, 91,456};


/*montana*/
int montana1[]={57,409, 229,409, 147,240, 57,409};
int montana2[]={168,409, 521,409, 353,57, 168,409};
int montana3[]={359,409, 565,409, 465,191, 359,409};
int punta1[]={113,305, 133,288, 144,310, 160,301, 167,310, 177,302, 147,240, 113,305};
int punta2[]={300,160, 324,152, 338,186, 348,169, 386,185, 405,167, 353,57, 300,160};
int punta3[]={429,267, 446,262, 452,278, 469,268, 477,279, 499,266, 465,191, 429,267};


	/*pasto*/
setfillstyle(SOLID_FILL,2);
bar(0,376,639,479);
	/*cielo*/
setfillstyle(SOLID_FILL,9);
bar(0,0,639,375);



	setfillstyle(SOLID_FILL, 2);

/*montana1*/
fillpoly(4, montana1);
fillpoly(4, montana2);
fillpoly(4, montana3);

setfillstyle(SOLID_FILL, 8);
fillpoly(8, punta1);
fillpoly(8, punta2);
fillpoly(8, punta3);


	/*amarillo*/
setfillstyle(INTERLEAVE_FILL,6);
bar(523,272,598,479);
	/*t4 naranja*/
setfillstyle(INTERLEAVE_FILL,14);
bar(518,245,603,271);
	/*cuadritos1 naranja*/
bar(518,231,537,244);
	/*cuadritos2 naranja*/
bar(552,231,571,244);
	/*cuadritos3 naranja*/
bar(585,231,603,244);
	/*palito de bandera*/
setfillstyle(SOLID_FILL,4);
bar(590,174,591,230);
	/*bandera*/
bar(592,174,614,194);

	/*negro*/
setfillstyle(INTERLEAVE_FILL,6);
bar(70,379,523,479);
	/*gris*/
bar(405,93,476,378);
	/*t3 gris azulado*/
setfillstyle(INTERLEAVE_FILL,14);
bar(397,69,484,92);
	/*cuadritos1 gris azulado*/
bar(397,51,415,68);
	/*cuadritos2 gris azulado*/
bar(429,51,450,68);
	/*cuadritos1 gris azulado*/
bar(466,51,484,68);




	/*celeste*/
setfillstyle(INTERLEAVE_FILL,6);
bar(70,280,327,378);
	/*morado*/
bar(70,250,141,279);
/*bandera*/
setfillstyle(SOLID_FILL,4);
bar(100,125,103,249);
bar(104,125,125,145);

	/*verde*/
setfillstyle(INTERLEAVE_FILL,6);
bar(189,92,260,279);
	/*t1 verde oscuro*/
setfillstyle(INTERLEAVE_FILL,14);
bar(180,69,267,91);
	/*cuadritos1 verde oscuro*/
bar(180,51,200,68);
	/*cuadritos2 verde oscuro*/
bar(215,51,234,68);
	/*cuadritos3 verde oscuro*/
bar(250,51,267,68);


	/*rojo*/
setfillstyle(INTERLEAVE_FILL,6);
bar(190,158,327,279);
	/*cafe*/
bar(328,158,404,222);
	/*t2 rojo oscuro*/
setfillstyle(INTERLEAVE_FILL,14);
bar(261,140,404,157);
/*cuadritos1 rojo oscuro*/
bar(261,125,284,139);
/*cuadritos2 rojo oscuro*/
bar(301,125,322,139);
/*cuadritos3 rojo oscuro*/
bar(341,125,362,139);
/*cuadritos4 rojo oscuro*/
bar(381,125,404,139);
	/*rosita*/
setfillstyle(INTERLEAVE_FILL,6);
bar(381,223,404,378);

	/*borde entre amarillo y gris*/
setfillstyle(INTERLEAVE_FILL,14);
bar(316,362,538,378);
	/*cuadritos entre amarillo y gris*/
bar(316,348,334,362);
	/*cuadritos entre amarillo y gris*/
bar(350,348,368,362);
	/*cuadritos entre amarillo y gris*/
bar(384,348,402,362);
	/*cuadritos entre amarillo y gris*/
bar(418,348,436,362);
	/*cuadritos entre amarillo y gris*/
bar(452,348,470,362);
	/*cuadritos entre amarillo y gris*/
bar(486,348,504,362);
	/*cuadritos entre amarillo y gris*/
bar(520,348,538,362);

/*PUERTAS*/
setfillstyle(INTERLEAVE_FILL,14);
bar(545,436,580,479);
bar(426,310,455,377);
bar(189,392,257,479);
/*PUERTA VENTANA*/
setfillstyle(INTERLEAVE_FILL,8);
bar(231,408,247,423);
bar(440,315,452,325);
bar(563,440,574,450);
/*VENTANA*/
setfillstyle(HATCH_FILL,8);
bar(552,291,571,321);
bar(552,379,571,408);
bar(427,135,454,171);
bar(427,225,454,258);
bar(214,127,237,160);
bar(94,255,114,278);
bar(264,313,288,354);
rectangle(10,10,628,479);
/*arbol*/

setfillstyle(INTERLEAVE_FILL, 2);
fillpoly (3,tri);
fillpoly (3,tris);
setfillstyle(SOLID_FILL, 2);
bar(477,460,485,479);

/*bandera*/
setfillstyle(SOLID_FILL, 6);
bar(483,300,485,345);
bar(328,40,330,140);
/*arbolito*/bar(47,457,55,479);
setfillstyle(SOLID_FILL, 1);
bar(331,40,370,65);
bar(486,300,505,320);
}
void pesca(void){

int arbol[]={1,331, 38,331, 38,250, 69,248, 69,285, 97,285, 99,205, 98,203, 129,205, 132,128, 191,124, 189,82, 223,85, 222,45, 251,45, 251,1, 1,1, 1,331};
cleardevice();
setfillstyle(SOLID_FILL, 9);
bar(0,0,640,480);

	/*AGUITA*/
setfillstyle(SOLID_FILL, 3);
bar(0,412,640,428);
setfillstyle(SOLID_FILL, 15);
bar(0,410,640,411);
setfillstyle(SOLID_FILL, 1);
/*mar del pueblito*/
bar(0,429,640,450);
/*casa de lin*/
setfillstyle(SOLID_FILL, 0);
bar(0,451,640,480);

/*PRINGAS*/

putpixel(174,380,WHITE);
putpixel(167,391,WHITE);
putpixel(177,400,WHITE);
putpixel(175,382,WHITE);
putpixel(168,392,WHITE);
putpixel(178,400,WHITE);

putpixel(168,393,WHITE);
putpixel(175,401,WHITE);
putpixel(184,400,WHITE);


putpixel(194,380,WHITE);
putpixel(187,391,WHITE);
putpixel(197,400,WHITE);
putpixel(195,382,WHITE);
putpixel(188,392,WHITE);
putpixel(198,400,WHITE);

putpixel(188,393,WHITE);
putpixel(195,401,WHITE);
putpixel(204,400,WHITE);

putpixel(188,373,WHITE);
putpixel(195,391,WHITE);
putpixel(204,390,WHITE);


putpixel(208,393,WHITE);
putpixel(215,401,WHITE);
putpixel(224,400,WHITE);

putpixel(228,373,WHITE);
putpixel(215,391,WHITE);
putpixel(244,390,WHITE);


putpixel(228,393,WHITE);
putpixel(215,401,WHITE);
putpixel(244,400,WHITE);

putpixel(224,380,WHITE);
putpixel(227,391,WHITE);
putpixel(227,400,WHITE);





putpixel(274,380,WHITE);
putpixel(267,391,WHITE);
putpixel(277,400,WHITE);
putpixel(275,382,WHITE);
putpixel(268,392,WHITE);
putpixel(278,400,WHITE);

putpixel(268,393,WHITE);
putpixel(275,401,WHITE);
putpixel(284,400,WHITE);


putpixel(294,380,WHITE);
putpixel(287,391,WHITE);
putpixel(297,400,WHITE);
putpixel(295,382,WHITE);
putpixel(288,392,WHITE);
putpixel(298,400,WHITE);

putpixel(288,393,WHITE);
putpixel(295,401,WHITE);
putpixel(304,400,WHITE);

putpixel(288,373,WHITE);
putpixel(295,391,WHITE);
putpixel(304,390,WHITE);



putpixel(165,382,WHITE);
putpixel(168,392,WHITE);
putpixel(168,400,WHITE);

putpixel(168,393,WHITE);
putpixel(125,401,WHITE);
putpixel(112,400,WHITE);

/*CERCO*/
setfillstyle(INTERLEAVE_FILL, 6);
bar(319,296,618,327);
bar(347,253,371,375);
bar(439,253,462,409);
bar(527,253,552,409);

setcolor(0);
rectangle(347,253,371,375);
rectangle(319,296,618,327);
rectangle(439,253,462,409);
rectangle(527,253,552,409);



/*PIEDRA*/
setfillstyle(SOLID_FILL, 8);
bar(347,376,371,450);
bar(372,396,402,450);
bar(620,367,639,409);
/*BLANCA*/
setfillstyle(SOLID_FILL, 15);
bar(620,296,639,367);


setcolor(0);
rectangle(620,296,639,367);
rectangle(347,376,371,450);
rectangle(372,396,402,450);
rectangle(620,367,639,409);

nubes();

/*ARBOL*/
setcolor(2);
setfillstyle(INTERLEAVE_FILL, 2);
fillpoly(17, arbol);

}
