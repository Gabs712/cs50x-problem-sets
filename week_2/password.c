// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);
bool upper(string letter);
bool lower(string letter);
bool num(string letter);
bool sym(string letter);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    if (upper(password) && lower(password) && num(password) && sym(password))
    {
        return true;
    }
    return false;
}

bool upper(string letter)
{
    for (int i = 0; i < strlen(letter); i++)
    {
        if (isupper(letter[i]))
        {
            return true;
        }
    }
    return false;
}

bool lower(string letter)
{
    for (int i = 0; i < strlen(letter); i++)
    {
        if (islower(letter[i]))
        {
            return true;
        }
    }
    return false;
}

bool num(string letter)
{
    for (int i = 0; i < strlen(letter); i++)
    {
        if (isdigit(letter[i]))
        {
            return true;
        }
    }
    return false;
}

bool sym(string letter)
{
    for (int i = 0; i < strlen(letter); i++)
    {
        if (!isalnum(letter[i]))
        {
            return true;
        }
    }
    return false;
}