#include<iostream.h>
#include<conio.h>

void main()
{
	char *sname;
	int rno,marks;
	clrscr();

	cout<<"-: Enter Students Details :-";

	cout<<"\n Enter Student Name:";
	cin>>sname;
	cout<<"\n Enter Student Roll.no:";
	cin>>rno;
	cout<<"\n Enter Student Marks:";
	cin>>marks;

	cout<<"\n-: Details Of Students :-\n";
	cout<<"\n Name Of Student is :"<<sname;
	cout<<"\n Roll.no Of Student is :"<<rno;
	cout<<"\n Marks Of Student is :"<<marks;

	if(marks>=90)
	{
		cout<<"\n* Grade A *";
	}
	else if(marks>=70)
	{
		cout<<"\n* Grade B *";
	}
	else if(marks>=60)
	{
		cout<<"\n* Grade c *";
	}
	else if(marks>=40)
	{
		cout<<"\n* Pass *";
	}
	else
	{
		cout<<"\n* Fail *";
	}


	getch();
}