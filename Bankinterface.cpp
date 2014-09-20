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
#include<welcum.cpp>
// To display the main menu options
unsigned long temporary;
   int cn=48;
	 int cp=48;
 int page;
 struct account
 {	unsigned  acc_no;
	char pass[50];
 }r;

 class accinfo
 {
  public:
     char type[10];
     int dd,mm,yy;
     float interest;
     float transamt;

     public:
	 accinfo()
	 {
	     strcpy(type,"cheque");
	     interest=5/100;
	     transamt=0;
	 }
	 float currbal;
	  unsigned long acc_no;
	 void debit();
	 void credit();
	 void modify();
	 void close  ();
	 void task(int);
 }a,b;

class info
{
   char name[50];
   char gen[2];
   char address[50];
   char city[50];
   char state[50];
   char pinc[6];
   char mob[20];
   char email[30];
   float dep;

   char pass[50];
      //int no;//to store no of accounts;
   public:

	unsigned acc;
	void menu();         //to displays choices
	void menu1();        //to display access acc choices
	int choice1();      //to swap keys 4 menu 1;
	void task1(int);     //to do task acc to choice1;
	void box(int x1,int y1,int x2,int y2);
	void newacc();
	void insert(int);
	void acccheck();
	int choice();
	int backkey();
	void choice2(int);   //to do task acc to back or exit;
	void task(int);     // to do task according to choice;
}p,ac,wr;
void info::box(int x1,int y1,int x2,int y2)
{         setcolor(3);
	  rectangle(x1,y1,x2,y2);
}
void info::menu()
{     setfillstyle(1,15);
      bar3d(150,8,632,455,4,1);
      setbkcolor(15);


     for(int j=0;j<8;j++)
	 box(j,j,630+j,470+j);
     setfillstyle(1,3);
     bar3d(0,0,150,650,10,1);//to display side strip
     setcolor(1);
     settextstyle(4,0,4);
     outtextxy(50,20,"O");
     outtextxy(50,50,"R");
     outtextxy(50,80,"I");
     outtextxy(50,120,"E");
     outtextxy(50,150,"N");
     outtextxy(50,180,"T");
     outtextxy(50,210,"A");
     outtextxy(50,240,"L");
     outtextxy(50,280,"B");
     outtextxy(50,310,"A");
     outtextxy(50,340,"N");
     outtextxy(50,380,"K");


      settextstyle(1,HORIZ_DIR,1);
     setcolor(0);
     setfillstyle(1,2);
     bar3d(300,100,500,150,4,1);
     setcolor(0);
     outtextxy(320,110,"  Access account");
      //outtextxy(320,110,"  Access account");


     setfillstyle(1,3);
     bar3d(300,180,500,230,4,1);
      bar3d(300,265,500,310,4,1);
     setcolor(6);
     outtextxy(303,190," Create new account");
       outtextxy(303,190," Create new account");
       outtextxy(380,275,"Exit");
     //setcolor(6);
	  outtextxy(380,275,"Exit");


    // setfillstyle(1,3);

     task(choice());
 }
 int info::choice()  //swapping between keyssssssss
{    int end;
     int i=0;
     do
     {
	   int key=getch();
	   //cout<<key;
	   switch(key)
	   {
		      case 80: switch(i)

			       {case 0:        setfillstyle(1,2);
					       bar3d(300,180,500,230,4,1);
					       setcolor(0);
					       outtextxy(303,190," Create new account");


					       setcolor(6);
					      setfillstyle(1,3);

					       bar3d(300,100,500,150,4,1);
					       outtextxy(320,110,"  Access account");

					       bar3d(300,265,500,310,4,1);
					      outtextxy(380,275,"Exit");



						i++;

						break;


				case 1:        setfillstyle(1,3);
					       bar3d(300,100,500,150,4,1);
					       setcolor(6);
					       outtextxy(320,110,"  Access account");

					       setfillstyle(1,3);
					       bar3d(300,180,500,230,4,1);
					       setcolor(6);
					       outtextxy(303,190," Create new account");

					       setfillstyle(1,2);
					       bar3d(300,265,500,310,4,1);
					       setcolor(0);
					       outtextxy(380,275,"Exit");
					       i++;
						//getch();

					       break;
			    }
			    break;
		     case 72: switch(i)
			      {     case 1:
					       setfillstyle(1,3);
					       bar3d(300,180,500,230,4,1);
						 bar3d(300,265,500,310,4,1);
					       setcolor(6);
						outtextxy(380,275,"Exit");
					       outtextxy(303,190," Create new account");

					       setcolor(0);
					       setfillstyle(1,2);
					       bar3d(300,100,500,150,4,1);
					       outtextxy(320,110,"  Access account");
					       i--;
					       break;
				    case 2:    setcolor(0);
					       setfillstyle(1,2);
					       bar3d(300,180,500,230,4,1);
					       outtextxy(303,190," Create new account");

					       setcolor(6);
					       setfillstyle(1,3);
					       bar3d(300,265,500,310,4,1);
					       outtextxy(380,275,"Exit");
					       bar3d(300,100,500,150,4,1);
					       outtextxy(320,110,"  Access account");
					       i--;
					       break;
				  }
				  break;
		     case 13:end=1;
	    }
	}while(end!=1);

	return(i);
 }
 void info::task(int i)
 {
	switch(i)
	{     case 0:
		       acccheck();
		       break;
	      case 1:
		     newacc();
		     break;
	      case 2:exit(0);
		     break;
	}
}

