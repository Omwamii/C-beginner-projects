#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//structure for data of user
typedef struct pass {
    char username[50];
    int date, month, year;
    char idnum[10];
    char adharnum[20];
    char fname[20];
    char lname[20];
    char fathname[20];
    char mothname[20];
    char address[50];
    char accounttype[20];
}pass;

// Structure to keep track of money transfer
typedef struct money {
    char to[50];
    char from[50];
    long int money1;
}money;

typedef struct userpass {
    char password[50];
}userpass;
