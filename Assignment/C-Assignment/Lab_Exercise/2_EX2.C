#include<stdio.h>
#include<conio.h>

void main()
{
	int num;
	clrscr();

	printf("\n Enter one number:");
	scanf("%d",&num);


	if(num%2==0)
	{
		printf("\n Number is even");
	}
	else
	{
		printf("\n Number is odd");
	}

	if(num<0)
	{
	       printf("\n Number is Negative");
	}
	else if(num>0)
	{
		printf("\n Number is positive");
	}
	else
	{
		printf("\n Number is Zero");
	}

	if(num%3==0 && num%5==0)
	{
		printf("\n Number is multiple of both 3 and 5");
	}
	else
	{
		printf("\n Number is not multiple of 3 and 5");
	}


	getch();
}
