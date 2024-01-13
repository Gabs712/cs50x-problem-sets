#include <cs50.h>
#include <stdio.h>

// Constant
const int N = 3;

// Prototype
float average(int array[]);

int main(void)
{
    // Get scores
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    // Print average
    printf("Average: %f\n", average(scores));
}

float average(int array[])
{
    // Calculate average
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += array[i];
    }
    return sum / (float) N;
}
