/*
** CALLER'S RESPONSIBILITY — FREEING MEMORY RETURNED BY A FUNCTION
**
** This is the counterpart to 7_array_range.c.
** It shows the caller side of the ownership pattern:
**   - Call a function that returns heap-allocated memory.
**   - Always check for NULL before using the pointer.
**   - Free the memory when done — even though it was allocated elsewhere.
**
** The golden rule: whoever calls malloc (directly or indirectly) must
** ensure that free() is called exactly once for each allocation, on
** every exit path (including error paths).
**
** Note: because of the bug in 7_array_range.c (free before return),
** this program actually accesses freed memory. Running it under
** valgrind or AddressSanitizer (-fsanitize=address) will catch this.
*/
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a = array_range(-2, 3); // caller receives ownership of the array

    int i;

    if (!a) {           // NULL check before any use
        return 1;
    }

    for (i = 0; i < 6; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
    free(a);            // caller is responsible for freeing
    return (0);
}