void info::newacc()
{      page=1;
       setfillstyle(1,15);
       bar3d(160,8,632,455,4,1);
       setcolor(6);

	 settextstyle(4,0,4);
	  outtextxy(200,40,"Enter the following details:");
	settextstyle(3,0,1);
	outtextxy(160,100,"Name");
	rectangle(250,105,600,120);

	outtextxy(160,135,"Password");
	rectangle(250,140,600,155);

	outtextxy(160,170,"Gender");
	rectangle(250,175,275,190);

	outtextxy(160,205,"Address");
	rectangle(250,210,600,225);

	outtextxy(160,240,"City");
	rectangle(250,245,600,260);

	outtextxy(160,275,"State");
	rectangle(250,280,600,295);

	outtextxy(160,310,"Pin Code");
	rectangle(250,315,400,330);

	outtextxy(160,345,"Mobile no.");
	rectangle(250,350,600,365);

	outtextxy(160,380,"E-Mail ID");
	rectangle(250,385,600,400);

	outtextxy(160,415,"Deposit");
	rectangle(250,420,600,435);
	 insert(page);
  }
 void info::insert(int page)
 {    date *d;
	getdate(d);
      fstream x,y;
       x.open("info.dat",ios::binary|ios::app|ios::in);
       y.open("master.dat",ios::binary|ios::app);
      // if(!y)  y.open("master.dat",ios::binary|ios::out);
       //info wr;
       if(!x && !y)
       {   cerr<<"file doesnt open";
	    getch();
	    exit(0);
       }
       fstream obj;
     if(page==1)
     {	  obj.open("ban.dat",ios::app|ios::binary);
	  if(!obj)
	  {   cerr<<"ban file doest open";
	   getch();
	   exit(0);
	   }
     }

	int i=0;
	int j=2;
	char *p;
	// _setcursortype(1);
	///////////for name insertion//////////////////
      if(page==0)
      {    name:
	    for(int k=0;k<50;k++)
		   wr.name[k]=NULL;
	 //    gotoxy(50,8);
	 //    gets(name);
	  //   exit(1);
		   setcolor(6);
		   outtextxy(250+j,135,"_");
		while((*(wr.name+i)=getch())!=13)
		{     outtextxy(250+j,135,wr.name+i);
		      i++;
		      j+=10;           //	rectangle(250,140,600,155);

		}
		   wr.name[i]='\0';
		   //setcolor(3);
		   //exit(1);
			    //bar(2,405,60,415);
		   if((wr.name[0]=='\0')&&(wr.name[1]=='\0'))
		    {	    outtextxy(2,410,"FILL NAME FIELD");
			    goto name;
		     }



      }



     if(page==1)
    {	 name1:
	    for(int k=0;k<50;k++)
		   wr.name[k]=NULL;
	 //    gotoxy(50,8);
	 //    gets(name);
	  //   exit(1);
		   setcolor(6);
		   outtextxy(250+j,100,"_");
		while((*(wr.name+i)=getch())!=13)
		{     outtextxy(250+j,100,wr.name+i);
		      i++;
		      j+=10;
		}
		   wr.name[i]='\0';
		   //setcolor(3);
		   //exit(1);
			    //bar(2,405,60,415);
		   if((wr.name[0]=='\0')&&(wr.name[1]=='\0'))
		    {	    outtextxy(2,410,"FILL NAME FIELD");
			    goto name1;
		     }
		//cout<<wr.name;
	////////////for password insertion//////////////

		entagain:

		j=0;
		i=0;
		p= new char;
		for( k=0;k<50;k++)
		     wr.pass[i]=NULL;
				   outtextxy(250+j,135,"_");
		while((*(p+i)=getche())!=13)
		 {
					  //cout<<" "<<*(p+i);
					  outtextxy(250+j,135,"*");
					  wr.pass[i]=*(p+i);
					  //M1.pass[i]=*(p+i);
					  i++;
					  j+=10;

		 }       wr.pass[i]='\0';
			 //M1.pass[i]='\0';
		 //setcolor(3);
		 //outtextxy(2,425,"pass length short");
		 setcolor(6);
			     if(i<5)
					  {
					  outtextxy(2,425,"pass length short");
					   goto entagain;
					  }
       }
			//cout<<wr.pass;
	////////////for gender insertion///////////
		j=2;
		i=0;
	   for(int k=0;k<2;k++)
		   wr.gen[k]=NULL;
		 outtextxy(250+j,170,"_");
		while(((*(wr.gen+i)=getch())!=13)&&(i==0))
		{
		      outtextxy(250+j,170,wr.gen+i);
		      //cout<<"   "<<*(wr.gen+i);
		      //wr.gen[0]=*(q+i);
		      i++;
		      j+=10;
		}     wr.gen[i]='\0';
		//cout<<"gender is   "<<wr.gen;

	///////////////for address insertion///////////////
		j=2;
		i=0;
		for(k=0;k<50;k++)
		      wr.address[k]=NULL;
		 outtextxy(250+j,205,"_");
		while((*(wr.address+i)=getche())!=13)
		{     outtextxy(250+j,205,wr.address+i);
		      i++;
		      j+=10;
		}
		   wr.address[i]='\0';
		   //cout<<"\n add is  "<<wr.address;
	//////////////////for city insertion//////////
		j=2;
		i=0;
		for(k=0;k<50;k++)
		     wr.city[k]=NULL;
		 outtextxy(250+j,240,"_");
		while((*(wr.city+i)=getche())!=13)
		{     outtextxy(250+j,240,wr.city+i);
		      i++;
		      j+=10;
		}
		wr.city[i]='\0';
	       //	cout<<"\n name of city is"<<wr.city;

	 /////////////for state insertion////////////
		j=2;
		i=0;
		for(k=0;k<50;k++)
		       wr.state[k]=NULL;
		 outtextxy(250+j,275,"_");
		while((*(wr.state+i)=getche())!=13)
		{     outtextxy(250+j,275,wr.state+i);
		      i++;
		      j+=10;
		}
		wr.state[i]='\0';
		//cout<<"\n  satte is  "<<wr.state;
	 ///////////////for pin code insertion//////////
		j=2;
		i=0;
		for(k=0;k<50;k++)
		      wr.pinc[k]=NULL;
		 outtextxy(250+j,310,"_");
		while((*(wr.pinc+i)=getche())!=13)
		{     outtextxy(250+j,310,wr.pinc+i);
		      i++;
		      j+=10;
		}
		wr.pinc[i]='\0';
	       //	cout<<"\n pin code is"<<wr.pinc;
	 ///////////////for mobile no.///////////////
		j=2;
		i=0;

		for(k=0;k<20;k++)
		     wr.mob[k]=NULL;
		      outtextxy(250+j,345,"_");
		while((*(wr.mob+i)=getche())!=13)
		{     outtextxy(250+j,345,(wr.mob+i));
		      i++;
		      j+=10;
		}
	       //	for(k=0;k<20;k++)
		   //    wr.mob[k]=(int)wr.mob[k];
		   wr.mob[i]='\0';

		      //	cout<<"mob is "<<wr.mob;
		//////////for email id insertion/////////
		i=0;
		j=2;
		for(k=0;k<20;k++)
		       wr.email[k]=NULL;
		 outtextxy(250+j,380,"_");
		while((*(wr.email+i)=getche())!=13)
		{     outtextxy(250+j,380,wr.email+i);
		      i++;
		      j+=10;
		}
		wr.email[i]='\0';

	 if(page==1)
	 {  dep:
		     gotoxy(33,27);
		     cin>>wr.dep;
		     //setcolor(3);
		     //outtextxy(2,400,"less amount");
		     if(wr.dep<1000)
		     {     	 setcolor(6);
				 outtextxy(2,440,"less amount");
				// outtextxy(2,400,"less amount");
				 goto dep;
		      }
		     a.currbal=wr.dep;
		     gotoxy(20,11);
		       //cout<<" deposit is" <<wr.dep;
		       //cout<<"\ndeposit are  "<<a.currbal;

  //////////////to store n generate account no  //////////////////////////

		/*     for(i=0;i<50;i++)
			 {	  wr.acc[0][i]=NULL;
				  a.acc_no[0][i]=NULL;
			  }*/
		  gotoxy(47,18);
		//cout<<"sixe is"<<sizeof(wr);
		 // cout<<" pper"<<x.tellg();
		//  getch();

	 // x.seekg(-(sizeof(wr)),ios::end);
	///////////////////////////////////////////////,,,,,///
	account onjj;
	fstream xy;
       xy.open("master.dat",ios::binary|ios::app|ios::in);
	int tott=0;
	 while(xy)
	  {
	  xy.read((char*)&onjj,sizeof(account));
	  tott++;
	  }
	 xy.close();
			    unsigned long a2=1000;
	    wr.acc=a2+tott+1;
	  // wr.acc[0][0]=cn;
	  // wr.acc[0][1]=++cp;
	 // cout<<"  "<<wr.acc[0];
	  a.acc_no=wr.acc;
     //	  a.acc_no[0][1]=wr.acc[0][1];
	  a.dd=d->da_day;
	  a.mm=d->da_mon;
	  a.yy=d->da_year;
	  a.transamt=wr.dep;
	  account M;
	  M.acc_no=wr.acc;
       //	  M.acc_no[0][1]=wr.acc[0][1];
	  strcpy(M.pass,wr.pass);
	  //cout<<"   a.acc no    "<<a.acc_no[0];
	  //getch();
//---       x.close();
    //   obj.close();
//---	 fstream x;
//----       x.open("info.dat",ios::binary|ios::app);
       //info wr;
       if(!x)
       {   cerr<<"file doesnt open";
	    getch();
	    exit(0);
       }
    //   fstream obj;
    // if(page==1)
      //	   obj.open("ban.dat",ios::app|ios::binary);
      //	  if(!obj)
      //	  {   cerr<<"ban file doest open";
       //	   getch();
	//   exit(0);
	 //  }

       x.write((char*)&wr,sizeof(wr));
       obj.write((char*)&a,sizeof(a));
       y.write((char*)&M,sizeof(M));
       setfillstyle(1,15);
       bar3d(160,8,632,455,4,1);
       setcolor(6);
       //for(int k=0;k<10;k++)
	  settextstyle(0,0,3);
	     outtextxy(200,40,"CONGRATULATIONS");


       outtextxy(260,100,wr.name);
       settextstyle(1,0,3);
       outtextxy(200,150,"YOUR NEW ACCOUNT IS CREATED");
	settextstyle(7,0,2);
	setcolor(2);
       outtextxy(180,200,"ACCOUNT NO IS");

	gotoxy(46,14);
	cout<<wr.acc;
      // outtextxy(360,200,wr.acc);
       //outtextxy(365,200,(char*)wr.acc[0]);
       outtextxy(180,250,"DEPOSIT IS");
       //outtextxy(340,250,wr.dep);
       gotoxy(46,17);
       cout<<wr.dep;
       x.close();
       obj.close();
       y.close();
       choice2(backkey());
     }

}
int info::backkey()
{   int i=0;
int end=0;
      //if (page==0)
	    setfillstyle(6,3);
	    fillellipse(550,400,50,30);
	    outtextxy(510,390,"EXIT");
	    setfillstyle(6,9);
	    fillellipse(250,400,50,30);
	    outtextxy(210,390,"BACK");

      /*else
      {  setfillstyle(6,3);
	    fillellipse(550,400,50,30);
	    setfillstyle(6,3);
	    fillellipse(250,400,50,30);
      }*/
     //
     //int key=getch();

    do
     {
	  int  key=getch();

	   switch(key)
	   {
			case 77:switch(i)
				{  case 1:
					setfillstyle(6,3);
					fillellipse(550,400,50,30);
					 outtextxy(510,390,"EXIT");
					setfillstyle(6,9);
					fillellipse(250,400,50,30);
					outtextxy(210,390,"BACK");
					i--;
					break;
				    case 0:setfillstyle(6,9);
					   fillellipse(550,400,50,30);
					    outtextxy(510,390,"EXIT");
					   setfillstyle(6,3);
					   fillellipse(250,400,50,30);
					   outtextxy(210,390,"BACK");
					   i++;
					   break;
				}
				break;

		    case 75:  switch(i)
			      {
				   case 1: setfillstyle(6,3);
					fillellipse(550,400,50,30);
					 outtextxy(510,390,"EXIT");
					setfillstyle(6,9);
					fillellipse(250,400,50,30);
					outtextxy(210,390,"BACK");
					i--;
					break;
				   case 0:setfillstyle(6,9);
					   fillellipse(550,400,50,30);
					    outtextxy(510,390,"EXIT");
					   setfillstyle(6,3);
					   fillellipse(250,400,50,30);
					   outtextxy(210,390,"BACK");
					   i++;
					   break;
				  }
				  break;
		       case 13: end=1;

		 }
	 }while(end!=1);
       return(i);
  }
