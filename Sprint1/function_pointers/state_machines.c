#include <stdio.h>

// Prototypes declarations
void closed(char evt);
void open(char evt);

typedef void (*state_f)(char evt);

// global variable - adding static to make is file restricted
state_f current;

void closed(char evt){
    puts("state=CLOSED");
    if (evt=='o') {
        current = open;
    }
}

void open(char evt){
    puts("state=OPEN");
    if (evt=='c') {
        current = closed;
    }
}

int main(void){
    current = closed; // The function is not called here, the current pointer is assigned to the function closed.    
    current('o');
    current('x');
    current('c');
    return 0;
}
