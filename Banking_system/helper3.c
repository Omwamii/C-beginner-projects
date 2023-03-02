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
