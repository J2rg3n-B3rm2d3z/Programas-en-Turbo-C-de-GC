#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<mouse.h>
#include<string.h>
#include<botones.h> 

void main(){ 
	int i,boleano1=0,xp,yp=9,zp,boleano2=0;
	int adap=DETECT,modo;
	initgraph(&adap,&modo,"c://tc20//bin");
	
	setfillstyle(SOLID_FILL, 9);
	bar(0,0,640,480);
	textboton(18,450,"FONDO",0,1);  
	
	mver();
	while(kbhit()!=1){
		if(mclick()==1 ){
			xp=textboton(18,450,"FONDO",0,1);
			if(xp==1){
				if(boleano1==0)
				for(i=1;i<8;i++){
					setfillstyle(SOLID_FILL, 7);
					bar(20,430-(30*i),50,400-(30*i));
					setcolor(0);
					
					delay(20); 
				}
				for(i=1;i<8;i++){
					setcolor(0);
					circle(35,415-(30*i),10);
					setfillstyle(SOLID_FILL, 15-i);

					floodfill(35,415-(30*i),0);
				}
				boleano1=1;
			}else{
				if(mxpos(1)>=21 && mypos(1)>=190 && mxpos(1)<=51 && mypos(1)<=400){
					do{
						
						if(mclick()==1){
								if(minlimit(1,22,191,52,221)==1){
								yp=8;
							}else if(minlimit(1,22,221,52,251)==1){
								yp=9;
							}else if(minlimit(1,22,251,52,281)==1){
								yp=10;
							}else if(minlimit(1,22,281,52,311)==1){
								yp=11;
							}else if(minlimit(1,22,311,52,341)==1){
								yp=12;
							}else if(minlimit(1,20,341,50,371)==1){
								yp=13;
							}else if(minlimit(1,22,371,52,401)==1){
								yp=14;
							}
						}
						if(mclick()==1){
							while(1){
							zp=textboton(100,450,"APLICAR",0,1);
							if(zp==1)
								break;
							
							}
							if(zp==1 && minlimit(1,21,190,51,400)!=1/*mxpos(1)>=21 && mypos(1)>=190 && mxpos(1)<=51 && mypos(1)<=400*/){
								mocultar();
								
								setfillstyle(SOLID_FILL, yp);
								floodfill(0,0,0);
								for(i=1;i<8;i++){
									setfillstyle(SOLID_FILL, yp);
									bar(20,430-(30*i),50,400-(30*i));
								
								}
								setfillstyle(SOLID_FILL, yp);
								bar(86,435,170,469);
								mver();
								break;
							}else{
								if(minlimit(1,21,190,51,400)!=1 && zp!=1){
									mocultar();
									yp=getpixel(3,3);
									for(i=1;i<8;i++){
										setfillstyle(SOLID_FILL, yp);
										bar(20,430-(30*i),50,400-(30*i));
										delay(20);
									}
									setfillstyle(SOLID_FILL, yp);
									bar(86,435,170,469);
									mver();
								}
							}
						}
					}while(minlimit(1,21,190,51,400)!=1 && minlimit(1,86,440,170,469)!=1);
				}else{
					yp=getpixel(1,1);
					boleano1=0;
					for(i=1;i<8;i++){
						setfillstyle(SOLID_FILL, yp);
						bar(20,430-(30*i),50,400-(30*i));
						delay(20);
					}
				}
			}
		}
	}
	
	
	getch();
	closegraph();
	
}

