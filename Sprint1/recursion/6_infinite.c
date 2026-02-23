#include <stdio.h>

int f(int n)
{
    if (n == 1)
        return 1;

    return f(n / 2 + 1); 
}

// tests

int main(void){
    printf("%d\n", f(5));
    return (0);
}