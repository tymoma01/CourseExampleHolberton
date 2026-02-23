#include <stdio.h>

int factorial(int n)
{
    if (n < 0) // undefined behaviour for negative values
        return -1;

    if (n == 0) // stop
        return 1;

    return n * factorial(n - 1);  // recursion
}

// 5! = 1 x 2 x 3 x 4 x 5 = 120


int main(void)
{
    int n = 5;
    printf("%d! = %d\n", n, factorial(n));
    return 0;
}