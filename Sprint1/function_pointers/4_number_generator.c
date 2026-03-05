#include <stdio.h>

int gen_const(void){
    return 7;                        // always returns the same value
}
int gen_cycle(void){
    static int v = 0;                // static keeps its value between calls
    return (v = (v+3)%10);          // advances the cycle each time it is called
}

int main(void){
    int (*next)(void);               // pointer to a function that takes nothing and returns int

    next = gen_const;                // point to the constant generator
    printf("%d %d\n", next(), next());             // both calls return 7

    next = gen_cycle;                // swap — now point to the cycling generator
    printf("%d %d %d\n", next(), next(), next()); // each call returns a different value
    return 0;
}

// The same pointer next is reused for two completely different generators.
// Swapping the pointer changes the behavior without changing the call site.
