#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

int r1=0,i1=0;

////// function to create borders ///////////

void box(int x, int y, int l, int b, char ch)
{
 for(int i=x;i<l;++i)
 {
  gotoxy(i,y);
  cout<<ch;
 }
 for(int j=y ;j<b;++j)
 {
  gotoxy(i,j);
  cout<<ch;
 }
 for(--x;y<b;++y)
 {
  gotoxy(x,y);
  cout<<ch;
 }
 for(++x,--y;x<l;++x)
 {
  gotoxy(x,y);
  cout<<ch;
 }
}

/*class
		defintion for customer details */

class guest
{
 char name[20],address[100];
 int room_no,id_no;
 float charges;
 float total_charge;
 long tel_no;
 char room_type;
 public:
 guest()
 {
	charges=0.0;
	total_charge=0.0;
 }
 void display()	 //can be used as checkout or printbill function
 {
  cout<<"ID number:"<<id_no;
  cout<<"\nName:"<<name;
  cout<<"\nAddress:"<<address;
  cout<<"\nTelephone number:"<<tel_no;
  cout<<"\nRoom number:"<<room_no;
  cout<<"\nTotal charge:"<<total_charge;
  cout<<"\nRoom Type:"<<room_type<<endl;
 }
 int getroomno()
 {
  return room_no;
 }
 char getroom_type()
 {
 return room_type;
 }
 int getidno()
 {
  return id_no;
 }
 void checkin();
 void putcharges()
{
 cout<<"Enter the total charge\n";       //include sum of all charges
 cin>>total_charge;
}
};

//function for checking existing room numbers and id numbers

void checkroidno(int r, int i)
{
 guest g;
 ifstream fin;
 fin.open("guest.dat",ios::app|ios::binary);
 clrscr();
 while(fin.read((char*)&g,sizeof(g)))
 {
  if(r==g.getroomno())
  {
	cout<<"Room Occupied\n";
	r1=1;
	i1=1;
  }
  if(i==g.getidno())
  {
	cout<<"ID number already assigned\n";
	r1=1;
	i1=1;
  }
 }
 fin.close();
}

/////// get details of customer /////////


 void guest::checkin()
 {
  cout<<"Name of customer\n";
  gets(name);
  cout<<"Address of customer\n";
  gets(address);
  cout<<"Telephone number\n";
  cin>>tel_no;
  cout<<"Allocate room type as\n";
  cin>>room_type;
  cout<<"Assign room number as\n";
  cin>>room_no;
  cout<<"Assign ID number as\n";
  cin>>id_no;
  checkroidno(room_no,id_no);
 }

 ////////// function to check number of specific rooms available /////////

void checkrooms()
{
 guest g;
 int e=10,l=10,s=10;
 ifstream fin;
 fin.open("guest.dat",ios::in|ios::binary);
 while(fin.read((char*)&g,sizeof(g)))
 {
  if(g.getroom_type()=='e')
  --e;
  else if(g.getroom_type()=='l')
  --l;
  else
  --s;
 }
fin.close();
cout<<e<<" enconomy rooms available\n";
cout<<l<<" luxury rooms available\n";
cout<<s<<" suites available\n";
}
void append()
{
 checkrooms();
 guest G;
 G.checkin();
 if(r1==0||i1==0)
 {
 ofstream fout;
 fout.open("guest.dat",ios::app|ios::binary);
 fout.write((char*)&G,sizeof(G));
 cout<<"Done!\n";
 fout.close();
 }
 else
  cout<<"Room number or ID number already assigned.. Try Again\n";
}

///////// search function with idno and roomno ////////

void search()
{
 next:
 clrscr();
 box(0,0,80,26,'*');
 box(14,5,69,22,'+');
 gotoxy(35,8);
 cout<<"Search with?\n";
 gotoxy(35,11);
 cout<<"1.ID number\n";
 gotoxy(35,13);
 cout<<"2.Room number\n";
 gotoxy(35,15);
 cout<<"3.Go back\n";
 char opt;
 gotoxy(48,19);
 cout<<"Enter the option _";
 gotoxy(65,19);
 opt=getch();
 guest g;
 ifstream fin;
 if(opt=='1')
 {
	clrscr();
	box(0,0,80,26,'*');
	box(14,5,69,22,'+');
	fin.open("guest.dat",ios::in|ios::binary);
	int ino;
	gotoxy(24,8);
	cout<<"Enter the ID number you want to search";
	gotoxy(24,9);
	cin>>ino;
	while(fin.read((char*)&g,sizeof(g)))
	{
	 if(ino==g.getidno())
	  g.display();
	}
	fin.close();
   cout<<"Press any key to go back\n";
	getch();
	goto next;
 }
 else if(opt=='2')
 {
	fin.open("guest.dat",ios::in|ios::binary);
	int rno;
	cout<<"Enter the room number number you want to search\n";
	cin>>rno;
	while(fin.read((char*)&g,sizeof(g)))
	{
	 if(rno==g.getroomno())
	 g.display();
	}
	fin.close();
 }

 else if(opt==8)
 return;
}

//////// main menu function starts //////////

 void menu()
{
 start:
 clrscr();
 box(0,0,80,26,'*');
 char opt;
 gotoxy(37,3);
 cout<<"MAIN MENU";
  box(13,5,35,10,'+');
  gotoxy(15,7);
  cout<<"1.Add new customer\n";
  box(48,5,66,10,'+');
  gotoxy(50,7);
  cout<<"2.Search with\n";
  box(13,12,35,17,'+');
  gotoxy(17,14);
  cout<<"3.Add charges\n";
  box(48,12,70,17,'+');
  gotoxy(49,14);
  cout<<"4.Proceed to billing\n";
  box(37,18,45,23,'+');
  gotoxy(38,20);
  cout<<"5.Exit\n";
  gotoxy(49,23);
  cout<<"Enter your option _";
  gotoxy(67,23);
  opt=getch();
  switch(opt)
  {
	case '1':
			 {
			 clrscr();
			 append();
			 break;
			 }
	case '2':
			 {
			 search();
			 clrscr();
			 break;
			 }
	case '3':
			 break;
	case '4':
			 break;
	case '5':
				exit(0);
				break;
	default:clrscr();
			 break;
  }
 goto start;
}

// void main() start //

void main()
{
 menu();
}