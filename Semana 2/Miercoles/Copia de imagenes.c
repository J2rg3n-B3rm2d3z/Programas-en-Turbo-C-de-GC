#include <graphics.h>
#include <alloc.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

 

int InitGraphics()

{

      int grd, grm;

      int gresult;



      detectgraph(&grd,&grm);


      initgraph(&grd, &grm, "");

 

      gresult = graphresult();

      if(gresult != grOk)

      {

            printf(grapherrormsg(gresult));

            getch();

            return -1;

      }

 


      setbkcolor(1);
	
		


      setcolor(WHITE);

		line(0,0,getmaxx(),getmaxy());

      rectangle(0,0,getmaxx(),getmaxy());

      return 1;

}

 

void main()

{

      int i, x, y, c;

      int left,top,right,bottom;

      int sz;

      int margin, cx, cy;

      char msg[128];

      void far *image = 0;

 

      if(InitGraphics() == -1)

            return;

 

      margin = 200; 

      left = margin;

      top = margin;

      bottom = getmaxy() - margin;

      right = getmaxx() - margin;

      cx = (left + right) / 2;

      cy = (top + bottom) / 2;

 

      setlinestyle(DOTTED_LINE, 0, 1);

      rectangle(left, top - 35, right + 35, bottom);

      setlinestyle(SOLID_LINE, 0, 1);

      sz = imagesize(left, top - 35, right + 35, bottom);

      image = farmalloc(sz);

 

 


      setfillstyle(SOLID_FILL, BLUE);

      bar3d(left, top, right, bottom, 35, 1);

   

      setfillstyle(SOLID_FILL, YELLOW);

      floodfill( (left + right) / 2, top - 2, WHITE);



      setfillstyle(SOLID_FILL, GREEN);

      floodfill( right + 2, cy, WHITE);

 

 

      circle(cx, cy, 5);

      putpixel(cx, cy, WHITE);

		
		
      c = getpixel(cx, cy);

      sprintf(msg, "Pixel Color: %d", c);

      outtextxy(cx - 20, cy + 10, msg);

      getimage(left, top - 35, right + 35, bottom, image);
	  
	 getch();
	 
      putimage(left, bottom + 10, image, COPY_PUT);
	  
	   getch();
	   
	  putimage(left, bottom + 10, image, XOR_PUT);
	  
	getch();
	
      putimage(left, top - 170, image, NOT_PUT);
	
	  getch();

      closegraph();

}