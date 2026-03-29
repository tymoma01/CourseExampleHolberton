#include <stdio.h>


void countdown(int n)
{
    if (n == 0) // BASE CASE: nothing left to count down
    {
        printf("Ready to go!\n");
        return; // STOP the recursion
    }

    printf("%d\n", n); // do some work BEFORE the recursive call

    countdown(n - 1); // RECURSIVE CALL — same function, smaller problem
}

int main(void)
{
    countdown(5);
    return 0;
}
