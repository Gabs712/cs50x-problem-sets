#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello %s\n", argv[1]);

        return 0;
    }
        else
    {
        printf("Prompt your first name\n");

        return 1;
    }

}