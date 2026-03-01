
// malloc() allocates memory on the HEAP instead of the stack.
//   - #include <stdlib.h> is required for malloc() and free().
//   - malloc(n) returns a void* pointing to n bytes of raw memory.
//   - You are responsible for calling free() when you are done.
//     Forgetting free() causes a memory leak.


#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    char *arr;

    n = 5;

    arr = malloc(n * sizeof(char)); // allocate 5 bytes on the heap

    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'd';
    arr[4] = 'e';
    // no '\0' at arr[5] -> printf("%s") is undefined behavior here
    // printf("%s") reads past the allocated memory -> undefined behavior.

    printf("%s\n", arr);

    free(arr); // always pair malloc with free
    return(0);
}
