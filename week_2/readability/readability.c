// Take a text and determine it's grade level
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float c_letters(string text);
float c_words(string text);
float c_sentences(string text);

int main()
{
    // Get prompt from user
    string useri = get_string("Text: ");

    // Determine value of letters, words and sentences
    float l = c_letters(useri);
    float w = c_words(useri);
    float s = c_sentences(useri);

    // Determine values per 100 words
    float l_sum = l / w * 100;
    float s_sum = s / w * 100;

    // Index values to formula
    float coleman = 0.0588 * l_sum - 0.296 * s_sum - 15.8;

    // Round result
    int r = (int) round(coleman);

    // Print accordingly to result
    if (r < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (r >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        int k[15];
        for (int i = 0, j = 1; i < 15; i++, j++)
        {
            k[i] = j;

            if (r == k[i])
            {
                printf("Grade %i\n", k[i]);
            }
        }
    }
}

float c_letters(string text)
{
    float val = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            val++;
        }
    }
    return val;
}

float c_words(string text)
{
    float val = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            val++;
        }
    }
    val++;
    return val;
}

float c_sentences(string text)
{
    float val = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            val++;
        }
    }
    return val;
}