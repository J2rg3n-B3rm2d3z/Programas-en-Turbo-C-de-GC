#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<mouse.h>

void main(void)
{
	int g_driver,g_mode,x,y,Salir;
	int Mx[2],My[2];
	
	g_driver=DETECT;
	g_mode=DETECT;
	initgraph(&g_driver,&g_mode,"...\\bgi");
	

	
	Mx[0]=Mx[1]=My[0]=My[1]=0;
	
	Salir=0;
	
	x=640/2;
	y=480;
	
	setcolor(15);
	rectangle(60,60,70,70);

	rectangle(60,80,70,90);
	
	rectangle(60,100,70,110);
	
	rectangle(60,120,70,130);
	
	mver();
	while (Salir!=1)
	{

		if(mclick()==1)
		{
			if(minlimit(1,70,0,640,480))
			{	
				if(Salir==2)
				{
					Mx[1]=Mx[0];
					My[1]=My[0];
					
					Mx[0]=mxpos(1);
					My[0]=mypos(1);
					
					if((Mx[0]!=0&&My[0]!=0&&Mx[1]!=0&&My[1]!=0)&&(Mx[1]!=Mx[0]&&My[1]!=My[0]))
					{
						setcolor(15);
						mocultar();
						line(Mx[0],My[0],Mx[1],My[1]);
						mver();
						Mx[1]=Mx[0]=0;
						My[1]=My[0]=0;
						
						delay(100);
					}
				}
				else if(Salir==3)
				{
					setfillstyle(SOLID_FILL,WHITE);
					mocultar();
					floodfill(mxpos(1),mypos(1),15);
					mver();
				}
			}
			
			if (minlimit(1,60,60,70,70)==1&&Salir!=1)
				Salir=1;
			else if (minlimit(1,60,80,70,90)==1&&Salir!=2)
			{
				Salir=2;
				Mx[1]=Mx[0]=0;
				My[1]=My[0]=0;
			}
			else if (minlimit(1,60,100,70,110)==1&&Salir!=3)
				Salir=3;
			else if (minlimit(1,60,120,70,130)==1&&Salir!=4)
			{
				mocultar();
				cleardevice();
				setcolor(15);
				rectangle(60,60,70,70);

				rectangle(60,80,70,90);
					
				rectangle(60,100,70,110);
					
				rectangle(60,120,70,130);
				Salir=0;
				mver();
			}

		}
		
	}
	closegraph();
}