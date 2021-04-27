/****header files****/

#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<process.h>
#include<fstream.h>
#include<ctype.h>
#include<graphics.h>
#include<string.h>
#include<dos.h>
#include<iomanip.h>
#include<io.h>

void draw_box(int l,int t,int r,int b,int c)
{
clrscr();
textcolor(c);
gotoxy(l,t);
cprintf("E");
for(int i=1;i<r-1;i++)
cprintf("I");
cprintf(">>");
for(i=t+1;i<b;i++)
{
gotoxy(r,i);
cprintf("o");
gotoxy(l,i);
cprintf("o");
}
gotoxy(r,b);
cprintf("1/4");
gotoxy(l,b);
cprintf("E");
for(i=1;i<r-1;i++)
cprintf("I");
}

void box(int l,int t,int r,int b,int c)
{
clrscr();
textcolor(c);
gotoxy(l,t);
cprintf("U");
for(int i=l;i<r-1;i++)
cprintf("A");
cprintf("$");
for(i=t+1;i<b;i++)
{
gotoxy(r,i);
cprintf("3");
gotoxy(l,i);
cprintf("3");
}
gotoxy(r,b);
cprintf("U");
gotoxy(l,b);
cprintf("A");
for(i=l;i<r-1;i++)
cprintf("A");
}

  static int templno;
class billing
{
protected:
long int metno,tempno;
char custnm[20],custadd[20],category,metstat;
long int curread;
long int prevread,tempread;
long int units,noofread;
int year1,month1,day1;
int colstat;
float actamount,fine,totamoun;
long int billno,tmpstore;
int byear,cyear,ryear;
int bmonth,cmonth,rmonth;
int bday,cday,rday,tday,tmonth,tyear;

public:
billing()
{
custnm[0]='\0';
custadd[0]='\0';
category='\0';
metstat='\0';
tempno=1110;
metno=0;
tmpstore=0;
prevread=0;
curread=0;
tempread=0;
noofread=0;
units=0;
year1=0;
month1=0;
day1=0;
colstat=0;
actamount=0.0;
fine=0.0;
totamoun=0.0;
billno=0;
tday=tmonth=tyear=0;
byear=cyear=ryear=0;
bday=cday=rday=0;
bmonth=cmonth=rmonth=0;
}
void accept1();
void accept2();
void display1();
void display2();
void display3();
void modify1();
void modify2();
void read();
int rtmetno();
void meterno();
void bill1no();
int rtbillno();
void calculate();
void duedate();
int collected();
int collection();
void mon();
void metstatus();
void display4();
void display5();
int rtpayst();
void fineamount();
float update();
int rtmont();
};

/*****billing class function*********/
int billing::rtmont()
{
cout<<"month:"<<cmonth;
return(cmonth);
}

float billing::update()
{
draw_box(13,5,55,15,78);
gotoxy(21,5);
textcolor(42124);
cprintf("***COLLECTION UPDATE***");
gotoxy(19,6);
textcolor(20);
cprintf("BILL NO. : %ld",billno);
gotoxy(19,7);
cprintf("METER NO. : %ld",metno);
gotoxy(19,8);
cprintf("NAME: %s",custnm);
gotoxy(19,9);
cprintf("ACTUAL AMOUNT : %f",actamount);
gotoxy(19,10);
cprintf("FINE AMOUNT : %f ",fine);
gotoxy(19,11);
cprintf("TOTAL AMOUNT : %f ",totamoun);
gotoxy(19,12);
cprintf("DATE OF COLLECTION: %d : %d : %d",cday,cmonth,cyear);
getch();
return(totamoun);
}

void billing::display5()
{
draw_box(13,5,45,10,58);
gotoxy(22,5);
textcolor(42124);
cprintf("***DEFAULTERS***");
gotoxy(20,6);
textcolor(39);
cprintf("NAME : %s",custnm);
gotoxy(20,7);
cprintf("METNO. : %ld",metno);
gotoxy(20,8);
cprintf("TOTAL AMOUNT = %f",totamoun);
gotoxy(20,9);
cprintf("PAYMENT STATUS : %d ",colstat);
getch();
}

void billing::fineamount()
{
int d1=0,m1=0,y1=0,d11=0,m11=0,y11=0;
struct dosdate_t d;
_dos_getdate(&d);
d11=d.day;
m11=d.month;
y11=d.year;
if(y11>=year1)
{
y1=y11-year1;
if(y1>0)
fine=10;
else
{
if(m11>month1)
{
m1=m11-month1;
if(m1>0)
fine =10;
else
{
if(d11>=day1)
{
d1=d11-day1;
if(d1>0)
fine=10;
else
fine=0;
}
else
fine=0;
}
}
else
fine=0;
}
}
else
fine=0;
}

int billing::rtpayst()
{
if(colstat==1)
return(0);
else
return(1);
}

void billing::meterno()
{
tempno=metno;
}

int billing::collected()
{
draw_box(10,2,60,22,20);
gotoxy(25,3);
textcolor(50205/*+blink*/);
cprintf("***COLLECTED***");
gotoxy(21,5);
textcolor(46);
cprintf("BILL NO: %ld",billno);
gotoxy(21,6);
cprintf("METER NO: %ld",metno);
gotoxy(21,7);
cprintf("NAME: %s ",custnm);
gotoxy(21,8);
cprintf("ADDRESS: %s ",custadd);
gotoxy(21,9);
cprintf("CATEGORY: %c ",category);
gotoxy(21,10);
cprintf("METER STATUS: %c",metstat);
gotoxy(21,11);
cprintf("DATE OF READING: %d:%d;%d",rday,rmonth,ryear);
gotoxy(21,12);
cprintf("PREVIOUS READING: %ld",prevread);
gotoxy(21,13);
cprintf("CURRENT METER READING: %ld",curread);
gotoxy(21,14);
cprintf("DATE OF BILLING: %d:%d:%d",bday,bmonth,byear);
gotoxy(21,15);
cprintf("DUE DATE OF COLLECTION: %d:%d:%d",day1,month1,year1);
gotoxy(21,16);
cprintf("ACTUAL AMOUNT: %f ",actamount);
fineamount();
gotoxy(21,17);
cprintf("FINE AMOUNT : %f ",fine);
totamoun=actamount+fine;
gotoxy(21,18);
cprintf("TOTAL AMOUNT : %f ",totamoun);
gotoxy(21,19);
cprintf("PAYMENT STATUS: %d", colstat);
gotoxy(21,20);
cprintf("DATE OF COLLECTION: %d:%d:%d",cday,cmonth,cyear);
getch();
return(1);
}

int billing::collection()
{
draw_box(10,3,60,24,15643);
gotoxy(25,3);
textcolor(42124);
cprintf("***NOT COLLECTED***");
gotoxy(21,5);
textcolor(45);
cprintf("BILL NO: %ld",billno);
gotoxy(21,6);
cprintf("METER NO: %ld",metno);
gotoxy(25,7);
cprintf("NAME: %s",custnm);
gotoxy(25,8);
cprintf("ADRESS: %s",custadd);
gotoxy(25,9);
cprintf("CATEGORY: %c",category);
gotoxy(21,10);
cprintf("METER STATUS: %c",metstat);
gotoxy(25,11);
cprintf("DATE OF READING: %d:%d:%d",rday,rmonth,ryear);
gotoxy(25,12);
cprintf("PREVIOUS READING: %ld",prevread);
gotoxy(25,13);
cprintf("CURRENT METER READING: %ld",curread);
gotoxy(21,14);
cprintf("DATE OF BILLING: %d:%d:%d",bday,bmonth,byear);
gotoxy(21,15);
cprintf("DUE DATE OF COLLECTION: %d:%d:%d",day1,month1,year1);
gotoxy(25,16);
cprintf("ACTUAL AMOUNT: %f",actamount);
fineamount();
gotoxy(25,17);
cprintf("FINE AMOUNT: %f",fine);
totamoun=actamount+fine;
gotoxy(21,18);
cprintf("TOTAL AMOUNT: %f",totamoun);
int ii=0;int pp=0;
while(pp!=3)
{
gotoxy(25,19);
cprintf("ENTER YOUR CHOICE: ");
gotoxy(21,20);
cprintf("1:PAID AND 2:NOT PAID");
cscanf("%d",&pp);
switch(pp)
{
case 1:
{
colstat=1;
pp=3;
ii=1;
struct dosdate_t d;
_dos_getdate(&d);
cday=d.day;
cmonth=d.month;
cyear=d.year;
gotoxy(21,21);
cprintf("DATE OF COLLECTION: %d:%d:%d",cday,cmonth,cyear);
break;
}
case 2:
{
colstat=0;
pp=3;
ii=2;
break;
}
case 3:
{
ii=3;
exit;
break;
}
default:
cout<<"INVALID INPUT";
}
}
if(colstat==1)
{
gotoxy(21,22);
textcolor(CYAN/*+BLINK*/);
cprintf("PAYMENT STATUS: PAID");
}
else
{
gotoxy(21,22);
textcolor(CYAN/*+BLINK*/);
cprintf("PAYMENT STATUS : NOT PAID");
}
getch();
return(ii);
}

void billing::bill1no()
{
templno=billno;
}