void info::choice2(int n)
{
       switch(n)
       {
	    case 0:  setfillstyle(1,15);
		     bar3d(150,8,632,455,4,1);
		     //setcolor(6);
		     //setfillstyle(1,2);

		     menu();
		     break;
	    case 1:   exit(0);
		      break;
       }
 }
void info::acccheck()
{    //setcolor(15);

     setfillstyle(1,15);
     bar3d(160,8,632,455,4,1);
     setcolor(6);
      settextstyle(8,0,2);
      outtextxy(220,100,"Account no:-");
      outtextxy(220,150,"Password:-");

      rectangle(400,105,600,130);
      rectangle(400,155,600,180);
      //setfillstyle(6,3);
     // fillellipse(550,400,50,30);
     // outtextxy(540,400,"BACK");
     // getch();
     int flag=0;//int end=0;
      unsigned long tempacc;
      char temppass[50];
      //account r;
      fstream x;
      x.open("master.dat",ios::binary|ios::in);
      if(!x)
      {  cerr<<"file doesnt exit";
	   getch();
	  exit(0);
      }
	     gotoxy(52,8);
			 cin>>tempacc;
			 gotoxy(52,11);
			 gets(temppass);
		 //     x.read((char*)&wr,sizeof(wr));

	      /*	      for(int i=2;i<50;i++)
		      {     tempacc[0][i]=NULL;
			    r.acc[0][i]=NULL;
		       }*/

			  while(x)
			  {
			  x.read((char*)&r,sizeof(account));

			   //cout<<"in loop......";
			   //		 getch();
			   //cout<<wr.acc[0];
				   //cout<<wr.dep;
				   //cout<<"  "<<a.currbal;
				   //cout<<"  "<<a.acc_no[0];
			  //getch();
				   if(tempacc==r.acc_no)
				   {	 if(strcmp(temppass,r.pass)==0)
					 {      temporary=tempacc;
						 flag=2;
						 break;


										 //getch();
					   //	      menu1();
					  }
					 else
					     flag=1;
				     }
				     else flag=1;
			   }
			    //	 x.read((char*)&wr,sizeof(wr));
			    if(flag==2)
			    {
					//cout<<"found......";
					//getch();					 getch();
						      menu1();
			     }
			     if(flag==1)
			     {       fflush(stdin);
					fflush(stdout);
				     outtextxy(200,400,"invalid password");
				     //cout<<"ghgfhg";
				     getch();
				      p.menu();
			      }
			      p.menu();
	 getch();
   }
 void info::menu1()
 {
	   setfillstyle(1,15);
	   bar3d(160,8,632,455,4,1);

	   setcolor(0);
	   setfillstyle(2,3);
	   bar3d(300,80,500,130,4,1);

	  setcolor(6);
	  setfillstyle(9,3);
	  bar3d(300,155,500,205,4,1);
	  bar3d(300,220,500,270,4,1);
	  bar3d(300,295,500,345,4,1);
	  bar3d(300,360,500,410,4,1);
	  setcolor(6);
	  outtextxy(360,90,"DEBIT");
	  outtextxy(360,160,"CREDIT");
	  outtextxy(305,230,"MODIFY ACCOUNT");
	  outtextxy(315,300,"CLOSE ACCOUNT");
	  outtextxy(360,370,"EXIT");
	  task1(choice1());

  }
  int info::choice1()
  {
	     int i=0;
	     int end=1;

	     do
	     {         int k=getch();
			//cout<<k;
		       //	getch();
			switch(k)
			{
			  case 80:  switch(i)
				   {
				    case 0:  setcolor(6);
					     setfillstyle(9,3);
					     bar3d(300,80,500,130,4,1);
					     bar3d(300,220,500,270,4,1);
					     bar3d(300,295,500,345,4,1);
					     bar3d(300,360,500,410,4,1);
					     outtextxy(360,90,"DEBIT");
					     outtextxy(305,230,"MODIFY ACCOUNT");
					    outtextxy(315,300,"CLOSE ACCOUNT");
					    outtextxy(360,370,"EXIT");


					     setfillstyle(2,3);
					     bar3d(300,155,500,205,4,1);
					     setcolor(1);
					     outtextxy(360,160,"CREDIT");
					     i++;
					     break;
				     case 1: setcolor(6);
					     setfillstyle(9,3);

					     bar3d(300,80,500,130,4,1);
					     bar3d(300,155,500,205,4,1);
					      bar3d(300,295,500,345,4,1);
					     bar3d(300,360,500,410,4,1);

					    outtextxy(360,90,"DEBIT");
					    outtextxy(315,300,"CLOSE ACCOUNT");
					    outtextxy(360,370,"EXIT");
					     outtextxy(360,160,"CREDIT");


					     setfillstyle(2,3);
					     bar3d(300,220,500,270,4,1);
					      setcolor(1);
					     outtextxy(305,230,"MODIFY ACCOUNT");
					     i++;
					     break;
				     case 2: setcolor(6);
					     setfillstyle(9,3);

					     bar3d(300,80,500,130,4,1);
					     bar3d(300,155,500,205,4,1);
					      bar3d(300,220,500,270,4,1);
					      bar3d(300,360,500,410,4,1);

					      outtextxy(360,90,"DEBIT");
					      outtextxy(360,370,"EXIT");
					     outtextxy(360,160,"CREDIT");
					     outtextxy(305,230,"MODIFY ACCOUNT");

					     setfillstyle(2,3);
					    bar3d(300,295,500,345,4,1);
					      setcolor(1);
						outtextxy(315,300,"CLOSE ACCOUNT");
					      i++;
					      break;
				    case 3: setcolor(6);
					     setfillstyle(9,3);

					     bar3d(300,80,500,130,4,1);
					     bar3d(300,155,500,205,4,1);
					      bar3d(300,220,500,270,4,1);
						bar3d(300,295,500,345,4,1);
						outtextxy(360,90,"DEBIT");
					    outtextxy(315,300,"CLOSE ACCOUNT");
					     outtextxy(360,160,"CREDIT");
					     outtextxy(305,230,"MODIFY ACCOUNT");

					     setfillstyle(2,3);
					      bar3d(300,360,500,410,4,1);
					      setcolor(1);
						outtextxy(360,370,"EXIT");
					      i++;
					      break;
				       }
				       break;
			     case 72: switch(i)
				      {
					 case 1:  setcolor(6);
						  setfillstyle(9,3);
						  bar3d(300,155,500,205,4,1);
						  bar3d(300,220,500,270,4,1);
						  bar3d(300,295,500,345,4,1);
						  bar3d(300,360,500,410,4,1);
						   outtextxy(360,160,"CREDIT");
						 outtextxy(305,230,"MODIFY ACCOUNT");
						outtextxy(315,300,"CLOSE ACCOUNT");
						 outtextxy(360,370,"EXIT");

						 setfillstyle(2,3);
						 bar3d(300,80,500,130,4,1);
						 setcolor(1);
						 outtextxy(360,90,"DEBIT");
						i--;
						break;
					case 2: setcolor(6);
						  setfillstyle(9,3);
						   bar3d(300,80,500,130,4,1);
						  bar3d(300,220,500,270,4,1);
						  bar3d(300,295,500,345,4,1);
						  bar3d(300,360,500,410,4,1);
						  outtextxy(360,90,"DEBIT");
						  outtextxy(305,230,"MODIFY ACCOUNT");
						outtextxy(315,300,"CLOSE ACCOUNT");
						 outtextxy(360,370,"EXIT");

						 setfillstyle(2,3);
						  bar3d(300,155,500,205,4,1);

						 setcolor(1);
						     outtextxy(360,160,"CREDIT");
						i--;
						break;

					case 3: setcolor(6);
						  setfillstyle(9,3);
						   bar3d(300,155,500,205,4,1);
						   bar3d(300,80,500,130,4,1);

						  bar3d(300,295,500,345,4,1);
						  bar3d(300,360,500,410,4,1);
						  outtextxy(360,90,"DEBIT");
						   outtextxy(360,160,"CREDIT");

						outtextxy(315,300,"CLOSE ACCOUNT");
						 outtextxy(360,370,"EXIT");

						 setfillstyle(2,3);
						  bar3d(300,220,500,270,4,1);

						 setcolor(1);
						  outtextxy(305,230,"MODIFY ACCOUNT");

						i--;
						break;

					case 4: setcolor(6);
						  setfillstyle(9,3);
						   bar3d(300,155,500,205,4,1);
						   bar3d(300,80,500,130,4,1);
						    bar3d(300,220,500,270,4,1);

						  bar3d(300,360,500,410,4,1);
						  outtextxy(360,90,"DEBIT");
						   outtextxy(360,160,"CREDIT");
						     outtextxy(305,230,"MODIFY ACCOUNT");

						 outtextxy(360,370,"EXIT");

						 setfillstyle(2,3);
						  bar3d(300,295,500,345,4,1);

						 setcolor(1);
						 outtextxy(315,300,"CLOSE ACCOUNT");

						i--;
						break;
					case 5:  setcolor(6);
						  setfillstyle(9,3);
						   bar3d(300,155,500,205,4,1);
						   bar3d(300,80,500,130,4,1);
						    bar3d(300,220,500,270,4,1);
						   bar3d(300,295,500,345,4,1);

						  outtextxy(360,90,"DEBIT");
						   outtextxy(360,160,"CREDIT");
						     outtextxy(305,230,"MODIFY ACCOUNT");
						     outtextxy(315,300,"CLOSE ACCOUNT");


						 setfillstyle(2,3);

						    bar3d(300,360,500,410,4,1);
						 setcolor(1);
					       outtextxy(360,370,"EXIT");
					       i--;
						break;

					}
					break;
				 case 13:end=0;
			  }
	       }while(end!=0);
	  return(i);
	    //getch();
}
void info::task1(int n)
{
       switch(n)
       {
	     case 0: a.debit();
		     break;
	     case 1:a.credit();
		   break;
	   case 2:a.modify();
		    break;
	    case 3:a.close();
		    break;
	     case 4:exit(0);

	 }
	// getch();

  }
