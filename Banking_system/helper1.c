#include "main.h"

/**
 * account_success - display sucess for account creation
 */
void account_success(void)
{
    system("clear");
    printf("\n\nPROCESSING DATA ...");
    sleep(4);
    printf("\n\nAccount created successfully!");
    /*printf("\n Press enter to login\n");
    getchar();
    //login(); */
}

/**
 * login - prompt for user login
 */
int login(void)
{
    char username[50];
    char *password, ch;
    static int trials;
    FILE *fp;
    user u1;
    int i = 0, in = 0;
    int logged_in = 0;

    system("clear");
    fp = fopen("accounts.txt","r");
    if (fp == NULL)
    {
	    printf("ERROR IN OPENING FILE");
	    return (-1);
    }
    printf(" ACCOUNT LOGIN \n");
    printf("*******************************************************************************\n");
    printf("==== LOG IN ====\n");
    printf("USERNAME: ");
    scanf("%s", username);

    while (1)
    {
	    printf("\nPASSWORD: ");

	    password = malloc(20);
	    if (password  == NULL)
	    {
		    fprintf(stderr, "Unable to allocate memory to password file");
		    return (-1);
	    }
	    /* Enter  password */
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

	    if (find_user(username) == 0)
	    {
		    trials++;
		    if (strcmp(password, u1.password) == 0)
		    {
			    in = 1;
			    free(password);
			    login_success();
			    sleep(1);
			    system("clear");
			    display(username);
			    break;
		    }
		    else
		    {
			    free(password);
			    printf("Incorrect password!");
			    if (trials >= 3)
			    {
				    printf("\nToo many attempts");
				    break;
			    }
		    }
	    }
	    else
	    {
		    free(password);
		    printf("\nUser not found: username\n");
		    break;
	    }
    }

    if (fclose(fp) != 0)
    {
	    fprintf(stderr, "Unable to close file: accounts\n");
	    return (-1);
    }
    if (!in)
    {
	    printf("Log in failed\n");
	    return (-1);
    }
    while(logged_in)
    {
	    logged_in = menu(&u1);
    }
    return (0);
}

/**
 * login_success - display sucess message after login
 */
void login_success(void)
{
    system("clear");
    printf("Fetching account details.....\n");
    sleep(3);
    printf("\n\nLOGIN SUCCESSFUL....");
    printf("\nPress any key to continue");
    getchar();
}

/**
 * logout -  user log out of account
 */
void logout(void)
{
    int i;

    system("clear");
    printf("\n\t<<<Updating system data>>>\t\n");
    printf("\n\tlogging out.....\t\n");

    for (i = 0; i < 5; i++)
    {
	    sleep(1);
	    printf(".");
    }
    printf("\n*** You are logged out ***\n");
    sleep(2);
    welcome();
}

/**
 *withdraw - user makes withdrawal
 *@user_id: user id
 *
 *Return: success value
 */
int withdraw(int user_id)
{
	int amnt;
	system("clear");

	printf("Enter amount to withdraw:: ");
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

	if(debit_account(user_id, amnt) == 0)
	{
		printf("%d Withdrawn successfuly\n", amnt);
		return (0);
	}
	printf("Withdrawal unsuccessful\n");
	return (-1);
}
