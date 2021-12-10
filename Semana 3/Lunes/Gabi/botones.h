#include<stdio.h>
#include<conio.h>
#include<graphics.h>

#include<string.h>

int* lengthText(int x,int y,char far *text,int tipo_text,int sizetext);
int textboton(int x,int y,char far *text,int tipo_text,int sizetext){
	int reto=0,pixel,modo=1;
	int *tm;

	int xx,yy;
	int color=0;
	tm=lengthText(x,y,text,tipo_text,sizetext);
	setcolor(color);
	rectangle(x-10,y-6,tm[0]+10,tm[1]+6);
	rectangle(x-14,y-8,tm[0]+14,tm[1]+8);
	setfillstyle(SOLID_FILL,7);
	floodfill(x-8,y-4,color);
	setfillstyle (SOLID_FILL, 7);
	floodfill(x-13,y-7,color);
	line(x-14,y-8,x-10,y-6);
	line(x-14,tm[1]+8,x-10,tm[1]+6);
	line(tm[0]+10,y-6,tm[0]+14,y-8);
	line(tm[0]+10,tm[1]+6,tm[0]+14,tm[1]+8);
	xx=((tm[0]-x)/2)+x;
	yy=((tm[1]-y-4)/2)+y;
	settextstyle (tipo_text, HORIZ_DIR , sizetext);
	settextjustify(CENTER_TEXT ,CENTER_TEXT);
	outtextxy(xx,yy,text);
	
	
	
	if((mxpos(modo)>=x-14) &&
			(mxpos(modo)<=tm[0]+14) &&
			(mypos(modo)>=y-8) &&
			(mypos(modo)<=tm[1]+8)){
			pixel=getpixel(x-10+2,y-6+2);
			setcolor(0);
			setlinestyle (3, 0, 1);
			rectangle(x-10+2,y-6+2,tm[0]+10-2,tm[1]+6-2);
			setcolor(pixel);
			delay(90);
			setlinestyle (3, 0, 1);
			rectangle(x-10+2,y-6+2,tm[0]+10-2,tm[1]+6-2);
			setlinestyle (0, 0, 1);
			reto=1;
		}else{
		reto=0;
		}
	return reto;
}

int* lengthText(int x,int y,char far *text,int tipo_text,int sizetext){
	int x1=1,y1=1;
	static int tm[2];
	fflush(stdin);
	
	settextstyle (tipo_text, HORIZ_DIR , sizetext);
	if(tipo_text>=0 && tipo_text<=4){
		if(sizetext>=1 && sizetext<=10){
			y1=textheight(text) + y;
			x1=textwidth(text) + x;
		}
	}
	tm[0]=x1;
	tm[1]=y1;
	
	return tm;
}