void billing::duedate()
{
int r=0;
long int mm=10,nn;
struct dosdate_t d;
_dos_getdate(&d);
byear=d.year;
bmonth=d.month;
bday=d.day;
if(bmonth==1||bmonth==3||bmonth==5||bmonth==7||bmonth==8||bmonth==10||bmonth==12)
{
if(bday==31)
{
if(bmonth==12)
{
year1=byear+1;
month1=1;
r=1;
}
day1=mm;
if(r!=1)
{
month1=bmonth+1;
year1=byear;
}
}
else
{
nn=mm;
day1=bday;
while(nn>1)
{
if(day1<=31)
{
day1=day1+1;
month1=bmonth;
year1=byear;
nn--;
}
else
{
if(bmonth==12)
{
year1=byear+1;
month1=1;
r=1;
}
day1=nn;
if(r!=1)
{
month1+=1;
year1=byear;
}
break;
}
}
}
}
else
{
if(month1==2)
{
if((byear%4==0&&byear%100!=0)||(byear%400==0))
{
if(bday==29)
{
month1=bmonth+1;
year1=byear;
day1=mm;
}
else
{
nn=mm;
day1=bday;
while(nn>=1)
{
if(day1<=29)
{
day1+=1;
month1=bmonth;
year1=byear;
nn--;
}
else{
month1=bmonth+1;
day1=nn;
year1=byear;
break;
}
}
}
}
else
{
if(bday==28)
{
month1=bmonth+1;
year1=byear;
day1=mm;
}
else
{
nn=mm;
day1=bday;
while(nn>=1)
{
if(day1<=28)
{
day1=day1+1;
month1=bmonth;
year1=byear;
nn--;
}
else
{
month1=bmonth+1;
day1=nn;
year1=byear;
break;
}
}
}
}
}
else
{
if(bday==30)
{
month1=bmonth+1;
day1=mm;
year1=byear;
}
else
{
nn=mm;
day1=bday;
while(nn>=1)
{
if(day1<=30)
{
day1=day1+1;
month1=bmonth;
year1=byear;
nn--;
}
else
{
month1=bmonth+1;
day1=nn;
year1=byear;
break;
}
}
}
}
}
}


void billing::display3()
{
draw_box(13,4,55,22,4);
gotoxy(28,4);
textcolor(42124);
cprintf("***DISPLAY***");
mon();
gotoxy(20,6);
textcolor(67);
cprintf("BILL NO: %ld",billno);
gotoxy(20,7);
cprintf("METER NO: %ld",metno);
gotoxy(20,8);
cprintf("NAME OF CUSTOMER: %s",custnm);
gotoxy(20,9);
cprintf("ADDRESS OF CUSTOMER: %s",custadd);
gotoxy(20,10);
cprintf("CATEGORY: %c",category);
gotoxy(20,11);
cprintf("METER STATUS: %C",metstat);
gotoxy(20,12);
cprintf("DATE OF READING: %d:%d:%d",rday,rmonth,ryear);
gotoxy(20,13);
cprintf("PREVIOUS READING: %ld",prevread);
gotoxy(20,14);
cprintf("CURRENT READING: %ld",curread);
gotoxy(20,15);
units=curread-prevread;
cprintf("UNITS CONSUMED: %ld",units);
gotoxy(20,16);
cprintf("DATE OF BILLING: %d:%d:%d",bday,bmonth,byear);
gotoxy(20,17);
cprintf("DUE DATE: %d:%d:%d",day1,month1,year1);
gotoxy(20,18);
cprintf("ACTUAL AMOUNT: %f",actamount);
gotoxy(20,19);
cprintf("FINE AMOUNT: %f",fine);
totamoun=actamount+fine;
gotoxy(20,20);
cprintf("TOTAL AMOUNT: %f",totamoun);
getch();
}


void billing::calculate()
{
colstat=0;
billno=templno+1;
duedate();
if(metstat=='b')
{
actamount=100;
totamoun=100;
}
else
{
units=curread-prevread;
if(category=='g'||category=='G')
{
if(units<=500)
actamount=units*1.00;
else
{
if(units<=1000)
actamount=units*1.50;
else
actamount=units*2.00;
}
}
else
{
if(category=='e'||category=='E')
{
if(units<=500)
actamount=units*0.50;
else
{
if(units<=1000)
actamount*1.00;
else
actamount=units*1.50;
}
}
else
{
if(category=='h' ||category=='H')
{
if(units<=500)
actamount=units*0.75;
else
{
if(units<=1000)
actamount=units*0.50;
else
actamount=units*0.75;
}
}
else
actamount=0.0;
}
}
}
draw_box(13,5,55,22,4);
gotoxy(28,5);
textcolor(42124);
cprintf("***BILL DETAILS***");
gotoxy(28,6);
textcolor(67);
cprintf("BILL NO: %ld",billno);
gotoxy(28,7);
cprintf("METER NO: %ld",metno);
gotoxy(28,8);
cprintf("NAME OF CUSTOMER: %s",custnm);
gotoxy(28,9);
cprintf("ADDRESS OF CUSTOMER: %s",custadd);
gotoxy(28,10);
cprintf("CATEGORY: %c",category);
gotoxy(28,11);
cprintf("METER STATUS: %c",metstat);
gotoxy(28,12);
cprintf("DATE OF READING: %d:%d:%d",rday,rmonth,ryear);
gotoxy(28,13);
cprintf("PREVIOUS READING: %ld",prevread);
gotoxy(28,14);
cprintf("CURRENT READONG: %ld",curread);
gotoxy(28,15);
units=curread-prevread;
cprintf("UNITS CONSUMED: %ld",units);
gotoxy(28,16);
cprintf("DATE OF BILLING: %d:%d:%d",bday,bmonth,byear);
gotoxy(28,17);
cprintf("DUE DATE: %d:%d:%d",day1,month1,year1);
gotoxy(28,18);
cprintf("ACTUAL AMOUNT: %f",actamount);
gotoxy(28,19);
cprintf("FINE AMOUNT: %f",fine);
totamoun=actamount+fine;
gotoxy(28,20);
cprintf("TOTAL AMOUNT:%f",totamoun);
getch();
}

void billing::mon()
{
struct dosdate_t d;
_dos_getdate (&d);
bmonth=d.month;
gotoxy(21,5);
cprintf("FOR THE MONTH OF %d",bmonth);
}

void billing::accept1()
{
draw_box(13,5,60,13,90);
gotoxy(28,5);
textcolor(42124);
prevread=0;
curread=0;
cprintf(">><<ADDITION>><<");
gotoxy(21,6);
textcolor(30);
metno=tempno+1;
cprintf("METER NO: %ld",metno);
gotoxy(15,7);
cprintf("NAME OF THE CUSTOMER: ");
gotoxy(15,8);
cprintf("ADDRESS OF THE CUSTOMER: ");
gotoxy(15,9);
cprintf("CATEGORY (G/E/H/P) :");
gotoxy(15,10);
cprintf("METER STATUS: ");
gotoxy(15,11);
cprintf("(G<FOR GOOD> | B<FOR BAD>)");
gotoxy(36,7);/*NAME VERIFICATION*/
gets(custnm);
int r=0,k,i=0;
while(r==0)
{
r=1;
for(i=0;custnm[i]!='\0';i++)
{
if(isalpha(custnm[i])==0)
{
if(isspace(custnm[i]))
continue;
r=0;
gotoxy(36,7);
cprintf(" ");
gets(custnm);
i=0;
}
}
}
for(k=0;custnm[k]!='\0';k++)
{
if(k==0)
custnm[k]=custnm[k]-32;
if(custnm[k]==' ')
custnm[k+1]=custnm[k+1]-32;
}
gotoxy(39,8);/*ADDRESS VERIFICATION*/
gets(custadd);
r=0;
while(r==0)
{
r=1;
for(i=0;custadd[i]!='\0';i++)
{
if(isalpha(custadd[i]==0))
{
if(isspace(custadd[i]))
continue;
r=0;
gotoxy(39,8);
cprintf(" ");
gotoxy(39,8);
gets(custadd);
i=0;
}
}
}
for(k=0;custadd[k]!='\0';k++)
{
if(k==0)
custadd[k]=custadd[k]-32;
if(custadd[k]==' ')
custadd[k+1]=custadd[k+1]-32;
}
int x=0; /*CATEGORY VERFICATION*/
while(x==0)
{
l:
x=1;
for(i=0;i<1;i++)
{
gotoxy(35,9);
cscanf("%C",&category);
r=0;
if(category=='g'||category=='h'||category=='G'||category=='H')
{
r=1;
break;
}
else
{
if(category=='p'||category=='e'||category=='P'||category=='E')
{
r=1;
break;
}
else
{
x=0;
sound(1000);
delay(100);
nosound();
i=0;
}
}
i+=1;
if(i==1)
break;
}
if(r==1)
break;
goto l;
}
getch();
int xxx=0; /*METER STATUS VERIFICATION*/
int vvv=0;
while(vvv==0)
{
l1:
vvv=1;
gotoxy(28,10);
for(int i=0;i<1;i++)
{
cscanf("%c",&metstat);
if(metstat=='g'||metstat=='G')
{
xxx=1;
break;
}
else
{
if(metstat=='b'|| metstat=='B')
{
xxx=1;
break;
}
else
{
sound(1000);
delay(100);
nosound();
i=0;
}
}
i+=1;
if(i==1)
break;
}
if(xxx==1)
break;
goto l1;
}
}
/*display function*/

