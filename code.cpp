#include<stdlib.h>
#include<stdio.h>
#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<iomanip.h>
#include<fstream.h>
struct player
{
   char name[20],sym;
   float balance;
   int no,t,pos,hc,free;
}p1,p2,p,op;
char a[16],b[16];
int x1,x2,x3,x4,x5,bh,pr=0;
class ticket
{
  public:
    char name[20],choice,choiceh;
    float b_price,b_rent,rent;
    float h1_p,h2_p,h3_p,h4_p;
    float h1_r,h2_r,h3_r,h4_r;
    int owner,hno;
    ticket(char n[20],float bp,float br,float h1p,float h2p,float h3p,float h4p,float h1r,float h2r,float h3r, float h4r,int hn)
       {
     strcpy(name,n);
     b_price=bp;
     b_rent=br;
     h1_p=h1p;
     h2_p=h2p;
     h3_p=h3p;
     h4_p=h4p;
     h1_r=h1r;
     h2_r=h2r;
     h3_r=h3r;
     h4_r=h4r;
     hno=hn;

    }
    void buy()
    {

      cout<<" Do you want to buy(Y/N) "<<name<<" at "<<b_price<<" M\n";
      cin>>choice;
      if(choice=='y'||choice=='Y')
      {                //p=player no who has rolled the dice
	p.balance-=b_price;
	owner=p.no;
	rent=b_rent;
	p.t++;
	x1=1;        //p.t=ticket no of player

      }
      else
      {
      x2=2;

      }
    }
    void payrent()
    {
      p.balance-=rent;
      op.balance+=rent;  //op=other player
      x3=3;
      pr=1;
    }
    void house()
    {
      if(hno>4)
	{
	cout<<p.name<<", you have already build maximum no. of houses on "<<name<<endl;
	x4=4;
	}
      else
      {
	cout<<"Do you want to build house no. "<<hno<<"\n";
	cin>>choiceh;   //choiceh=choice of building a house
	if(choiceh=='n'||choiceh=='N')
	 {
	  x2=2;
	 }
	else if(choiceh=='y'||choiceh=='Y')
	{
		  bh=1;//bd=build house
		  p.hc+=1;
	  switch(hno)
	  {
	   case 1:
		   p.balance-=h1_p;
		   rent=h1_r;
		   hno++;

		   break;
	   case 2:
		   p.balance-=h2_p;
		   rent=h2_r;
		   hno++;

		   break;
	   case 3:
		   p.balance-=h3_p;
		   rent=h3_r;
		   hno++;

		   break;
	   case 4:
		   p.balance-=h4_p;
		   rent=h4_r;
		   hno++;

		   break;
	  }
	}
      }
    }
};
   ticket t1("BEIJING" ,1.50,0.10,0.50,0.75,1.50,2.00,0.25,0.60,2.00,3.00,1);
   ticket t2("TOKYO"   ,2.00,0.15,0.50,0.75,1.50,2.00,0.35,0.75,2.50,3.50,1);
   ticket t3("PARIS"   ,2.50,0.20,0.75,1.00,2.00,2.50,0.45,0.90,3.00,4.50,1);
   ticket t4("DELHI"   ,2.50,0.20,0.75,1.00,2.00,2.50,0.45,0.90,3.00,4.50,1);
   ticket t5("MOSCOW"  ,3.00,0.35,0.75,1.25,2.00,2.50,0.60,1.30,3.50,5.50,1);
   ticket t6("SYDNEY"  ,3.00,0.35,0.75,1.50,2.50,3.00,0.60,1.30,4.25,6.50,1);
   ticket t7("BERLIN"  ,3.50,0.45,0.75,1.50,2.50,3.00,0.80,2.00,5.00,7.00,1);
   ticket t8("ROME"    ,4.00,0.55,1.00,1.75,3.00,4.00,1.00,2.50,5.50,8.50,1);
   ticket t9("NEW YORK",4.50,0.75,1.00,1.75,3.00,4.00,1.50,3.50,7.50,10.00,1);
   ticket t10("LONDON" ,5.00,1.00,1.00,1.75,3.00,4.00,2.00,4.50,9.00,14.00,1);
   ticket t("BEIJING"  ,1.50,0.10,0.50,0.75,1.50,2.00,0.25,0.60,2.00,3.00,1);
void save()
{
  ofstream fout("player.dat",ios::binary);
  fout.write((char*)&p1,sizeof(p1));
  fout.write((char*)&p2,sizeof(p2));
  fout.close();
  fout.open("ticket.dat",ios::binary);
  fout.write((char*)&t1,sizeof(t1));
  fout.write((char*)&t2,sizeof(t2));
  fout.write((char*)&t3,sizeof(t3));
  fout.write((char*)&t4,sizeof(t4));
  fout.write((char*)&t5,sizeof(t5));
  fout.write((char*)&t6,sizeof(t6));
  fout.write((char*)&t7,sizeof(t7));
  fout.write((char*)&t8,sizeof(t8));
  fout.write((char*)&t9,sizeof(t9));
  fout.write((char*)&t10,sizeof(t10));
  fout.close();
  cout<<"Your data has been saved";
  getch();
}
void load()
{
  ifstream fin("player.dat",ios::binary);
  fin.read((char*)&p1,sizeof(p1));
  a[p1.pos]=p1.sym;
  fin.read((char*)&p2,sizeof(p2));
  b[p2.pos]=p2.sym;
  fin.close();
  fin.open("ticket.dat",ios::binary);
  fin.read((char*)&t1,sizeof(t1));
  fin.read((char*)&t2,sizeof(t2));
  fin.read((char*)&t3,sizeof(t3));
  fin.read((char*)&t4,sizeof(t4));
  fin.read((char*)&t5,sizeof(t5));
  fin.read((char*)&t6,sizeof(t6));
  fin.read((char*)&t7,sizeof(t7));
  fin.read((char*)&t8,sizeof(t8));
  fin.read((char*)&t9,sizeof(t9));
  fin.read((char*)&t10,sizeof(t10));
  fin.close();
  cout<<"Your data has been retrived\n.Press enter to continue";
  getch();
}
void init()
{
    clrscr();
    cout<<"Welcome to the game of MONOPOLY-THE ULTIMATE BUSINESS GAME \n";
   cout<<"Enter name of player 1.\n";
   gets(p1.name);
   cout<<p1.name<<", enter your symbol of token\n";
   cin>>p1.sym;
   cout<<"Enter name of player 2.\n";
   gets(p2.name);
   cout<<p2.name<<", enter your symbol of token\n";
   cin>>p2.sym;
   p1.balance=p2.balance=10;
   p1.no=1;
   p2.no=2;
   p1.t=p2.t=p1.pos=p2.pos=p1.hc=p2.hc=p1.free=p2.free=0;

   for(int i=0;i<16;i++)
   {
    a[i]=' ';
    b[i]=' ';
   }
   a[0]=p1.sym;
   b[0]=p2.sym;
	      //name,bp,br,h1p,h2p,h3p,h4p,   h1r,  h2r, h3r, h4r
}

