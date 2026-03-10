#include <stdio.h>

void show_digit(char c){
    printf("[digit:%c]\n", c);
}
void show_other(char c){
    printf("[other:%c]\n", c);
}

int main(void){
    const char *s = "a1b2!";
    void (*on_digit)(char) = show_digit; // pointer initialized to show_digit — can be swapped later
    void (*on_other)(char) = show_other; // pointer initialized to show_other
    void (*temp)(char);

    for (const char *p = s; *p; p++){ // walk through each character of the string
        if (*p >= '0' && *p <= '9') {
            on_digit(*p); // call the function pointed to by on_digit
            // on_digit -> find the address of the pointer -> retrieve the function at this address
            // get the argument (p) -> call the function
        }
        if (*p >= 's'){
            // swap the behaviour
            temp = on_digit;
            on_other = temp;
            on_digit = on_other;
        }
        else {
            on_other(*p); // call the function pointed to by on_other
        }
    }
    return 0;
}

// use function pointers when the function to be called is not known in advance.
// It can depend on the environment, the user choice, a given file...
// You can’t decide that at compile time.
