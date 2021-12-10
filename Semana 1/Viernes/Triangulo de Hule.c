#include<conio.h>
#include<graphics.h>
void main(void)
{
int modo=DETECT,driver=DETECT,x,y,tem,tem2,tem3;
initgraph(&modo,&driver, "C:\\TC20\\BIN ");

x=getmaxx();
y=getmaxy();

outtextxy(20,20,"Presione las teclas direccionales para alargarlo" );
outtextxy(20,30," a y b para mover el vertice superior");

line(x/2-20,y/2+20,x/2+20,y/2+20);
line(x/2+20,y/2+20,x/2,y/2-20);
line(x/2,y/2-20,x/2-20,y/2+20);
tem=x/2+20;
tem2=y/2-20;
tem3=x/2;

while (getch()!=27)
{
	
          if (getch()==77)
		  { 
			cleardevice();
            line(x/2-20,y/2+20,tem=tem+1,y/2+20);
            line(tem+1,y/2+20,tem3,tem2);
            line(tem3,tem2,x/2-20,y/2+20);
          }
          else if (getch()==75)
		  { 
			cleardevice();
            line(x/2-20,y/2+20,tem=tem-1,y/2+20);
            line(tem-1,y/2+20,tem3,tem2);
            line(tem3,tem2,x/2-20,y/2+20);
          }
          else if (getch()==72)
		  { 
			cleardevice();
            line(x/2-20,y/2+20,tem,y/2+20);
            line(tem,y/2+20,tem3,tem2=tem2-1);
            line(tem3,tem2-1,x/2-20,y/2+20);
          }
          else if (getch()==80)
		  {  
			cleardevice();
            line(x/2-20,y/2+20,tem,y/2+20);
            line(tem,y/2+20,tem3,tem2=tem2+1);
            line(tem3,tem2+1,x/2-20,y/2+20);
          }
          else if (getch()==97)
		  { 
			cleardevice();
			line(x/2-20,y/2+20,tem,y/2+20);
            line(tem,y/2+20,tem3=tem3+1,tem2);
			line(tem3+1,tem2,x/2-20,y/2+20);
		  }
          else if (getch()==98)
		  { 
		    cleardevice();
            line(x/2-20,y/2+20,tem,y/2+20);
            line(tem,y/2+20,tem3=tem3-1,tem2);
            line(tem3-1,tem2,x/2-20,y/2+20);
          }
}
getch();
closegraph();
}

