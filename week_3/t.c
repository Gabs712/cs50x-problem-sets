#include <stdio.h>
#include <cs50.h>

void print(int n)
{
    if (n <= 0)
    {
        return;
    }

    print(n - 1);

    for (int i = 0; i < n; i++)
    printf("%i", i);

    printf("\n");
}

int main(void)
{
    print(get_int("n: "));
}