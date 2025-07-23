#include<iostream.h>
#include<conio.h>

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
	return a/b;
}

void main()
{
	int x,y,ans;
	char opr;
	clrscr();

	cout<<"\n Enter First Num:";
	cin>>x;
	cout<<"\n Enter Operation sign:";
	cin>>opr;
	cout<<"\n Enter Second Num:";
	cin>>y;

	switch(opr)
	{
		case '+':
			cout<<"\n Additon is :"<<add(x,y);
			break;

		case '-':
			cout<<"\n Subtraction is:"<<sub(x,y);
			break;

		case '*':
			cout<<"\n Multlication is:"<<mul(x,y);
			break;

		case '/':
			cout<<"\n Division is:"<<div(x,y);
			break;

		default:
			cout<<"\n Invalid option";
			break;
	}

	getch();
}
