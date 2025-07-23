#include<iostream.h>
#include<conio.h>
#include<string.h>

void main()
{
	char *s1,*s2;
	int x;
	clrscr();

	cout<<"\n-:This program checks that given string is palindrome or not:-\n";

	cout<<"\nEnter String:";
	cin>>s1;
	strcpy(s2,s1);
	strrev(s1);
	x=strcmp(s1,s2);

	if(x==0)
	{
		cout<<"\n ** String is Palindrome **";
	}
	else
	{
		cout<<"\n ** String is not Palindrome **";
	}

	getch();
}