#include <stdio.h>

void countdown(int n)
{
    if (n == 0)
    {
        printf("Ready to go!\n");
        return; // STOP the recursion
    }

    printf("%d\n", n);

    countdown(n - 1); // RECURSIVE CALL
}

int main(void)
{
    countdown(5);
    return 0;
}
