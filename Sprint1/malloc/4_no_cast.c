#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr;

    arr = malloc(5 * sizeof(*arr));
    if (!arr)
    {
        perror("malloc failed");
        return 1;
    }

    for (int i = 0; i < 5; i++){
        arr[i] = i * 10;
    }

    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
