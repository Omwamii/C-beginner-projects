#ifndef MAIN_H
#define MAIN_

#include <stdio.h>
#include <string.h>

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

#endif
