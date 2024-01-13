// Print the size of a pyramid according to the user input
#include <cs50.h>
#include <stdio.h>

int x(int s);

int main()
{
    for (int i = 0 ; i < 1; i++)
    {
        printf("%i\n", x(1));
    }
}

int x(int s)
{
    int x = 1 + s;
    return x;

}