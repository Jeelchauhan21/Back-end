#include<iostream.h>
#include<conio.h>

void main()
{
	int m1[2][2],m2[2][2],sum[2][2],i,j;
	clrscr();

	cout<<"\n Enter Elments of M1:\n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			cout<<"Enter["<<i<<"]["<<j<<"]";
			cin>>m1[i][j];
		}
	cout<<"\n";
	}
	cout<<"\n Enter Elments of M2:\n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			cout<<"Enter["<<i<<"]["<<j<<"]";
			cin>>m2[i][j];
		}
	cout<<"\n";
	}

	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			sum[i][j]=m1[i][j]+m2[i][j];
		}
	cout<<"\n";
	}

	cout<<"\n-: Matrix Of M1 :-\n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			cout<<"\t "<<m1[i][j];
		}
	cout<<"\n";
	}

	cout<<"\n-: Matrix Of M2 :-\n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			cout<<"\t "<<m2[i][j];
		}
	cout<<"\n";
	}

	cout<<"\n-: Sum Of 2 Matrix :-\n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			cout<<"\t "<<sum[i][j];
		}
	cout<<"\n";
	}


	getch();
}


