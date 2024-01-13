#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main()
{
    string text = get_string("Input: ");
    printf("Output: ");

    for(int i = 0, l = strlen(text); i < l; i++)
    {
        char s = toupper(text[i]);
        printf("%c", s);
    }
    printf("\n");
}