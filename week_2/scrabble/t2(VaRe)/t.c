#include <stdio.h>

int tripple (int y);

int main()
{
    int x = 4;
    tripple (x);
    printf("%i\n", x);
}

int tripple (int y)
{
    return y *= 3;
}