/*write a c program that uses the break statement to stop printing numbers
 when it reaches 5.Modify the program to skip printing the number 3 using
 the continue statement.*/


#include<stdio.h>
#include<conio.h>

void main()
{
	int i;
	clrscr();

	for(i=0;i<10;i++)
	{
		if(i==5)
		{
			break;
		}
		else if(i==3)
		{
			continue;
		}
		else
		{
			printf("\n%d",i);
		}
	}


	getch();
}