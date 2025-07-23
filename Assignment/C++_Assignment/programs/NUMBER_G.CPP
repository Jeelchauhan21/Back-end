#include<iostream.h>
#include<conio.h>
#include<stdlib.h>


void main()
{
	clrscr();

	int num,sec_num;


	randomize();
	sec_num=random(100)+1;

	cout<<"\nGuess the number (between 1 and 100):";

	while(1)
	{
		cout<<"\n Enter Your num:";
		cin>>num;

		if(num<sec_num)
		{
			cout<<"\nToo Low...";
		}
		else if(num>sec_num)
		{
			cout<<"\nToo High...";
		}
		else
		{
			cout<<"\n Congratulations You guessed Right num...";
			break;
		}
	}
	getch();
}
