#include<iostream.h>
#include<conio.h>
#include<stdlib.h>


class Game
{
	public:
		void displayMenu()
		{
			cout<<"\n 1).Rock";
			cout<<"\n 2).Paper";
			cout<<"\n 3).Scissor";
		}

};
void main()
{
	int unum,snum,round=0,i=1,u_score=0,s_score=0,u_choice,c_choice;
	int ans,j;
	char u_name[50];
	clrscr();

	Game g;

	cout<<"\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";
	cout<<"\t\t NAME ";
	cout<<"\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";
	cout<<"\n Enter Your Name:";
	cin>>u_name;

	cout<<"\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";
	cout<<"\t\t ROUNDS ";
	cout<<"\n\n*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*\n\n";
	cout<<"\n"<<u_name<<" How many Rounds You want to play?:";
	cin>>round;




	cout<<"\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";
	cout<<"\t\t GAME ";
	cout<<"\n\n*-**-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*\n\n";

	 while(1)
	 {

		do{

		if(round<1 || round >3)
		{
			cout<<"\n Only 3 rounds you can Play :";
		}
		else
		{
			cout<<"\n Round :"<<i++<<"/"<<round;
		}
		cout<<"\n\n"<<u_name<<" score = "<<u_score;
		cout<<"\n\n computer score = "<<s_score<<"\n";
		g.displayMenu();

		cout<<"\n\n Select Your choice:";
		cin>>u_choice;

		c_choice=(rand()%3)+1;
		cout<<"\n computer choice is :"<<c_choice;

		if(u_choice==1 && c_choice==2 || u_choice==2 && c_choice==3)
		{
			cout<<"\n Computer Win....!!";
			s_score++;
		}
		else if(u_choice==1 && c_choice==1 || u_choice==2 || c_choice==2 && u_choice==3 || c_choice==3)
		{
			cout<<"\n Draw...!";
		}
		else
		{
			cout<<"\n Congratulations You Win.......!";
			u_score++;
		}

		cout<<"\n\n Do you Want to continue..? (YES==1 || NO==2):";
		cin>>ans;
		}while(ans!=2);
		break;
	 }


	getch();
}