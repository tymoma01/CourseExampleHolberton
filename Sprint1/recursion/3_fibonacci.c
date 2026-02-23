#include <stdio.h>

// 1 + 1 = 2
// 1 + 2 = 3 
// 2 + 3 = 5
// 8
// 13

int fib(int n)
{
    if (n < 0) // undefined behaviour
        return -1;
    if (n == 0) // stop condition 1
        return 0;
    if (n == 1) // stop condition 2
        return 1;

    return fib(n - 1) + fib(n - 2);
}

int main(void)
{
    for (int i = 0; i < 10; i++)
        printf("%d ", fib(i));
    printf("\n");
    return 0;
}