void billing::display1()
{
draw_box(13,4,55,10,RED);
gotoxy(27,4);
textcolor(42124);
cprintf(">><<DISPLAY>><<");
gotoxy(18,5);
textcolor(67);
cprintf("METER NO. : %d",metno);
gotoxy(18,6);
cprintf("NAME OF CUSTOMER : %s",custnm);
gotoxy(18,7);
cprintf("ADDRESS OF CUSTOMER: %s",custadd);
gotoxy(18,8);
cprintf("CATEGORY : %c ",category);
gotoxy(18,9);
cprintf("METER STATUS: %c",metstat);
gotoxy(20,14);
textcolor(421124);
cprintf("PRESS ANY KEY TO RETURN TO THE	CONNECTION MENU...");
getch();
}

/*MODIFY FUNCTION*/

void billing::modify1()
{
int rp=0;
while(rp!=5)
{
rp=0;
draw_box(13,5,65,16,59);
gotoxy(30,5);
textcolor(42124);
cprintf("<<>>MODIFICATION>><<");
gotoxy(15,6);
textcolor(90);
cprintf("METER NO.: %ld",metno);
gotoxy(15,7);
cprintf("1.NAME (previous name): %s",custnm);
gotoxy(15,8);
cprintf("2.ADDRESS (previous address): %s",custadd);
gotoxy(15,9);
cprintf("3.CATEGORY (previous category) : %c",category);
gotoxy(15,10);
cprintf("4.METER STATUS (previous status: %c",metstat);
gotoxy(15,11);
cprintf("5.EXIT");
gotoxy(15,20);
textcolor(42124);
cprintf("press 1: TPO MODIFY NAME");
gotoxy(15,21);
cprintf("press 2: TO MODIFY ADDRESS");
gotoxy(15,22);
cprintf("press 3: TO MODIFY CATEGORY");
gotoxy(15,23);
cprintf("press 4: TO MODIFY METER STATUS");
gotoxy(15,24);
cprintf("press 5: TO EXIT");
gotoxy(15,14);
char u[1];
int v=0,hh,i;
while(v==0)
{
bi:
gotoxy(21,13);
textcolor(4);
textbackground(123);
cprintf("ENTER THE CHOICE: ");
v=1;
for(i=0;i<1;i++)
{
u[i]=getche();
if(!isdigit(u[i]))
{
sound(1500);
delay(300);
nosound();
v=0;
break;
}
else
{
char *st=u;
hh=atoi(st);
if(hh<=0||hh>5)
{
v=0;
break;
}
}
if(i==1)
break;
}
if(v==0)
goto bi;
}
u[i+1]='\0';
char *str=u;
rp=atoi(str);
textbackground(0);
switch(rp)
{
case 1:
draw_box(13,5,45,8,67);
gotoxy(15,6);
textcolor(69);
cprintf("OLD NAME: %s",custnm);
gotoxy(15,7);
cprintf("NEW NAME: ");
gets(custnm);
int r=0,k,i=0;
while(r==0)
{
r=1;
for(i=0;custnm[i]!='\0';i++)
{
if(isalpha(custnm[i])==0)
{
if(isspace(custnm[i]))
continue;
r=0;
gotoxy(15,7);
cprintf(" ");
cprintf("ENTER THE CORRECT NAME: ");
gets(custnm);
i=0;
}
}
}
for(k=0;custnm[k]!='\0';k++)
{
if(k==0)
custnm[k]=custnm[k]-32;
if(custnm[k]==' ')
custnm[k+1]=custnm[k+1]-32;
}
break;

case 2:
draw_box(13,5,45,8,67);
gotoxy(15,6);
textcolor(4);
cprintf("OLD ADDRESS : %s ",custadd);
gotoxy(15,7);
cprintf("NEW ADDRESS: ");
gets(custadd);
r=0;
while(r==0)
{
r=1;
for(i=0;custadd[i]!='\0';i++)
{
if(isalpha(custadd[i]==0))
{
if(isspace(custadd[i]))
continue;
r=0;
gotoxy(15,7);
cprintf(" ");
cprintf("ENTER THE CORRECT ADDRESS: ");
gets(custadd);
i=0;
}
}
}
for(k=0;custadd[k]!='\0';k++)
{
if(k==0)
custadd[k]=custadd[k]-32;
if(custadd[k]==' ')
custadd[k+1]=custadd[k+1]-32;
}
break;

case 3:
draw_box(13,5,40,8,67);
gotoxy(15,6);
textcolor(50);
cprintf("OLD CATEGORY: %c",category);
int x=0;
while(x==0)
{
l:
x=1;
for(i=0;i<1;i++)
{
gotoxy(15,7);
cprintf(" ");
gotoxy(15,7);
cprintf("CATEGORY (g/h/e/p): ");
category=getche();
r=0;
if(category=='g'||category=='h'||category=='G'||category=='H')
{
r=1;
break;
}
else
{
if(category=='p'||category=='e'||category=='P'||category=='E')
{
r=1;
break;
}
else
{
x=0;sound(1000);delay(100);nosound();i=0;
}
}
i=i+1;
if(i==1)
break;
}
if(r==1)
break;
goto l;
}
break;

case 4:
draw_box(13,5,40,8,67);
gotoxy(15,6);
textcolor(30);
cprintf("OLD METER STATUS: %c",metstat);
int xxx=0;
int vvv=0;
while(vvv==0)
{
l1:
vvv=1;
gotoxy(15,7);
cprintf(" ");
gotoxy(15,7);
cprintf("METER STATUS (g/b): ");
for(int i=0;i<1;i++)
{
metstat=getche();
if(metstat=='g'||metstat=='G')
{
xxx=1;
break;
}
else
{
if(metstat=='b'||metstat=='B')
{
xxx=2;
break;
}
else
{
sound(1000);delay(100);nosound();i=0;
}
}
i+=1;
if(i==1)
break;
}
if(xxx==1)
break;
goto l1;
}
break;

case 5:
exit;
break;
}
}
}

/*a common function for all the classes */

int billing::rtmetno()
{
return metno;
}

void billing::metstatus()
{
if(metstat=='b')
{
draw_box(13,5,45,10,75);
gotoxy(19,5);
textcolor(4/*+BLINK*/);
cprintf("***BAD METER STATUS***");
gotoxy(23,6);
textcolor(90);
cprintf("METER NO. : %ld",metno);
gotoxy(23,7);
cprintf("CUSTOMER NAME: %s",custnm);
gotoxy(23,8);
cprintf("CUSTOMER ADDRESS: %s",custadd);
}
else
{
draw_box(13,5,41,7,67);
gotoxy(17,5);
textcolor(42124);
cprintf("**GOOD METER STATUS**");
gotoxy(17,6);
textcolor(45);
cprintf("METER STATUS IS GOOD");
}
getch();
}

int billing::rtbillno()
{
return billno;
}

/****function of the reading class******************/

void billing::read()
{
prevread=curread;
}

void billing::accept2()
{
draw_box(13,5,55,15,67);
gotoxy(26,5);
textcolor(450);
cprintf("***ADDITION***");
gotoxy(20,6);
read();
textcolor(67);
cprintf("METER NO. : %d",metno);
gotoxy(20,7);
cprintf("NAME OF THE CUSTOMER: %s",custnm);
gotoxy(20,8);
cprintf("ADDRESS OF CUSTOMER: %s",custadd);
gotoxy(20,9);
cprintf("CATEGORY: %c",category);
gotoxy(20,10);
cprintf("METER STATUS: %c",metstat);
gotoxy(20,11);
struct dosdate_t d;
_dos_getdate(&d);
ryear=d.year;
rmonth=d.month;
rday=d.day;
cprintf("DATE : %d:%d:%d",rday,rmonth,ryear);
gotoxy(20,12);
cprintf("PREVIOUS READING: %ld",prevread);
char x[5];
int v=0;
int i;
while(v==0)
{
b:
v=1;
gotoxy(20,13);
cprintf("ENTER THE CURRENT READNG: ");
for(i=0;i<5;i++)
{
x[i]=getche();
if(!isdigit(x[i]))
{
v=0;
gotoxy(20,13);
cprintf(" ");
gotoxy(20,13);
cprintf("ENTER THE CURRENT READING: ");
break;
}
if(i==4)
break;
}
if(v==0)
goto b;
}
x[i+1]='\0';
char *str=x;    /*atol fun/to convert it into integer*****/
curread=atol(str);
}


void billing::display2()
{
draw_box(13,5,45,15,4);
gotoxy(23,5);
textcolor(42124);
cprintf("***DISPLAY***");
gotoxy(20,6);
textcolor(67);
cprintf("METER NO. : %ld",metno);
gotoxy(20,7);
cprintf("NAME OF THE CUSTOMER: %s",custnm);
gotoxy(20,8);
cprintf("ADDRESS OF THE CUTOMER: %s",custadd);
gotoxy(20,9);
cprintf("CATEGORY: %c",category);
gotoxy(20,10);
cprintf("METER STATUS: %c",metstat);
gotoxy(20,11);
cprintf("DATE : %d:%d:%d",rday,rmonth,ryear);
gotoxy(20,12);
cprintf("PREVIOUS READING: %ld",prevread);
gotoxy(20,13);
cprintf("CURRENT READING: %ld",curread);
gotoxy(20,14);
units=curread-prevread;
cprintf("UNITS CONSUMED: %ld",units);
gotoxy(20,16);
textcolor(42124);
cprintf("PRESS ANY KEY TO RETURN TO READING MENU...");
getch();
}

