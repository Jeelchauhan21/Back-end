#include<stdio.h>
#include<conio.h>

void main()
{
	int num1,num2,ans,choice;
	char operatar;
	clrscr();

	printf("\n Enter number 1 :");
	scanf("%d",&num1);
	printf("\n Enter Oprater:");
	scanf(" %c",&operatar);
	printf("\n Enter Number 2:");
	scanf("%d",&num2);

	printf("\n Select Operation Which You want to perform\n");
	printf("\n + ADDITION +");
	printf("\n - SUBTRACTION -");
	printf("\n * MULTIPLICATION *");
	printf("\n / DIVISION /\n");

	printf("\n Enter Your Choice :");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			ans=num1+num2;
			printf("\n Addtion is : %d",ans);
			break;

		case 2:
			ans=num1-num2;
			printf("\n Subtraction is : %d",ans);
			break;

		case 3:
			ans=num1*num2;
			printf("\n Multiplication is : %d",ans);
			break;

		case 4:
			ans=num1/num2;
			printf("\n Division is : %d",ans);
			break;

		default:
			printf("\n Invalid Choice");
			break;
	}

	getch();
}


