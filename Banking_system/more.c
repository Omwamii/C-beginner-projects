#include "main.h"

void welcome(void)
{
	int choice;
	user u1;
	system("clear");
	printf("\n\n\t\t\tAKIBA BANKING MANAGEMENT SYSTEM");
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n\t\t\t1.Create new account\n\t\t");
	printf("\n\t\t\t2.Log in\n\t\t");
	printf("\n\t\t\t3.Quit\n\n\n\t\t\tEnter your choice:");
	do{
		scanf("%d", &choice);

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
			default:
				printf("\n\t\t\t!!! Invalid choice (1 - 3) !!!\n");
				break;
		}

	} while (choice < 1 || choice > 3);
}

int fetch_balance(int user_id)
{
	FILE* fp;
    	user u1;
    	int balance;

	fp = fopen("accounts.txt", "r");

	/* Read username to fetch correct record */
	while (fread(&u1, sizeof(user), 1, fp))
	{
		if (user_id == u1.id)
		{
			balance = u1.money;
			break;
		}
	}
	fclose(fp);

	if (balance)
		return (balance);
	return (-1);
}
