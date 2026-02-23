#include <stdio.h>

void show_digit(char c){
    printf("[digit:%c]\n", c);
}
void show_other(char c){
    printf("[other:%c]\n", c);
}

int main(void){
    const char *s = "a1b2!";
    void (*on_digit)(char) = show_digit;
    void (*on_other)(char) = show_other;

    for (const char *p = s; *p; p++){
        if (*p >= '0' && *p <= '9') {
            on_digit(*p);
        }
        else {
            on_other(*p);
        }
    }
    return 0;
}
// use function pointers when the function to be called is not know before.
// It can depend on the environment, the user choice, a given file...
// You can’t decide that at compile time.
