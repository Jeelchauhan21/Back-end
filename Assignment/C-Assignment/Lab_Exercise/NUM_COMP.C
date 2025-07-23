#include<stdio.h>
#include<conio.h>

void main()
{
	int num1,num2,num3,largest,smallest;
	clrscr();

	printf("\nEnter num1,num2 & num3 :");
	scanf("%d %d %d",&num1,&num2,&num3);

	if(num1 > num2 && num1 > num3)
	{
		largest = num1;
	}
	else if(num2 > num3 && num2 > num1)
	{
		largest=num2;
	}
	else if(num3 > num1 && num3 > num2)
	{
		largest=num3;
	}
	else
	{
		printf("\n Invalid value");
	}

	if(num1 < num2 && num1 < num3)
	{
		smallest = num1;
	}
	else if(num2 < num3 && num2 < num1)
	{
		smallest=num2;
	}
	else if(num3 < num1 && num3 < num2)
	{
		smallest=num3;
	}
	else
	{
		printf("\n Invalid value");
	}

	printf("\n *** Result ***");
	printf("\n Largest value : %d",largest);
	printf("\n Smallest Value : %d",smallest);

	getch();
}