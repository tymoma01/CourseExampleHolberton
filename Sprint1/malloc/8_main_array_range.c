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
