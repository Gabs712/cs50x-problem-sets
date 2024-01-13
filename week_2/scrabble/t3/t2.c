#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main()
{
    string text = get_string("Input: ");
    printf("Output: ");
    printf("%c", toupper(text[0]));

    for (int i = 1, l = strlen(text); i < l; i++)
    {
        printf("%c", tolower(text[i]));
    }
    printf("\n");
}