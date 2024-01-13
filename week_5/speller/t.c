#include <stdio.h>
#include <stdlib.h>

#define numbers 25

typedef struct node
{
    int num;
    struct node *next;
}
node;

int main()
{
    node *header = NULL;

    for (int i = 0; i < numbers; i++)
    {
        node *p = malloc(sizeof(node));
        if (p == NULL)
        {
            return 1;
        }
        p->num = i + 1;
        p->next = header;
        header = p;
    }


    printf("\n-- List --\n----------\n");
    node *trav = header;
    while(trav != NULL)
    {
        printf(". %02i\n", trav->num);
        trav = trav->next;
    }
    printf("----------\n");

    trav = header;

    while (trav != NULL)
    {
        trav = trav->next;
        free(header);
        header = trav;
    }
}