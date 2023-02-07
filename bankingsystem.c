#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

//structure for data of user
typedef struct pass {
    char username[20];
    int date, month, year;
    int idnum;
    char fname[20];
    char lname[20];
    char address[20];
    char accounttype[20];
    char password[20];
}user;

// Structure to keep track of money transfer
typedef struct money {
    char to[50];
    char from[50];
    long int money1;
}money;

void createaccount(void)
{
    char password[20], ch;
    int i;
    FILE *fp;
    user u1;

    fp = fopen("accounts.bin", "ab");

    system("cls");

    printf("********** CREATE ACCOUNT **********\n");
    printf("Enter first name:");
    scanf("%s", &u1.fname);
    printf("Enter last name:");
    scanf("%s", &u1.lname);
    printf("Enter a username:");
    scanf("%s", &u1.username);
    printf("Enter date of birth:");
    scanf("%d", &u1.date);
    printf("Enter month of birth:");
    scanf("%d", &u1.month);
    printf("Enter year of birth:");
    scanf("%d", &u1.year);
    printf("Enter account type");
    scanf("%s", &u1.accounttype);
    printf("Enter your town name");
    scanf("%s", &u1.address);
    printf("Enter your id number:");
    scanf("%d", &u1.idnum);
    printf("Enter your password (8 characters minimum)");

    for (i = 0; i <= 20; i++)
    {
        ch = getch();
        if (ch != 10) //10 is ascii for ENTER key
        {
            password[i] = ch;
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

    if (fp == NULL)
    {
        printf("Error creating file");
        exit(1);
    }

    fwrite(&u1, sizeof(user), 1, fp);

    fclose(fp);

}
