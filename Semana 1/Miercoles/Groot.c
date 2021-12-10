#include <graphics.h>
#include <dos.h>

int main(void)
{
    int driver = DETECT, mod;

    int pot[] =
    {
        200, 374
        ,212, 374
        ,217, 374
        ,217, 398
        ,230, 398
        ,235, 398
        ,235, 422
        ,247, 422
        ,252, 422
        ,252, 445
        ,352, 445
        ,352, 422
        ,356, 422
        ,369, 422
        ,369, 398
        ,374, 398
        ,387, 398
        ,387, 374
        ,391, 374
        ,404, 374
        ,404, 331
        ,200, 331
    };

    int head[] =
    {
        165, 53
        ,195, 53
        ,195, 41
        ,216, 41
        ,216, 54
        ,235, 54
        ,235, 77
        ,247, 77
        ,247, 54
        ,247, 30
        ,270, 30
        ,270, 53
        ,301, 53
        ,301, 30
        ,322, 30
        ,322, 42
        ,339, 42
        ,339, 53
        ,352, 53
        ,352, 18
        ,374, 18
        ,374, 29
        ,409, 29
        ,409, 41
        ,427, 41
        ,427, 106
        ,409, 106
        ,409, 212
        ,391, 212
        ,391, 223
        ,374, 223
        ,374, 235
        ,230, 235
        ,230, 224
        ,212, 224
        ,212, 213
        ,196, 213
        ,196, 106
        ,178, 106
        ,178, 70
        ,165, 70
    };

    int body[] =
    {
		270, 235
        ,270, 272
        ,282, 272
        ,282, 291
        ,266, 291
        ,266, 315
        ,247, 315
        ,247, 327
        ,357, 327
        ,357, 315
        ,339, 315
        ,339, 296
        ,357, 296
		,357, 243
        ,339, 243
        ,339, 235
    };

    int arm_1[] =
    {
		270, 284
        ,252, 284
        ,252, 295
        ,235, 295
        ,235, 307
        ,196, 307
        ,196, 295
        ,177, 295
        ,177, 284
        ,142, 284
        ,142, 268
        ,161, 268
        ,161, 256
        ,199, 256
        ,199, 268
        ,230, 268
        ,230, 256
        ,248, 256
        ,248, 243
		,270, 243
		,270, 280
    };

    int arm_2[] =
	{
        462, 197
        ,440, 197
        ,440, 219
        ,423, 219
        ,423, 232
        ,404, 232
		,404, 243
		,357, 243
        ,357, 284
        ,409, 284
        ,409, 272
        ,427, 272
        ,427, 260
        ,444, 260
        ,444, 248
        ,461, 248
        ,461, 236
        ,497, 236
        ,497, 220
        ,478, 220
        ,478, 208
        ,462, 208
        ,462, 197
    };



    initgraph(&driver,&mod, "C:\\tc20\\bin");

	cleardevice();

	/*setbkcolor(WHITE);*/

    /* Empezar a dibujar */

	settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
	setcolor(GREEN);
	outtextxy(30,150, "Soy");
	outtextxy(420,300, "Groot");

    /* Jarron o masetera */
	setfillstyle(SOLID_FILL,WHITE);

    fillpoly(22, pot);

    setfillstyle(1,DARKGRAY);

    bar(200,327,404,338);
	bar(200,339,217,374);
	bar(217,375,234,398);
	bar(235,400,251,422);
	bar(252,425,264,445);
	bar(265,437,338,445);
	bar(339,423,352,445);
	bar(353,400,369,422);
	bar(370,375,387,398);
	bar(389,339,404,374);
	bar(217,365,388,374);

    /* Hojitas */
    setfillstyle(1,GREEN);

	bar(147,245,160,255);
	bar(182,245,199,256);
	bar(440,187,462,196);
	bar(479,208,497,219);
	bar(462,236,475,247);

    /* Hojas cabeza */
    bar(182,58,195,66);
    bar(235,34,247,41);
	bar(287,59,300,65);
	bar(305,20,317,35);
	bar(322,30,334,45);
	bar(374,18,387,35);
	bar(409,30,421,40);
	bar(182,30,195,40);


    setlinestyle(SOLID_LINE,1,1);
    setfillstyle(SOLID_FILL,BROWN);
    setcolor(0);

    /* Cabeza */
    fillpoly(41, head);

    /* Cuerpo */
    fillpoly(16, body);

    /* Brazo 1*/
    fillpoly(21,arm_1);

    /* Brazo 2*/
	fillpoly(22, arm_2);

    /* Ojos y boca */
    setfillstyle(1,BLACK);
    bar(235,153,265,172);
    bar(339,153,369,172);
    bar(235,189,247,196);
    bar(357,189,369,196);
    bar(247,196,357,208);

	getch();

    closegraph();

    return 0;
}