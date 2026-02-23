#include <stdio.h>

int main(void)
{
    char *words[] = {"Holberton", "C_is_fun", "Pointers"};
    char **p = words; // decays to &words[0]

    printf("%s\n", words[0]);
    printf("%s\n", *p);
    printf("%s\n", *(p + 1));
    printf("%c\n", *(*(p + 2) + 0));

    return 0;
}