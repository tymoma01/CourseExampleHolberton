#include <stdio.h>

void modif_my_char_var(char *cc, char ccc)
{
    if (*cc != ccc){
        *cc = ccc;
    }
}

int main(void)
{
    char c = 'H';
    char *p = &c;
    char new_char = 'Y';

    // p -> c -> 'H'

    printf("Before: c = %c\n", c);
    modif_my_char_var(p, new_char);
    printf("After: c = %c\n", c);
    return 0;
}



