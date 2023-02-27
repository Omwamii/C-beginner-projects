#include "main.h"

/**
 *create_account - creates user account
 */
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

/**
 *deposit - user makes deposit to account
 *@u: user struct
 */
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

/**
 * display - display user info
 * @username: user's username string
 */
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

/**
 * transfer_money - user to transfer money
 */
void transfer_money(void)
{
     int i, j;
    FILE *fp;
    user u1;
    char user_from[20];
    char user_to[20];
    system("cls");

    // Opening file in read mode to
    // read user's username
    fp = fopen("accounts.txt", "rb");

    //fmt
    printf("---- TRANSFER MONEY ----");
    //fmt
    printf("========================");

    //fmt
    printf("FROM (your username).. ");
    scanf("%s", &user_from);

    //fmt
    printf(" TO (username of person)..");
    scanf("%s", &user_to);

    // Checking for username if it
    // is present in file or not
    while (fread(&u1, sizeof(u1),
                 1, fp))

    {
        if (strcmp(user_from,
                   u1.username)
            == 0) {
            strcpy(m1.usernameto,
                   u1.username);
            strcpy(m1.userpersonfrom,
                   usernamet);
        }
    }
    //fmt
    // Taking amount input
    printf("ENTER THE AMOUNT TO BE TRANSFERRED..");
    scanf("%d", &m1.money1);

    // Writing to the file
    fwrite(&m1, sizeof(m1),
           1, fm);

    //fmt
    printf(
        "--------------------------------------------------"
        "--------------------------------------------");

    //fmt
    printf(
        "--------------------------------------------------"
        "--------------------------------------------");

    //fmt
    printf("transferring amount, Please wait..");

    //fmt
    for (i = 0; i < 70; i++) {
        for (j = 0; j < 1200000; j++) {
            j++;
            j--;
        }
        printf("*");
    }

    //fmt
    printf("AMOUNT SUCCESSFULLY TRANSFERRED....");
    getchar();

    // Close the files
    fclose(fp);
    fclose(fm);

    // Function to return
    // to the home screen
    display(user_to); //?
}

/**
 * check_balance - user to check balance
 * @username2: username string 
 */
void check_balance(char username2[])
{
    system("cls");
    FILE* fm;
    struct money m1;
    char ch;
    int i = 1, summoney = 0;

    // Opening amount file record
    fm = fopen("mon.txt", "rb");


    //fmt
    printf("==== BALANCE DASHBOARD ====");
    //fmt
    printf("***************************");
    //fmt
    printf("S no.");
    //fmt
    printf("TRANSACTION ID");
    //fmt
    printf("AMOUNT");

    // Reading username to
    // fetch the correct record
    while (fread(&m1, sizeof(m1),
                 1, fm)) {
        if (strcmp(username2,
                   m1.to)
            == 0) {
            //fmt
            printf("%d", i);
            i++;
            //fmt
            printf("%s", m1.from);

            //fmt
            printf("%d", m1.money1);
            // Adding and
            // finding total money
            summoney = summoney + m1.money1;
        }
    }

    //fmt
    printf("TOTAL AMOUNT");

    //fmt
    printf("%d", summoney);

    getchar();

    // Closing file after
    // reading it
    fclose(fm);
    display(username2);
}

