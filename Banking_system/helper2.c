#include "main.h"

/**
 *create_account - creates user account
 *
 *Return: success value
 */
int create_account(void)
{
	/*struct termios term;*/
	char password[20], ch;
    	int i = 0;
    	FILE *fp;
    	user u1;

    	fp = fopen("accounts.txt", "a");

    	if (fp == NULL)
    	{
        	printf("Error opening file\n");
        	exit(EXIT_FAILURE);
    	}

    	system("clear");

    	printf("********** CREATE ACCOUNT **********\n");
    	printf("Enter first name: ");
    	scanf("%s", u1.fname);
   	fprintf(fp, "%s\n", u1.fname);
    	printf("Enter last name: ");
    	scanf("%s", u1.lname);
    	fprintf(fp, "%s\n", u1.lname);
    	printf("Enter a username: ");
    	scanf("%s", u1.username);
    	fprintf(fp, "%s\n", u1.username);
    	printf("Enter date of birth: ");
    	scanf("%d", &u1.date);
    	fprintf(fp, "%d\n", u1.date);
    	printf("Enter month of birth: ");
    	scanf("%d", &u1.month);
    	fprintf(fp, "%d\n", u1.month);
    	printf("Enter year of birth: ");
    	scanf("%d", &u1.year);
    	fprintf(fp, "%d\n", u1.year);
    	printf("Enter mobile number: ");
    	scanf("%d", &u1.mobile_no);
    	fprintf(fp, "%d\n", u1.mobile_no);
    	printf("Enter account type: ");
    	scanf("%s", u1.account_type);
    	fprintf(fp, "%s\n", u1.account_type);
    	printf("Enter your town name: ");
    	scanf("%s", u1.address);
    	fprintf(fp, "%s\n", u1.address);
    	printf("Enter your id number: ");
    	scanf("%d", &u1.idnum);
    	fprintf(fp, "%d\n", u1.idnum);
    	printf("Enter your password (8 characters minimum)");

    	while (i < 20)
    	{
		    ch = getchar();
		    if (ch == '\r' || ch == '\n')
			    break;
		    password[i++] = ch;
		    putchar('*'); /* print * to screen to hide password */
		    fflush(stdout);
    	}

    	password[i] = '\0';
    	strcpy(u1.password, password);
    	fprintf(fp, "%s\n", u1.password);
    	fclose(fp);
	if (set_uid(u1.username) == 0)
		printf("\n\nID set successfully\n");
	sleep(1);
	account_success();
    	return (0);
}

/**
 *deposit - user makes deposit to account
 *@user_id: unique user id
 *@amount: amount to deposit
 *
 *Return: success value
 */
int deposit(int user_id)
{
	int amnt;
	system("clear");

	printf("Enter amount to deposit:: ");
	while (1)
	{
		if (scanf("%d", &amnt) != 1)
		{
			printf("Invalid input\n");
			continue;
		}
		if (amnt <= 0)
		{
			printf("Amount must be more than 0\n");
			continue;
		}
		break;
	}

	if(credit_account(user_id, amnt) == 0)
	{
		printf("Deposit successful\n");
		return (0);
	}
	printf("Deposit unsuccessful\n");
	return (-1);
}

/**
 * display - display user info
 * @username: user's username string
 *
 *Return: 0 if user found -1 if error
 */
int display(char *username)
{
    int found = 0;
    FILE *fp;
    user u1;

    fp = fopen("accounts.txt", "r");
    if (fp == NULL)
    {
	    printf("Cannot open file: accounts\n");
	    return (-1);
    }

    system("clear");
    if(find_user(username) == 0)
    {
	    while(fread(&u1, sizeof(user), 1, fp));
	    found = 1;
	    printf("WELCOME, %s %s\n", u1.fname, u1.lname);
	    printf("..........................\n");
	    printf("==== YOUR ACCOUNT INFO ====\n");
            printf("***************************\n");
            printf("NAME: %s %s\n", u1.fname, u1.lname);
            printf("ID NUMBER: %d\n", u1.idnum);
            printf("MOBILE NUMBER: %d\n", u1.mobile_no);
            printf("DATE OF BIRTH: %d-%d-%d\n", u1.date, u1.month, u1.year);
            printf("ADDRESS: %s\n", u1.address);
            printf("ACCOUNT TYPE: %s\n", u1.account_type);
    }
    fclose(fp);
    if(!found)
    {
	    printf("User not found\n");
	    return (-1);
    }

    printf("\n\nPress any key to continue");
    getchar();
    return (0);
    //menu();
}

