#include<stdio.h>
#include<conio.h>


void main()
{
	int i,n=1,no=1;
	clrscr();

	printf("\n This is use of for loop");

	for(i=0;i<=10;i++)
	{
		printf("\n %d",i);
	}

	printf("\nThis is use of while loop");

	while(n<11)
	{
		printf("\n %d",n++);
	       //n++;
	}

	printf("\n This is use of do while loop");

	do{
		printf("\n %d",no);
		no++;
	}while(no<11);

	getch();
}