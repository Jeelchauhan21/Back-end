#include<iostream.h>
#include<conio.h>

class Calculator
{
	public:
		int add(int a,int b)
		{
			return a+b;
		}
		int sub(int a,int b)
		{
			return a-b;
		}
		int mul(int a,int b)
		{
			return a*b;
		}
		int div(int a,int b)
		{
			if(b==0)
			{
				cout<<"\n Error:not divide by zero";
				return 0;
			}
			else
			{
				return a/b;
			}
		}
};

void main()
{
	clrscr();
	int x,y;
	Calculator c;

	cout<<"\n -> Enter two numbers:";
	cin>>x>>y;

	cout<<"\n ** Result ** \n";

	cout<<"\n * Addition : "<<c.add(x,y);
	cout<<"\n * Subtraction : "<<c.sub(x,y);
	cout<<"\n * Multiplication : "<<c.mul(x,y);
	cout<<"\n * Division : "<<c.div(x,y);

	getch();
}