#include "main.h"

/**
 * main - entry point
 *
 * Return: success value
 */
int main(void)
{
	int choice;

	while (1)
	{
		system("cls");
		printf("\n\n\t\t\tAKIBA BANKING MANAGEMENT SYSTEM");
		printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		printf("\n\n\t\t\t1.Create new account\n\t\t");
		printf("\n\t\t\t2.Log in\n\t\t");
		printf("\n\t\t\t3.Quit\n\n\n\t\t\t Enter your choice:");
		while (1)
		{
			if (scanf("%d",&choice) != 1)
			{
				printf("Invalid choice \n");
				continue;
			}
			if (choice < 1 || choice > 3)
			{
				printf("Invalid choice (1 - 3)\n");
				continue;
			}
			break;
		}

		switch(choice)
		{
			case 1:
				create_account();
				break;
			case 2:
				login();
				break;
			case 3:
				exit(0);

		 }
	}
	return(0);
}