//////////////functions of 2nd class...debit credit ,modify,close/////////////////////

//fstream ob;
//ob.open("bank1.dat",ios::in|ios::out|ios::binary)

void accinfo::debit()
{      fstream objj,y,obj;
       objj.open("ban.dat",ios::binary|ios::in);
       accinfo r1;

     //  r1=new accinfo;
       if(!objj)
       {   cerr<<"ban file doest open";
	   getch();
	   exit(0);
       }
 /*      for(int i=2;i<50;i++)
		      {     //tempacc[0][i]=NULL;
			    wr.acc[0][i]=NULL;
			    a.acc_no[0][i]=NULL;
		       }
		       */
       //for(int i=3;i<50;i++)
	 //  wr.acc[0][3]=NULL;
	 int nrec=0;float currbal1=0;
   //    obj.read((char*)&a,sizeof(a));
       ////////////to find the current balance////////////////////////////
     //cout<<"\nloop starts";
     //getch();
      while(objj)
      {
	objj.read((char*)&r1,sizeof(accinfo));
	   //cout<<"loop continue";
	  // getch();
	    if(r1.acc_no==temporary)
		  { currbal1=r1.currbal;
		     //cout<<"\n\ngot currn : "<<currbal1;
		      // getch();
		     //  break;
		    }
      }

      objj.close();
	r1.acc_no=r.acc_no;
	//cout<<"/n rrrrr"<<r.acc_no;
	//cout<<"/n r1111111"<<r1.acc_no;
	//getch();
       obj.open("ban.dat",ios::binary|ios::app);
       if(!obj)
       {   cerr<<"ban file doest open";
	   getch();
	   exit(0);
       }

  //     for(i=2;i<50;i++)
    //		      {     //tempacc[0][i]=NULL;
      //			    wr.acc[0][i]=NULL;
	//		    a.acc_no[0][i]=NULL;
	  //	       }

       //	  r1=new accinfo;

				setfillstyle(1,15);
				bar3d(160,8,632,455,4,1);
				setcolor(6);
				//gotoxy(60,5);
				//cout<<wr.acc;

				settextstyle(6,0,2);
				outtextxy(200,50,"ACCOUNT NO ");
				gotoxy(60,5);
				cout<<r1.acc_no;
				//outtextxy(400,50,(char*)r1->acc_no);

				outtextxy(160,60,"--------------------------------------------------------------------");
				outtextxy(160,62,"--------------------------------------------------------------------");
				settextstyle(1,0,1);
				outtextxy(190,100,"Mode of payment(cheque/cash)");
				rectangle(190,135,600,160);

				outtextxy(190,190,"date of transaction(dd/mm/yyyy)");
				rectangle(190,223,210,247);
				rectangle(220,223,240,247);
				rectangle(250,223,290,247);
			outtextxy(190,270,"amount deposit");
			rectangle(190,300,600,320);
			outtextxy(190,340,"Current balance");
			rectangle(190,360,600,390);
			gotoxy(25,24);
			cout<<currbal1;
			gotoxy(25,10);
			gets(r1.type);
			date:
				outtextxy(2,400,"                   ");
					gotoxy(25,15);
					cout<<"  ";
					gotoxy(29,15);
					cout<<"  ";
					gotoxy(33,15);
					cout<<"    ";
				gotoxy(25,15);
				cin>>r1.dd;
				gotoxy(29,15);
				cin>>r1.mm;

				gotoxy(33,15);
				cin>>r1.yy;
				if( (r1.dd<1)||(r1.dd>31)||(r1.mm<1)||(r1.mm>12)||(r1.yy<1900)||(r1.yy>2020))
				{            outtextxy(2,400,"Invalid date");
						goto date;
				}
				gotoxy(25,20);
				cin>>r1.transamt;
				r1.currbal=currbal1+r1.transamt;
				//obj.seekp(-sizeof(a),ios::cur);

	  //			break;

      obj.write((char*)&r1,sizeof(r1));
      setfillstyle(1,15);
       bar3d(160,8,632,455,4,1);
       setcolor(3);
       settextstyle(1,0,2);
       outtextxy(280,50,"SUCCESS");
       outtextxy(210,100,"amonut deposited to your account");
       outtextxy(160,140,"==================================================================================");
       setcolor(2);
       settextstyle(6,0,5);
       outtextxy(200,200,"Account no");
       outtextxy(200,240,"Deposited amount");
       outtextxy(200,280,"Current balance");
       gotoxy(66,15);
       cout<<r1.acc_no;
       gotoxy(66,18);
       cout<<r1.transamt;
       gotoxy(66,20);
       cout<<r1.currbal;
       obj.close();


       setcolor(6);
       settextstyle(1,0,1);
       task(wr.backkey());
    obj.close();
 }
 void accinfo::task(int n)
 {
       switch(n)

       {
	   case 0:setfillstyle(1,15);
		  bar3d(150,8,632,455,4,1);
		   setcolor(6);
		   wr.menu1();
		   break;
	 case 1:exit(0);
	}
 }

