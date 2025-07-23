#include<iostream.h>
#include<conio.h>

class Bank
{
	int acno;
	char *cname;
	double balance;

	public:
		void openAccount();
		void deposit();
		void withdraw();
		void checkBalance();
		void showDetails();
};

void Bank::openAccount()
{
	cout<<"\n Enter Account Number:";
	cin>>acno;
	cout<<"\n Enter Customer Name:";
	cin>>cname;
	cout<<"\n Initial Balance:";
	cin>>balance;
}
void Bank::deposit()
{
	double amount;
	cout<<"\n Enter Amount:";
	cin>>amount;
	if(amount>0)
	{
		balance=balance+amount;
	}
	else
	{
		cout<<"\n Invalid Amount";
	}
}

void Bank::withdraw()
{
	double amount;
	cout<<"\n Enter Withdraw Amoint:";
	cin>>amount;
	if(amount>0)
	{
		if(amount<=balance)
		{
			balance=balance-amount;
		}
		else
		{
			cout<<"\n Withdraw Amount is greater Then Your Balance";
		}
	}
	else
	{
		cout<<"\n Invalid Amount Entered";
	}
}

void Bank::checkBalance()
{
	cout<<"\n Current Balance"<<balance;
}

void Bank::showDetails()
{
	cout<<"\n Account Nuber : "<<acno;
	cout<<"\n Customer Name : "<<cname;
	cout<<"\n intial Balance : "<<balance;
}

void main()
{
	Bank b;
	int choice,a;
	clrscr();

	cout<<"\n *****************************************\n";
	b.openAccount();
	do{
	cout<<"\n1. Deposit";
	cout<<"\n2. Withdraw";
	cout<<"\n3. Check Balance";
	cout<<"\n4. Show Details";
	cout<<"\n5. Exit";
	cout<<"\n *****************************************\n";
	cout<<"\n\n Enter Your Choice: ";
	cin>>choice;
	cout<<"\n *****************************************\n";
	if(choice==1)
	{
		b.deposit();
		cout<<"\n *****************************************\n";
	}
	else if(choice==2)
	{
		b.withdraw();
		cout<<"\n *****************************************\n";
	}
	else if(choice==3)
	{
		b.checkBalance();
		cout<<"\n *****************************************\n";
	}
	else if(choice==4)
	{
		b.showDetails();
		cout<<"\n *****************************************\n";
	}
	else if(choice==5)
	{
		cout<<"\n Thank You for using Our services";
		cout<<"\n *****************************************\n";
		break;
	}
	else
	{
		cout<<"\n Invalid Choice Please Try Again";
		cout<<"\n *****************************************\n";
	}
	cout<<"\n\n Do Your Want To Continue? (Yes=1||No=2) ";
	cin>>a;
	}while(a!=2);
	getch();
}
