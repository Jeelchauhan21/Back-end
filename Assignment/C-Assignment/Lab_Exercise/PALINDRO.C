#include<stdio.h>
#include<conio.h>

int palindrome(int num)
{
	int reversed=0,original=num;

	while(num>0)
	{
		int digit=num %10;
		reversed=reversed * 10 + digit;
		num/=10;
	}
	return (original==reversed);
}

void main()
{
	int number;
	clrscr();

	printf("\nEnter a number:");
	scanf("%d",&number);

	if(palindrome(number))
	{
		printf("%d is palindrome ",number);
	}
	else
	{
		printf("%d is not a palindrome",number);
	}

	getch();
}