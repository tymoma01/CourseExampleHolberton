// This is the baseline before introducing malloc.
// The array lives on the stack: the compiler knows its size at compile time
// (here it is hardcoded to 3), so it reserves exactly the right space.
// When main() returns, the stack frame is destroyed and the memory is
// reclaimed automatically — no free() needed.

// The size must be a compile-time constant.

#include <stdio.h>

int main(void)
{
    int numbers[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Memory is freed automatically when main() returns
    return (0);
}
