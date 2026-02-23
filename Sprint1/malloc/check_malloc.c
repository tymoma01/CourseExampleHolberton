#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(void)
{
    char *s;
    while (1)
    {
        s = malloc(INT_MAX);
        if (s == NULL)
            {
                fprintf(stderr, "Not enough memory left!\n");
                return (1);
            }
        s[0] = 'H';
    }
    free(s);
    return (0);
}
