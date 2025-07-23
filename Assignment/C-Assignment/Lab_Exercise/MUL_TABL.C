#include<stdio.h>
#include<conio.h>

void main()
{
	int i,n,ans,range,j;
	clrscr();

	printf("\n Enter number to give its multiplication table:");
	scanf("%d",&n);
	printf("\n Enter range if you want print table till that:");
	scanf("%d",&range);

	if(range==0)
	{
		for(i=1;i<=10;i++)

		{
			ans=n*i;
			printf("\n %d * %d = %d ",n,i,ans);
		}
	}
	else
	{
		for(j=1;j<=range;j++)
		{
			ans=n*j;
			printf("\n %d * %d = %d ",n,j,ans);

		}
	}

	getch();
}