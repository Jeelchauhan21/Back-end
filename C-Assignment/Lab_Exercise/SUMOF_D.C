#include<stdio.h>
#include<conio.h>

void main()
{
	int n,sum=0;
	clrscr();

	printf("\n Enter N :");
	scanf("%d",&n);

	while(n>0)
	{
		sum=sum+n;
		n--;
	}

	printf("\n Sum : %d",sum);

	getch();
}