///////////////////////new credit////////////////////////


void accinfo::credit()
{      fstream objj,y,obj;
       objj.open("ban.dat",ios::binary|ios::in);
       accinfo r1;

     //  r1=new accinfo;
       if(!objj)
       {   cerr<<"ban file doest open";
	   getch();
	   exit(0);
       }
 /*      for(int i=2;i<50;i++)
		      {     //tempacc[0][i]=NULL;
			    wr.acc[0][i]=NULL;
			    a.acc_no[0][i]=NULL;
		       }
		       */
       //for(int i=3;i<50;i++)
	 //  wr.acc[0][3]=NULL;
	 int nrec=0;float currbal1=0;
   //    obj.read((char*)&a,sizeof(a));
       ////////////to find the current balance////////////////////////////

      while(objj)
      {
	objj.read((char*)&r1,sizeof(accinfo));

	    if(r1.acc_no==temporary)
		  { currbal1=r1.currbal;
		    //cout<<"\n\ngot currn : "<<currbal1;
		     //  getch();
		       //break;
		    }
      }

      objj.close();

	r1.acc_no=r.acc_no;
    //	cout<<"/n rrrrr"<<r.acc_no;
   //	cout<<"/n r1111111"<<r1.acc_no;
    //	getch();
       obj.open("ban.dat",ios::binary|ios::app);
       if(!obj)
       {   cerr<<"ban file doest open";
	   getch();
	   exit(0);
       }


				setfillstyle(1,15);
				bar3d(160,8,632,455,4,1);
				setcolor(6);
				//gotoxy(60,5);
				//cout<<wr.acc;

				settextstyle(6,0,2);
				outtextxy(200,50,"ACCOUNT NO ");
				gotoxy(60,5);
				cout<<r1.acc_no;
				//outtextxy(400,50,(char*)r1->acc_no);

				outtextxy(160,60,"--------------------------------------------------------------------");
				outtextxy(160,62,"--------------------------------------------------------------------");
				settextstyle(1,0,1);
				outtextxy(190,100,"Mode of payment(cheque/cash)");
				rectangle(190,135,600,160);


				outtextxy(190,190,"date of transaction(dd/mm/yyyy)");
				rectangle(190,223,210,247);
				rectangle(220,223,240,247);
				rectangle(250,223,290,247);
			outtextxy(190,270,"amount to be withdrawn");
			rectangle(190,300,600,320);
			outtextxy(190,340,"Current balance");
			rectangle(190,360,600,390);
			gotoxy(25,24);
			cout<<currbal1;
			gotoxy(25,10);
			gets(r1.type);
			date:
				outtextxy(2,400,"                   ");
					gotoxy(25,15);
					cout<<"  ";
					gotoxy(29,15);
					cout<<"  ";
					gotoxy(33,15);
					cout<<"    ";
				gotoxy(25,15);
				cin>>r1.dd;
				gotoxy(29,15);
				cin>>r1.mm;

				gotoxy(33,15);
				cin>>r1.yy;
				if( (r1.dd<1)||(r1.dd>31)||(r1.mm<1)||(r1.mm>12)||(r1.yy<1900)||(r1.yy>2020))
				{            outtextxy(2,400,"Invalid date");
						goto date;
				}
				gotoxy(25,20);
				withdraw:
				cin>>r1.transamt;

				if(r1.transamt>r1.currbal)
				{     outtextxy(2,350,"cant withdraw");
				     goto withdraw;
				}

				r1.currbal=currbal1-r1.transamt;
				//obj.seekp(-sizeof(a),ios::cur);

	  //			break;

      obj.write((char*)&r1,sizeof(r1));
      setfillstyle(1,15);
       bar3d(160,8,632,455,4,1);
       setcolor(3);
       settextstyle(1,0,2);
       outtextxy(280,50,"SUCCESS");
       outtextxy(210,100,"amonut withdrawn from your account");
       outtextxy(160,140,"==================================================================================");
       setcolor(2);
       settextstyle(6,0,5);
       outtextxy(200,200,"Account no");
       outtextxy(200,240,"Withdrawn amount");
       outtextxy(200,280,"Current balance");
       gotoxy(66,15);
       cout<<r1.acc_no;
       gotoxy(66,18);
       cout<<r1.transamt;
       gotoxy(66,20);
       cout<<r1.currbal;
       obj.close();


       setcolor(6);
       settextstyle(1,0,1);
       task(wr.backkey());
    obj.close();
 }


