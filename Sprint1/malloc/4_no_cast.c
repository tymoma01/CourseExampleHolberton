// 3 best practices here:
//   1. Do NOT cast the return of malloc in C.
//      malloc returns void*, which is implicitly converted to any pointer type.
//      Adding a cast like (int*) is redundant and can mask a real bug:
//      if you forget #include <stdlib.h>, the compiler (in C89) assumes malloc
//      returns int. Without the cast it warns you; with the cast it silently
//      produces wrong code on 64-bit systems where sizeof(int) != sizeof(void*).
// 
//   2. Use sizeof(*arr) instead of sizeof(int).
//      If you later change the type of arr (e.g. to long*), sizeof(*arr)
//      updates automatically — one less place to forget to change.
// 
//   3. Always check the return value of malloc before using the pointer.
//      perror() prints the system error message to stderr.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr;

    arr = malloc(5 * sizeof(*arr)); // no cast, sizeof(*arr) adapts to the type
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
