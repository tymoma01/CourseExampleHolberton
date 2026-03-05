#include <stdio.h>

struct meter {
    int value;
    void (*add)(struct meter*, int); // function pointer stored as a field 
    void (*show)(const struct meter*); // — acts like a method
};

void m_add(struct meter* m, int d){
    // guard against NULL pointer
    if (m) {
        m->value += d;
    }
}
void m_show(const struct meter* m){
    // guard against NULL pointer
    if (m) {
        printf("meter=%d\n", m->value);
    }
}

int main(void){
    struct meter m = {0, m_add, m_show}; // initialize value=0, assign both function pointers
    m.add(&m, 5); // call through the pointer
    m.add(&m, 12); // same pointer, same function, different argument
    m.show(&m); // call through the show pointer
    return 0;
}

// Storing function pointers inside a struct bundles data and behavior together.
// This is the same idea behind methods in object-oriented languages.
