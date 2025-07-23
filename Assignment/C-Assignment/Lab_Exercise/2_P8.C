
#include<stdio.h>
#include<conio.h>

int factorial(int n)
{
	if(n==0)
	{
		return 1;
	}
	return n*factorial(n-1);
}

void main()
{
	int n,fact;
	clrscr();

	printf("\nEnter N number :");
	scanf("%d",&n);

       fact=factorial(n);

	printf("\n Factorial of N=[%d] number  is : %d",n,fact);

	getch();

}