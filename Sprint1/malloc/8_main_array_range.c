#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a = array_range(-2, 3);

    int i;

    if (!a) {
        return 1;
    }

    for (i = 0; i < 6; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
    free(a);
    return (0);
}
