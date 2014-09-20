#include <fstream.h>
#include <process.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <iomanip.h>
#include <graphics.h>
void welcums(void)
{

	  /*	int gdriver = DETECT, gmode, errorcode;
	    initgraph(&gdriver, &gmode, "");
	  /* read result of initialization */
      /*	errorcode = graphresult();
	  if (errorcode != grOk)
	 {
		  printf("Graphics error: %s\n", grapherrormsg(errorcode));
		 printf("Press any key to halt:");
		 getch();
		 exit(1);*/

	  setbkcolor(15);

			  for(int i=0;i<9;i++)
		    {
			setcolor(1);
			settextstyle(1,0,i);
			outtextxy(80,100,"O");
			outtextxy(120,100,"R");
			outtextxy(165,100,"I");
			outtextxy(205,100,"E");
			outtextxy(245,100,"N");
			outtextxy(285,100,"T");
			outtextxy(325,100,"A");
			outtextxy(365,100,"L");

			 delay(100);
		       setcolor(15);
			settextstyle(1,0,i);
			outtextxy(80,100,"O");
			outtextxy(120,100,"R");
			outtextxy(165,100,"I");
			outtextxy(205,100,"E");
			outtextxy(245,100,"N");
			outtextxy(285,100,"T");
			outtextxy(325,100,"A");
			outtextxy(365,100,"L");

			  delay(100);



		       //	p=p+10;
		     }
				setcolor(1);
			settextstyle(1,0,8);
			outtextxy(70,100,"O");
			outtextxy(110,100,"R");
			outtextxy(155,100,"I");
			outtextxy(195,100,"E");
			outtextxy(235,100,"N");
			outtextxy(275,100,"T");
			outtextxy(315,100,"A");
			outtextxy(355,100,"L");
			for(i=0;i<9;i++)
			{
				setcolor(1);
			settextstyle(1,0,i);
			  outtextxy(405,100,"B");
			  outtextxy(445,100,"A");
			  outtextxy(485,100,"N");
			  outtextxy(525,100,"K");
			  delay(100);
			  setcolor(15);
			settextstyle(1,0,i);
			  outtextxy(405,100,"B");
			  outtextxy(445,100,"A");
			  outtextxy(485,100,"N");
			  outtextxy(525,100,"K");
			  delay(100);
			}

			setcolor(1);
			settextstyle(1,0,8);
			outtextxy(405,100,"B");
			outtextxy(445,100,"A");
			  outtextxy(485,100,"N");
			  outtextxy(525,100,"K");

			setcolor(1);
			settextstyle(1,0,8);
		      settextstyle(3,0,5);
		      outtextxy(160,200,"WELCOMES YOU");
		     // settextstyle(1,0,1);
		     // outtextxy(530,400,"LOADING");
		   for(int j=0;j<2;j++)
		      for( i=0;i<360;i++)
		       {  settextstyle(1,0,1);
		      outtextxy(520,400,"LOADING");
			 pieslice(550,400,0,i,40);
			 delay(5);
		       }






}
