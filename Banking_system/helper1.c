#include "main.h"

/**
 * account_success - display sucess for account creation
 */
void account_success(void)
{
    int i;

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
    char *password;
    static int trials;
    char ch;
    FILE *fp;
    user u1;

    fp = fopen("accounts.txt","r");
    if (fp == NULL)
    {
	    printf("ERROR IN OPENING FILE");
	    return (-1);
    }

    printf(" ACCOUNT LOGIN \n");
    printf("***********************************************"
           "********************************\n");
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

    // Closing the file
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
 *deposit - user makes deposit to account
 *@u: user struct
 */
int withdraw(int user_id, unsigned int amount)
{
    FILE *fp;
    user u;
    int cash_out = 0;
    unsigned int amnt = amount;
    size_t offset; /* file offset to set to write new amount correctly*/

    system("cls");

    if (amnt <= 0)
    {
	    printf("Error: amount to withdraw must be a positive number\n");
	    return (-1);
    }

    fp = fopen("accounts.txt", "rb+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return (-1);
    }

    while (fread(&u, sizeof(user), 1, fp))
    {
	    if (u.id == user_id)
	    {
		    u.money -= amnt;
		    offset = -(sizeof(u.money));
		    fseek(fp, offset, SEEK_CUR); /* set file cursor to beginning to write amount properly */
		    fwrite(&u.money, sizeof(u.money), 1, fp);
		    cash_out = 1;
		    break;
	    }
    }

    if (fclose(fp) == -1)
    {
	    printf("Error closing file\n");
	    return (-1);
    }

    if (cash_out)
	    return (0);

    return (-1);
}
