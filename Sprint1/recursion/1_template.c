#include <stdio.h>

void countdown(int n)
{
    if (n == 0) // stop condition 
    {
        printf("Lift off!\n");
        return;
    }

    countdown(n - 1); // the recursive call
    
    printf("%d\n", n);
}

int main(void)
{
    countdown(5);
    return 0;
}