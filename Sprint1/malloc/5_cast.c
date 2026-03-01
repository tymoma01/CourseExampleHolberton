// Why does it still work?
//   - #include <stdlib.h> makes the compiler aware that malloc returns void*.
//   - void* is implicitly and safely converted to int* without a cast.

// Why is the cast still a bad habit?
//   - It adds noise with no benefit (readability)
//   - If you accidentally omit #include <stdlib.h> and add the cast, the
//     compiler may silently assume malloc returns int (C89 implicit int rule),
//     leading to a truncated pointer on 64-bit systems — a hard-to-find bug.

// Rule: in C, never cast the return value of malloc/calloc/realloc -> code works
// Unless you want to have a better readability -> code readable

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr;

    // unnecessary cast — remove it in real C code
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
