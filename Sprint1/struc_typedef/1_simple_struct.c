#include <stdio.h>

struct user {
    char *name;
    unsigned int age;
    unsigned int id;
    char *mail;
};

// -> Object Oriented Programming (see in Sprint 2)

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

    print_user(u); 
    return (0);
}


