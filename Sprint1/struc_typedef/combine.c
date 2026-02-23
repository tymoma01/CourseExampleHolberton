#include <stdio.h>
#include <stdlib.h>

// Define + alias at once
typedef struct user {
    char *name;
    unsigned int age;
} user_t;

user_t make_user(char *name, unsigned int age) {
    user_t u;
    u.name = name;
    u.age = age;
    return (u);
}

int main(void) {
    user_t u = make_user("Fran", 33);

    printf("%s is %u\n", u.name, u.age);
    return (0);
}
