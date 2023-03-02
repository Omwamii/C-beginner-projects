#include "main.h"

/**
  *find_user - finds user
  *@username: username string
  *
  *Return: 0 if found -1 if error
  */
int find_user(char *username)
{
	FILE *fp;
	user u1;
	int found = 0;

	fp = fopen("accounts.txt", "r");
	if (fp == NULL)
		return (-1);

	while (fread(&u1, sizeof(user), 1, fp))
	{
		if (strcmp(username, u1.username) == 0)
			found = 1;
	}
	fclose(fp);

	if (!found)
		return (-1);
	return (0);
}

/**
  *set_uid - sets user id after account creation
  *@username: username of user
  *
  *Return: success value
  */
int set_uid(char *username)
{
	FILE *fp;
	user u1;
	int set = 0;
	int random_id;
	long offset;

	fp = fopen("accounts.txt", "r+");
	if (fp == NULL)
		return (-1);

	srand(time());
	random_id = rand();
	if (random_id)
		set = 1;
	if (set)
	{
		if(find_user(username) == 0)
		{
			fread(&u1, sizeof(user), 1, fp);
			u1.id = random_id;
			offset = -(long)(sizeof(u1.id));
			fseek(fp, offset, SEEK_CUR);
			fwrite(&u1.id, sizeof(u1.id), 1, fp); /* add error-checking */
		}
		else
		{
			printf("Error: user not found\n");
			set = 0;
		}
	}
	fclose(fp);

	if(set)
		return (0);
	return (-1);
}

/**
  *get_uid - fetches user id
  *@username: username of user
  *
  *Return: user id;
  */
int get_uid(char *username)
{
	FILE *fp;
	user u1;
	int got = 0;

	fp = fopen("accounts.txt", "r");
	if (fp == NULL)
		return (-1);

	while(fread(u1, sizeof(user), 1, fp))
	{
		if(u1.id > 0)
			got = u1.id
	}
	fclose(fp);

	if (got)
		return (got);
	return (-1);
}

/**
  *credit_account - money sending transactions
  *@u_id: user id
  *@amount: amount to send
  *
  *Return: success value
  */
int credit_account(int user_id, unsigned int amount)
{
    FILE *fp;
    user u;
    int cash_in = 0;
    size_t offset; /* file offset to set to write new amount correctly*/
    unsigned int amnt = amount;

    system("cls");
    fp = fopen("file.txt", "rb+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return (-1);
    }

    while (fread(&u, sizeof(user), 1, fp))
    {
	    if (u.id == user_id)
	    {
		    u.money += amnt;
		    offset = -(sizeof(u.money));
		    fseek(fp, offset, SEEK_CUR); /* set file cursor to beginning to write amount properly */
		    fwrite(&u.money, sizeof(u.money), 1, fp);
		    cash_in = 1;
		    break;
	    }
    }

    if (fclose(fp) == -1)
    {
	    printf("Error closing file\n");
	    return (-1);
    }

    if (cash_in)
	    return (0);

    return (-1);
}

/**
  *debit_account - deducts money from account
  *@u_id: user id
  *@amount: amount to deduct
  *
  *Return: success value
  */
int debit_account(int u_id, unsigned int amount)
{
	FILE *fp;
	user u;
	int cash_out = 0;
	unsigned int amnt = amount;
	long offset; /* file offset to set to write new amount correctly*/

    	system("cls");
    	fp = fopen("accounts.txt", "rb+");
    	if (fp == NULL) {
        	printf("Error opening file!\n");
        	return (-1);
	}

    	while (fread(&u, sizeof(user), 1, fp))
    	{
	    	if (u.id == user_id)
	    	{
			u.money -= amnt;
		    	offset = -(long)(sizeof(u.money));
		    	fseek(fp, offset, SEEK_CUR); /* set file cursor to beginning to write amount properly */
		    	fwrite(&u.money, sizeof(u.money), 1, fp);
		    	cash_out = 1;
		    	break;
	    	}
    	}

    	if (fclose(fp) == -1)
    	{
	    	printf("Error closing file\n");
	    	return (-1);
    	}

    	if (cash_out)
		return (0);
	return (-1);
}
