#include<stdio.h>
#include<conio.h>

void main()
{
	int choice,ans,quantity;
	int amount=0,total=0;
	clrscr();

	do{
		printf("\n------ M E N U ------");
		printf("\n1.Pizza        price = 180rs/pcs");
		printf("\n2.Burger       Price = 100rs/pcs");
		printf("\n3.Dosa          Price = 120rs/pcs");
		printf("\n4.Idli         Price = 50rs/pcs");

		printf("\n Enter Your Choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\n You have selected Pizza...");
				printf("\nEnter the Quantity:");
				scanf("%d",&quantity);
				amount = quantity * 180;
				break;

			case 2:
				printf("\n You have selected Burger...");
				printf("\nEnter the quantity:");
				scanf("%d",&quantity);
				amount = quantity * 100;
				break;

			case 3:
				printf("\n You have selected Dosa...");
				printf("\nEnter the Quantity:");
				scanf("%d",&quantity);
				amount = quantity * 120;
				break;

			case 4:
				printf("\n You have selected Idli...");
				printf("\nEnter the quantity:");
				scanf("%d",&quantity);
				amount = quantity * 50;
				break;

			default:
				printf("\n Invalid Choice...");
				amount = 0;
				break;
		}

		printf("Amount : %d\n",amount);
		total += amount;
		printf("Total Amount is = %d\n",total);



		printf("\n Do You want to place more orders..? (Y=1:N=2):" );
		scanf("%d",&ans);
	}while(ans!=2);

	printf("\n Thank you for your order. Pleaase Pay %d rs. \n",total);

	getch();
}
