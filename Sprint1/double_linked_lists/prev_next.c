#include <stdio.h>
#include <stdlib.h>

typedef struct dlist_s {
    char *song;
    struct dlist_s *prev;
    struct dlist_s *next;
} dlist_t;

int main(void)
{
    dlist_t *track1 = malloc(sizeof(dlist_t));
    dlist_t *track2 = malloc(sizeof(dlist_t));

    track1->song = "Song A";
    track1->prev = NULL;
    track1->next = track2;

    track2->song = "Song B";
    track2->prev = track1;
    track2->next = NULL;

    // Traverse forward
    printf("Forward: %s -> %s\n", track1->song, track1->next->song);

    // Traverse backward
    printf("Backward: %s -> %s\n", track2->song, track1->song);

    free(track1);
    free(track2);

    return 0;
}
