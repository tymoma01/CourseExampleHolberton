#include <stdio.h>

int strlen_rec(const char *s)
{
    if (*s == '\0') // stop condition
        return 0;

    return 1 + strlen_rec(s + 1);
}

int main(void)
{
    printf("%d\n", strlen_rec("Holberton"));
    return 0;
}