// encode according to user key and plaintext
#include <cs50.h>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // force the correct input from user
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    string text = get_string("plaintext:  ");

    // calculate and print encrypted text
    printf("ciphertext: ");
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]))
        {
            printf("%c", (text[i] - 65 + key) % 26 + 65);
        }
        else if (islower(text[i]))
        {
            printf("%c", (text[i] - 97 + key) % 26 + 97);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}