/* swap_behavior.c */
#include <stdio.h>

void wave(void){
    puts("~");
}
void beep(void){
    puts("beep");
}

int main(void){
    void (*act)(void); // pointer to a function, not defined yet

    act = wave; // first assignment - wave or &wave are equivalent (a function decays to its address)
    act();
    
    act = beep; // second assignment
    act();

    return 0;
}

// The pointer doesn’t store numbers — it stores actions.
