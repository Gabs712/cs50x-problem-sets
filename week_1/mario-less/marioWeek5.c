#include <cs50.h>
#include <stdio.h>

int main()
{
    int x;
    do
    {
        x = get_int("height: ");
    }
    while (x < 1 || x > 8);

    for (int i = 0; i < x; i++)
    {
        for (int k = 0; k < x - 1 - i; k++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
