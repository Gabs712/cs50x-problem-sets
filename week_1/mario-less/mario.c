// Print the size of a pyramid according to the user input
#include <cs50.h>
#include <stdio.h>

int input(void);
void print1(void);
void print2(void);
void print3(void);
void print4(void);
void print5(void);
void print6(void);
void print7(void);
void print8(void);
void value1(int s);
void value2(int s);
void value3(int s);
void value4(int s);
void value5(int s);
void value6(int s);
void value7(int s);
void value8(int s);

int main(void)
{

    // User input
    int n = input();

    // Print size of pyramid
    if (n == 1)
    {
        print1();
    }

    if (n == 2)
    {
        print2();
    }

    if (n == 3)
    {
        print3();
    }

    if (n == 4)
    {
        print4();
    }

    if (n == 5)
    {
        print5();
    }

    if (n == 6)
    {
        print6();
    }

    if (n == 7)
    {
        print7();
    }

    if (n == 8)
    {
        print8();
    }
}

int input(void)
{
    int h;
    do
    {
        h = get_int("height: ");
    }
    while (h < 1 || h > 8);
    return h;
}

void print1(void)
{
    value1(0);
}

void print2(void)
{
    value1(1);
    value2(0);
}

void print3(void)
{
    value1(2);
    value2(1);
    value3(0);
}

void print4(void)
{
    value1(3);
    value2(2);
    value3(1);
    value4(0);
}

void print5(void)
{
    value1(4);
    value2(3);
    value3(2);
    value4(1);
    value5(0);
}

void print6(void)
{
    value1(6);
    value2(5);
    value3(4);
    value4(3);
    value5(2);
    value6(1);
}

void print7(void)
{
    value1(6);
    value2(5);
    value3(4);
    value4(3);
    value5(2);
    value6(1);
    value7(0);
}

void print8(void)
{
    value1(7);
    value2(6);
    value3(5);
    value4(4);
    value5(3);
    value6(2);
    value7(1);
    value8(0);
}

void value1(int s)
{
    for (int i = 0; i < s; i++)
    {
        printf(" ");
    }

    for (int i = 0; i < 1; i++)
    {
        printf("#");
    }
    printf("\n");
}

void value2(int s)
{
    for (int i = 0; i < s; i++)
    {
        printf(" ");
    }

    for (int i = 0; i < 2; i++)
    {
        printf("#");
    }
    printf("\n");
}

void value3(int s)
{
    for (int i = 0; i < s; i++)
    {
        printf(" ");
    }

    for (int i = 0; i < 3; i++)
    {
        printf("#");
    }
    printf("\n");
}

void value4(int s)
{
    for (int i = 0; i < s; i++)
    {
        printf(" ");
    }

    for (int i = 0; i < 4; i++)
    {
        printf("#");
    }
    printf("\n");
}

void value5(int s)
{
    for (int i = 0; i < s; i++)
    {
        printf(" ");
    }

    for (int i = 0; i < 5; i++)
    {
        printf("#");
    }
    printf("\n");
}

void value6(int s)
{
    for (int i = 0; i < s; i++)
    {
        printf(" ");
    }

    for (int i = 0; i < 6; i++)
    {
        printf("#");
    }
    printf("\n");
}

void value7(int s)
{
    for (int i = 0; i < s; i++)
    {
        printf(" ");
    }

    for (int i = 0; i < 7; i++)
    {
        printf("#");
    }
    printf("\n");
}

void value8(int s)
{
    for (int i = 0; i < s; i++)
    {
        printf(" ");
    }

    for (int i = 0; i < 8; i++)
    {
        printf("#");
    }
    printf("\n");
}