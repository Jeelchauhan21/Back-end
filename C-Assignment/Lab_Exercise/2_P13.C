#include<stdio.h>
#include<conio.h>

void main()
{
	FILE *f1;
	char *name;
	clrscr();

	f1=fopen("2_p13.txt","w");
	printf("\n Enter Your Name:");
	gets(name);

	fprintf(f1,"%s",name);
	fclose(f1);
	printf("\n File Written Successfully");

	f1=fopen("2_p13.txt","r");

	fscanf(f1,"%s",name);
	printf("\n Name is : %s",name);
	fclose(f1);

	getch();
}

