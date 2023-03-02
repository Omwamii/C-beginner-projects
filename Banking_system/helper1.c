#include "main.h"

/**
 * account_success - display sucess for account creation
 */
void account_success(void)
{
    system("cls");
    printf("\n\nPROCESSING DATA ...");
    sleep(5);
    printf("\n\nAccount created successfully!");
    printf("\n Press enter to login");
    getchar();
    login();
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

    fp = fopen("accounts.txt","r");
    if (fp == NULL)
    {
	    printf("ERROR IN OPENING FILE");
	    return (-1);
    }
    printf(" ACCOUNT LOGIN \n");
    printf("*******************************************************************************\n");
    printf("==== LOG IN ====\n");
    printf("USERNAME..");
    scanf("%s", username);

password:  /* incase wrong password is entered, prompt again */
    printf("\nPASSWORD..");
    password = malloc(51);
    if (password  == NULL)
    {
	    fprintf(stderr, "Unable to allocate memory to password file");
	    return (-1);
    }
    /* Enter  password */
     while (i < sizeof(password) - 1)
     {
	     ch = getchar;
	     if (ch == '\r' || ch == '\n')
		     break;

	     password[i++] = ch;
	     putchar('*'); /* print * to screen to hide password */
	     fflush(stdout);
     }
     password[i] = '\0';

    /* Check if user exists */
    while (fread(&u1, sizeof(user), fp))
    {
	    if (strcmp(username,u1.username) == 0)
	    {
		    trials++;
		    if (strcmp(password, u1.password) == 0)
		    {
			    free(password);
			    login_success();
			    sleep(2);
			    display(username);
			    break;
		    }
		    free(password);
		    printf("Incorrect password!");
		    if (trials < 4)
			    goto password; //prompt user again to enter password
        }
    }
    if (fclose(fp) != 0)
    {
	    fprintf(stderr, "Unable to close file: accounts\n");
	    return;
    }
    login_success();
    return (0); //?
}

/**
 * login_success - display sucess message after login
 */
void login_success(void)
{
    system("cls");
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

    system("cls");
    printf("\n\t<<<Updating system data>>>\t\n");
    printf("\n\tlogging out.....\t\n");

    for (i = 0; i < 10; i++)
    {
	    sleep(2);
	    printf(".");
    }
    printf("\n*** You are logged out ***\n");
    sleep(2);
}

/**
 *withdraw - user makes withdrawal
 *@user_id: user id
 *
 *Return: success value
 */
int withdraw(int user_id)
{
	unsigned int amnt;
	system("cls");

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
