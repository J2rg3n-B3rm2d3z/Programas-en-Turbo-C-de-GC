# include <conio.h>
# include <stdio.h>
# include <stdlib.h>
# include <graphics.h>
# include <math.h>
# include <dos.h>

void inicializar(void);

void main()
{
float y2,y1,x,x2;
void *buffer;

clrscr();
inicializar();

	buffer=malloc(imagesize(0,20,20,20));
	do
	{
		outtextxy(150,50,"MOVIMIENTO DE ROTACION DE LA TIERRA al rededor del sol");
		x2=-300;
		
		while(x2<=300 && !kbhit())
		{
			putpixel(random(639),random(480),WHITE);
			putpixel(random(639),random(480),YELLOW);
			if((x2>=-300)&&(x2<-200))
			{
				rectangle(480,440,600,460);
				setfillstyle(1,BLUE);
				floodfill(485,450,WHITE);
				outtextxy(500,450,"Enero");
			}
			else
			{
				if((x2>=-200)&&(x2<-100))
				{
					setcolor(BLUE);outtextxy(500,450,"Enero");
					setcolor(RED);
					rectangle(480,440,600,460);
					setfillstyle(1,GREEN);
					floodfill(485,450,BLUE);
					outtextxy(500,450,"Febrero");
				}
				else
				{
					if((x2>=-100)&&(x2<0))
					{
						setcolor(YELLOW);
						rectangle(480,440,600,460);
						setfillstyle(1,BLUE);
						floodfill(485,450,YELLOW);
						outtextxy(500,450,"Marzo");
					}
					else
					{
						if((x2>=0)&&(x2<100))
						{
							setcolor(GREEN);
							rectangle(480,440,600,460);
							setfillstyle(1,BLUE);
							floodfill(485,450,GREEN);
							outtextxy(500,450,"Abril");
						}
						else
						{
							if((x2>=100)&&(x2<200))
							{
								setcolor(CYAN);
								rectangle(480,440,600,460);
								setfillstyle(1,BLUE);
								floodfill(485,450,CYAN);
								outtextxy(500,450,"Mayo");
							}
							else
							{
								if((x2>=200)&&(x2<299))
								{
									setcolor(MAGENTA);
									rectangle(480,440,600,460);
									setfillstyle(1,BLUE);
									floodfill(485,450,MAGENTA);
									outtextxy(500,450,"Junio");
								}
							}
						}
					}
				}
			}
			setcolor(WHITE);
			y2=sqrt((1-((x2*x2)/90000.00))*23850.00);
			circle(310+x2,240-y2,10);
			setfillstyle(1,GREEN);
			floodfill(310+x2,240-y2,WHITE);
			getimage(310+x2-10,240-y2-10,310+x2+10,240-y2+10,buffer);
			delay(200);
			putimage(310+x2-10,240-y2-10,buffer,XOR_PUT);
			circle(310,240,30);
			setfillstyle(1,YELLOW);
			floodfill(310,240,WHITE);
			setcolor(WHITE);
			x2+=2;
		}
		
		free(buffer);
		delay(300);
		x=300;
		
		while(x>=-300 && !kbhit())
		{
			putpixel(random(639),random(480),WHITE);
			putpixel(random(639),random(480),YELLOW);
			if((x<=300)&&(x>200))
			{
				setcolor(RED);
				rectangle(480,440,600,460);
				setfillstyle(1,BLUE);
				floodfill(485,450,RED);
				outtextxy(500,450,"Julio");
			}
			else
			{
				if((x2<=200)&&(x>100))
				{
					setcolor(LIGHTGRAY);
							rectangle(480,440,600,460);
					setfillstyle(1,BLUE);
					floodfill(485,450,LIGHTGRAY);
					outtextxy(501,450,"Agosto");
				}
				else
				{
					if((x<=100)&&(x>0))
					{
						setcolor(YELLOW);
						rectangle(480,440,600,460);
						setfillstyle(1,BLUE);
						floodfill(485,450,YELLOW);
						outtextxy(500,450,"Septiembre");
					}
					else
					{
						if((x<=0)&&(x>-100))
						{
							setcolor(GREEN);
							rectangle(480,440,600,460);
							setfillstyle(1,BLUE);
							floodfill(485,450,GREEN);
							outtextxy(500,450,"Octubre");
						}
						else
						{
							if((x<=-100)&&(x>-200))
							{
								setcolor(CYAN);
								rectangle(480,440,600,460);
								setfillstyle(1,BLUE);
								floodfill(485,450,CYAN);
								outtextxy(500,450,"Noviembre");
							}
							else
							{
								if((x<=-200)&&(x>-300))
								{
									setcolor(MAGENTA);
									rectangle(480,440,600,460);
									setfillstyle(1,BLUE);
									floodfill(485,450,MAGENTA);
									outtextxy(500,450,"Diciembre");
								}
							}
						}
					}
				}
			}

			setcolor(WHITE);
			y1=(sqrt((1-((x*x)/90000.00))*23850.00))*-1;

			circle(310+x,240-y1,10);
			setfillstyle(1,GREEN);
			floodfill(310+x,240-y1,WHITE);
			getimage(310+x-10,240-y1-10,310+x+10,240-y1+10,buffer);
			delay(200);
			putimage(310+x-10,240-y1-10,buffer,XOR_PUT);
			circle(310,240,30);
			setfillstyle(1,YELLOW);
			floodfill(310,240,WHITE);
			setcolor(WHITE);
			x-=2;
		}
		free(buffer);
		delay(20);
	}while(!kbhit());
}

/***********************INICIALIZAR***************************/

void inicializar(void)
{
	int drive=DETECT,modo;
	initgraph(&drive,&modo,"c:\\tc20\\bin");
}
