#include "main.h"

/**
 * account_success - display sucess for account creation
 */
void account_success(void)
{
    int i;

    system("cls");
    printf("\n\nPROCESSING DATA ...");

    for (i = 0; i < 200000000; i++);

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
    char password[50];

    int i, j, k;
    char ch;
    FILE *fp;
    user u1;

    // Opening file of
    // user data
    fp = fopen("accounts.txt",
               "r");

    if (fp == NULL) {
        printf("ERROR IN OPENING FILE");
    }

    printf(" ACCOUNT LOGIN ");

    printf("***********************************************"
           "********************************");

    printf("==== LOG IN ====");

    // Take input

    printf("USERNAME..");
    scanf("%s", &username);

    printf("PASSWORD..");

 password:
    // Input the password
    for (i = 0; i < 50; i++) {
        ch = getchar();
        if (ch != 10) {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }

        else
            break;
    }

    // Checking if username
    // exists in the file or not
    while (fgets(u1.username,20,fp)) {
        if (strcmp(username,u1.username) == 0)
        {
            if (strcmp(password, u1.password) == 0)
            {
                login_success();
                display(username);
            }

            printf("Incorrect password!");
            goto password; //prompt user again to enter password
        }
    }

    // Closing the file
    fclose(fp);
}

/**
 * login_success - display sucess message after login
 */
void login_success(void)
{
    int i;
    system("cls");
    printf("Fetching account details.....\n");
    for (i = 0; i < 200000000; i++); //waits

    printf("\n\nLOGIN SUCCESSFUL....");
    printf("\nPress enter to continue");

    getchar();
}

/**
 * logout -  user log out of account
 */
void logout(void)
{
    int i, j;
    system("cls");
    printf("please wait, logging out");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 25000000; j++) {
            i++;
            i--;
        }
        printf(".");
    }

    //fmt
    printf("Sign out successfully..\n");

    //fmt
    printf("press any key to continue..");

    getchar();
}

