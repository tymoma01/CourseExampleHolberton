#include <stdio.h>

int gen_const(void){
    return 7;
}
int gen_cycle(void){
    static int v = 0; 
    return (v = (v+3)%10);
}

int main(void){
    int (*next)(void);

    next = gen_const;
    printf("%d %d\n", next(), next());

    next = gen_cycle;
    printf("%d %d %d\n", next(), next(), next());
    return 0;
}
