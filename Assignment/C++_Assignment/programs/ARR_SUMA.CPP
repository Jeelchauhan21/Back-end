#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();
	int arr[10],i;
	int sum=0;
	float avg;


	cout<<"\n Enter Elements\n";

	for(i=0;i<10;i++)
	{
		cout<<"Enter Element "<<i+1<<":";
		cin>>arr[i];
		sum=sum+arr[i];
	}

	avg=sum/10;

	cout<<"\n Sum of N number is :"<<sum;
	cout<<"\n Average of Sum is :"<<avg;

	getch();
}