void billing::modify2()
{
int zz=0;
while(zz!=6)
{
zz=0;
draw_box(13,5,70,16,57);
gotoxy(29,5);
textcolor(42124);
cprintf("***MODIFICATION***");
gotoxy(21,6);
textcolor(YELLOW);
cprintf("METER NO. :%ld",metno);
gotoxy(21,7);
cprintf("1.NAME OF THE CUSTOMER (previous name): %s",custnm);
gotoxy(21,8);
cprintf("2.ADDRESS OF THE CUSTOMER (previous address) : %s",custadd);
gotoxy(21,9);
cprintf("3.CATEGORY (previous category) : %c",category);
gotoxy(21,10);
cprintf("4.METER STATUS (previous status) : %c",metstat);
gotoxy(21,11);
cprintf("5.CURRENT METER READING (previous reading): %ld",curread);
gotoxy(21,12);
cprintf("6.EXIT MODIFICATION.");
gotoxy(21,20);
textcolor(42124);
cprintf("PRESS 1 : TO MODIFY NAME.");
gotoxy(21,21);
cprintf("PRESS 2: TO MODIFY ADDRESS.");
gotoxy(21,22);
cprintf("PRESS 3: TO MODIFY CATEGORY.");
gotoxy(21,23);
cprintf("PRESS 4: TO MODIFY METER STATUS.");
gotoxy(21,24);
cprintf("PRESS 5: TO MODIFY CURRENT READING.");
gotoxy(21,25);
cprintf("PRESS 6: TO EXIT MODIFICATION.");
char u[1];
int v=0,hh,i;
while(v==0)
{
bi1:
gotoxy(21,13);
textcolor(4);
textbackground(123);
cprintf("\nENTER THE CHOICE: ");
v=1;
for(i=0;i<1;i++)
{
u[i]=getche();
if(!isdigit(u[i]))
{
sound(1500);
delay(300);
nosound();
v=0;
break;
}
else
{
char *st=u;
hh=atoi(st);
if(hh<=0||hh>6)
{
v=0;
break;
}
if(i==1)
break;
}
if(v==0)
goto bi1;
}
u[i+1]='\0';
char *str=u;
zz=atoi(str);
textbackground(0);
switch(zz)
{
case 1:
draw_box(13,5,45,8,42);
gotoxy(15,6);
cprintf("OLD NAME: %s",custnm);
gotoxy(15,7);
cprintf("NEW NAME: ");
gets(custnm);
int r=0,k,i=0;
while(r==0)
{
r=1;
for(i=0;custnm[i]!='\0';i++)
{
if(isalpha(custnm[i])==0)
{
if(isspace(custnm[i]))
continue;
r=0;
gotoxy(15,7);
cprintf(" ");
gotoxy(15,7);
cprintf("NEW NAME: ");
gets(custnm);
i=0;
}
}
}
for(k=0;custnm[k]!='\0';k++)
{
if(k==0)
custnm[k]=custnm[k]-32;
}
break;

case 2:
draw_box(13,5,45,8,42);
gotoxy(15,6);
cprintf("OLD ADDRESS: %s",custadd);
gotoxy(15,7);
cprintf(" ");
gotoxy(15,7);
cprintf("NEW ADDRESS: ");
gets(custadd);
r=0;
while(r==0)
{
r=1;
for(i=0;custadd[i]!='\0';i++)
{
if(isalpha(custadd[i])==0)
{
if(isspace(custadd[i]))
continue;
r=0;
gotoxy(15,7);
cprintf(" ");
gotoxy(15,7);
cprintf("new address: ");
gets(custadd);
i=0;
}
}
}
for(k=0;custadd[k]!='\0';k++)
{
if(k==0)
custadd[k]=custadd[k]-32;
if(custadd[k]==' ')
custadd[k+1]=custadd[k+1]-32;
}
break;

case 3:
draw_box(13,5,45,8,42);
gotoxy(15,6);
cprintf("OLD CATEGORY: %c",category);
int x=0;
while(x==0)
{
l:
x=1;
for(i=0;i<1;i++)
{
gotoxy(15,7);
cprintf(" ");
gotoxy(15,7);
cprintf("NEW CATEGORY: ");
category=getche();
r=0;
if(category=='g'|| category=='h'||category=='G'||category=='H')
{
r=1;
break;
}
else
{
if(category=='p'||category=='e'||category=='P'||category=='E')
{
r=1;
break;
}
else
{
x=0;
sound(1000);
delay(100);
nosound();
i=0;
}
}
i+=1;
if(i==1)
break;
}
if(r==1)
break;
goto l;
}
break;

case 4:
draw_box(13,5,45,8,42);
gotoxy(15,6);
cprintf("OLD METER STATUS: %c",metstat);
int xxx=0;
int vvv=0;
while(vvv==0)
{
l1:
vvv=1;
gotoxy(15,7);
cprintf(" " );
gotoxy(15,7);
cprintf("NEW METER STATUS: ");
for(int i=0;i<1;i++)
{
metstat=getche();
if(metstat=='g'||metstat=='G')
{
xxx=1;
break;
}
else
{
if(metstat=='b'||metstat=='B')
{
xxx=1;
break;
}
else
{
sound(1000);
delay(100);
nosound();
i=0;
}
}
i+=1;
if(i==1)
break;
}
if(xxx==1)
break;
goto l1;
}
break;

case 5:
draw_box(13,5,45,8,42);
gotoxy(15,6);
cprintf("OLD CURRENT METER READING: %ld",curread);
char u[5];
int v=0;
int ii;
while(v==0)
{
b:
v=1;
gotoxy(15,7);
cprintf("NEW CURRENT METER READING: ");
for(i=0;i<5;i++)
{
u[i]=getche();
if(!isdigit(u[i]))
{
v=0;
gotoxy(15,7);
cprintf(" ");
gotoxy(15,7);
cprintf("NEW CURRENT METER READING: ");
break;
}
if(i==4)
break;
}
if(v==0)
goto b;
}
u[i+1]='\0';
char *str=u;   /***atol fun/to convert it into integer***/
curread=atol(str);
break;

case 6:
exit;
break;

default:
cout<<"\nINVALID INPUT.";
}
}
}
}

void billing::display4()
{
draw_box(13,5,45,10,67);
gotoxy(20,5);
textcolor(YELLOW/*+BLINK*/);
cprintf("***DISCONNECTED***");
gotoxy(20,6);
textcolor(57);
cprintf("METER NO : %ld",metno);
gotoxy(20,7);
cprintf("CUSTNAME: %s",custnm);
gotoxy(20,8);
cprintf("CUSTOMER ADDRESS: %s",custadd);
getch();
}

/*********************    MAIN()    ***************************/



