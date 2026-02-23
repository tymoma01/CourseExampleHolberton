#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    char *word;
    struct node_s *next;
} node_t;

void free_l_list(node_t *head)
{
    node_t *tmp;

    while (head)
    {
        tmp = head->next;
        free(head->word);
        free(head);
        head = tmp;
    }
}

int main(void)
{
    node_t *head = malloc(sizeof(node_t));
    head->word = strdup("Hello");

    head->next = malloc(sizeof(node_t));
    head->next->word = strdup("World");
    
    head->next->next = NULL;

    printf("%s %s\n", head->word, head->next->word);

    // Free all allocated memory
    free_l_list(head);

    return 0;
}
