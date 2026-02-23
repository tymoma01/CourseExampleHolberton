#include <stdio.h>

int main(void)
{
    int *pi;
    char *pc;
    double *pd;

    printf("sizeof(int*)    = %lu\n", (unsigned long)sizeof(pi));
    printf("sizeof(char*)   = %lu\n", (unsigned long)sizeof(pc));
    printf("sizeof(double*) = %lu\n", (unsigned long)sizeof(pd));

    return 0;
}
