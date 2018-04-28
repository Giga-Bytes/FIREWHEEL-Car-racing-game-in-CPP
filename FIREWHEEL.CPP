#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fstream.h>
void collider();      //Collision with right car
void oppcarr();       //Opposite right car
void oppcarl();       //Opposite left car
void collidel();      //Collision with left car
void roadstrip(int,int,int,int);     //Road strips running back
void carr(int,int);                  //Right side user's car
void carl(int,int);                  // left side user's car
void destcarr();                     //Destroying right user car
void destcarl();                     //Destroying left user car
void startimer();                    //Race Starting 3 2 1		    //Timer during Race
void play();
void cars();                         //Car selection
void help();                         //Help for user
void result();                       //Result of the race
void initpos1();                     //initialising position of right side opp. car
void initpos2();                     //initialising position of left side opp. car
void menu();                         //Main menu of the game
void finishline();
void score_disp();
void score_calc();
void sound1();
void sound2();
void sound3();
void sound4();
void sound5();
void sound7();
void sound8();
void sound9();
int x1[]={255,251,161,217,246,242,164,190,190,230,217};
int x2[]={250,151,151,167,217,221,158,160,167,194,194};
int x3[]={250,151,151,167,217,221,158,168,160,194,194};
int x4[]={255,251,167,217,246,242,164,190,190,217,230};
int x5[]={255,251,161,217,246,242,164,190,190,230,217};
int x6[]={250,151,151,167,217,221,158,160,167,194,194};
int x7[]={250,151,151,167,217,221,158,168,160,194,194};
int x8[]={255,251,167,217,246,242,164,190,190,217,230};
int timer=0, bang=0, speed=0, sec=0, min=0, hour=0;
int col1=BLACK,col2=CYAN;
int rcolspot1=366,rcolspot2;
int lcolspot1=366,lcolspot2;
int dif;
fstream obj;
int s;
time_t first,second;
char carflag='r';
int flag1=0,flag2=0,cl1=col1+1,cl2=col2+1,cl3=col1+2,cl4=col2+1,winflag=0;
char name[50];int level,lmin;
int score;
void main()
{
	int gd=DETECT,gm,i;
	char key;
	initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	setcolor(YELLOW);
	outtextxy(195,50,"WELCOME TO");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
	setcolor(RED);
	outtextxy(120,200,"FIRE-WHEEL");
	outtextxy(240,300,"RACE");
	setcolor(YELLOW);
	line(0,360,635,360);
	line(0,160,635,160);
	getch();
	sound1();
	cleardevice();
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	setcolor(YELLOW);
	outtextxy(160,150,"-:CREATED BY:-");
	setcolor(RED);sound9();delay(20);
	outtextxy(160,200,"GAURAV BAGUL");
	delay(10);sound9();delay(20);
	outtextxy(160,250,"SAGAR GOMTE");
	sound9();delay(20);
	outtextxy(160,300,"SHAUNAK DATAR");
	sound9();delay(20);
	getch();
	sound1();
	cleardevice();
	menu();
	getch();
}
void menu()
{
	char key,ch;
	int pos[]={0,480,0,0,635,0,635,480,0,480};
	do
	{
		setcolor(YELLOW);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
		outtextxy(10,50,"***********************MAIN MENU******************************");
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
		setcolor(LIGHTRED);
		outtextxy(204,120,"1.START GAME");
		setcolor(GREEN);
		outtextxy(204,170,"2.SELECT CAR");
		setcolor(LIGHTMAGENTA);
		settextjustify(LEFT_TEXT,TOP_TEXT);
		outtextxy(204,220,"3.SELECT LEVEL");
		setcolor(LIGHTGRAY);
		outtextxy(204,270,"4.HELP");
		setcolor(LIGHTCYAN);
		outtextxy(204,320,"5.HIGH SCORES");
		setcolor(MAGENTA);
		outtextxy(204,370,"6.EXIT");
		setcolor(YELLOW);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
		outtextxy(10,400,"*********************************************************************************");
		key=getch();
		switch(key)
		{
			case 49:
				sound4();
				play();
				sound2();
				clrscr();
				cleardevice();
			break;
			case 50:
				sound4();
				settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
				setfillstyle(SOLID_FILL,WHITE);
				fillpoly(4,pos);
				setcolor(RED);
				outtextxy(200,210,"CAR SELECTION");
				cars();
				sound2();
				clrscr();
				cleardevice();
			break;
			case 51:
				sound4();
				clrscr();
				cleardevice();
				setcolor(LIGHTGREEN);
				outtextxy(10,120,"**************LEVEL SELECTION***************");
				setcolor(MAGENTA);
				outtextxy(204,170,"1.EASY");
				setcolor(YELLOW);
				outtextxy(204,220,"2.HARD");
				setcolor(LIGHTGREEN);
				outtextxy(10,270,"********************************************");
				ch=getch();
				switch(ch)
				{
					case 49:
						level=1;
					break;
					case 50:
						level=2;
					break;
				}
				sound2();
				clrscr();
				cleardevice();
				break;
			case 52:
				sound4();
				clrscr();
				cleardevice();
				settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
				help();
				sound2();
				clrscr();
				cleardevice();
			break;
			case 53:
				sound4();
				cleardevice();
				score_disp();
				cleardevice();
			break;
			case 54:
				sound9();
				nosound();
				exit(0);
		}
	}while(key!=54);
 }
