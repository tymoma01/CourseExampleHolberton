#include <stdio.h>

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main(void)
{
    printf("%d\n", factorial(5)); /* 120 */
    return 0;
}



 //  4! = 1 x 2 x 3 x 4