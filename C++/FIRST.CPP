#include<iostream.h>
#include<conio.h>

class Student
{
	int rno;
	char *sname;
	double per;

	public:
		void getData()
		{
			cout<<"\nENter student roll no:";
			cin>>rno;
			cout<<"\nEnter student name:";
			cin>>sname;
			cout<<"\nEnter student percentage:";
			cin>>per;
		}
		void putData()
		{
			cout<<"\n student Roll no is :"<<rno;
			cout<<"\n Student Name is : "<<sname;
			cout<<"\n Percentage is :"<<per;
		}
};

void main()
{
	Student s1;
	clrscr();
	s1.getData();
	s1.putData();
	getch();
}