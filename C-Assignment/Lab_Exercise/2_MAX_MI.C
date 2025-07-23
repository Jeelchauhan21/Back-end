#include<stdio.h>
#include<conio.h>

void main()
{
	int arr[10],i,j,maximum,minimum,temp;
	clrscr();

	for(i=0;i<10;i++)
	{
		printf("\nEnter Arr[%d]:",i);
		scanf("%d",&arr[i]);
	}

	for(i=0;i<10;i++)
	{
		printf("\n Arr[%d] of value is : %d",i,arr[i]);
	}
	printf("\n");

	//This code is for finding maximum and minimum value from the array.
	for(i=0;i<=10;i++)
	{
		for(j=i+1;j<=10;j++)
		{
			if(arr[i]>maximum)
			{
				maximum=arr[i];
			}
		}
	}
	printf("\n ****************************************\n");
	printf("\n Maximum value is : %d\n",maximum);


	for(i=0;i<=10;i++)
	{
		for(j=i+1;j<=10;j++)
		{
			if(arr[i]<minimum)
			{
				minimum=arr[i];
			}
		}
	}
	printf("\n Minimum value is : %d\n",minimum);
	printf("\n ****************************************\n");

	//This code for ascending order.

	for(i=0;i<=10;i++)
	{
		for(j=i+1;j<=10;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}

	printf("\n-: Array Elements in Ascending Order :-\n");
	for(i=0;i<10;i++)
	{
	printf("\n ARRAY[%d]  : %d",i,arr[i]);
	}


	printf("\n ****************************************\n");
	getch();
}

