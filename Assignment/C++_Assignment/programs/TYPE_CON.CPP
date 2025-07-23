#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();

	int a=10;
	float b=a;

	float x=12.75;
	int y=(int)x;

	cout<<"\n-:Implicit conversion:-\n";
	cout<<"\n-> Origin int a ="<<a;
	cout<<"\n-> Converted float b ="<<b;

	cout<<"\n\n-:Explicit Conversion:-\n";
	cout<<"\n-> Origin Float x ="<<x;
	cout<<"\n-> Convert Int y ="<<y;

	getch();
}

