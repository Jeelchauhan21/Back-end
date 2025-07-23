#include<iostream.h>
#include<conio.h>

int x=100;  //its Global variable

void showGlobal()
{
	cout<<"\n Its Global variable :"<<x;
}
void showLocal()
{
	int y=50;  //its local variable
	cout<<"\n Its Local variable :"<<y;
}

void main()
{
	clrscr();

	showGlobal();
	showLocal();

	getch();
}