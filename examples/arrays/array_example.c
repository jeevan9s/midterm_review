#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// @practice - write a C program that defines a structure describing a generic account, and implement lookup functions

typedef struct
{
    int id;
    char *name;
} account;

account accounts[20];
int active_accounts;

char *locateUserById(int id)
{
    for (int i = 0; i < active_accounts; i++)
    {
        if (accounts[i].id == id)
        {
            return accounts[i].name;
        }
    }
    return NULL;
}

char *locateUserByName(char *username)
{
    for (int i = 0; i < active_accounts; i++)
    {
        if (strcmp(accounts[i].name, username) == 0)
        {
            return accounts[i].name;
        }
    }
    return NULL;
}

int main()
{
    account Person1;
    account Person2;

    Person1.id = 1;
    Person1.name = "Bob";

    Person2.id = 2;
    Person2.name = "Jeevan";

    accounts[0] = Person1;
    accounts[1] = Person2;

    active_accounts = 2;

    // char *name = locateUserByName("Jeevan");
    char *name = locateUserById(1);
    printf("name: %s\n", name);
}
