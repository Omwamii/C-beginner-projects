#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <termios.h> //use conio.h for windows
#include <unistd.h>
#include <time.h>

#define USERNAME_SIZE 30

/* user account info struct */
typedef struct pass {
    char username[20];
    int date, month, year;
    int idnum, mobile_no;
    char fname[20];
    char lname[20];
    char address[20];
    char account_type[20];
    char password[20];
    unsigned int money = 0;
    unsigned int id = 0;/* default user id before set_id */
} user;
int create_account(void);
int deposit(int user_id, unsigned int amount);
void display(char *username);
void transfer_money(void);
void check_balance(char *username);
void account_success(void);
void logout(void);
void login_success(void);
int login(void);
int menu(void);
int withdraw(int user_id, unsigned int amount);
int find_user(char *username);
int set_uid(char *username);
int get_uid(char *username);
int credit_account(int u_id, unsigned int amount);
int debit_account(int u_id, unsigned int amount);
#endif
