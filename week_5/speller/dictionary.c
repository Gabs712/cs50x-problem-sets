// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 77;

// Hash table
node *table[N];
unsigned long int words_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    node *trav = table[index];
    while (trav != NULL)
    {
        if (strcasecmp(word, trav->word) == 0)
        {
            return true;
        }

        else
        {
            trav = trav->next;
        }
    }
    return false;
}
// Hashes word to a number
unsigned int hash(const char *word)
{
    if (!isalpha(word[0]) || !isalpha(word[1]) || !isalpha(word[2]))
    {
        return 76;
    }
    else if (strlen(word) >= 3)
    {
        return (toupper(word[0]) - 'A') + (toupper(word[1]) - 'A') + (toupper(word[2]) - 'A');
    }
    else if (strlen(word) == 2)
    {
        return (toupper(word[0]) - 'A') + (toupper(word[1]) - 'A');
    }
    else
    {
        return (toupper(word[0]) - 'A');
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1];
    while (fscanf(file, "%s", buffer) != EOF)
    {
        words_count++;
        node *p = malloc(sizeof(node));
        if (p == NULL)
        {
            return false;
        }

        int index = hash(buffer);

        strcpy(p->word, buffer);
        p->next = table[index];
        table[index] = p;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return words_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *trav = NULL;
    for (int i = 0; i < N; i++)
    {
        trav = table[i];
        while (trav != NULL)
        {
            node *temp = trav;
            trav = trav->next;
            free(temp);
        }
    }
    return true;
}