//////////////////////////////////////////////////////



void accinfo::modify()
{        page=0;
       setfillstyle(1,15);
       bar3d(160,8,632,455,4,1);
       setcolor(6);
	info tr;

       fstream x,temp;
       x.open("info.dat",ios::binary|ios::in);
       temp.open("copy.dat",ios::binary|ios::out);
      if(!x)
      {  cerr<<"file doesnt exit";
	   getch();
	  exit(0);
      }
      if(!temp)
      {    cerr<<"file doesnt exit";
	   getch();
	  exit(0);
       }

	x.read((char*)&tr,sizeof(info));
      while(x)
      {
	 //cout<<" :"<<tr.acc;
	 //getch();
   /*	 for(int i=2;i<50;i++)
	 {      tr.acc[0][i]=NULL;
	       wr.acc[0][i]= NULL;
	  }   */

	 if(tr.acc==r.acc_no)
	 {
	       settextstyle(4,0,4);
		outtextxy(200,40,"Enter the following details:");
		 settextstyle(3,0,1);
	       outtextxy(160,135,"Name");
		rectangle(250,140,600,155);

		//outtextxy(160,135,"Password");
	       //	rectangle(250,140,600,155);

		outtextxy(160,170,"Gender");
		rectangle(250,175,275,190);

		outtextxy(160,205,"Address");
		rectangle(250,210,600,225);

		outtextxy(160,240,"City");
		rectangle(250,245,600,260);

		outtextxy(160,275,"State");
		rectangle(250,280,600,295);

		outtextxy(160,310,"Pin Code");
		rectangle(250,315,400,330);

		outtextxy(160,345,"Mobile no.");
		rectangle(250,350,600,365);

		outtextxy(160,380,"E-Mail ID");
		rectangle(250,385,600,400);

		wr.insert(page);
		temp.write((char*)&wr,sizeof(wr));
		break;
	   }
       //	else
	   temp.write((char*)&wr,sizeof(wr));
	    x.read((char*)&tr,sizeof(tr));
     }
     temp.close();
     x.close();


     x.open("info.dat",ios::binary|ios::out);
      temp.open("copy.dat",ios::binary|ios::in);
      if(!x)
      {  cerr<<"file doesnt exit";
	   getch();
	  exit(0);
      }
      if(!temp)
      {    cerr<<"file doesnt exit";
	   getch();
	  exit(0);
       }
       while(temp)
       {     temp.read((char*)&tr,sizeof(info));
	     x.write((char*)&tr,sizeof(info));
       }
       x.close();
       temp.close();

    /*   account M;
       fstream xy,temp1;
       xy.open("master.dat",ios::binary|ios::app|ios::in);
       temp1.open("copy1.dat",ios::binary|ios::out);
       if(!xy)
      {  cerr<<"file doesnt exit";
	   getch();
	  exit(0);
      }
      if(!temp1)
      {    cerr<<"file doesnt exit";
	   getch();
	  exit(0);
       }

	 xy.read((char*)&M,sizeof(M));
	 while(xy)
	 {       cout<<"   "<<M.pass;
		 cout<<"aacc no"<<M.acc_no;
		  getch();
		 if(M.acc_no==r.acc_no)
		 {        strcpy(M.pass,M1.pass);
			 cout<<"copied";
			 getch();
			   break;
		 }
		 temp1.write((char*)&M,sizeof(M));
		  xy.read((char*)&M,sizeof(M));
	}
	temp1.close();
	xy.close();

      xy.open("master.dat",ios::binary|ios::out);
      temp1.open("copy1.dat",ios::binary|ios::in);
      if(!xy)
      {  cerr<<"file doesnt exit";
	   getch();
	  exit(0);
      }
      if(!temp1)
      {    cerr<<"file doesnt exit";
	   getch();
	  exit(0);
       }
       //account M;
       while(temp1)
       {     temp1.read((char*)&M,sizeof(account));
	     xy.write((char*)&M,sizeof(account));
       }
       xy.close();
       temp1.close();
    */
       setfillstyle(1,15);
       bar3d(160,8,632,455,4,1);
       setcolor(6);
	outtextxy(280,50,"SUCCESS");
       outtextxy(210,100,"Account details modified");
       outtextxy(160,140,"==================================================================================");
       task(wr.backkey());
 }

 void accinfo::close()
 {
	 setfillstyle(1,15);
       bar3d(160,8,632,455,4,1);
       setcolor(6);
	 info tr;
	settextstyle(3,0,1);
	char ch;

	outtextxy(200,100,"are u sure you want to delete your account");
	outtextxy(200,120,"confirm deletion(y/n)");
	ch=getch();
	outtextxy(240,120,(char*)ch);
       account objn;

	if(ch=='y')
	{    /*   fstream x,temp;
		      x.open("info.dat",ios::binary|ios::in);
		      temp.open("copy.dat",ios::binary|ios::out);
		     //info wr;
		     if(!x)
		     {   cerr<<"111file doesnt open";
			    getch();
			      exit(0);
		       }
		       fstream obj;

			      obj.open("ban.dat",ios::app|ios::binary);
			       if(!obj)
			      {  cerr<<"ban file doest open";
				     getch();
				     exit(0);
				}
	      x.read((char*)&tr,sizeof(tr));
	       while(x)
	      {    //	 for(int i=2;i<50;i++)
		     //	 {      tr.acc[0][i]=NULL;
		       //	       wr.acc[0][i]= NULL;
			// }

		 if(tr.acc==r.acc_no)
		 {     gotoxy(20,20);
		       cout<<r.acc_no;
		       outtextxy(240,200,"ACCOUNT DELETED");
		       //temp.write((char*)&tr,sizeof(tr));
		       //x.read((char*)&p,sizeof(p));

		 }
		 else
		     temp.write((char*)&tr,sizeof(tr));
		     //getch();
		   x.read((char*)&tr,sizeof(tr));

	       }
	       x.close();
	       temp.close();
	       x.open("info.dat",ios::binary|ios::out);
	      temp.open("copy.dat",ios::binary|ios::in);
      if(!x)
      {  cerr<<"file doesnt exit";
	   getch();
	  exit(0);
      }
      if(!temp)
      {    cerr<<"file doesnt exit";
	   getch();
	  exit(0);
       }
       while(temp)
       {     temp.read((char*)&tr,sizeof(tr));
	     x.write((char*)&tr,sizeof(tr));
       }
       x.close();
       temp.close();
      */
////////////////deleteting contents of 2nd file////////////////////////


       fstream temp,obj;
       temp.open("copy.dat",ios::binary|ios::out);
       obj.open("master.dat",ios::binary|ios::in);


//       x.write((char*)&tr,sizeof(info));


       while(obj)
       {
	    obj.read((char*)&objn,sizeof(account));
		 //for(int i=2;i<50;i++)
		   //	 {      tr.acc[0][i]=NULL;
		     //	       wr.acc[0][i]= NULL;
		      //	 }

		// if(tr.acc!=objn.acc_no)
		if(temporary!=objn.acc_no)
		      temp.write((char*)&objn,sizeof(account));


	}
	temp.close();
	obj.close();
	remove("master.dat");
	rename("copy.dat","master.dat");
	 if(rename("copy.dat","master.dat")==0)
	  {
		outtextxy(200,190,"Succesful : your account closed ");
		getch();
		//p.menu();
	  }

	  else
	   {
	   outtextxy(200,200," not sucessful in deleting ");
	   getch();
	  }
		      /*

		 obj.read((char*)&b,sizeof(b));

       }
	       //x.close();
	       temp.close();
		 obj.open("info.dat",ios::binary|ios::out);
	      temp.open("copy.dat",ios::binary|ios::in);
      if(!obj)
      {  cerr<<"obj file doesnt exit";
	   getch();
	  exit(0);
      }
      if(!temp)
      {    cerr<<"temp file doesnt exit";
	   getch();
	  exit(0);
       }
       while(temp)
       {     temp.read((char*)&b,sizeof(b));
	     obj.write((char*)&b,sizeof(b));
       }
       obj.close();
       temp.close();

	    outtextxy(200,200,"SUCESS");
	    outtextxy(200,230,"ACCOUNT DELETED");

     }
  ////////deleting contents of 3rd file////////////////////////////////
	  account M;
       fstream xy,temp1;
       xy.open("master.dat",ios::binary|ios::in);
       temp1.open("copy1.dat",ios::binary|ios::out);
       if(!xy)
      {  cerr<<"file doesnt exit";
	   getch();
	  exit(0);
      }
      if(!temp1)
      {    cerr<<"file doesnt exit";
	   getch();
	  exit(0);
       }

	 xy.read((char*)&M,sizeof(M));
	 while(xy)
	 {       cout<<"   "<<M.pass;
		 cout<<"aacc no"<<M.acc_no;
		  getch();
		 if(M.acc_no==r.acc_no)
		 {       xy.read((char*)&M,sizeof(M));
			 cout<<"deeted";
			 getch();

		 }
		 temp1.write((char*)&M,sizeof(M));
		  xy.read((char*)&M,sizeof(M));
	}
	temp1.close();
	xy.close();

      xy.open("master.dat",ios::binary|ios::out);
      temp1.open("copy1.dat",ios::binary|ios::in);
      if(!xy)
      {  cerr<<"file doesnt exit";
	   getch();
	  exit(0);
      }
      if(!temp1)
      {    cerr<<"file doesnt exit";
	   getch();
	  exit(0);
       }
       //account M;
       while(temp1)
       {     temp1.read((char*)&M,sizeof(account));
	     xy.write((char*)&M,sizeof(account));
       }
       xy.close();
       temp1.close();

      */

     }
       p.menu();
       task(wr.backkey());
 }
 void main(void)
{

		int gdriver = DETECT, gmode, errorcode;
	    initgraph(&gdriver, &gmode, "");
	  /* read result of initialization */
	errorcode = graphresult();
	  if (errorcode != grOk)  /* an error occurred */
	 {
		  printf("Graphics error: %s\n", grapherrormsg(errorcode));
		 printf("Press any key to halt:");
		 getch();
		 exit(1); /* terminate with an error code */
	  }
	welcums();
	 p.menu();
	 getch();
	closegraph();
}
