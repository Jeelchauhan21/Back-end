#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
	char *s1,*s2;
	int length;
	clrscr();

	printf("\nEnter First String : ");
	gets(s1);
	printf("\nEnter Second String:");
	gets(s2);


	printf("\n First String is : %s",s1);
	printf("\n Second String is : %s",s2);

	strcat(s1,s2);

	printf("\n After concate Both string result is : %s",s1);

       length=strlen(s1);
	printf("\n Length of String is : %d",length);


	getch();
}