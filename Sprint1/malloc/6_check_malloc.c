// malloc() can return NULL — it is not guaranteed to succeed.
// This example deliberately exhausts memory to show that scenario.

// How it works:
//   - INT_MAX is the largest possible int (~2 GB on most systems).
//   - The loop asks for ~2 GB repeatedly without freeing anything.
//   - After a few iterations the OS has no more memory to give,
//     malloc returns NULL, and the program exits cleanly via the error branch.

// Key lesson: ALWAYS check the return value of malloc before dereferencing it.
// Dereferencing a NULL pointer is undefined behavior (usually a segfault).

// Also notice: the free(s) after the loop is unreachable here.
// In real code, every successful malloc must have a matching free on
// every exit path — including error paths.

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(void)
{
    char *s;
    while (1)
    {
        s = malloc(INT_MAX); // request ~2 GB each iteration
        if (s == NULL)       // this WILL happen eventually
            {
                fprintf(stderr, "Not enough memory left!\n");
                return (1);
            }
        s[0] = 'H';
        // no free(s) here -> memory leaks until the OS refuses to give more
    }
    free(s); // unreachable, but shows where the free should logically go
    return (0);
}
