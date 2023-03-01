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
void login(void)
{
     system("cls");

    char username[50];
    char *password;
    static int trials;
    char ch;
    FILE *fp;
    user u1;

    fp = fopen("accounts.txt","r");

    if (fp == NULL) {
        printf("ERROR IN OPENING FILE");
    }

    printf(" ACCOUNT LOGIN ");

    printf("***********************************************"
           "********************************");

    printf("==== LOG IN ====");


    printf("USERNAME..");
    scanf("%s", username);

password:  /* incase wrong password is entered, prompt again */
    printf("PASSWORD..");

    password = malloc(51);

    if (password  == NULL)
    {
	    fprintf(stderr, "Unable to allocate memory to password file");
	    return;
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
    return (0); //?
}

/**
 * login_success - display sucess message after login
 */
void login_success(void)
{
    int i;
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
    int i, j;
    system("cls");
    printf("\n\t<<<Updating system data>>>\t\n");
    printf("\n\tlogging out.....\t\n");

    for (i = 0; i < 10; i++) {
        sleep(2);
        printf(".");
    }

    printf("\n*** You are logged out ***\n");
    printf("\npress any key to continue..\n");
    getchar();
}

