#include<stdio.h>
#include<conio.h>

void main()
{
	int a[5],i,j,m1[3][3],m2[3][3],sum[3][3];
	clrscr();


	for(i=0;i<5;i++)
	{
		printf("\nEnter Element :");
		scanf("%d",&a[i]);
	}

	for(i=0;i<5;i++)
	{
		printf("\n Elment of a[%d] is : %d",i,a[i]);
	}
	printf("\n Enter matrix one values");

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\n Enter Row[%d],and column[%d] : ",i,j);
			scanf("%d",&m1[i][j]);
		}
		printf("\n");
	}

	printf("\n Enter matrix 2 values");

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\n Enter Row[%d],and column[%d] : ",i,j);
			scanf("%d",&m2[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			sum[i][j]=m1[i][j]+m2[i][j];
		}
		printf("\n");
	}

	printf("\n value of matrix 1\n\n");

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t %d",m1[i][j]);
		}
		printf("\n");
	}

	printf("\n value of matrix 2\n\n");

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t %d",m2[i][j]);
		}
		printf("\n");
	}


	printf("\nSum of two matrix\n\n");

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t %d",sum[i][j]);
		}
		printf("\n");
	}





	getch();
}

