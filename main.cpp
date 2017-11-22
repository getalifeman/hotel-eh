// header files required

#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

int r1=0,i1=0; //global variables

void menu();

//////// function to produce delay ////////

void delay()
{
 for(long l=0;l<=9599999999;++l);
}

//////// function to create borders ////////

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

/* class defintion
	       for password management */

class pwd_mng
{
 private:
 char usn[30];
 char pwd[30];
 public:

 void create_acc();

 char* getuser()
 {
  return usn;
 }

 char* getpwd()
 {
  return pwd;
 }
};

//////// function to create an account ////////////

void pwd_mng :: create_acc()
{
 gotoxy(20,10);
 cout<<"Create Username:";
 gets(usn);
 gotoxy(20,12);
 cout<<"Create Password:";
 gotoxy(36,12);
 int x=35;
 int i=0;
 char ch;
 ch = getch();
 n: if(ch != 13)
 {
  ++x;
  if(ch==8)
  {
	pwd[i-1]=pwd[i];
	--i;
	gotoxy(x-1,12);
	cout<<" ";
	gotoxy(x-1,12);
	ch=getch();
  }
  pwd[i]=ch;
  cout << '*';
  ch=getch();
  ++i;
  goto n;
}

pwd[i]='\0';
}

////////// function for login ////////////

void login()
{
 again:
 clrscr();
 box(0,2,80,26,'*');
 char user[30], pass[30];
 pwd_mng p;
 ifstream fin;
 fin.open("pwd.dat",ios::binary);
 gotoxy(20,10);
 cout<<"Username:";
 gets(user);
 gotoxy(20,12);
 cout<<"Password:";
 gotoxy(29,12);
 int x=28;
 int i=0;
 char ch;
 ch = getch();
 n: if(ch != 13)
 {
	++x;
	if(ch==8)
	{
	 pass[i-1]=pass[i];
	 --i;
	 gotoxy(x-1,12);
	 cout<<" ";
	 gotoxy(x-1,12);
	 ch=getch();
	}
 pass[i]=ch;
 cout << '*';
 ch=getch();
 ++i;
 goto n;
}
pass[i]='\0'; //assigning null character at the end 
 while(fin.read((char*)&p,sizeof(p)))
 {
  if( strcmp(p.getuser(),user)==0 && strcmp(p.getpwd(),pass)==0 )
	{
	 gotoxy(38,20);
	 cout<<"Access granted";
	 delay();
	 menu();
	}
  else
   {
	gotoxy(38,20);
	cout<<"Access revoked... Try again!";
	delay();
	goto again;
  }
 }
 fin.close();
}

///////////// start program function //////////////

void start_prgm()
{
 box(0,2,80,26,'*');
 char str[100]="Welcome to Hotel Pydrium";
 gotoxy(24,12);
 for(int i=0; str[i]!= '\0';++i)
 {
   cout<<str[i];
 }
 getch();
 clrscr();
 box(0,2,80,26,'*');
 pwd_mng P;
 ofstream fout;
 ifstream fin;
 fin.open("pwd.dat",ios::in|ios::binary);
 fout.open("temp.dat",ios::out|ios::binary);
 if(!fin)
 {
   P.create_acc();
   fout.write((char*)&P,sizeof(P));
   fout.close();
   rename("temp.dat","pwd.dat");
   exit(0);
 }
 else
 {
   fin.close();
   login();
 }
}


/*class
       defintion for customer details */

class guest
{
 char name[20],address[100];

 int room_no,id_no;

 float total_charge;

 long tel_no;

 char room_type;

 public:

 guest()             // constructor to initialise values
 {
  total_charge=0.0;
 }

 void checkin(); //prototype for getting details function

 void addspa_charge();              /* bunch of prototypes for
																			 assigning charges */
 void addgym_charge();

 void addsnack_charge();

 void addint_charge();

 //////// display details of customer ////////

