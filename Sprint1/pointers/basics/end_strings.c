#include <stdio.h>

int main(void)
{
    char s[10] = "Holberton";

    printf("%s\n", s);
    printf("Last char numeric value = %d\n", s[9]);
    printf("s (decayed) = %p\n", (void *)s);
    printf("\"Holberton\" literal = %p\n", (void *)"Holberton");

    // int i = 0;
    // while (s[i] != "\0"){
    //     //do something
    //     i++;
    // }

    return 0;
}
