#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <termios.h> //use conio.h for windows
#include <unistd.h>

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
} user;

// Structure to keep track of money transfer
typedef struct money {
    char to[50];
    char from[50];
    long int money1;
} money;

int create_account(void);
void deposit(user *u);
void display(char *username);
void transfer_money(void);
void check_balance(char *username);
void account_success(void);
void logout(void);
void login_success(void);
void login(void); 
#endif