 void display()
 {
   clrscr();
   box(0,2,80,26,'*');
   box(14,5,69,22,'+');
   gotoxy(15,7);
   cout<<"ID number:"<<id_no;
   gotoxy(15,9);
   cout<<"Name:"<<name;
   gotoxy(15,11);
   cout<<"Address:"<<address;
   gotoxy(15,13);
   cout<<"Telephone number:"<<tel_no;
   gotoxy(15,15);
   cout<<"Room number:"<<room_no;
   gotoxy(15,17);
   cout<<"Total charge:"<<total_charge;
   gotoxy(15,19);
   cout<<"Room Type:"<<room_type<<endl;
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
};

//////// individual function declarations for assigning charges ////////

void guest :: addspa_charge()
{

 clrscr();
 box(0,2,80,26,'*');
 box(14,5,69,22,'+');
 gotoxy(16,7);
 cout<<"The rate is 10 BHD";
 gotoxy(16,9);
 cout<<"Press any key to continue or backspace to go back";
 char ch = getch();
 if(ch==8)
  return;
 else
  total_charge+=10;
}

void guest :: addgym_charge()
{
 clrscr();
 box(0,2,80,26,'*');
 box(14,5,69,22,'+');
 gotoxy(16,7);
 cout<<"The rate is 5 BHD";
 gotoxy(16,9);
 cout<<"Press any key to continue or backspace to go back";
 char ch = getch();
 if(ch==8)
  return;
 else
  total_charge+=5;
}

void guest :: addsnack_charge()               // will add submenu later
{
  return;
}

void guest :: addint_charge()
{
 clrscr();
 box(0,2,80,26,'*');
 box(14,5,69,22,'+');
 gotoxy(16,7);
 cout<<"The rate is 2 BHD";
 gotoxy(16,9);
 cout<<"Press any key to continue or backspace to go back";
 char ch = getch();
 if(ch==8)
  return;
 else
  total_charge+=2;
}

//////// function to call functions and assign relevant charges ////////

void charges()
{
  now:
  clrscr();
  box(0,2,80,26,'*');
  box(14,5,69,22,'+');
  guest g;
  gotoxy(30,8);
  cout<<"Enter the room number:";
  int room;
  cin>>room;
  clrscr();
  box(0,2,80,26,'*');
  box(14,5,69,22,'+');
  fstream file;
  file.open("guest.dat",ios::out|ios::in|ios::binary);
  while(file.read((char*)&g,sizeof(g)))
  {
   if(room==g.getroomno())
   {
	gotoxy(16,7);
	cout<<"1. Add spa charge";
	gotoxy(16,9);
	cout<<"2. Add gym charge";
	gotoxy(16,11);
	cout<<"3. Add snack charge";
	gotoxy(16,13);
	cout<<"4. Add WiFi usage charge";
	gotoxy(16,15);
	cout<<"5. Go back";
	gotoxy(45,19);
	cout<<"Enter your option";
	char opt=getch();
	switch(opt)
	{
	  case '1' :                    file.seekp((-1)*sizeof(g),ios::cur);
	 			        g.addspa_charge();
	  	   			file.write((char*)&g,sizeof(g));
					break;
	  case '2' :                    file.seekp((-1)*sizeof(g),ios::cur);
					g.addgym_charge();
					file.write((char*)&g,sizeof(g));
					break;
          case '3' :                    file.seekp((-1)*sizeof(g),ios::cur);
					g.addsnack_charge();
					file.write((char*)&g,sizeof(g));
					break;
	  case '4' :                    file.seekp((-1)*sizeof(g),ios::cur);
					g.addint_charge();
					file.write((char*)&g,sizeof(g));
					break;
	 case '5' :                     return;

	 default  :                     clrscr();
					box(0,2,80,26,'*');
					box(14,5,69,22,'+');
					gotoxy(30,12);
					cout<<"Wrong choice... Try Again!";
					delay();
					goto now;
	 }
	}
  }
  file.close();
  goto now;
 }

//////// function for checking existing room numbers and id numbers ////////

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

//////// get details of customer ////////