void main(int)
{
void acknowledgement();
fflush(stdin);
int counter=1,c,d;
clrscr();
void end();
int passw();
void menu();
billing b,f,fc,b1;
void printmonth(int);
char che,ch;
long int mmno,bbno;
int ans=0,x,i,sto=0;
int c1,c2;
fstream file1,file2,file3,file4;
int key=passw();
if(key!=1)
{
while(counter!=3)
{
cout<<"\n\n\n\n\n\n\n\t\t INCORRECT PASSWORD TRY AGAIN. chance"<<counter;
counter++;
getch();
key=passw();
break;
}
if(counter==3)
{
clrscr();
cout<<"\n\n\n\n\n\t SORRY:TOO MANY UNSUCCESSFUL ATTEMPTS";
getch();
end();
}
counter++;
if(key!=1)
end();
}
clrscr();
menu();
while(ans!=6)
{
ans=0;x=0;
draw_box(20,5,60,15,YELLOW);
gotoxy(23,3);
textcolor(49594);
cprintf("<=<=<=WATER BILLING SYSTEM=>=>=>");
gotoxy(28,5);
textcolor(42124);
cprintf("=>=>=> MAIN MENU =>=>=>");
textcolor(GREEN);
gotoxy(28,6);
cprintf("0 - ABOUT THE PROJECT.");
gotoxy(28,7);
cprintf("1 - CONNECTION REGISTER.");
gotoxy(28,8);
cprintf("2 - READING REGISTER.");
gotoxy(28,9);
cprintf("3 - BILLING REGISTER.");
gotoxy(28,10);
cprintf("4 - COLLECTION REGISTER.");
gotoxy(28,11);
cprintf("5 -REPORT REGISTER.");
gotoxy(28,12);
cprintf("6 - EXIT.");
gotoxy(28,18);
textcolor(67);
cprintf("PRESS 1: FOR CONNECTION REGISTER");
gotoxy(28,19);
cprintf("PRESS 2: FOR READING REGISTER");
gotoxy(28,20);
cprintf("PRESS 3: FOR BILLING REGISTER");
gotoxy(28,21);
cprintf("PRESS 4: FOR COLLECTION REGISTER");
gotoxy(28,22);
cprintf("PRESS 5: FOR REPORT REGISTER");
gotoxy(28,23);
cprintf("PRESS 6: TO EXIT");
char u[1];
int v=0,hh,i;
while(v==0)
{
b:
gotoxy(30,13);
textcolor(4);
textbackground(123);
cprintf("\nENTER THE CHOICE: ");
v=1;
for(i=0;i<1;i++)
{
u[i]=getche();
if(!isdigit(u[i]))
{
sound(1500);delay(100);nosound();v=0;
break;
}
else
{
char *st=u;
hh=atoi(st);
if(hh<0||hh>6)
{
v=0;
break;
}
}
if(i==1)
break;
}
if(v==0)
goto b;
}
u[i+1]='\0';
char *str=u;
ans=atoi(str);
textbackground(0);
switch(ans)
{
case 0:
acknowledgement();
break;
/**connection register**/
case 1:
while(x!=5)
{
x=0;
draw_box(13,5,45,15,345);
gotoxy(20,5);
textcolor(42124);
cprintf("****CONNECTION****");
gotoxy(21,7);
textcolor(38);
cprintf("1-ADD RECORDS");
gotoxy(21,8);
cprintf("2-MODIFY RECORD");
gotoxy(21,9);
cprintf("3-DELETE RECORD");
gotoxy(21,10);
cprintf("4-DISPLAY RECORD");
gotoxy(21,11);
cprintf("5-EXIT");
gotoxy(21,18);
textcolor(57);
cprintf("PRESS 1: TO ADD RECORD DETAILS.");
gotoxy(21,19);
cprintf("PRESS 2: TO MODIFY RECORD.");
gotoxy(21,20);
cprintf("PRESS 3: TO DELETE RECORD.");
gotoxy(21,21);
cprintf("PRESS 4: TO DISPLAY RECORDS.");
gotoxy(21,22);
cprintf("PRESS 5: TO EXIT.");
char u[1];
int v=0,hh;
while(v==0)
{
b1:
gotoxy(21,13);
textcolor(4);
textbackground(123);
cprintf("ENTER THE CHOICE: ");
v=1;
for(i=0;i<1;i++)
{
u[i]=getche();
if(!isdigit(u[i]))
{
sound(1500);delay(300);nosound();v=0;
break;
}
else
{
char *st=u;
hh=atoi(st);
if(hh<=0||hh>5)
{
v=0;
break;
}
}
if(i==1)
break;
}
if(v==0)
goto b1;
}
u[i+1]='\0';
char *str=u;
x=atoi(str);
textbackground(0);
sto=0;
switch(x)
{
case 1:
ch='y';
while(ch=='y')
{
file1.open("origfile.txt",ios::in);
file1.read((char*)&b,sizeof(b));
while(file1)
{
b.meterno();
file1.read((char*)&b,sizeof(b));
}
file1.close();
file1.open("origfile.text",ios::in|ios::out|ios::ate|ios::app);
b.accept1();
cin.get(che);
file1.write((char *)&b,sizeof(b));
gotoxy(20,21);
cprintf("TO INPUT ANOTHER RECORD (PRESS - Y) ");
gotoxy(20,22);
cprintf("TO TERMINATE (PRESS - N)");
cscanf("%c",&ch);
file1.close();
}
file1.close();
break;
case 2:
file1.open("origfile.txt",ios::in);
file2.open("tempfile.txt",ios::out);
gotoxy(20,16);
cprintf("ENTER THE METER NO. TO BE MODIFIED: ");
char x[4];
int v=0;int i;
while(v==0)
{
bc:
v=1;
for(i=0;i<4;i++)
{
x[i]=getche();
if(!isdigit(x[i]))
{
v=0;
gotoxy(54,23);
cprintf(" ");
gotoxy(54,23);
break;
}
if(i==3)
break;
}
if(v==0)
goto bc;
}
x[i+1]='\0';
char *str=x;
mmno=atol(str);
file1.read((char*)&b,sizeof(b));
while(file1)
{
if(mmno!=b.rtmetno())
file2.write((char*)&b,sizeof(b));
else
{
sto=1;
b.modify();
file2.write((char*)&b,sizeof(b));
}
file1.read((char*)&b,sizeof(b));
}
file1.close();
file2.close();
if(sto==0)
{
gotoxy(21,24);
textcolor(42124);
cprintf("RECORD NOT FOUND.");
getch();
}
file2.open("tempfile.txt",ios::in);
file1.open("origfile.txt",ios::out);
file2.read((char*)&b,sizeof(b));
while(file2)
{
file1.write((char*)&b,sizeof(b));
file2.read((char*)&b,sizeof(b));
}
file2.close();
file1.close();
break;
case 3:
gotoxy(21,16);
textcolor(4);
cprintf("ENTER THE METER NO. TO BE DELETED: ");
v=0;
while(v==0)
{
bd1:
v=1;
for(i=0;i<4;i++)
{
x[i]=getche();
if(!isdigit(x[i]))
{
v=0;
gotoxy(54,20);
cprintf(" ");
gotoxy(54,20);
break;
}
if(i==3)
break;
}
if(v==0)
goto bd1;
}
x[i+1]='\0';
char*str=x;
mmno=atol(str);
file3.open("delfile.txt",ios::in|ios::out|ios::ate|ios::app);
file1.open("origfile.txt",ios::in);
file2.open("tempfile.txt",ios::out);
file1.read((char*)&b,sizeof(b));
while(file1)
{
if(mmno==b.rtmetno())
{
sto=1;
file3.write((char*)&b,sizeof(b));
}
if(mmno!=b.rtmetno())
file2.write((char*)&b,sizeof(b));
file1.read((char*)&b,sizeof(b));
}
file1.close();
file2.close();
file3.close();
file2.open("tempfile.txt",ios::in);
file1.open("origfile.txt",ios::out);
file2.read((char*)&b,sizeof(b));
while(file2)
{
file1.write((char*)&b,sizeof(b));
file2.read((char*)&b,sizeof(b));
}
file1.close();
file2.close();
file1.open("billfile.txt",ios::in);
file2.open("tempfile.txt",ios::out);
file1.read((char*)&b,sizeof(b));
while(file1)
{
if(mmno!=b.rtmetno())
file2.write((char*)&b,sizeof(b));
file1.read((char*)&b,sizeof(b));
}
file1.close();
file2.close();
file2.open("tempfile.txt",ios::in);
file1.open("billfile.txt",ios::out);
file2.read((char*)&b,sizeof(b));
while(file2)
{
file1.write((char*)&b,sizeof(b));
file2.read((char*)&b,sizeof(b));
}
file1.close();
file2.close();
if(sto==0)
{
gotoxy(21,24);
textcolor(42124);
cprintf("RECORD NOT FOUND");
getch();
}
break;

case 4:
gotoxy(21,16);
cprintf("ENTER THE METER NO. TO VIEW THE RECORD");
v=0;
while(v==0)
{
bds:
v=1;
for(i=0;i<4;i++)
{
x[i]=getche();
if(!isdigit(x[i]))
{
v=0;
gotoxy(59,18);
cprintf(" ");
gotoxy(59,18);
break;
}
if(i==3)
break;
}
if(v==0)
goto bds;
}
x[i=1]='\0';
char*str=x;
mmno=atol(str);
file1.open("origfile.txt",ios::in);
while(file1.read((char*)&b,sizeof(b)))
{
if(mmno==b.rtmetno())
{
sto=1;
clrscr();
b.display1();
getch();
cout.put(che);
}
}
file1.close();
if(sto==0)
{
gotoxy(21,24);
textcolor(42124);
cprintf("RECORD NOT FOUND");
getch();
}
break;
case 5:
exit;
break;
}
}
break;

/************ reading register******/
case 2:
while(x!=5)
{
x=0;
draw_box(13,5,45,15,10);
gotoxy(22,5);
textcolor(42124);
cprintf("***READING***");
gotoxy(21,7);
textcolor(CYAN);
cprintf("1-ADD METER DETAILS: ");
gotoxy(21,8);
cprintf("2-MODIFY METER DETAILS: ");
gotoxy(21,9);
cprintf("3-DELETE: ");
gotoxy(21,10);
cprintf("4-DISPLAY: ");
gotoxy(21,11);
cprintf("5-EXT: ");
gotoxy(21,18);
textcolor(54);
cprintf("PRESS 1- FOR ADDING READING DETAILS.");
gotoxy(21,19);
cprintf("PRESS 2- FOR MODIFICATION.");
gotoxy(21,20);
cprintf("PRESS 3- FOR DELETION.");
gotoxy(21,21);
cprintf("PRESS 4- FOR DISPLAY.");
gotoxy(21,22);
cprintf("PRESS 5- FOR EXIT.");
char u[1];
int v=0,hh;
while(v==0)
{
b2:
gotoxy(21,13);
textcolor(4);
textbackground(123);
cprintf("ENTER THE CHOICE: ");
v=1;
for(i=0;i<1;i++)
{
u[i]=getche();
if(!isdigit(u[i]))
{
sound(1500);
delay(300);
nosound();
v=0;
break;
}
else
{
char*st=u;
hh=atoi(st);
if(hh<=0||hh>5)
{
v=0;
break;
}
}
if(i==1)
break;
}
if(v==0)
goto b2;
}
u[i+1]='\0';
char *str=u;
x=atoi(str);
textbackground(0);
sto=0;
switch(x)
{
case 1:
gotoxy(21,16);
cprintf("ENTER THE METER NO. : ");
char x[4];
int v=0;int i;
while(v==0)
{
brg:
v=1;
for(i=0;i<4;i++)
{
x[i]=getche();
if(!isdigit(x[i]))
{
v=0;
gotoxy(35,23);
cprintf(" ");
gotoxy(35,23);
break;
}
if(i==3)
break;
}
if(v==0)
goto brg;
}
x[i+1]='\0';
char*str=x;
mmno=atol(str);    /******atol fun/to convert it into integer***/
file2.open("tempfile.txt",ios::out);
file1.open("origfile.txt",ios::in);
while(file1.read((char*)&b,sizeof(b))
{
if(mmno==b.rtmetno())
{
sto=1;
b.read();
file2.write((char*)&b,sizeof(b));
}
else
{
file2.write((char*)&b,sizeof(b));
}
}
file1.close();
file2.close();
file2.open("tempfile.txt",ios::in);
file1.open("origfile.txt",ios::out);
while(file2.read((char*)&b,sizeof(b))
{
file1.write((char*)&b,sizeof(b));
}
file2.close();
file1.close();
file1.open("origfile.txt",ios::in);
file2.open("tempfile.txt",ios::out);
while(file1.read((char*)&b,sizeof(b))
{
if(mmno!=b.rtmetno())
file2.write((char*)&b,sizeof(b));
else
{
b.accept2();
file2.write((char*)&b,sizeof(b));
}
}
file1.close();
file2.close();
file2.open("tempfile.txt",ios::in);
file1.open("origfile.txt",ios::out);
while(file2.read((char*)&b,sizeof(b)))
{
file1.write((char*)&b,sizeof(b));
}
file2.close();
file1.close();
if(sto==0)
{
gotoxy(21,24);
textcolor(42124);
cprintf("RECORD NOT FOUND.");
getch();
}
break;
case 2:
file1.open("origfile.txt",ios::in);
file2.open("tempfile.txt",ios::out);
gotoxy(21,16);
cprintf("ENTER THE RECORD NO. TO BE MODIFIED: ");
v=0;
while(v==0)
{
brm:
v=1;
for(i=0;i<4;i++)
{
x[i]=getche();
if(!isdigit(x[i]))
{
v=0;
gotoxy(58,20);
cprintf(" ");
gotoxy(58,20);
break;
}
if(i==3)
break;
}
if(v==0)
goto brm;
}
x[i+1]='\0';
char*str=x;  /****atol fun/to conver it into integer***/
mmno=atol(str);
file1.read((char*)&b,sizeof(b));
while(file1)
{
if(mmno!=b.rtmetno())
file2.write((char*)&b,sizeof(b));
else
{
sto=1;
b.modify2();
file2.write((char*)&b,sizeof(b));
}
file1.read((char*)&b,sizeof(b));
}
file1.close();
file2.close();
file2.open("tempfile.txt",ios::in);
file1.open("origfile.txt",ios::out);
file2.read((char*)&b,sizeof(b));
while(file2)
{
file1.write((char*)&b,sizeof(b));
file2.read((char*)&b,sizeof(b));
}
file2.close();
file1.close();
if(sto==0)
{
gotoxy(21,24);
textcolor(42124);
cprintf("RECORD NOT FOUND.");
getch();
}
break;
case 3:
gotoxy(21,16);
cprintf("ENTER THE METER NO. TO BE DELETED: ");
v=0;
while(v==0)
{
brd:
v=1;
for(i=0;i<4;i++)
{
x[i]=getche();
if(!isdigit(x[i]))
{
v=0;
gotoxy(54,23);
cprintf(" ");
gotoxy(54,23);
break;
}
if(i==3)
break;
}
if(v==0)
goto brd;
}
x[i+1]='\0';
char*str=x;
mmno=atol(str);  /*****atol fun/to conver it into integer*****/
file3.open("delfile.txt",ios::in|ios::out|ios::ate|ios::app);
file1.open("origfile.txt",ios::in);
file2.open("tempfile.txt",ios::out);
file1.read((char*)&b,sizeof(b));
while(file1)
{
if(mmno==b.rtmetno())
{
sto=1;
file3.write((char*)&b,sizeof(b));
}
if(mmno!=b.rtmetno())
file2.write((char*)&b,sizeof(b));
file1.read((char*)&b,sizeof(b));
}
file1.close();
file2.close();
file3.close();
file2.open("tempfile.txt",ios::in);
file1.open("origfile.txt",ios::out);
file2.read((char*)&b,sizeof(b));
while(file2)
{
file1.write((char*)&b,sizeof(b));
file2.read((char*)&b,sizeof(b));
}
file1.close();
file2.close();
file1.open("billfile.txt",ios::in);
file2.open("tempfile.txt",ios::out);
file1.read((char*)&b,sizeof(b));
while(file1)
{
if(mmno!=b.rtmetno())
file2.write((char*)&b,sizeof(b));
file1.read((char*)&b,sizeof(b));
}
file1.close();
file2.close();
file2.open("tempfile.txt",ios::in);
file1.open("billfile.txt",ios::out);
file2.read((char*)&b,sizeof(b));
while(file2)
{
file1.write((char*)&b,sizeof(b));
file2.read((char*)&b,sizeof(b));
}
file1.close();
file2.close();
if(sto==0)
{
gotoxy(21,24);
textcolor(42124);
cprintf("RECORD NOT FOUND.");
getch();
}
break;
case 4:
gotoxy(21,16);
cprintf("ENTER THE METER NO. TO VIEW THE RECORD: ");
char x[4];
int v=0;
while(v==0)
{
brd1:
v=1;
for(i=0;i<4;i++)
{
x[i]=getche();
if(!isdigit(x[i]))
{
v=0;
gotoxy(35,23);
cprintf(" ");
gotoxy(35,23);
break;
}
if(i==3)
break;
}
if(v==0)
goto brd1;
}
x[i+1]='\0';
char*str=x;
mmno=atol(str);  /****atol fun/to convert it into integer****/
file1.open("origfile.txt",ios::in);
file1.read((char*)&b,sizeof(b));
while(file1)
{
if(mmno==b.rtmetno())
{
sto=1;
b.display2();
getch();
cout.put(che);
}
file1.read((char*)&b,sizeof(b));
}
file1.close();
if(sto==0)
{
gotoxy(21,24);
textcolor(42124);
cprintf("RECORD NOT FOUND. ");
getch();
}
break;
case 5:
exit;
break;
}
}
break;

/*************billing register**********/
case 3:
while(x!=4)
{
draw_box(13,5,45,12,67);
gotoxy(21,5);
textcolor(42124);
cprintf("***BILLING***");
gotoxy(20,6);
textcolor(15);
cprintf("1- ADD BILLING DETAILS.");
gotoxy(20,7);
cprintf("2- DELETE: ");
gotoxy(20,8);
cprintf("3- DISPLAY: ");
gotoxy(20,9);
cprintf("4- EXIT: ");
gotoxy(20,15);
textcolor(26);
cprintf("PRESS 1: FOR ADDING BILLING DETAILS.");
gotoxy(20,16);
cprintf("PRESS 2: FOR DELETION.");
gotoxy(20,17);
cprintf("PRESS 3: FOR DISPLAY.");
gotoxy(20,18);
cprintf("PRESS 4: TO EXIT.");
char u[1];
int v=0,hh;
while(v==0)
{
b3:
gotoxy(21,10);
textcolor(4);
textbackgorund(123);
cprintf("\nENTER THE CHOICE: ");
v=1;
for(i=0;i<1;i++)
{
u[i]=getche();
if(!isdigit(u[i]))
{
sound(1500);
delay(300);
nosound();
v=0;
break;
}
else
{
char *st=u;
hh=atoi(st);
if(hh<=0||hh>4)
{
v=0;
break;
}
}
if(i==1)
break;
}
if(v==0)
goto b3;
}
u[i+1]='\0';
char *str=u;
x=atoi(str);
textbackground(0);
sto=0;
switch(x)
{
case 1:
gotoxy(20,13);
cprintf("ENTER THE METER NO. :");
char x[4];
int v=0;int i;
while(v==0)
{
bba:
v=1;
for(i=0;i<4;i++)
{
x[i]=getche();
if(!isdigit(x[i]))
{
v=0;
gotoxy(35,23);
cprintf(" ");
gotoxy(35,23);
break;
}
if(i==3)
break;
}
if(v==0)
goto bba;
}
x[i+1]='\0';
char *str=x;
/*****atol fun/to convert it into integer*****/
mmno=atol(str);
file4.open("billfile.txt",ios::in);
while(file4.read((char*)&b,sizeof(b)))
{
b.billno();
}
file4.close();
file4.open("billfile.txt",ios::in|ios::out|ios::ate|ios::app);
file1.open("origfile.txt",ios::in);
while(file1.read((char*)&b,sizeof(b)))
{
if(mmno==b.rtmetno())
{
sto=1;
b.calculate();
file4.write((char*)&b,sizeof(b));
getch();
}
}
file4.close();
file1.close();
if(sto==0)
{
gotoxy(21,24);
textcolor(42124);
cprintf("RECORD NOT FOUND.");
getch();
}
break;
case 2:
gotoxy(20,13);
cprintf("ENTER THE BILL NO. TO BE DELETED: ");
char x[4];
int v=0;
while(v==0)
{
bbd:
v=1;
for(i=0;i<4;i++)
{
x[i]=getche();
if(!isdigit(x[i]))
{
v=0;
gotoxy(35,23);
cprintf(" ");
gotoxy(35,23);
break;
}
if(i==3)
break;
}
if(v==0)
goto bbd;
}
x[i+1]='\0';
char*str=x;
/*****atol fun/to convert it into integer*******/
mmno=atol(str);
fstream file2;
file3.open("delfile.txt",ios::in|ios::out|ios::ate|ios::app);
file1.open("origfile.txt",ios::in);
file2.open("tempfile.txt",ios::out);
while(file1.read((char*)&b,sizeof(b)))
{
if(mmno==b.rtmetno())
{
sto=1;
file3.write((char*)&b,sizeof(b));
}
if(mmno!=b.rtmetno())
file2.write((char*)&b,sizeof(b));
}
file1.close();
file2.close();
file3.close();
file2.open("tempfile.txt",ios::in);
file1.open("origfile.txt",ios::out);
while(file2.read((char*)&b,sizeof(b)))
{
file1.write((char*)&b,sizeof(b));
}
file1.close();
file2.close();
file1.open("billfile.txt",ios::in);
file2.open("tempfile.txt",ios::out);
while(file1.read((char*)&b,sizeof(b)))
{
if(mmno!=b.rtmetno())
file2.write((char*)&b,sizeof(b));
}
file1.close();
file2.close();
file2.open("tempfile.txt",ios::in);
file1.open("billfile.txt",ios::out);
while(file2.read((char*)&b,sizeof(b)))
{
file1.write((char*)&b,sizeof(b));
}
file1.close();
file2.close();
if(sto==0)
{
gotoxy(21,24);
textcolor(42124);
cprintf("RECORD NOT FOUND.");
getch();
}
break;
case 3:
sto=0;
gotoxy(20,13);
cprintf("ENTER THE BILL NO. TO VIEW THE RECORD: ");
char x[4];
int v=0;
while(v==0)
{
bv:
v=1;
for(i=0;i<4;i++)
{
x[i]=getche();
if(!isdigit(x[i]))
{
v=0;
gotoxy(35,23);
cprintf(" ");
gotoxy(35,23);
break;
}
if(i==3)
break;
}
if(v==0)
goto bv;
}
x[i+1]='\0';
char*str=x;
/*****atol fun/to convert it into integer*********/
bbno=atol(str);
file1.open("billfile.txt",ios::in);
while(file1.read((char*)&b,sizeof(b)))
 {
 if(bbno==b.rtbillno())
 {
 sto=1;
 b.display3();
 getch();
 cout.put(che);
 }
 }
 file1.close();
 if(sto==0)
 {
 gotoxy(21,24);
 textcolor(42124);
 cprintf("RECORD NOT FOUND." );
 getch();
 }
 getch();
 break;
 case 4:
 exit;
 break;
 }
 }
 break;
 /************collection handling***********/
 case 4:
 sto=0;
 gotoxy(30,17);
 cprintf("ENTER THE BILL NO. :");
 cscanf("%ld",&bbno);
 int res=0,re=0;
 file2.open("collfile.txt",ios::in);
 file2.read((char*)&b,sizeof(b));
 while(file2)
 {
 if(bbno==b.rtbillno())
 {
 sto=1;
 res=b.collected();
 getch();
 cout.put(che);
 }
 file2.read((char*)&b,sizeof(b));
 }
 if(sto==0)
 {
 gotoxy(21,24);
 textcolor(42124);
 cprintf("RECORD NOT FOUND.");
 getch();
 }
 file2.close();
 file2.open("collfile.txt",ios::out|ios::app);
 file1.open("billfile.txt",ios::in);
 while(file1.read((char*)&b,sizeof(b)))
 {
 if(res==1)
 break;
 if(bbno==b.rtbillno())
 {
 sto=1;
 re=b.collecton();
 getch();
 cout.put(che);
 if(re==1)
 file2.write((char*)&b,sizeof(b));
 }
 }
 file1.close();
 file2.close();
 if(sto==0)
 {
 gotoxy(21,24);
 textcolor(42124);
 cprintf("RECORD NOT FOUND.");
 getch();
 }
 break;

 /**********report generation********/
 case 5:
 while(x!=6)
 {
 x=0;
 draw_box(13,5,50,15,34);
 gotoxy(25,5);
 textcolor(42124);
 cprintf("***REPORT***");
 gotoxy(21,6);
 textcolor(45);
 cprintf("1- BILL REPORT");
 gotoxy(21,7);
 cprintf("2- DEFAULTERS LIST");
 gotoxy(21,8);
 cprintf("3- METER STATUS REMARKS");
 gotoxy(21,9);
 cprintf("4- COLLECTION UPDATE");
 gotoxy(21,10);
 cprintf("5- LIST OF DISCONNECTION");
 gotoxy(21,11);
 cprintf("6- EXIT");
 gotoxy(21,18);
 textcolor(42);
 cprintf("PRESS 1- FOR BILL REPORT.");
 gotoxy(21,19);
 cprintf("PRESS 2- FOR DEFAULTERS LIST.");
 gotoxy(21,20);
 cprintf("PRESS 3- FOR METER STATUS REMARKS.");
 gotoxy(21,21);
 cprintf("PRESS 4- FOR COLLECTION UPDATE.");
 gotoxy(21,22);
 cprintf("PRESS 5- FOR LIST OF DISSCONECTIONS.");
 gotoxy(21,23);
 cprintf("PRESS 6- TO EXIT.");
 char u[1];
 int v=0,hh;
 while(v==0)
 {
 b4:
 gotoxy(22,13);
 textcolor(4);
 textbackground(123);
 cprintf("ENTER THE CHOICE: ");
 v=1;
 for(i=0;i<1;i++)
 {
 u[i]=getche();
 if(!isdigit(u[i]))
 {
 sound(1500);delay(300);nosound();v=0;
 break;
 }
 else
 {
 char *st=u;
 hh=atoi(st);
 if(hh<=0||h>6)
 {
 v=0;
 break;
 }
 }
 if(i==1)
 break;
 }
 if(v==0)
 goto b4;
 }
 u[i+1]='\0';
 char*str=u;
 x=atoi(str);
 textbackground(0);
 sto=0;
 switch(x)
 {
 case 1:
 gotoxy(21,17);
 textcolor(45);
 cprintf("ENTER THE METER NO. : ");
 char x[4];
 int v=0;
 int i;
 while(v==0)
 {
 dbr:
 v=1;
 for(i=0;i<4;i++)
 {
 x[i]=getche();
 if(!isdigit(x[i]))
 {
 v=0;
 gotoxy(35,23);
 cprintf(" ");
 gotoxy(35,23);
 break;
 }
 if(i==3)
 break;
 }
 if(v==0)
 goto dbr;
 }
 x[i+1]='\0';
 char*str=x;
 /****atol fun/to convert it into integer*****/
 mmno=atol(str);
 file1.open("billfile.txt",ios::in);
 while(file1.read((char*)&b,sizeof(b)))
 {
 if(mmno==b.rtmetno())
 {
 sto=1;
 clrscr();
 b.display3();
 getch();
 cout.put(che);
 }
 }
 file1.close();
 if(sto==0)
 {
 gotoxy(21,24);
 textcolor(42124);
 cprintf("RECORD NOT FOUND.");
 getch();
 }
 break;

 case 2:
 int rrr=0,stri=0;
 file1.open("billfile.txt",ios::in);
 while(file1.read((char*)&b,sizeof(b)))
 {
 rrr=b.rtbillno();
 file2.open("collfile.txt",ios::in);
 while(file2.read((char*)&f,sizeof(f)))
 {
 stri=0;
 if(rrr=f.rtbillno())
 {
 stri=1;
 break;
 }
 }
 file2.close();
 if(stri!=1)
 {
 b.display5();
 getch();
 }
 }
 file1.close();
 break;
 case 3:
 gotoxy(21,17);
 textcolor(GREEN);
 cprintf("ENTER THE METER NO.: ");
char x[4];
int v=0;
 while(v==0)
 {
 dmr:
 v=1;
 for(i=0;i<4;i++)
 {
 x[i]=getche();
 if(!isdigit(x[i]))
 {
 v=0;
 gotoxy(35,23);
 cprintf(" ");
 gotoxy(35,23);
 break;
 }
 if(i==3)
 break;
 }
 if(v==0)
 goto dmr;
 }
 x[i+1]='\0';
char*str=x;
 /*****atol fun/to convert it into integer******/
 mmno=atol(str);
 file1.open("origfile.txt",ios::in);
 while(file1.read((char*)&b.sizeof(b)))
 {
 if(mmno==b.rtmetno())
 {
 sto=1;
 b.metstatus();
 getch();
 cout.put(che);
 }
 }
 file1.close();
 if(sto==0)
 {
 gotoxy(21,24);
 textcolor(42124);
 cprintf("RECORD NOT FOUND.");
 getch();
 }
 break;
 case 4:
 float amount=0.0,amount1=0.0;
 int mont;
 clrscr();
 gotoxy(20,17);
 textcolor(10);
 cprintf("ENTER THE NO. OF MONTH TO VIEW ITS DETAILS: ");
 cscanf("%d",&mont);
 file1.open("collfile.txt",ios::in);
 while(file1.read((char*)&b,sizeof(b)))
 {
 if(mont==b.rtmont())
 {
 amount=b.update();
 getch();
 amount1=amount1+amount;
 }
 }
 file1.close();
 printmonth(mont);
 gotoxy(19,14);
 cprintf("TOTAL AMOUNT COLLECTED: %f",amount1);
 getch();
 break;

 case 5:
 file3.open("delfile.txt",ios::in);
 while(file3.read((char*)&b,sizeof(b)))
 {
 b.display4();
 getch();
 }
 file3.close();
 break;
 case 6:
 exit;
 break;
 }
 }
 break;

 case 6:
 end();
 break;
 }
 }
 }
void printmonth(int m)
{
if(m==1)
{
gotoxy(19,13);
cprintf("FOR THE MONTH OF: JANUARY ");
}
else if(m==2)
{
gotoxy(19,13);
cprintf("FOR THE MONTH OF: FEBRUARY");
}
else if(m==3)
{
gotoxy(19,13);
cprintf("FOR THE MONTH OF: MARCH");
}
else if(m==4)
{
gotoxy(19,13);
cprintf("FOR THE MONTH OF: APRIL");
}
else if(m==5)
{
gotoxy(19,13);
cprintf("FOR THE MONTH OF: MAY");
}
else if(m==6)
{
gotoxy(19,14);
cprintf("FOR THE MONTH OF: JUNE");
}
else if(m==7)
{
gotoxy(19,15);
cprintf("FOR THE MONTH OF: JULY");
}
else if(m==8)
{
gotoxy(19,13);
cprintf("FOR THE MONTH OF: AUGUST");
}
else if(m==9)
{
gotoxy(19,13);
cprintf("FOR THE MONTH OF: SEPTEMBER");
}
else if(m==10)
{
gotoxy(19,13);
cprintf("FOR THE MONTH OF: OCTOBER");
}
else if(m==11)
{
gotoxy(19,13);
cprintf("FOR THE MONTH OF: NOVEMBER");
}
else if(m==12)
{
gotoxy(19,13);
cprintf("FOR THE MONTH OF: DECEMBER");
}
}

void menu()
{
int k;
clrscr();
draw_box(18,9,50,11,5);
gotoxy(18,8);
textcolor(CYAN);delay(15);textcolor(BLINK+YELLOW);
cprintf("THE COUNTDOWN BEGINS.....");
for(int x=1;x>0;x--)
{
for(int y=15;y>=0;y--)
{
for(int z=60;z>0;z--)
{
textbackground(BLACK);
textcolor(CYAN);
gotoxy(28,10);
cprintf("00:00:%2d:%2d",y,z);
delay(10);
}
}
}
gotoxy(28,10);
cprintf("00:00:00:00");
delay(1000);
}

int passw()
{
char ch1;
char *pass,option1,*newpass;
static char *default_pass="2003";
int c,k,pa,val1;
clrscr();
draw_box(18,9,50,11,5);
gotoxy(20,10);
pass=getpass("ENTER LOGIN PASSWORD: ");
c=strcmp(pass,default_pass);
fstream filep;
file.open("ssap",ios::in);
filep>>newpass;
k=strcmp(pass,newpass);
filep.close();
clrscr();
if(c==0||k==0)
{
pa=1;
draw_box(13,7,65,16,5);
gotoxy(20,10);
cout<<"PASSWORD ACCEPTED";
gotoxy(25,10);
cout<<"\n\t\tDO YOU WANT TO CHANGE THE PASSWORD (Y/N)";
option1=getche();
//module for changing password
while(option1=='y'||option1=='Y')
{
fflush(stdin);
char *temp_newpass1,*temp_newpass2;
temp_newpass1=getpass("\n\tENTER NEW PASSWORD: ");
fflush(stdin);
temp_newpass2=getpass("\n\tRE-ENTER NEW PASSWORD: ");
fflush(stdin);
if(strcmp(temp_newpass1,temp_newpass2)==0)
{
strcpy(newpass,temp_newpass1);
//storing the new password in a file
fstream filep;
file.open("ssap",ios::out);
filep<<newpass;
filep.close();
cout<<"\n\t PASSWORD CHANGED.";
getch();
return pa;
}
else
{
cout<<"\nDO YOU STILL WANT TO CHANGE THE PASSWORD (Y)";
cin>>option1;
}
}
//end of password change module
}
return pa;
}

void end()
{
clrscr();
draw_box(18,7,50,11,5);
gotoxy(20,8);
for(int i=0;i<=80;i++)
{
gotoxy(i,12);
cout<<"GOOD BYE!";
delay(50);
cout<<" ";
}
getch();
exit(0);
}

void acknowledgement()
{
textbackground(BLACK);
textcolor(9);
clrscr();
cprintf("\t\tWATER BILLING SYSTEM");
cout<<"\n\n\nINTRODUCTION TO PHYSCIAL SYSTEM :- ";
cout<<"\nwater supply dept. of a city is basically responsible for providing water\nconnection to ";
cout<<"the consumers and billing them accordingly to the volume of water consumed by them.";
cout<<"\n\t For carrying out these activities, the dept. install a water meter at\n consumer site.";
cout<<"At the end of every month, a personfrom the WSD(water supply dept.) goes to each\nconsumer's site & note the meter reading";
cout<<"based on each meter reading & previous meter reading, volume of water consumed is calculated.";
cout<<"\n\tBILLS are prepared & sent to the consumers.";
cout<<"\n\tconsumes are supposed to pay the due amount on or before a given date.";
cout<<"As far as PAYMENT is concerned,There are 3 types of consumers";
cout<<"\n1-Those who pay on TIME.";
cout<<"\n2-Those who pay late.";
cout<<"\n3-Those who donot pay.");
cout<<"If the dues are not paid on Time then late fee is charged @Rs 1.00 per day";
cout<<"\nIf the consumer does not pay their due in 3 months time then there water connectionis\nis disconnected by WSD";
cout<<"\n PRESS ANY KEY.......";
getch();
clrscr();
cprintf("THE MAJOR ACTIVITIES OF WSD: ");
cout<<"\n-Meter Installation.";
cout<<"\n-Meter Reading.";
cout<<"\n-Bill Genereation.";
cout<<"\n-Collection Handling.";
cout<<"\n-Report Generation.";
cout<<"\n\tTo understand the system more clearly above mentioned activities are\ndescribed in detail";
cout<<"\n\n\nPRESS ANY KEY.......";
getch();
clrscr();
cprintf("METER INSTALLATION");
cout<<"\nWhen a consumer wants a water connection,he/she gives an application to the WSD";
cout<<"\nin a prescribed format.\nFormat of application is - ";
cout<<"\nConnection register  ";
cout<<"\nsl.no. | meter no. | name | adddress | category |";
cout<<"\n\n\n\n\n\nPRESS ANY KEY.......";
getch();
clrscr();
cprintf("METER READING");
cout<<"\nFor each meter installed, WSD maintains a meter card,\n format-";
cout<<"\nmonth | meter status | meter reading |";
cout<<"\n\n\n\n\n\n\nPRESS ANY KEY.......";
getch();
clrscr();
cprintf("BILL GENERATION");
cout<<"For the purpose of bill generation, the consumers are categorized as -";
cout<<"\n-General Consumers.";
cout<<"\n-Employee of WSD.";
cout<<"\n-Handicapped.";
cout<<"\n-Privilleged Consumers (hospitals,schools,parks,govt. offices,etc.";
cout<<"\n\n\n\n\n\n\nPRESS ANY KEY.........";
getch();
clrscr();
cprintf("RATE");
cout<<"\nFor these categories following Rates are charged: ";
cout<<"\n-General Consumers: rate of consumption of water upto 500 units @ Rs 1.00/unit.";
cout<<"\nFrom 501-1000 units @ Rs 1.50/unit & above 1000 units rate charges is Rs 2.00/unit.";
cout<<"\n\nEmployee of WSD: rate of consumption of water upto 500 units @ Rs 0.50/unit.";
cout<<"\nFrom 501-1000 units rate charged @ Rs 1.00/unit. \nAnd above 1000 units rate charged @ Rs 1.50/unit.";
cout<<"\n\nHandicapped: rate of consumption of water upto 500 units @ Rs 0.25/unit.";
cout<<"\nFrom 501-1000 units rate charged @ Rs 0.50/unit.\nAnd above 1000 units rate charged @ Rs 0.75/unit.";
cout<<"\n\nPrivilleged Consumers: Water is Free...";
cout<<"\n\n\n\n\n\n\nPRESS ANY KEY.............";
getch();
clrscr();
cprintf("VOLUME OF WATER CONSUMED IN UNITS");
cout<<"\nWSD calculates volume of water consumed in units by the consumer under";
cout<<"\ntwo conditions as follows-";
cout<<"\n- If water meter is functioning properly then volume of water consumed";
cout<<"\n- It is calculated directly by substracting previous meter reading from ";
cout<<"\npresent month reading.";
cout<<"\n-When water meter is not functioning properly then volume of water consumed is";
cout<<"\ntaken as average of last 3 months volume of water consumed.";
cout<<"\n\n\n\n\nPRESS ANY KEY...........";
getch();
clrscr();
cprintf("BILL FORMAT");
cout<<"\n-Meter no.:- ";
cout<<"\n-Consumer's NAME:- ";
cout<<"\n-Consumer's Address:- ";
cout<<"\n-Consumer's Category:- ";
cout<<"\n-Meter Status:-";
cout<<"\nFor the month of:- ";
cout<<"\n-Units consumed | concession | total chargeable | rate | amount | late fine |";
cout<<"\n\n\n\n\n\nPRESS ANY KEY..........";
getch();
clrscr();
cprintf("REPORT GENERATION");
cout<<"\nFor smooth functioning & effective control,followinf reports are generated: ";
cout<<"\n\t-List of meters that are not functioning.";
cout<<"\n\t-List of consumers along with their water bills.";
cout<<"\n\n\n\n\n\nPRESS ANY KEY.......";
getch();
clrscr();
cprintf("COLLECTION HANDLING");
cout<<"\n It is done manually by the WSD collection incharge";
cout<<"\n\n\n\n\n\nPRESS ANY KEY.........";
getch();
}







