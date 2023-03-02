#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>

#define NAME_SIZE 30

/* user account info struct */
typedef struct user_info {
    char username[30];
    int date;
    int month;
    int year;
    int idnum;
    int mobile_no;
    char fname[15];
    char lname[15];
    char address[20];
    char account_type[20];
    char password[20];
    int money;
    int id; /* default user id before set_id */
} user;
int create_account(void);
int deposit(int user_id);
int display(char *username);
int transfer_money(char *username);
void check_balance(int u_id);
void account_success(void);
void logout(void);
void login_success(void);
int login(void);
int menu(user *u1);
int withdraw(int user_id);
int find_user(char *username);
int set_uid(char *username);
int get_uid(char *username);
int credit_account(int u_id, int amount);
int debit_account(int u_id, int amount);

#endif