void roadstrip(int i,int j,int l,int m)
{
		char key;
		int x1=150,x2=170;
		if(key==49)
		{
			sound(5000);
			delay(40);
			nosound();
		}
		sound(200);
		setfillstyle(SOLID_FILL,i);
		bar(315,x1,319,x2);
		setfillstyle(SOLID_FILL,j);
		bar(315,x2,319,x2+20);
		setfillstyle(SOLID_FILL,i);
		bar(315,x2+20,319,x2+40);
		setfillstyle(SOLID_FILL,j);
		bar(315,x2+40,319,x2+60);
		setfillstyle(SOLID_FILL,i);
		bar(315,x2+60,319,x2+80);
		setfillstyle(SOLID_FILL,j);
		bar(315,x2+80,319,x2+100);
		setfillstyle(SOLID_FILL,i);
		bar(315,x2+100,319,x2+120);
		setfillstyle(SOLID_FILL,j);
		bar(315,x2+120,319,x2+140);
		setfillstyle(SOLID_FILL,i);
		bar(315,x2+140,319,x2+160);
		setfillstyle(SOLID_FILL,j);
		bar(315,x2+160,319,x2+180);
		setfillstyle(SOLID_FILL,i);
		bar(315,x2+180,319,x2+200);
		setfillstyle(SOLID_FILL,j);
		bar(315,x2+200,319,x2+220);
		setfillstyle(SOLID_FILL,i);
		bar(315,x2+220,319,x2+240);
		setfillstyle(SOLID_FILL,j);
		bar(315,x2+240,319,x2+260);
		setfillstyle(SOLID_FILL,i);
		bar(315,x2+260,319,x2+280);
		setfillstyle(SOLID_FILL,j);
		bar(315,x2+280,319,x2+300);
		setfillstyle(SOLID_FILL,i);
		bar(315,x2+300,319,x2+320);
		setfillstyle(SOLID_FILL,j);
		bar(315,x2+320,319,x2+340);
		setfillstyle(SOLID_FILL,i);
		bar(315,x2+340,319,x2+360);
		setfillstyle(SOLID_FILL,j);
		bar(315,x2+360,319,x2+380);
		setfillstyle(SOLID_FILL,i);
		bar(315,x2+400,319,x2+420);
		setfillstyle(SOLID_FILL,j);
		setfillstyle(SOLID_FILL,l);
		bar(127,195,137,205);
		bar(500,195,510,205);
		setfillstyle(SOLID_FILL,m);
		bar(104,249,115,261);
		bar(523,249,534,261);
		setfillstyle(SOLID_FILL,l);
		bar(65,342,77,360);
		bar(558,342,570,360);
		setfillstyle(SOLID_FILL,m);
		bar(597,440,614,465);
		bar(23,440,39,465);
		winflag++;
}
void carr(int col1,int col2)
{
	int pos1[]={342,470,342,465,432,465,432,470,342,470};  //Rear bumper
	int pos2[]={342,466,357,366,417,366,432,466,342,466};  //red body
	int pos3[]={362,382,357,366,417,366,411,382,362,382};//front window cover
	int pos4[]={360,432,362,382,411,382,414,432,360,432};//roof
	int pos5[]={343,461,360,432,414,432,431,461,343,461};//rear window cover
	int pos6[]={352,457,365,436,409,436,422,457,352,457};//rear window
	int pos7[]={366,379,362,373,412,373,407,379,366,379};//front window
	int pos9[]={353,405,357,375,359,383,357,405,353,405};//left first  window
	int pos10[]={416,405,414,382,417,375,420,405,416,405};//right first window
	int pos11[]={347,445,353,409,358,409,356,432,350,430};//left second window
	int pos12[]={418,432,416,409,421,409,427,445,418,432};//right second window
	setcolor(col1);
	setfillstyle(SOLID_FILL,col1);
	fillpoly(4,pos1);
	setfillstyle(SOLID_FILL,YELLOW);
	fillellipse(347,468,3,2);
	fillellipse(427,468,3,2);
	setfillstyle(SOLID_FILL,col1);
	fillpoly(4,pos2);
	setcolor(BLACK);
	drawpoly(5,pos3);
	drawpoly(5,pos4);
	drawpoly(5,pos5);
	setfillstyle(SOLID_FILL,col2);
	fillpoly(4,pos6);
	fillpoly(4,pos7);
	fillpoly(4,pos9);
	fillpoly(4,pos10);
	fillpoly(4,pos11);
	fillpoly(4,pos12);
	fillpoly(4,pos7);
}
void carl(int col1,int col2)
{
	int pos1[]={202,470,202,465,292,465,292,470,202,470};  //Rear bumper
	int pos2[]={202,466,217,366,277,366,292,466,202,466};  //red body
	int pos3[]={222,382,217,366,277,366,271,382,222,382};//front window cover
	int pos4[]={222,432,222,382,271,382,274,432,222,432};//roof
	int pos5[]={203,461,220,432,274,432,291,461,203,461};//rear window cover
	int pos6[]={212,457,225,436,269,436,282,457,212,457};//rear window
	int pos7[]={226,379,222,373,272,373,267,379,226,379};//front window
	int pos9[]={213,405,217,375,219,383,217,405,213,405};//left first  window
	int pos10[]={276,405,274,382,277,375,280,405,276,405};//right first window
	int pos11[]={207,445,213,409,218,409,216,432,207,430};//left second window
	int pos12[]={278,432,276,409,281,409,287,445,278,432};//right second window
	setcolor(col1);
	setfillstyle(SOLID_FILL,col1);
	fillpoly(4,pos1);
	setcolor(col1);
	setfillstyle(SOLID_FILL,YELLOW);
	fillellipse(207,468,3,2);
	fillellipse(287,468,3,2);
	setfillstyle(SOLID_FILL,col1);
	fillpoly(4,pos2);
	setcolor(BLACK);
	drawpoly(5,pos3);
	drawpoly(5,pos4);
	drawpoly(5,pos5);
	setfillstyle(SOLID_FILL,col2);
	fillpoly(4,pos6);
	fillpoly(4,pos7);
	fillpoly(4,pos9);
	fillpoly(4,pos10);
	fillpoly(4,pos11);
	fillpoly(4,pos12);
	fillpoly(4,pos7);
}
void destcarr()
{
	int pos1[]={320,475,320,350,460,350,460,475,320,475};
	int pos[]={342,466,357,366,417,366,432,466,342,466};
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL,DARKGRAY);
	fillpoly(4,pos);
	fillpoly(4,pos1);
}
void destcarl()
{
	int pos1[]={150,475,150,350,300,350,300,475,150,475};
	int pos[]={202,466,217,366,277,366,292,466,202,466};
	setcolor(DARKGRAY);
	setfillstyle(SOLID_FILL,DARKGRAY);
	fillpoly(4,pos);
	fillpoly(4,pos1);
}
void startimer()
{

	int i;
	char a[5];
	int pos3[]={0,150,0,0,635,0,635,150};
	settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
	setcolor(RED);
	for(i=3;i>0;i--)
	{
		sprintf(a,"%d",i);
		outtextxy(305,50, a);
		sound(1800);
		delay(1000);
		nosound();
		delay(100);
		setcolor(BLACK);
		setfillstyle(SOLID_FILL,BLUE);
		fillpoly(4,pos3);
		setcolor(RED);

	}
	outtextxy(290,50,"GO");
	sound(1500);
	delay(1000);
	nosound();
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLUE);
	fillpoly(4,pos3);
}
void collider()
{
	int i;
	sound9();
	for(i=0;i<20;i++)
	{
		int pos[]={340,370,345,410,360,370,375,410,390,370,405,410,420,370,425,470,410,440,395,470,380,440,365,470,350,440,345,470,340,370};
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL,YELLOW);
		fillpoly(14,pos);
		setfillstyle(SOLID_FILL,LIGHTRED);
		fillpoly(14,pos);
		setfillstyle(SOLID_FILL,RED);
		fillpoly(14,pos);
		delay(0);
	}
	destcarl();
	destcarr();
	setcolor(BLACK);

}
void collidel()
{
	int i;
	int pos[]={200,370,205,410,220,370,235,410,250,370,265,410,280,370,285,470,270,440,255,470,240,440,225,470,210,440,205,470,200,370};
	sound9();
	for(i=0;i<20;i++)
	{
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL,YELLOW);
		fillpoly(14,pos);
		setfillstyle(SOLID_FILL,LIGHTRED);
		fillpoly(14,pos);
		setfillstyle(SOLID_FILL,RED);
		fillpoly(14,pos);
		delay(0);
	}
	destcarl();
	destcarr();
	setcolor(BLACK);
}
void play()
{
	int gd=DETECT,gm,pos1[]={0,480,0,480,140,150,0,150},i=WHITE,j=DARKGRAY,k,l=YELLOW,m=BROWN;
	int pos2[]={635,480,635,480,497,150,635,150};    //Grass
	int pos3[]={0,150,0,0,635,0,635,150}; //sky
	int pos4[]={40,480,90,150,477,150,595,480,50,480}; //ROAD
	int pos5[]={40,380,80,380,60,320,50,320};   //start bar
	int pos6[]={50,320,90,320,70,260,60,260}; //startbar
	int pos7[]={0,480,40,480,160,150,140,150}; //left footpath
	int pos8[]={595,480,635,480,497,150,477,150,595,480};//right footpath
	int pos9[]={595,380,555,380,575,320,585,320};//left start bar
	int pos10[]={585,320,545,320,565,260,575,260};   //left start bar
	int x1=150,x2=170;
	char key2;
	initgraph(&gd,&gm,"");
	printf("\n\n\n\n\n\n\n\t\t\tEnter name of the player\n\n\t\t\t");
	scanf("%s",name);
	sound2();
	clrscr();
	cleardevice();
	delay(1000);
	printf("\n\n\n\n\n\n");
	setcolor(BLACK);
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL,DARKGRAY);
	fillpoly(4,pos4);
	setfillstyle(SOLID_FILL,GREEN);
	fillpoly(4,pos1);
	setfillstyle(SOLID_FILL,GREEN);
	fillpoly(4,pos2);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLUE);
	fillpoly(4,pos3);
	setfillstyle(SOLID_FILL,BROWN);
	fillpoly(4,pos7);
	fillpoly(4,pos8);
	setfillstyle(SOLID_FILL,BLACK);
	bar(145,160,153,168);
	bar(486,160,494,168);
	bar(127,195,137,205);
	bar(500,195,510,205);
	bar(104,249,115,261);
	bar(523,249,534,261);
	bar(65,342,77,360);
	bar(558,342,570,360);
	bar(597,440,614,465);
	bar(23,440,39,465);
	setfillstyle(SOLID_FILL,RED);
	fillpoly(4,pos5);
	fillpoly(4,pos6);
	fillpoly(4,pos9);
	fillpoly(4,pos10);
	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
	setcolor(WHITE);
	sound7();
	outtextxy(53,325,"S");
	outtextxy(53,335,"T");
	outtextxy(53,345,"A");
	outtextxy(53,356,"R");
	outtextxy(53,368,"T");
	outtextxy(578,325,"S");
	outtextxy(578,335,"T");
	outtextxy(578,345,"A");
	outtextxy(578,356,"R");
	outtextxy(578,368,"T");
	setfillstyle(SOLID_FILL,RED);
	carr(col1,col2);
	setfillstyle(SOLID_FILL,i);
	bar(315,x1,319,x2);
	setfillstyle(SOLID_FILL,j);
	bar(315,x2,319,x2+20);
	setfillstyle(SOLID_FILL,i);
	bar(315,x2+20,319,x2+40);
	setfillstyle(SOLID_FILL,j);
	bar(315,x2+40,319,x2+60);
	setfillstyle(SOLID_FILL,i);
	bar(315,x2+60,319,x2+80);
	setfillstyle(SOLID_FILL,j);
	bar(315,x2+80,319,x2+100);
	setfillstyle(SOLID_FILL,i);
	bar(315,x2+100,319,x2+120);
	setfillstyle(SOLID_FILL,j);
	bar(315,x2+120,319,x2+140);
	setfillstyle(SOLID_FILL,i);
	bar(315,x2+140,319,x2+160);
	setfillstyle(SOLID_FILL,j);
	bar(315,x2+160,319,x2+180);
	setfillstyle(SOLID_FILL,i);
	bar(315,x2+180,319,x2+200);
	setfillstyle(SOLID_FILL,j);
	bar(315,x2+200,319,x2+220);
	setfillstyle(SOLID_FILL,i);
	bar(315,x2+220,319,x2+240);
	setfillstyle(SOLID_FILL,j);
	bar(315,x2+240,319,x2+260);
	setfillstyle(SOLID_FILL,i);
	bar(315,x2+260,319,x2+280);
	setfillstyle(SOLID_FILL,j);
	bar(315,x2+280,319,x2+300);
	setfillstyle(SOLID_FILL,i);
	bar(315,x2+300,319,x2+320);
	setfillstyle(SOLID_FILL,j);
	bar(315,x2+320,319,x2+340);
	setfillstyle(SOLID_FILL,i);
	bar(315,x2+340,319,x2+360);
	startimer();
	carr(col1,col2);
	setfillstyle(SOLID_FILL,GREEN);
	fillpoly(4,pos1);
	setfillstyle(SOLID_FILL,GREEN);
	fillpoly(4,pos2);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLUE);
	fillpoly(4,pos3);
	setfillstyle(SOLID_FILL,BROWN);
	fillpoly(4,pos7);
	fillpoly(4,pos8);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(YELLOW);
	outtextxy(200,10,"FIRE WHEEL RACE");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	setcolor(RED);
	outtextxy(1,85,":TIMER:");
	outtextxy(500,85,":PLAYER NAME:");
	outtextxy(508,98,name);
	if(level==2)
	{
		lmin=1;
	}
	else
	{
		lmin=2;
	}
	setcolor(BLACK);
	do
	{
		while(key2!=27)
		{
			for(min=lmin; min>=0; min--)
			for(sec=60; sec>=0; sec--)
			for(timer=99; timer>=0; timer--)
			{
				printf("%02d:%02d:%02d\r", min, sec,timer);
				result();
				first=time(NULL);
				key2=getch();
				second=time(NULL);
				dif=difftime(second,first);
				sec=sec-dif;
				switch(key2)
				{
				case 72:
					if(i%2==0)
					{
						i=DARKGRAY;
						j=WHITE;
						l=BLACK;
						m=BROWN;
					}
					else
					{
						i=WHITE;
						j=DARKGRAY;
						l=BROWN;
						m=BLACK;
					}
					roadstrip(i,j,l,m);
					i++,j++;
						if(level==2)
						{
						if(winflag>0&&winflag<331)
							oppcarr();
						if(winflag>229&&winflag<560)
							oppcarl();
						if(winflag>458&&winflag<789)
							oppcarr();
						if(winflag>687&&winflag<1018)
							oppcarl();
						if(winflag>916&&winflag<1247)
							oppcarr();
						if(winflag>1145&&winflag<1476)
							oppcarl();
						if(winflag>1374&&winflag<1705)
							oppcarr();
						if(winflag>1603&&winflag<1934)
							oppcarl();
						if(winflag>1832&&winflag<2163)
							oppcarr();
						if(winflag>2061&&winflag<2392)
							oppcarl();
						 }
						 else
						 {

							flag1++;
							if(flag1<331)
							oppcarr();
							if(flag1>330)
							oppcarl();
							if(flag1==660)
							{
							flag1=0;
							}
						}
						result();
					break;

				case 75:
					carl(col1,col2);
					carflag='l';
					destcarr();
					break;
				case 77:
					destcarl();
					carr(col1,col2);
					carflag='r';
					break;
				case 27:
					cleardevice();
					menu();
					break;

				}

			}
		}
	}while(key2==getch());
}
void cars()
{
	char key,key2;
	int i=BLACK,j=CYAN;
	do
	{
	int pos1[]={272,470,272,465,362,465,362,470,272,470};  //Rear bumper
	int pos2[]={272,466,287,366,347,366,362,466,272,466};  //body
	int pos3[]={292,382,287,366,347,366,341,382,292,382};//front window cover
	int pos4[]={292,432,292,382,341,382,344,432,292,432};//roof
	int pos5[]={273,461,290,432,344,432,361,461,273,461};//rear window cover
	int pos6[]={282,457,295,436,339,436,352,457,282,457};//rear window
	int pos7[]={296,379,292,373,342,373,337,379,296,379};//front window
	int pos9[]={283,405,287,375,289,383,287,405,283,405};//left first  window
	int pos10[]={346,405,344,382,347,375,350,405,346,405};//right first window
	int pos11[]={277,445,283,409,288,409,286,432,277,430};//left second window
	int pos12[]={348,432,346,409,351,409,357,445,348,432};//right second window
	setcolor(i);
	setfillstyle(SOLID_FILL,i);
	fillpoly(4,pos1);
	setfillstyle(SOLID_FILL,YELLOW);
	fillellipse(283,468,3,2);
	fillellipse(352,468,3,2);
	setfillstyle(SOLID_FILL,i);
	fillpoly(4,pos2);
	setcolor(BLACK);
	drawpoly(5,pos3);
	drawpoly(5,pos4);
	drawpoly(5,pos5);
	setfillstyle(SOLID_FILL,j);
	fillpoly(4,pos6);
	fillpoly(4,pos7);
	fillpoly(4,pos9);
	fillpoly(4,pos10);
	fillpoly(4,pos11);
	fillpoly(4,pos12);
	fillpoly(4,pos7);
	key=getch();
	switch(key)
	{
		case 72:
			i++;
			j++;
			break;
		case 80:
			i++;
			j++;
			break;

	}
	}while(key!='\r');
	col1=i;
	col2=j;
}
void help()
{
	cleardevice();
	int l=27,r=26,u=24,d=25;
	char c1[2],c2[2],c3[2],c4[2];
	printf("\n\n\t Fire wheel race is an exiciting car racing game in which the ");
	printf("\n\n\t player has to  complete the  track path within a given  time ");
	printf("\n\n\t limit. Player should  take care to avoide collision  with the");
	printf("\n\n\t oppontment cars.");
	printf("\n\n\n\n\n\t CONTROLS:-");
	sprintf(c1,"%c",l);
	sprintf(c2,"%c",r);
	sprintf(c3,"%c",u);
	sprintf(c4,"%c",d);
	setcolor(WHITE);
	sound9();delay(30);
	outtextxy(100,250,"1.");
	outtextxy(200,250,c3);sound9();delay(30);
	outtextxy(275,250,": ACCELERATION");
	outtextxy(100,280,"2.");
	outtextxy(200,280,c4);sound9();delay(30);
	outtextxy(275,280,": BRAKES");
	outtextxy(100,310,"3.");
	outtextxy(200,310,c1);sound9();delay(30);
	outtextxy(275,310,": TURN LEFT");
	outtextxy(100,340,"4.");
	outtextxy(200,340,c2);sound9();delay(30);
	outtextxy(275,340,": TURN RIGHT");
	sound9();delay(30);
	getch();
	clrscr();
	cleardevice();
}
void oppcarr()
{
	int i;
	int pos2[]={342,x1[1],357,x2[1],417,x3[1],432,x4[1]};  //red body
	int pos3[]={362,x1[2],357,x2[2],417,x3[2],411,x4[2]};//front window cover
	int pos4[]={360,x1[3],362,x2[3],411,x3[3],414,x4[3]};//roof
	int pos5[]={343,x1[4],360,x2[4],414,x3[4],431,x4[4]};//rear window cover
	int pos6[]={352,x1[5],365,x2[5],409,x3[5],422,x4[5]};//rear window
	int pos7[]={366,x1[6],362,x2[6],412,x3[6],407,x4[6]};//front window
	int pos9[]={353,x1[7],357,x2[7],359,x3[7],357,x4[7]};//left first  window
	int pos10[]={416,x1[8],414,x2[8],417,x3[8],420,x4[8]};//right first window
	int pos11[]={347,x1[9],353,x2[9],358,x3[9],356,x4[9]};//left second window
	int pos12[]={418,x1[10],416,x2[10],421,x3[10],427,x4[10]};//right second window
	int finish[]={340,x1[1]+1,355,x2[1]-1,419,x3[1]-1,434,x4[1]+1};
	if(cl1==DARKGRAY)
	{
		cl1++;
	}
	if(cl2==DARKGRAY)
	{
		cl2++;
	}
	setcolor(DARKGRAY);
	drawpoly(4,finish);
	setcolor(cl1);
	setfillstyle(SOLID_FILL,cl1);
	fillpoly(4,pos2);
	setcolor(cl1);
	drawpoly(5,pos3);
	drawpoly(5,pos4);
	drawpoly(5,pos5);
	setfillstyle(SOLID_FILL,cl2);
	fillpoly(4,pos6);
	fillpoly(4,pos7);
	fillpoly(4,pos9);
	fillpoly(4,pos10);
	fillpoly(4,pos11);
	fillpoly(4,pos12);
	fillpoly(4,pos7);
	rcolspot2=x1[1];
	if((rcolspot1==rcolspot2||rcolspot1<rcolspot2)&&(carflag=='r'))
	{
		collider();
		carr(col1,col2);
		winflag--;
	}
	for(i=0;i<12;i++)
	{
		x1[i]++;
		x2[i]++;
		x3[i]++;
		x4[i]++;
	}
	setcolor(BLACK);
	if(x2[1]>=481)
	{
		initpos1();
		cl1++;cl2++;
	}
}
void initpos1()
{
	x1[0]=255;x1[1]=251;x1[2]=161;x1[3]=217;x1[4]=246;x1[5]=242;x1[6]=164;
	x1[7]=190;x1[8]=190;x1[9]=230;x1[10]=217;
	x2[0]=250;x2[1]=151;x2[2]=151;x2[3]=167;x2[4]=217;x2[5]=221;x2[6]=158;
	x2[7]=160;x2[8]=167;x2[9]=194;x2[10]=194;
	x3[0]=250;x3[1]=151;x3[2]=151;x3[3]=167;x3[4]=217;x3[5]=221;x3[6]=158;
	x3[7]=168;x3[8]=160;x3[9]=194;x3[10]=194;
	x4[0]=255;x4[1]=251;x4[2]=167;x4[3]=217;x4[4]=246;x4[5]=242;x4[6]=164;
	x4[7]=190;x4[8]=190;x4[9]=217;x4[10]=230;
}
void oppcarl()
{
	int i;
	int pos2[]={202,x5[1],217,x6[1],277,x7[1],292,x8[1]};  //red body
	int pos3[]={222,x5[2],217,x6[2],277,x7[2],271,x8[2]};//front window cover
	int pos4[]={222,x5[3],222,x6[3],271,x7[3],274,x8[3]};//roof
	int pos5[]={203,x5[4],220,x6[4],274,x7[4],291,x8[4]};//rear window cover
	int pos6[]={212,x5[5],225,x6[5],269,x7[5],282,x8[5]};//rear window
	int pos7[]={226,x5[6],222,x6[6],272,x7[6],267,x8[6]};//front window
	int pos9[]={213,x5[7],217,x6[7],219,x7[7],217,x8[7]};//left first  window
	int pos10[]={276,x5[8],274,x6[8],277,x7[8],280,x8[8]};//right first window
	int pos11[]={207,x5[9],213,x6[9],218,x7[9],216,x8[9]};//left second window
	int pos12[]={278,x5[10],276,x6[10],281,x7[10],287,x8[10]};//right second window
	int finish[]={200,x5[1]+1,215,x6[1]-1,279,x7[1]-1,294,x8[1]+1};
	if(cl3==DARKGRAY)
	{
		cl3++;
	}
	if(cl4==DARKGRAY)
		cl4++;
	setcolor(DARKGRAY);
	drawpoly(4,finish);
	setcolor(cl3);
	setfillstyle(SOLID_FILL,cl3);
	fillpoly(4,pos2);
	setcolor(cl3);
	drawpoly(5,pos3);
	drawpoly(5,pos4);
	drawpoly(5,pos5);
	setfillstyle(SOLID_FILL,cl4);
	fillpoly(4,pos6);
	fillpoly(4,pos7);
	fillpoly(4,pos9);
	fillpoly(4,pos10);
	fillpoly(4,pos11);
	fillpoly(4,pos12);
	fillpoly(4,pos7);
	lcolspot2=x5[1];
	if((lcolspot1==lcolspot2||lcolspot1<lcolspot2)&&(carflag=='l'))
	{
		collidel();
		carl(col1,col2);
		winflag--;
	}
	for(i=0;i<12;i++)
	{
		x5[i]++;
		x6[i]++;
		x7[i]++;
		x8[i]++;
	}
	setcolor(BLACK);
	if(x6[1]>=481)
	  {	initpos2();
		cl3++;
		cl4++;
	   }
}
void initpos2()
{
	x5[0]=255;x5[1]=251;x5[2]=161;x5[3]=217;x5[4]=246;x5[5]=242;x5[6]=164;
	x5[7]=190;x5[8]=190;x5[9]=230;x5[10]=217;
	x6[0]=250;x6[1]=151;x6[2]=151;x6[3]=167;x6[4]=217;x6[5]=221;x6[6]=158;
	x6[7]=160;x6[8]=167;x6[9]=194;x6[10]=194;
	x7[0]=250;x7[1]=151;x7[2]=151;x7[3]=167;x7[4]=217;x7[5]=221;x7[6]=158;
	x7[7]=168;x7[8]=160;x7[9]=194;x7[10]=194;
	x8[0]=255;x8[1]=251;x8[2]=167;x8[3]=217;x8[4]=246;x8[5]=242;x8[6]=164;
	x8[7]=190;x8[8]=190;x8[9]=217;x8[10]=230;
}
void result()
{
		char score_str[10];
		if((min<=0&&sec<=0)||(winflag>=2000))
		{
				if(winflag>=2000)
				{
							score=(100+min+sec);
							score_calc();
							finishline();
							nosound();
							delay(5000);
							clrscr();
							cleardevice();
							settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
							setcolor(YELLOW);
							sound7();delay(20);sound8();
							outtextxy(100,50,"CONGRATS");
							outtextxy(350,50,name);
							outtextxy(100,100,"YOU WIN");
							outtextxy(100,200,"YOUR SCORE IS");
							sprintf(score_str,"%d",score);
							outtextxy(100,250,score_str);
							sound9();
							delay(3000);
							cleardevice();
							menu();
				}
				else
				{
							nosound();
							clrscr();
							cleardevice();
							settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
							setcolor(YELLOW);
							sound7();delay(20);sound8();
							outtextxy(100,50,"SORRY");
							outtextxy(350,50,name);
							outtextxy(195,150,"YOU FAILED");
							sound9();
							delay(3000);
							cleardevice();
							menu();

				}
		}
}
void finishline()
{
	int pos5[]={40,360,80,360,60,300,50,300};   //start bar
	int pos6[]={50,300,90,300,70,240,60,240};
	int pos9[]={595,360,555,360,575,300,585,300};//left start bar
	int pos10[]={585,300,545,300,565,240,575,240};
	setfillstyle(SOLID_FILL,RED);
	fillpoly(4,pos5);
	fillpoly(4,pos6);
	fillpoly(4,pos9);
	fillpoly(4,pos10);
	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
	setcolor(WHITE);
	outtextxy(53,325,"E");
	outtextxy(53,335,"N");
	outtextxy(53,345,"D");
	outtextxy(578,325,"E");
	outtextxy(578,335,"N");
	outtextxy(578,345,"D");
	line(80,360,555,360);
	line(90,300,555,300);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
	setcolor(RED);
	sound7();
	outtextxy(220,320,"FINISH");
}
void score_calc()
{
	obj.open("SCORE.txt",ios::in);
	obj>>s;
	if(s<score)
	{
		s=score;
	obj.close();
	obj.open("SCORE.txt",ios::out);
	obj<<s;
	obj.close();
	obj.open("NAME.txt",ios::out);
	obj<<name;
	obj.close();
	}
	obj.close();
}
void score_disp()
{
	char str[5],wname[20];
	obj.open("SCORE.txt",ios::in);
	obj>>s;
	obj.close();
	obj.open("NAME.txt",ios::in);
	obj>>wname;
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(0,50,"***************HIGH SCORE**********************");
	sprintf(str,"%d",s);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	outtextxy(150,200,wname);
	outtextxy(150,250,str);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(0,350,"*************************************************");
	getch();
}
void sound1()
{
	sound(1800);
	delay(100);
	nosound();
	delay(100);
	sound(1870);
	delay(200);
	sound(1800);
	delay(100);
	nosound();
	delay(100);
	sound(1890);
	delay(200);
	sound(2100);
	delay(100);
	nosound();
}
void sound2()
{
	sound(1850);
	delay(100);
	sound(1900);
	delay(100);
	nosound();
}
void sound3()
{

	sound(2100);
	delay(100);
	nosound();
	sound(1890);
	delay(200);
	nosound();
	delay(100);
	sound(1870);
	delay(200);
	sound(1870);
	delay(200);
	sound(1800);
	delay(100);
	nosound();
}
void sound4()
{
	sound(1900);
	delay(100);
	sound(1850);
	delay(100);
	nosound();
}
void sound7()
{

	sound(5000);delay(220);
	sound(4200);delay(200);sound(3500);delay(180);
	sound(3000);delay(170);sound(2000);delay(145);
	sound(1000);delay(130);sound(500);delay(10);
	nosound();
}
void sound8()
{
	sound(700);delay(220);sound(1500);delay(200);
	sound(2000);delay(180);sound(3900);delay(170);
	sound(4100);delay(145);sound(4800);delay(130);
	sound(5000);delay(10);nosound();
}
void sound9()
{
	sound(4100);delay(145);sound(4800);delay(130);
	sound(5000);delay(10);nosound();
	sound(5000);delay(145);sound(4800);delay(130);
	sound(4100);delay(10);nosound();

}
