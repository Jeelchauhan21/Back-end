#include<iostream.h>
#include<conio.h>

class Person
{
	char name[50];
	int age;
	public:
		void getDetails()
		{
			cout<<"\n Enter Name:";
			cin>>name;
			cout<<"\n Enter Age:";
			cin>>age;
		}
		void showDetails()
		{
			cout<<"\n Name is :"<<name;
			cout<<"\n Age  is :"<<age;
		}
};

class Student:public Person
{
	int rno;
	char course[50];
	public:
		void getStudentdetails()
		{
			getDetails();
			cout<<"\n Enter Roll.no:";
			cin>>rno;
			cout<<"\n Enter Course Name:";
			cin>>course;
		}
		void showStudentdetails()
		{
			showDetails();
			cout<<"\n Roll.no is:"<<rno;
			cout<<"\n Course is:"<<course;
		}
};

class Teacher:public Person
{
	float sal;
	char *dept;
	public:
		void getTeacherdetails()
		{
			getDetails();
			cout<<"\n Enter Teacher Department:";
			cin>>dept;
			cout<<"\n Enter Teacher Salary:";
			cin>>sal;
		}
		void showTeacherdetails()
		{
			showDetails();
			cout<<"\n Department of Teacher:"<<dept;
			cout<<"\n Salary of teacher:"<<sal;
		}
};

void main()
{
	clrscr();
	Teacher t;
	Student s;

	cout<<"\n**Enter Information Of Student**\n";
	s.getStudentdetails();

	cout<<"\n **Enter Information Of Teacher**";
	t.getTeacherdetails();

	cout<<"\n **Information Of Student**";
	s.showStudentdetails();

	cout<<"\n **Information Of teacher**";
	t.showTeacherdetails();

	getch();
}