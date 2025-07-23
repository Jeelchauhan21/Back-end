#include	<stdio.h>
#include<conio.h>

void main()
{
	int m1[2][2],m2[2][2],sum[2][2],a[3][3],b[3][3],c[3][3],i,j;
	clrscr();

	printf("\n-: Enter First Matrix M1 :-");

	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("\n Enter M1[%d][%d] :",i,j);
			scanf("%d",&m1[i][j]);
		}
	printf("\n");
	}

	printf("\n-: Enter Second Matrix M2 :-");

	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("\n Enter M2[%d][%d] :",i,j);
			scanf("%d",&m2[i][j]);
		}
	printf("\n");
	}

	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			sum[i][j]=m1[i][j]+m2[i][j];
		}
	printf("\n");
	}

	printf("\n ****************************************\n");
	printf("\n -:Result Of M1:-\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("\t %d",m1[i][j]);
		}
	printf("\n");
	}

	printf("\n -:Result Of M2:-\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("\t %d",m2[i][j]);
		}
	printf("\n");
	}

	printf("\n -:Sum Of M1 & M2:-\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("\t %d",sum[i][j]);
		}
	printf("\n");
	}

	printf("\n ****************************************\n");

	//This is code for 3*3 matrix.

	printf("\n-: Enter A :-\n");

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\n Enter A[%d] : ",i);
			scanf("%d",&a[i][j]);
		}
	printf("\n");
	}

	printf("\n-: Enter B :-\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\n Enter B[%d] : ",i);
			scanf("%d",&b[i][j]);
		}
	printf("\n");
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=a[i][j]*b[i][j];
		}
	printf("\n");
	}

	printf("\n ****************************************\n");
	printf("\n -:Elmenets Of A:-\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t %d",a[i][j]);
		}
	printf("\n");
	}

	printf("\n -:Elmenets Of B:-\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t %d",b[i][j]);
		}
	printf("\n");
	}

	printf("\n -:Sum Of A & B:-\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("\t %d",c[i][j]);
		}
	printf("\n");
	}

	printf("\n ****************************************\n");
	getch();
}