void roll1(int s)
{
 switch(s)
    {
       case 1:clrscr();
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<endl;
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<endl;
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|\n";
       cout<<"| TOKYO  |                          | SYDNEY |\n";
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |\n";
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |\n";
       cout<<"|--------|   |--------|             |--------|\n";
       cout<<"| CHANCE |                          | BERLIN |"<<"               _______ \n";
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<"              |       |\n";
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<"              |   .   |\n";
       cout<<"|--------|             |---------|  |--------|"<<"              |       |\n";
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<"              |_______|\n";
       cout<<"| 1.5 M  |             |---------|  |        |\n";
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |\n";
       cout<<"|--------|--------|--------|--------|--------|\n";
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;
       break;
      case 2:clrscr();
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<endl;
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<endl;
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|\n";
       cout<<"| TOKYO  |                          | SYDNEY |\n";
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |\n";
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |\n";
       cout<<"|--------|   |--------|             |--------|\n";
       cout<<"| CHANCE |                          | BERLIN |"<<"               _______ \n";
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<"              |  .    |\n";
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<"              |       |\n";
       cout<<"|--------|             |---------|  |--------|"<<"              |    .  |\n";
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<"              |_______|\n";
       cout<<"| 1.5 M  |             |---------|  |        |\n";
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |\n";
       cout<<"|--------|--------|--------|--------|--------|\n";
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;
       break;
      case 3:clrscr();
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<endl;
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<endl;
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|\n";
       cout<<"| TOKYO  |                          | SYDNEY |\n";
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |\n";
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |\n";
       cout<<"|--------|   |--------|             |--------|\n";
       cout<<"| CHANCE |                          | BERLIN |"<<"               _______ \n";
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<"              | .     |\n";
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<"              |   .   |\n";
       cout<<"|--------|             |---------|  |--------|"<<"              |     . |\n";
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<"              |_______|\n";
       cout<<"| 1.5 M  |             |---------|  |        |\n";
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |\n";
       cout<<"|--------|--------|--------|--------|--------|\n";
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;
       break;
      case 4:clrscr();
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<endl;
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<endl;
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|\n";
       cout<<"| TOKYO  |                          | SYDNEY |\n";
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |\n";
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |\n";
       cout<<"|--------|   |--------|             |--------|\n";
       cout<<"| CHANCE |                          | BERLIN |"<<"               _______ \n";
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<"              | .   . |\n";
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<"              |       |\n";
       cout<<"|--------|             |---------|  |--------|"<<"              | .   . |\n";
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<"              |_______|\n";
       cout<<"| 1.5 M  |             |---------|  |        |\n";
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |\n";
       cout<<"|--------|--------|--------|--------|--------|\n";
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;
       break;
      case 5:clrscr();
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<endl;
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<endl;
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|\n";
       cout<<"| TOKYO  |                          | SYDNEY |\n";
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |\n";
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |\n";
       cout<<"|--------|   |--------|             |--------|\n";
       cout<<"| CHANCE |                          | BERLIN |"<<"               _______ \n";
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<"              | .   . |\n";
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<"              |   .   |\n";
       cout<<"|--------|             |---------|  |--------|"<<"              | .   . |\n";
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<"              |_______|\n";
       cout<<"| 1.5 M  |             |---------|  |        |\n";
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |\n";
       cout<<"|--------|--------|--------|--------|--------|\n";
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;
       break;
      case 6:clrscr();
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<endl;
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<endl;
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|\n";
       cout<<"| TOKYO  |                          | SYDNEY |\n";
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |\n";
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |\n";
       cout<<"|--------|   |--------|             |--------|\n";
       cout<<"| CHANCE |                          | BERLIN |"<<"               _______ \n";
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<"              | .   . |\n";
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<"              | .   . |\n";
       cout<<"|--------|             |---------|  |--------|"<<"              | .   . |\n";
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<"              |_______|\n";
       cout<<"| 1.5 M  |             |---------|  |        |\n";
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |\n";
       cout<<"|--------|--------|--------|--------|--------|\n";
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;
       break;
    }
};
void roll(int s)
{
 switch(s)
    {
      case 1:clrscr();
       cout<<"|--------|--------|--------|--------|--------|"<<"               _______ \n";
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<"              |       |\n";
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<"              |   .   |\n";
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<"              |       |\n";
       cout<<"|--------|--------|--------|--------|--------|"<<"              |_______|\n";
       cout<<"| TOKYO  |                          | SYDNEY |"<<"\t    |--------------------|"<<endl;
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |"<<"\t    |     "<<setw(8)<<t.name<<"       |"<<endl;
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |"<<"\t    |--------------------|"<<endl;
       cout<<"|--------|   |--------|             |--------|"<<"\t    | BASE PRICE  "<<t.b_price<<" M |"<<endl;
       cout<<"| CHANCE |                          | BERLIN |"<<"\t    | BASE RENT   "<<t.b_rent<<" M |"<<endl;
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<"\t    |--------------------|"<<endl;
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<"\t    | HOUSE  PRICE  RENT |"<<endl;
       cout<<"|--------|             |---------|  |--------|"<<"\t    |  NO                |"<<endl;
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<"\t    |   1   "<<t.h1_p<<"M  "<<t.h1_r<<"M |"<<endl;
       cout<<"| 1.5 M  |             |---------|  |        |"<<"\t    |   2   "<<t.h2_p<<"M  "<<t.h2_r<<"M |"<<endl;
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |"<<"\t    |   3   "<<t.h3_p<<"M  "<<t.h3_r<<"M |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"\t    |   4   "<<t.h4_p<<"M  "<<t.h4_r<<"M |"<<endl;
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<"\t    |--------------------|"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;

      break;
      case 2:clrscr();
       cout<<"|--------|--------|--------|--------|--------|"<<"               _______ \n";
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<"              |  .    |\n";
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<"              |       |\n";
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<"              |     . |\n";
       cout<<"|--------|--------|--------|--------|--------|"<<"              |_______|\n";
       cout<<"| TOKYO  |                          | SYDNEY |"<<"\t    |--------------------|"<<endl;
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |"<<"\t    |     "<<setw(8)<<t.name<<"       |"<<endl;
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |"<<"\t    |--------------------|"<<endl;
       cout<<"|--------|   |--------|             |--------|"<<"\t    | BASE PRICE  "<<t.b_price<<" M |"<<endl;
       cout<<"| CHANCE |                          | BERLIN |"<<"\t    | BASE RENT   "<<t.b_rent<<" M |"<<endl;
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<"\t    |--------------------|"<<endl;
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<"\t    | HOUSE  PRICE  RENT |"<<endl;
       cout<<"|--------|             |---------|  |--------|"<<"\t    |  NO                |"<<endl;
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<"\t    |   1   "<<t.h1_p<<"M  "<<t.h1_r<<"M |"<<endl;;
       cout<<"| 1.5 M  |             |---------|  |        |"<<"\t    |   2   "<<t.h2_p<<"M  "<<t.h2_r<<"M |"<<endl;
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |"<<"\t    |   3   "<<t.h3_p<<"M  "<<t.h3_r<<"M |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"\t    |   4   "<<t.h4_p<<"M  "<<t.h4_r<<"M |"<<endl;
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<"\t    |--------------------|"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;

       break;
      case 3:clrscr();
       cout<<"|--------|--------|--------|--------|--------|"<<"               _______ \n";
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<"              | .     |\n";
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<"              |   .   |\n";
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<"              |     . |\n";
       cout<<"|--------|--------|--------|--------|--------|"<<"              |_______|\n";
       cout<<"| TOKYO  |                          | SYDNEY |"<<"\t    |--------------------|"<<endl;
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |"<<"\t    |     "<<setw(8)<<t.name<<"       |"<<endl;
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |"<<"\t    |--------------------|"<<endl;
       cout<<"|--------|   |--------|             |--------|"<<"\t    | BASE PRICE  "<<t.b_price<<" M |"<<endl;
       cout<<"| CHANCE |                          | BERLIN |"<<"\t    | BASE RENT   "<<t.b_rent<<" M |"<<endl;
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<"\t    |--------------------|"<<endl;
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<"\t    | HOUSE  PRICE  RENT |"<<endl;
       cout<<"|--------|             |---------|  |--------|"<<"\t    |  NO                |"<<endl;
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<"\t    |   1   "<<t.h1_p<<"M  "<<t.h1_r<<"M |"<<endl;;
       cout<<"| 1.5 M  |             |---------|  |        |"<<"\t    |   2   "<<t.h2_p<<"M  "<<t.h2_r<<"M |"<<endl;
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |"<<"\t    |   3   "<<t.h3_p<<"M  "<<t.h3_r<<"M |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"\t    |   4   "<<t.h4_p<<"M  "<<t.h4_r<<"M |"<<endl;
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<"\t    |--------------------|"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;
    break;
      case 4:clrscr();
       cout<<"|--------|--------|--------|--------|--------|"<<"               _______ \n";
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<"              | .   . |\n";
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<"              |       |\n";
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<"              | .   . |\n";
       cout<<"|--------|--------|--------|--------|--------|"<<"              |_______|\n";
       cout<<"| TOKYO  |                          | SYDNEY |"<<"\t    |--------------------|"<<endl;
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |"<<"\t    |     "<<setw(8)<<t.name<<"       |"<<endl;
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |"<<"\t    |--------------------|"<<endl;
       cout<<"|--------|   |--------|             |--------|"<<"\t    | BASE PRICE  "<<t.b_price<<" M |"<<endl;
       cout<<"| CHANCE |                          | BERLIN |"<<"\t    | BASE RENT   "<<t.b_rent<<" M |"<<endl;
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<"\t    |--------------------|"<<endl;
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<"\t    | HOUSE  PRICE  RENT |"<<endl;
       cout<<"|--------|             |---------|  |--------|"<<"\t    |  NO                |"<<endl;
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<"\t    |   1   "<<t.h1_p<<"M  "<<t.h1_r<<"M |"<<endl;;
       cout<<"| 1.5 M  |             |---------|  |        |"<<"\t    |   2   "<<t.h2_p<<"M  "<<t.h2_r<<"M |"<<endl;
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |"<<"\t    |   3   "<<t.h3_p<<"M  "<<t.h3_r<<"M |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"\t    |   4   "<<t.h4_p<<"M  "<<t.h4_r<<"M |"<<endl;
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<"\t    |--------------------|"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;
       break;
      case 5:clrscr();
       cout<<"|--------|--------|--------|--------|--------|"<<"               _______ \n";
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<"              | .   . |\n";
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<"              |   .   |\n";
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<"              | .   . |\n";
       cout<<"|--------|--------|--------|--------|--------|"<<"              |_______|\n";
       cout<<"| TOKYO  |                          | SYDNEY |"<<"\t    |--------------------|"<<endl;
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |"<<"\t    |     "<<setw(8)<<t.name<<"       |"<<endl;
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |"<<"\t    |--------------------|"<<endl;
       cout<<"|--------|   |--------|             |--------|"<<"\t    | BASE PRICE  "<<t.b_price<<" M |"<<endl;
       cout<<"| CHANCE |                          | BERLIN |"<<"\t    | BASE RENT   "<<t.b_rent<<" M |"<<endl;
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<"\t    |--------------------|"<<endl;
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<"\t    | HOUSE  PRICE  RENT |"<<endl;
       cout<<"|--------|             |---------|  |--------|"<<"\t    |  NO                |"<<endl;
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<"\t    |   1   "<<t.h1_p<<"M  "<<t.h1_r<<"M |"<<endl;;
       cout<<"| 1.5 M  |             |---------|  |        |"<<"\t    |   2   "<<t.h2_p<<"M  "<<t.h2_r<<"M |"<<endl;
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |"<<"\t    |   3   "<<t.h3_p<<"M  "<<t.h3_r<<"M |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"\t    |   4   "<<t.h4_p<<"M  "<<t.h4_r<<"M |"<<endl;
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<"\t    |--------------------|"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;
       break;
      case 6:
       cout<<"|--------|--------|--------|--------|--------|"<<"               _______ \n";
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<"              | .   . |\n";
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<"              | .   . |\n";
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<"              | .   . |\n";
       cout<<"|--------|--------|--------|--------|--------|"<<"              |_______|\n";
       cout<<"| TOKYO  |                          | SYDNEY |"<<"\t    |--------------------|"<<endl;
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |"<<"\t    |     "<<setw(8)<<t.name<<"       |"<<endl;
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |"<<"\t    |--------------------|"<<endl;
       cout<<"|--------|   |--------|             |--------|"<<"\t    | BASE PRICE  "<<t.b_price<<" M |"<<endl;
       cout<<"| CHANCE |                          | BERLIN |"<<"\t    | BASE RENT   "<<t.b_rent<<" M |"<<endl;
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<"\t    |--------------------|"<<endl;
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<"\t    | HOUSE  PRICE  RENT |"<<endl;
       cout<<"|--------|             |---------|  |--------|"<<"\t    |  NO                |"<<endl;
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<"\t    |   1   "<<t.h1_p<<"M  "<<t.h1_r<<"M |"<<endl;;
       cout<<"| 1.5 M  |             |---------|  |        |"<<"\t    |   2   "<<t.h2_p<<"M  "<<t.h2_r<<"M |"<<endl;
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |"<<"\t    |   3   "<<t.h3_p<<"M  "<<t.h3_r<<"M |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"\t    |   4   "<<t.h4_p<<"M  "<<t.h4_r<<"M |"<<endl;
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<"\t    |--------------------|"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;
	break;
       }

};
void main()
{
  clrscr();
  int d1,chance1,chest;   //chance1=choice of chance cards
  char d2;
  cout.setf(ios::showpoint);
  cout.setf(ios::left);
  cout<<setprecision(2);
  cout<<"\nEnter your choice\n1.START new game.\n2.LOAD previous game\n";
  cin>>d1;
  if(d1==1)
   init();
  else if(d1==2)
   load();
  p=p1;         //p=current player
  op=p2;        //op=other player
  int chance=1,z=0;
  char ch1;
  do
  {
   clrscr();
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<endl;
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<endl;
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"| TOKYO  |                          | SYDNEY |"<<endl;
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |"<<endl;
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |"<<endl;
       cout<<"|--------|   |--------|             |--------|"<<endl;
       cout<<"| CHANCE |                          | BERLIN |"<<endl;
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<endl;
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<endl;
       cout<<"|--------|             |---------|  |--------|"<<endl;
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<endl;
       cout<<"| 1.5 M  |             |---------|  |        |"<<endl;
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;
       randomize();
    cout<<p.name<<" click enter to roll dice \n";
    getch();

      int s=random(6)+1;
      if(chance==1)
	a[p.pos]=' ';
      else if(chance==2)
	b[p.pos]=' ';
      p.pos+=s;
      clrscr();
      if(p.pos>15)       //16 blocks in current board
      {
	p.pos-=16;

	z=1;
	p.balance+=1.5;
      }
      if(chance==1)
	a[p.pos]=p.sym;
      else if(chance==2)
	b[p.pos]=p.sym;


	int show=1;//show== to display last board or not
	switch(p.pos)
      {
	case 0: show=0;
		cout<<p.name<<", you are at start\n";
		roll(s);
      cout<<p.name<<", you have just rolled a "<<s<<"\n";
      if(z==1)
      {
	cout<<p.name<<",you have just reached or passed GO. 1.5 M added to balance.\n";
	z=0;
      }
		break;
	case 1: show=1;
	t=t1;
	roll(s);
      cout<<p.name<<", you have just rolled a "<<s<<"\n";
      if(z==1)
      {
	cout<<p.name<<",you have just reached or passed GO. 1.5 M added to balance.\n";
	z=0;
      }
	cout<<p.name<<", you are at BEIJING\n";
		if(t1.owner==0)
		{
		  t1.buy();
		}
		else if(t1.owner==p.no)
		{
		 t1.house();
		}
		else if(t1.owner==op.no)
		{
		 t1.payrent();
		}
		break;
	case 2:show=0;
	roll1(s);
      cout<<p.name<<", you have just rolled a "<<s<<"\n";
      if(z==1)
      {
	cout<<p.name<<",you have just reached or passed GO. 1.5 M added to balance.\n";
	z=0;
      }
      chance1=random(6)+1;
		cout<<p.name<<", CHANCE says,";
	switch(chance1)
	{
	  case 1: cout<<"It's your birthday. Collect a gift of 500 k from "<<op.name<<"\n";
		  p.balance+=0.5;
		  op.balance-=0.5;
		  break;
	  case 2: cout<<"Advance to go.Collect 1.5 M.\n";
		 if(chance==1)
		 a[p.pos]=' ';
		 else if(chance==2)
		 b[p.pos]=' ';
		 p.pos=0;
		 if(chance==1)
		 a[p.pos]=p.sym;
		 else if(chance==2)
		 b[p.pos]=p.sym;
		 p.balance+=1.5;
		 break;
	  case 3:cout<<" President is in town.He is happy by your service.You have been awrded a 'GET OUT OF JAIL FREE' card.\n";
		 p.free=1;
		 break;
	  case 4:cout<<" Your mother wants a new house.Buy a Condo for 1 M.\n";
		 p.balance-=1;
		 break;
	  case 5:clrscr();
		  t=t10;
		  if(chance==1)
		 a[p.pos]=' ';
		 else if(chance==2)
		 b[p.pos]=' ';
		 p.pos=15;
		 if(chance==1)
		 a[p.pos]=p.sym;
		 else if(chance==2)
		 b[p.pos]=p.sym;

       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<endl;
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<endl;
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"\t    |--------------------|"<<endl;
       cout<<"| TOKYO  |                          | SYDNEY |"<<"\t    |     "<<setw(8)<<t.name<<"       |"<<endl;
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |"<<"\t    |--------------------|"<<endl;
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |"<<"\t    | BASE PRICE  "<<t.b_price<<" M |"<<endl;
       cout<<"|--------|   |--------|             |--------|"<<"\t    | BASE RENT   "<<t.b_rent<<" M |"<<endl;
       cout<<"| CHANCE |                          | BERLIN |"<<"\t    |--------------------|"<<endl;
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<"\t    | HOUSE  PRICE  RENT |"<<endl;
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<"\t    |  NO                |"<<endl;
       cout<<"|--------|             |---------|  |--------|"<<"\t    |   1   "<<t.h1_p<<"M  "<<t.h1_r<<"M |"<<endl;
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<"\t    |   2   "<<t.h2_p<<"M  "<<t.h2_r<<"M |"<<endl;
       cout<<"| 1.5 M  |             |---------|  |        |"<<"\t    |   3   "<<t.h3_p<<"M  "<<t.h3_r<<"M |"<<endl;
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |"<<"\t    |   4   "<<t.h4_p<<"M  "<<t.h4_r<<"M |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"\t    |--------------------|"<<endl;
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;
	cout<<"You have been awarded a free trip to london.\n";


		cout<<p.name<<", you are at LONDON\n";
		if(t10.owner==0)
		{
		  t10.buy();
		}
		else if(t10.owner==p.no)
		{
		 t10.house();
		}
		else if(t10.owner==op.no)
		{
		 t10.payrent();
		}
		 break;
	  case 6: cout<<"A comet just hit all your properties .Pay 500 k for repair on each property you own.\n";
		  p.balance-=(p.t*0.50);
		  break;

	}

		break;
	case 3: show=1;
	t=t2;
	roll(s);
      cout<<p.name<<", you have just rolled a "<<s<<"\n";
      if(z==1)
      {
	cout<<p.name<<",you have just reached or passed GO. 1.5 M added to balance.\n";
	z=0;
      }
	cout<<p.name<<", you are at TOKYO\n";
			if(t2.owner==0)
		{
		  t2.buy();
		}
		else if(t2.owner==p.no)
		{
		 t2.house();
		}
		else if(t2.owner==op.no)
		{
		 t2.payrent();
		}
		break;
	case 4: show=0;
	roll1(s);
      cout<<p.name<<", you have just rolled a "<<s<<"\n";
      if(z==1)
      {
	cout<<p.name<<",you have just reached or passed GO. 1.5 M added to balance.\n";
	z=0;
      }
	 cout<<p.name<<", you are visiting JAIL\n";
		break;
	case 5: show=1;
	t=t3;
	roll(s);
      cout<<p.name<<", you have just rolled a "<<s<<"\n";
      if(z==1)
      {
	cout<<p.name<<",you have just reached or passed GO. 1.5 M added to balance.\n";
	z=0;
      }
	cout<<p.name<<", you are at PARIS\n";
			if(t3.owner==0)
		{
		  t3.buy();
		}
		else if(t3.owner==p.no)
		{
		 t3.house();
		}
		else if(t3.owner==op.no)
		{
		 t3.payrent();
		}
		 break;
	case 6: show=1;
		t=t4;
	 roll(s);
      cout<<p.name<<", you have just rolled a "<<s<<"\n";
      if(z==1)
      {
	cout<<p.name<<",you have just reached or passed GO. 1.5 M added to balance.\n";
	z=0;
      }
	cout<<p.name<<", you are at DELHI\n";
			if(t4.owner==0)
		{
		  t4.buy();
		}
		else if(t4.owner==p.no)
		{
		 t4.house();
		}
		else if(t4.owner==op.no)
		{
		 t4.payrent();
		}
		 break;
	case 7: show=1;
	t=t5;
	roll(s);
      cout<<p.name<<", you have just rolled a "<<s<<"\n";
      if(z==1)
      {
	cout<<p.name<<",you have just reached or passed GO. 1.5 M added to balance.\n";
	z=0;
      }
	cout<<p.name<<", you are at MOSCOW\n";
			if(t5.owner==0)
		{
		  t5.buy();
		}
		else if(t5.owner==p.no)
		{
		 t5.house();
		}
		else if(t5.owner==op.no)
		{
		 t5.payrent();
		}
		 break;
	case 8: show=0;
	roll1(s);
      cout<<p.name<<", you have just rolled a "<<s<<"\n";
      if(z==1)
      {
	cout<<p.name<<",you have just reached or passed GO. 1.5 M added to balance.\n";
	z=0;
      }
	cout<<p.name<<", you are at FREE PARKING\n";
		 break;
	case 9:show=1;
	 t=t6;
	roll(s);
      cout<<p.name<<", you have just rolled a "<<s<<"\n";
      if(z==1)
      {
	cout<<p.name<<",you have just reached or passed GO. 1.5 M added to balance.\n";
	z=0;
      }
	cout<<p.name<<", you are at SYDNEY\n";
			if(t6.owner==0)
		{
		  t6.buy();
		}
		else if(t6.owner==p.no)
		{
		 t6.house();
		}
		else if(t6.owner==op.no)
		{
		 t6.payrent();
		}
		 break;
	case 10:show=1;
	t=t7;
	roll(s);
      cout<<p.name<<", you have just rolled a "<<s<<"\n";
      if(z==1)
      {
	cout<<p.name<<",you have just reached or passed GO. 1.5 M added to balance.\n";
	z=0;
      }
	 cout<<p.name<<", you are at BERLIN\n";
			if(t7.owner==0)
		{
		  t7.buy();
		}
		else if(t7.owner==p.no)
		{
		 t7.house();
		}
		else if(t7.owner==op.no)
		{
		 t7.payrent();
		}
		 break;
	case 11: show=0;
	roll1(s);
      cout<<p.name<<", you have just rolled a "<<s<<"\n";
      if(z==1)
      {
	cout<<p.name<<",you have just reached or passed GO. 1.5 M added to balance.\n";
	z=0;
      }
       chest=random(6)+1;
	cout<<p.name<<", CHEST says,";
	switch(chest)
	{
	  case 1: cout<<"It is 25 th anniversary of the bank. COllect 500k on each property you own.\n";
		  p.balance+=(p.t*0.5);
		  break;
	  case 2: cout<<"Advance to go.Collect 1.5 M.\n";
		 if(chance==1)
		 a[p.pos]=' ';
		 else if(chance==2)
		 b[p.pos]=' ';
		 p.pos=0;
		 if(chance==1)
		 a[p.pos]=p.sym;
		 else if(chance==2)
		 b[p.pos]=p.sym;
		 p.balance+=1.5;
		 break;
	  case 3:cout<<" President is in town.He is happy by your service.You have been awrded a 'GET OUT OF JAIL FREE' card.\n";
		 p.free=1;
		 break;
	  case 4:cout<<" Your wife wants a new car.Buy a Mercedes for 750 k.\n";
		 p.balance-=0.75;
		 break;
	  case 5:
		 t=t4;
		 if(chance==1)
		 a[p.pos]=' ';
		 else if(chance==2)
		 b[p.pos]=' ';
		 p.pos=6;
		 if(chance==1)
		 a[p.pos]=p.sym;
		 else if(chance==2)
		 b[p.pos]=p.sym;
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<endl;
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<endl;
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"\t    |--------------------|"<<endl;
       cout<<"| TOKYO  |                          | SYDNEY |"<<"\t    |     "<<setw(8)<<t.name<<"       |"<<endl;
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |"<<"\t    |--------------------|"<<endl;
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |"<<"\t    | BASE PRICE  "<<t.b_price<<" M |"<<endl;
       cout<<"|--------|   |--------|             |--------|"<<"\t    | BASE RENT   "<<t.b_rent<<" M |"<<endl;
       cout<<"| CHANCE |                          | BERLIN |"<<"\t    |--------------------|"<<endl;
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<"\t    | HOUSE  PRICE  RENT |"<<endl;
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<"\t    |  NO                |"<<endl;
       cout<<"|--------|             |---------|  |--------|"<<"\t    |   1   "<<t.h1_p<<"M  "<<t.h1_r<<"M |"<<endl;
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<"\t    |   2   "<<t.h2_p<<"M  "<<t.h2_r<<"M |"<<endl;
       cout<<"| 1.5 M  |             |---------|  |        |"<<"\t    |   3   "<<t.h3_p<<"M  "<<t.h3_r<<"M |"<<endl;
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |"<<"\t    |   4   "<<t.h4_p<<"M  "<<t.h4_r<<"M |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"\t    |--------------------|"<<endl;
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;

		cout<<"You have been awarded a free trip to New Delhi.\n";
		cout<<p.name<<", you are at New Delhi\n";
		if(t4.owner==0)
		{
		  t4.buy();
		}
		else if(t4.owner==p.no)
		{
		 t4.house();
		}
		else if(t4.owner==op.no)
		{
		 t4.payrent();
		}
		 break;
	  case 6: cout<<"An earthquake shattered all houses on your property.Pay 250 k for each house you own.\n";
		  p.balance-=(p.hc*0.25);
		  break;

	}
		 break;
	case 12:x5=5;
	show=1;
	roll1(s);
      cout<<p.name<<", you have just rolled a "<<s<<"\n";
      if(z==1)
      {
	cout<<p.name<<",you have just reached or passed GO. 1.5 M added to balance.\n";
	z=0;
      }
	cout<<p.name<<", you have been JAILED. Do not pass GO. \n";
		 if(chance==1)
		 a[p.pos]=' ';
		 else if(chance==2)
		 b[p.pos]=' ';
		 p.pos=4;
		 if(chance==1)
		 a[p.pos]=p.sym;
		 else if(chance==2)
		 b[p.pos]=p.sym;
	if(p.free==0)
	   p.balance-=0.25;
	else if(p.free==1)
	  {
	   cout<<p.name<<" you hauve used your 'GET OUT OF JAIL FREE ' card\n";
	   p.free=0;
	   getch();
	  }
		 break;
	case 13: show=1;
	 t=t8;
	roll(s);
      cout<<p.name<<", you have just rolled a "<<s<<"\n";
      if(z==1)
      {
	cout<<p.name<<",you have just reached or passed GO. 1.5 M added to balance.\n";
	z=0;
      }
	cout<<p.name<<", you are at ROME\n";
			if(t8.owner==0)
		{
		  t8.buy();
		}
		else if(t8.owner==p.no)
		{
		 t8.house();
		}
		else if(t8.owner==op.no)
		{
		 t8.payrent();
		}
		 break;
	case 14: show=1;
	t=t9;
	roll(s);
      cout<<p.name<<", you have just rolled a "<<s<<"\n";
      if(z==1)
      {
	cout<<p.name<<",you have just reached or passed GO. 1.5 M added to balance.\n";
	z=0;
      }
	cout<<p.name<<", you are at NEW YORK\n";
		 if(t9.owner==0)
		{
		  t9.buy();
		}
		else if(t9.owner==p.no)
		{
		 t9.house();
		}
		else if(t9.owner==op.no)
		{
		 t9.payrent();
		}
		 break;
	case 15:  show=1;
	t=t10;
	roll(s);
      cout<<p.name<<", you have just rolled a "<<s<<"\n";
      if(z==1)
      {
	cout<<p.name<<",you have just reached or passed GO. 1.5 M added to balance.\n";
	z=0;
      }
	cout<<p.name<<", you are at LONDON\n";
		if(t10.owner==0)
		{
		  t10.buy();
		}
		else if(t10.owner==p.no)
		{
		 t10.house();
		}
		else if(t10.owner==op.no)
		{
		 t10.payrent();
		}
		 break;
      }
      if(chance==1)
      {
       if(show==1&&pr==0)            //pr=if player paid rent
      {
       clrscr();
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<endl;
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<endl;
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"| TOKYO  |                          | SYDNEY |"<<endl;
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |"<<endl;
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |"<<endl;
       cout<<"|--------|   |--------|             |--------|"<<endl;
       cout<<"| CHANCE |                          | BERLIN |"<<endl;
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<endl;
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<endl;
       cout<<"|--------|             |---------|  |--------|"<<endl;
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<endl;
       cout<<"| 1.5 M  |             |---------|  |        |"<<endl;
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;
   show=0;
      }
      else if(show==1&&pr==1)
      {
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<endl;
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<endl;
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"\t    |--------------------|"<<endl;
       cout<<"| TOKYO  |                          | SYDNEY |"<<"\t    |     "<<setw(8)<<t.name<<"       |"<<endl;
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |"<<"\t    |--------------------|"<<endl;
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |"<<"\t    | BASE PRICE  "<<t.b_price<<" M |"<<endl;
       cout<<"|--------|   |--------|             |--------|"<<"\t    | BASE RENT   "<<t.b_rent<<" M |"<<endl;
       cout<<"| CHANCE |                          | BERLIN |"<<"\t    |--------------------|"<<endl;
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<"\t    | HOUSE  PRICE  RENT |"<<endl;
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<"\t    |  NO                |"<<endl;
       cout<<"|--------|             |---------|  |--------|"<<"\t    |   1   "<<t.h1_p<<"M  "<<t.h1_r<<"M |"<<endl;
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<"\t    |   2   "<<t.h2_p<<"M  "<<t.h2_r<<"M |"<<endl;
       cout<<"| 1.5 M  |             |---------|  |        |"<<"\t    |   3   "<<t.h3_p<<"M  "<<t.h3_r<<"M |"<<endl;
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |"<<"\t    |   4   "<<t.h4_p<<"M  "<<t.h4_r<<"M |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"\t    |--------------------|"<<endl;
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;
     show=0;
       pr=0;
      }
      if(x1==1)
      {
	cout<<"\n"<<p.name<<", you have successfully bought "<<t.name<<"\n";
       x1=0;
      }
      else if(x2==2)
      {
	cout<<"\nNO Problem.Have a good day.\n";
       x2=0;
      }
      else if(x3==3)
      {   if (chance==1)
	   cout<<"\n"<<p1.name<<",you have paid a rent of "<<t.rent<<" M to "<<p2.name<<endl;

       x3=0;
      }
      else if(x5==5)
      {
	  cout<<p.name<<",you have been jailed.DO not pass GO.Do not collect 1.5 M\n";
	  x5=0;
      }
      else if(bh==1)
      {
	  cout<<p.name<<",you have successfully built house no."<<t.hno<<" on "<<t.name<<endl;
	  bh=0;
      }
      if(p.balance<0)
       {
	 cout<<p.name<<", you have been bankrupt.But you can always try again some time.\n";
	 break;
       }
	 p1=p;
	 p2=op;
	 p=p2;
	 op=p1;
	 chance=2;
       }
    else if(chance==2)
    {
      if(show==1&&pr==0)            //pr=if player paid rent
      {
       clrscr();
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<endl;
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<endl;
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"| TOKYO  |                          | SYDNEY |"<<endl;
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |"<<endl;
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |"<<endl;
       cout<<"|--------|   |--------|             |--------|"<<endl;
       cout<<"| CHANCE |                          | BERLIN |"<<endl;
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<endl;
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<endl;
       cout<<"|--------|             |---------|  |--------|"<<endl;
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<endl;
       cout<<"| 1.5 M  |             |---------|  |        |"<<endl;
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;



       show=0;
      }
      else if(show==1&&pr==1)
      {
       cout<<"|--------|--------|--------|--------|--------|"<<endl;
       cout<<"|  JAIL  | PARIS  | DELHI  | MOSCOW |  FREE  |"<<endl;
       cout<<"|        | 2.5 M  | 2.5 M  | 3.0 M  |PARKING |"<<endl;
       cout<<"|  "<<a[4]<<"  "<<b[4]<<"  |  "<<a[5]<<"  "<<b[5]<<"  |  "<<a[6]<<"  "<<b[6]<<"  |  "<<a[7]<<"  "<<b[7]<<"  |  "<<a[8]<<"  "<<b[8]<<"  |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"\t    |--------------------|"<<endl;
       cout<<"| TOKYO  |                          | SYDNEY |"<<"\t    |     "<<setw(8)<<t.name<<"       |"<<endl;
       cout<<"| 2.0 M  |   |--------|             |  3.0 M |"<<"\t    |--------------------|"<<endl;
       cout<<"|  "<<a[3]<<"  "<<b[3]<<"  |   | CHANCE |             |  "<<a[9]<<"  "<<b[9]<<"  |"<<"\t    | BASE PRICE  "<<t.b_price<<" M |"<<endl;
       cout<<"|--------|   |--------|             |--------|"<<"\t    | BASE RENT   "<<t.b_rent<<" M |"<<endl;
       cout<<"| CHANCE |                          | BERLIN |"<<"\t    |--------------------|"<<endl;
       cout<<"|        |         MONOPOLY         |  3.5 M |"<<"\t    | HOUSE  PRICE  RENT |"<<endl;
       cout<<"|  "<<a[2]<<"  "<<b[2]<<"  |                          |  "<<a[10]<<"  "<<b[10]<<"  |"<<"\t    |  NO                |"<<endl;
       cout<<"|--------|             |---------|  |--------|"<<"\t    |   1   "<<t.h1_p<<"M  "<<t.h1_r<<"M |"<<endl;
       cout<<"|BEIJING |             |  CHEST  |  | CHEST  |"<<"\t    |   2   "<<t.h2_p<<"M  "<<t.h2_r<<"M |"<<endl;
       cout<<"| 1.5 M  |             |---------|  |        |"<<"\t    |   3   "<<t.h3_p<<"M  "<<t.h3_r<<"M |"<<endl;
       cout<<"|  "<<a[1]<<"  "<<b[1]<<"  |                          |  "<<a[11]<<"  "<<b[11]<<"  |"<<"\t    |   4   "<<t.h4_p<<"M  "<<t.h4_r<<"M |"<<endl;
       cout<<"|--------|--------|--------|--------|--------|"<<"\t    |--------------------|"<<endl;
       cout<<"|   GO   | LONDON |NEW YORK|  ROME  |  GO TO |"<<endl;
       cout<<"|+ 1.5 M |  5.0 M | 4.5 M  |  4.0 M |  JAIL  |"<<"       NAME         BALANCE"<<endl;
       cout<<"|  "<<a[0]<<"  "<<b[0]<<"  |  "<<a[15]<<"  "<<b[15]<<"  |  "<<a[14]<<"  "<<b[14]<<"  |  "<<a[13]<<"  "<<b[13]<<"  |  "<<a[12]<<"  "<<b[12]<<"  |"<<"       "<<setw(10)<<p.name<<"   "<<p.balance<<" M"<<endl;;
       cout<<"|--------|--------|--------|--------|--------|"<<"       "<<setw(10)<<op.name<<"   "<<op.balance<<" M"<<endl;


       show=0;
       pr=0;
      }
      if(x1==1)
      {
	cout<<"\n"<<p.name<<", you have successfully bought "<<t.name<<"\n";
       x1=0;
      }
      else if(x2==2)
      {
	cout<<"\nNO Problem.Have a good day.\n";
       x2=0;
      }
      else if(x3==3)
      {   if (chance==1)
	   cout<<"\n"<<p1.name<<",you have paid a rent of "<<t.rent<<" M to "<<p2.name<<endl;
	  else if(chance==2)
	   cout<<"\n"<<p2.name<<",you have paid a rent of "<<t.rent<<" M to "<<p1.name<<endl;
       x3=0;
      }
      else if(x5==5)
      {
	  cout<<p.name<<",you have been jailed.DO not pass GO.Do not collect 1.5 M\n";
	  x5=0;
      }
      else if(bh==1)
      {
	  cout<<p.name<<",you have successfully built house no."<<t.hno<<" on "<<t.name<<endl;
	  bh=0;
      }
      if(p.balance<0)
       {
	 cout<<p.name<<", you have been bankrupt.But you can always try again some time.\n";
	 break;
       }
	 p1=op;
	 p2=p;
	 p=p1;
	 op=p2;
	 chance=1;
    }

    cout<<"want to continue.press y to continue or press n to exit\n";
    cin>>ch1;
  }while(ch1=='y'||ch1=='Y');
  cout<<"Do you want to save your game(y/n)\n";
  cin>>d2;
  if(d2=='y')
    save();
cout<<endl<<"END OF GAME";
getch();
}
