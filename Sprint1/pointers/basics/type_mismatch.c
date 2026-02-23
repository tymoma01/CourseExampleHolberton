#include <stdio.h>

int main(void)
{
    char c = 'H';
    int *p;

    p = &c;
    // WRONG: pointer type mismatch

    (void)c;
    (void)p;
    return 0;
}
