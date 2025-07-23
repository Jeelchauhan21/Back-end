/*write a c program to check if a number is even or odd using
if-else statement.extend the program using switch statement to display
the month name based on the users input.*/

#include<stdio.h>
#include<conio.h>

void main()

{
	int no,month;
	clrscr();

	printf("\n Enter one number to check number is odd or even:");
	scanf("%d",&no);

	if(no%2==0)
	{
		printf("\n Number is even\n");
	}
	else
	{
		printf("\n Number is odd\n");
	}

	printf("\n Enter any number\n");
	scanf("%d",&month);

	switch(month)
	{
		case 1:
			printf("\n Jan");
			break;
		case 2:
			printf("\n Feb");
			break;

		case 3:
			printf("\n March");
			break;

		case 4:
			printf("\n April");
			break;

		case 5:
			printf("\n May");
			break;

		case 6:
			printf("\n June");
			break;
		case 7:
			printf("\n July");
			break;
		case 8:
			printf("\n August");
			break;
		case 9:
			printf("\n September");
			break;
		case 10:
			printf("\n October");
			break;

		case 11:
			printf("\n November");
			break;

		case 12:
			printf("\n December");
			break;

		default:
			printf("\n invalid number");
	 }

	getch();
}
