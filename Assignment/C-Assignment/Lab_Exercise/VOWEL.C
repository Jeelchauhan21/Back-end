#include<stdio.h>
#include<conio.h>


void main()
{
	char s[50];
	int i,vowel=0,consto=0;
	clrscr();

	printf("\n Enter Any String:");
	scanf("%s",&s);


	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
		{
		     vowel++;
		}
		else
		{
			consto++;
		}

	}


	printf("\n String is : %s",s);
	printf("\n Vowels = %d",vowel);
	printf("\n Consto = %d",consto);

	getch();
}