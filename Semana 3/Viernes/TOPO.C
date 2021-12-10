#include<graphics.h>
#include<conio.h>
void llamar(void);
void main(void){
llamar();
outtextxy(15,15,"boton1");
rectangle(10,10,110,40);
getch();
}
void llamar(void){
int a,b;
a=DETECT;
initgraph(&a,&b,"c:/tc/bgi");
}