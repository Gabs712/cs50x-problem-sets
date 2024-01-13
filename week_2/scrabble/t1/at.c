#include <stdio.h>
#include <cs50.h>

float sum(int eleme[]);
int main()
{
    int get[2];

    for(int i = 0; i < 3; i++)
    {
        get[i] = get_int("number: ");
    }

    printf("%f\n", sum(get));
}

float sum(int eleme[])
{
    return ((float) eleme[0] + eleme[1] + eleme[2])/3;
}