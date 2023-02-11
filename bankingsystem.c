#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

/**
 * a simple banking system program with basic bank transactions
*/
//structure for data of user
typedef struct pass {
    char username[20];
    int date, month, year;
    int idnum, mobile_no;
    char fname[20];
    char lname[20];
    char address[20];
    char account_type[20];
    char password[20];
    long money;
}user;

// Structure to keep track of money transfer
typedef struct money {
    char to[50];
    char from[50];
    long int money1;
}money;

void create_account(void)
{
    char password[20], ch;
    int i;
    FILE *fp;
    user u1;

    fp = fopen("accounts.txt", "a+");

    if (fp == NULL)
    {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }

    system("cls");

    printf("********** CREATE ACCOUNT **********\n");
    printf("Enter first name:");
    gets(u1.fname);
    fputs(u1.fname, fp);
    printf("Enter last name:");
    gets(u1.lname);
    fputs(u1.lname, fp);
    printf("Enter a username:");
    gets(u1.username);
    fputs(u1.username, fp);
    printf("Enter date of birth:");
    scanf("%d", &u1.date);
    fputw(u1.date, fp);
    printf("Enter month of birth:");
    scanf("%d", &u1.month);
    fputw(u1.month, fp);
    printf("Enter year of birth:");
    scanf("%d", &u1.year);
    fputw(u1.year, fp);
    printf("Enter mobile number:");
    scanf("%d", &u1.mobile_no);
    fputw(u1.mobile_no, fp);
    printf("Enter account type");
    gets(u1.account_type);
    fputs(u1.account_type, fp);
    printf("Enter your town name");
    gets(u1.address);
    fputs(u1.address, fp);
    printf("Enter your id number:");
    scanf("%d", &u1.idnum);
    fputw(u1.idnum, fp);
    printf("Enter your password (8 characters minimum)");

    for (i = 0; i <= 20; i++)
    {
        ch = getchar();
        if (ch != 10) //10 is ascii for ENTER key
        {
            password[i] = ch;
            u1.password[i] = password[i];
            ch = '*'; //to hide password as ***
            printf("%c", ch);
        }
        else
        {
            if (strlen(password) < 8)
            {
                printf("Password is too short!");
                continue;
            }

            break;
        }
    }
    fputs(u1.password, fp);

    fclose(fp);

    account_success();

}
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

void display(char username[])
{
    system("cls");
    FILE* fp;
    int choice, i;
    fp = fopen("accounts.txt", "r");
    user u1;
 
    if (fp == NULL) {
        printf("error in opening file");
    }
 
    while (fgets(u1.username, 20, fp)) {
        if (strcmp(username, u1.username) == 0) {
            //format screen
            printf("WELCOME, %s %s", u1.fname, u1.lname);
            //format screen
            printf("..........................");
            //fmt screen
            printf("==== YOUR ACCOUNT INFO ====");
            //fmt screen
            printf("***************************");
            //fmt screen
            printf("NAME: %s %s", u1.fname, u1.lname);
 
            //fmt screen
            printf("ID NUMBER: %d", u1.idnum);
 
            //fmt screen
            printf("MOBILE NUMBER: %d", u1.mobile_no);
 
            //fmt screen
            printf("DATE OF BIRTH: %d-%d-%d", u1.date, u1.month, u1.year);
 
            //fmt screen
            printf("ADDRESS: %s", u1.address);
 
            //fmt screen
            printf("ACCOUNT TYPE: %s", u1.account_type);
        }
    }
 
    fclose(fp);
 
    //fmt screen
 
    // Menu to perform different
    // actions by user
    printf(" HOME ");
    //fmt

    printf("******");
    //fmt

    printf(" 1....CHECK BALANCE");
    //fmt

    printf(" 2....DEPOSIT MONEY");

    printf(" 3....TRANSFER MONEY");
    //fmt

    printf(" 4....LOG OUT\n\n");
    //fmt

    printf(" 5....EXIT\n\n");
 
    printf(" ENTER YOUR CHOICES... ");
    scanf("%d", &choice);
 
    switch (choice) {
    case 1:
        checkbalance(username);
        break;
    
    case 2:
        deposit(&u1);
 
    case 3:
        transfer_money();
        break;
 
    case 4:
        logout();
        login(); //prompt for login after logout
        break;
 
    case 5:
        system("cls");
        printf("\t\t\t.......");
        printf("\t\t\tGoodbye");
        printf("\t\t\t.......");
        exit(0);
        break;
    }
}

void deposit(user *u)
{
    FILE *fp;
    long amnt;
    char current_amnt[32];
    int cash_in = 0;
    long offset; /* file offset to set to write new amount correclty*/

    system("cls");

    printf("Enter amount to deposit");
    scanf("%lu", &amnt);

    fp = fopen("file.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fread(&u, sizeof(user), 1, fp))
    {
            u->money += amnt;
            offset = -(long)(sizeof(u->money));
            fseek(fp, offset, SEEK_CUR);
            fwrite(&u->money, sizeof(u->money), 1, fp);
            cash_in = 1;
            break;
    }
    fclose(fp);

    if (cash_in) {
        printf("Deposit Successful! New balance: %ld\n", u->money);
    } else {
        printf("!!!! Error: Unable to deposit funds\n !!!!");
    }
}

void transfer_money()