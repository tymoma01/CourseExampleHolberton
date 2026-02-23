#include <stdio.h>

struct meter {
    int value;
    void (*add)(struct meter*, int);
    void (*show)(const struct meter*);
};

void m_add(struct meter* m, int d){
    if (m) {
        m->value += d;
    }
}
void m_show(const struct meter* m){ 
    if (m) {
        printf("meter=%d\n", m->value);
    }
}

int main(void){
    struct meter m = {0, m_add, m_show};
    m.add(&m, 5);
    m.add(&m, 12);
    m.show(&m);
    return 0;
}
