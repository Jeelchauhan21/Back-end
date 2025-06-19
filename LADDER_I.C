#include<stdio.h>
#include<conio.h>

void main()
{
	int rno,s1,s2,s3,total;
	double per;
	char sname[50];
	clrscr();

	printf("\Enter student name:");
	gets(sname);
	printf("\nEnter student roll no:");
	scanf("%d",&rno);
	printf("\nEnter marks of subject 1:");
	scanf("%d",&s1);
	printf("\nEnter marks of subject 2:");
	scanf("%d",&s2);
	printf("\nEnter marks of subject 3:");
	scanf("%d",&s3);

	total=s1+s2+s3;
	per=total/3;

	printf("\nName: %s",sname);
	printf("\nRoll no: %d",rno);
	printf("\nTotal :%d",total);
	printf("\nPercentage: %f",per);

	if(per>=80)
	{
		printf("\n *** Distinction ***");
	}
	else if(per>=60)
	{
		printf("\n*** First class ***");
	}
	else if(per>=40)
	{
		printf("\n*** Second class ***");
	}
	else if(per>=30)
	{
		printf("\n*** Pass class ***");
	}
	else
	{
		printf("\n*** FAIL ***");
	}


	getch();
}
