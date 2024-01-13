#include <stdio.h>
#include <cs50.h>

int main()
{
    long x = get_int("Count to: ");
    long sum[x];
    for(long i = 0, j = 1; i < x; i++, j++)
    {
        sum[i] = j;
        printf("%li\n", sum[i]);
    }
}