 void guest :: checkin()
 {
   gotoxy(12,3);
   cout<<"Name of customer:";
   gets(name);
   gotoxy(12,5);
   cout<<"Address of customer:";
   gets(address);
   gotoxy(12,7);
   cout<<"Telephone number:";
   cin>>tel_no;
   gotoxy(12,9);
   cout<<"Allocate room type as:";
   cin>>room_type;
   gotoxy(12,11);
   cout<<"Assign room number as:";
   cin>>room_no;
   gotoxy(12,13);
   cout<<"Assign ID number as:";
   cin>>id_no;
   checkroidno(room_no,id_no);
 }

//////// function to check number of specific rooms available ////////

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
  if(e<0)
  {
   	gotoxy(29,5);
	cout<<"No economy rooms available";
  }
  else
  {
        gotoxy(29,5);
        cout<<e<<" economy rooms available";
  }
  if(l<0)
  {
	gotoxy(29,7);
	cout<<"No luxury rooms available";
  }
  else
  {
        gotoxy(29,7);
        cout<<l<<" luxury rooms available\n";
  }
 if(s<0)
 {
	gotoxy(29,9);
	cout<<"No suites available";
 }
 else
 {
        gotoxy(29,9);
        cout<<s<<" suites available\n";
 }
}

//////// function to add records ////////

void append()
{
 box(0,2,80,26,'*');
 checkrooms();
 gotoxy(10,11);
 cout<<"Book record?.. press any key to continue or backspace to go back";
 char ch=getch();
 if(ch!=8)
 {
  clrscr();
  box(0,0,80,26,'*');
  guest G;
  G.checkin();
  if(r1==0||i1==0)
  {
	ofstream fout;
	fout.open("guest.dat",ios::app|ios::binary);
	fout.write((char*)&G,sizeof(G));
	fout.close();
  }
  else
	{
	 box(0,2,80,26,'*');
	 gotoxy(11,11);
	 cout<<"Room number or ID number already assigned.. Try Again\n";
	 delay();
	}
 }
 return;
}

//////// search function with idno and roomno ////////

void search()
{
 next:
 clrscr();
 box(0,2,80,26,'*');
 box(14,5,69,22,'+');
 gotoxy(35,8);
 cout<<"Search with?\n";
 gotoxy(35,11);
 cout<<"1.ID number";
 gotoxy(35,13);
 cout<<"2.Room number";
 gotoxy(35,15);
 cout<<"3.Go back";
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
	box(0,2,80,26,'*');
	box(14,5,69,22,'+');
	fin.open("guest.dat",ios::in|ios::binary);
	int ino;
	gotoxy(24,8);
	cout<<"Enter the ID number you want to search:";
	cin>>ino;
	while(fin.read((char*)&g,sizeof(g)))
	{
	 if(ino==g.getidno())
	  g.display();
	}
	fin.close();
	gotoxy(40,20);
	cout<<"Press any key to go back";
	getch();
	goto next;
 }
 else if(opt=='2')
 {
	clrscr();
	box(0,2,80,26,'*');
	box(14,5,69,22,'+');
	fin.open("guest.dat",ios::in|ios::binary);
	int rno;
	gotoxy(18,8);
	cout<<"Enter the room number number you want to search:";
	cin>>rno;
	while(fin.read((char*)&g,sizeof(g)))
	{
	 if(rno==g.getroomno())
	 g.display();
	}
	fin.close();
	gotoxy(40,20);
	cout<<"Press any key to go back";
	getch();
	goto next;
 }

 else if(opt==8)
 return;
}

//////// main menu function starts ////////

 void menu()
{
 start:
 clrscr();
 box(0,2,80,26,'*');
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
	case '1':        clrscr();
			 append();
			 break;
			 
	case '2':	 search();
			 clrscr();
			 break;
		  
	case '3':        charges();
			 break;
		  
	case '4':	 clrscr();
			 box(0,2,80,26,'*');
			 box(14,5,69,22,'+');
			 gotoxy(18,8);
		         int room;
			 cout<<"Enter the room number:";
			 cin>>room;
			 guest g;
		         ifstream fin;
			 fin.open("guest.dat",ios::in|ios::binary);
			 while(fin.read((char*)&g,sizeof(g)))
			 {
			    if(room==g.getroomno())
		  	    g.display();
			 }
			 gotoxy(40,4);
			 cout<<"BILL";
		         fin.close();
			 gotoxy(40,20);
			 cout<<"Press any key to print bill";
			 getch();
		         delay();
			 break;
			 
	case '5':        clrscr();
	                 box(0,2,80,26,'*');
	   	         gotoxy(27,12);
			 cout<<"Thank You for using the program!";
			 exit(0);
	 	         break;
				
	default:         clrscr();
			 break;
		  
  }
 goto start;
}

//////// execution start point /////////

void main()
{
 start_prgm();
}