/**
 * transfer_money - user to transfer money
 *@username: username of user
 *
 *Return: sucess value
 */
int transfer_money(char *username)
{
	int withd, depo, id1, id2;
	int amnt, i;
	char *user_from, *user_to;

    	user_from = malloc(NAME_SIZE + 1);
    	user_to = malloc(NAME_SIZE + 1);
    	if (user_from == NULL || user_to == NULL)
    	{
	   	 fprintf(stderr, "Error allocating memory\n");
		 return (-1);
	}

    	system("clear");
	strcpy(user_from, username);
    	printf("---- TRANSFER MONEY ----\n");
    	printf("========================\n\n");
    	printf(" TO (username of person)...\n");
    	scanf("%s", user_to); /* add check to verify input */
    	printf("\n\nENTER THE AMOUNT TO BE TRANSFERRED..");
	while (1)
	{
		if (scanf("%d", &amnt) != 1)
		{
			printf("Error: Invalid input.\n");
			while (getchar() != '\n'); /* clear input buffer for non-numeric */
			continue;
		}
		if (amnt <= 0)
		{
			printf("Error: amount to deposit must be a positive number\n");
			continue;
		}
		break;
	}

	 printf("\n----------------------------------------------------------------------------------------------");
	 printf("\n----------------------------------------------------------------------------------------------");
	 printf("\n\nTransferring amount, Please wait..\n\n");
	 for (i = 0; i < 6; i++)
	 {
		 sleep(2);
		 putchar('.');
	 }

	 id1 = get_uid(user_from); /*see if works */
	 id2= get_uid(user_to);
	 depo = credit_account(id2, amnt); /* deposit to user_to */
	 withd = debit_account(id1, amnt); /* withdraw from user_from */
	 free(user_from), free(user_to);

	 if ((depo == 0) && (withd == 0))
		 printf("\n\nTRANSACTION SUCCESSFUL....");
	 else
	 {
		 printf("\n\nTRANSACTION FAILED!\n");
		 return (-1);
	 }

	 printf("\nPress any key to go back to menu\n");
	 getchar();
	 return (0);
}

/**
 * check_balance - user to check balance
 * @username2: username string
 */
void check_balance(int u_id)
{
    int balance = fetch_balance(u_id);

    system("clear");

    if (balance == -1)
    {
	    printf("\nAccount information unavailable: balance\n");
	    return;
    }
    printf("==== BALANCE DASHBOARD ====\n");
    printf("***************************\n");
    printf("S no.\n");
    printf("TRANSACTION ID\n");
    printf("AMOUNT\n");
    printf("TOTAL AMOUNT: ");
    printf("%d\n", balance);
    printf("\n\nPress any key to continue\n");
    getchar();
}

int menu(user *u)
{
	int choice;
	int logged_in = 1;

	system("clear");
	printf("\t\t\t HOME \n\n");
	printf("\t\t\t******\n");
	printf("\t\t\t 1....CHECK BALANCE\n");
	printf("\t\t\t 2....DEPOSIT MONEY\n");
	printf("\t\t\t 3....TRANSFER MONEY\n");
	printf("\t\t\t 4....WITHDRAW MONEY\n");
	printf("\t\t\t 5....LOG OUT\n");
	printf("\t\t\t 6....QUIT\n\n");
	printf("\t\t\t ENTER YOUR CHOICE... ");

	do{
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				check_balance(u->id);
				break;
			case 2:
				deposit(u->id);
				break;
			case 3:
				transfer_money(u->username);
				break;
			case 4:
				withdraw(u->id);
				break;
			case 5:
				logout();
				logged_in = 0;
				break;
			case 6:
				system("clear");
				printf("\t\t\t.......");
				printf("Goodbye ");
				printf(".......\t\t\t\n\n");
				printf("\a"); /* beep */
				sleep(1);
				exit(0);
				break;
			default:
				printf("Invalid choice");
				break;
		}
	}while (choice < 1 || choice > 6);
	return (logged_in); /* loop */
}
