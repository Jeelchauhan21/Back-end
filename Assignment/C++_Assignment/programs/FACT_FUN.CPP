#include<iostream.h>
#include<conio.h>

int fact(int n)
{
	if(n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return n*fact(n-1);
	}
}

void main()
{
	int num;
	clrscr();

	cout<<"\n Enter Number :";
	cin>>num;

	cout<<"\n Factorial of  "<<num<<" is : " <<fact(num);

	getch();
}