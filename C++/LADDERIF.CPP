#include<iostream.h>
#include<conio.h>

void main()
{
	int a,b,c;
	clrscr();

	cout<<"\n Enter A:";
	cin>>a;
	cout<<"\n Enter B :";
	cin>>b;
	cout<<"\n Enter C :";
	cin>>c;

	if(a>b)
	{
		if(b>c)
		{
		cout<<"\n A is Max";
		}
		else
		{
		cout<<"\n C is Max";
		}
	}
	else if(b>c)
	{
		cout<<"\n B is Max";
	}
	else
	{
		cout<<"\n C is Max";
	}

	getch();
}