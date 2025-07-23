#include<iostream.h>
#include<conio.h>

void main()
{
	int age;
	char sname[10];
	clrscr();

	cout<<"\n -:Enter Student Details:-";

	cout<<"\n Enter Student Name:";
	cin>>sname;
	cout<<"\n Enter Student Age:";
	cin>>age;

	cout<<"\n Hello! "<<sname<<" You are "<<age<<" Years old";

	getch();
}