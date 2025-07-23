#include<stdio.h>
#include<conio.h>

void main()
{
	int i,n,prime=1;
	clrscr();

	printf("\nEnter Number :");
	scanf("%d",&n);

	if(n<=1)
	{
	      prime=0;
	}
	else
	{

		for(i=2;i<=n/2;i++)
		{
			if(n % i == 0)
			{
			prime=0;
			break;
			}
		}
	}

	if(prime)
	{
		printf("\n %d is a prime ",n);
	}
	else
	{
		printf("\n %d is not a prime number.",n);
	}

	getch();
}