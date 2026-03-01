#include <stdio.h>

struct user {
    char *name;
    unsigned int age;
    unsigned int id;
};

void print_user(struct user u)
{
    printf("[print_user] %s (%u years) — id=%u\n", u.name, u.age, u.id);
}

int main(void)
{
    struct user u;

    u.name = "Thomas";
    u.age = 25;
    u.id = 1;

    // printf("User: name=%s, age=%u, id=%u\n", u.name, u.age, u.id);
    print_user(u); 
    return (0);
}


