// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string replace(string t);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels (text)\n");
        return 1;
    }
    printf("%s\n", replace(argv[1]));
}

string replace(string t)
{
    for(int i = 0; i < strlen(t); i++)
    {
        if (t[i] == 'a' || t[i] == 'A')
        {
            t[i] = '6';
        }
        else if (t[i] == 'e' || t[i] == 'E')
        {
            t[i] = '3';
        }
        else if (t[i] == 'i' || t[i] == 'I')
        {
            t[i] = '1';
        }
        else if (t[i] == 'o' || t[i] == 'O')
        {
            t[i] = '0';
        }
    }
    return t;
}
