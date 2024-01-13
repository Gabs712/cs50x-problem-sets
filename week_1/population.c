//Context: we have a population of start llamas. Each year, start/3 new llamas are born, and start/4 llamas
//pass away. How many years will to take to have a certain population of llamas?

#include <stdio.h>
#include <cs50.h>

int main ()
{

// start
int start;
do
{
    start = get_int ("Start size: ");
}
while (start < 9);

//end
int end;
do
{
    end = get_int ("End size: ");
}
while (end < start);

//calculus

int n = start;
int years = 0;

while ( n < end)
{
    n = n + n/3 - n/4;
    years++;
}


//print

printf ("Years: %i\n", years);

}