#include <stdio.h>
#include <stdbool.h>
bool test();

int main ()
{
    if(test)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n"0;)
    }
}

bool test()
{
    for (int i = 0; i < 5; i++)
    {
        while(1)
        {
            if(i == 3)
            {
                return false;
            }
            else if (i == 5)
            {
                return true;
            }
        }
    }
}