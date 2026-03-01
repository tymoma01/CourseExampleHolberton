#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr;

    // unnecessary cast
    // Works thanks to -> #include <stdlib.h>
    arr = (int *)malloc(5 * sizeof(*arr));

    if (!arr){
        return 1;
    }

    for (int i = 0; i < 5; i++){
        arr[i] = i;
    }
    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
