#include<stdio.h>
#include<conio.h>

void main()
{

	int a,b,c;
	clrscr();

	printf("\nEnter value of A,b & c:");
	scanf("%d %d %d",&a,&b,&c);

	if(a>b)
	{
		if(a>c)
		{
			printf("\nA is MAX");
		}
		else
		{
			printf("\nC is MAX");
		}
	}
	else
	{
		if(b>c)
		{
			printf("\nB is MAX");
		}
		else
		{
			printf("\nC is MAX");
		}
	}
	getch();
}