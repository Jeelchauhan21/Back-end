#include<stdio.h>
#include<conio.h>

struct Student
{
	int rno,s1,s2,s3,total;
	double per;
	char *sname;
};

void main()
{
	struct Student s;
	clrscr();

	printf("\nENter student name : ");
	gets(s.sname);
	printf("\nEnter student roll no : ");
	scanf("%d",&s.rno);
	printf("\nEnter subject 1 marks :");
	scanf("%d",&s.s1);
	printf("\nEnter subject 2 marks :");
	scanf("%d",&s.s2);
	printf("\nEnter subjcet 3 marks :");
	scanf("%d",&s.s3);

	s.total=s.s1+s.s2+s.s3;
	s.per=s.total/3;

	printf("\n Student name is : %s ",s.sname);
	printf("\n Student rno is : %d",s.rno);
	printf("\n Student subject 1 marks : %d",s.s1);
	printf("\n student subject 2 marks : %d",s.s2);
	printf("\n Student subject 3 marks : %d",s.s3);
	printf("\n Total is : %d ",s.total);
	printf("\n Percentage is : %lf ",s.per);

	if(s.per>80)
	{
		printf("\n Distiction");
	}
	else if(s.per>70)
	{
		printf("\n First class");
	}
	else if(s.per>60)
	{
		printf("\n second class");
	}
	else if(s.per>50)
	{
		printf("\n Pass");
	}
	else
	{
		printf("\nFail");
	}

	getch();
}
