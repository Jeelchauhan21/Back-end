#include<stdio.h>
#include<conio.h>

void main()
{

	int rno,marks;
	char *sname;
	clrscr();

	printf("\n -:Enter Students Details:-\n");

	printf("\n Enter Student Name:");
	gets(sname);
	printf("\n Enter Student Roll.no:");
	scanf("%d",&rno);
	printf("\n Enter Student Marks:");
	scanf("%d",&marks);

	printf("\n -:Student Details:-\n");

	printf("\n Student Roll.no is : %d",rno);
	printf("\n Student Name is : %s",sname);
	printf("\n Student Marks is : %d",marks);

	if(marks>90)
	{
		printf("\n *** Grade A ***");
	}
	else if(marks>75 && marks<=90)
	{
		printf("\n *** Grade B ***");
	}
	else if(marks>50 && marks<=75)
	{
		printf("\n *** Grade C ***");
	}
	else if(marks<=50)
	{
		printf("\n *** Grade D ***");
	}
	else
	{
		printf("\n *** Fail ***");
	}

	getch();
}

