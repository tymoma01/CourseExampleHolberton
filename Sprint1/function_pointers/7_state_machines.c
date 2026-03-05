#include <stdio.h>

// Prototypes needed because closed and open reference each other
void closed(char evt);
void open(char evt);

// define a type alias for the function pointer — easier to read
typedef void (*state_f)(char evt); 

// global variable — holds the current state as a function pointer
// adding static would restrict it to this file
state_f current;

void closed(char evt){
    puts("state=CLOSED");
    if (evt=='o') {
        current = open; // transition: event 'o' moves us to the open state
    }
}

void open(char evt){
    puts("state=OPEN");
    if (evt=='c') {
        current = closed; // transition: event 'c' moves us back to the closed state
    }
}

int main(void){
    current = closed; // initial state — the pointer is assigned, not called
    current('o'); // calls closed('o') — prints state, then transitions to open
    current('x'); // calls open('x') — prints state, no transition ('x' is not handled)
    current('c'); // calls open('c') — prints state, then transitions back to closed
    printf("final state=%s\n", current == open ? "open" : "closed");
    return 0;
}

// Each state is a function. The current pointer holds which state we are in.
// Transitioning means reassigning the pointer — no switch, no enum needed.
