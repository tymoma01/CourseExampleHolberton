#include <stdio.h>

struct point {
    int x;
    int y;
};

typedef struct point point_t;

int main(void)
{
    struct point a = { 1, 2 };
    point_t b = { -3, 5 };

    printf("a=(%d,%d), b=(%d,%d)\n", a.x, a.y, b.x, b.y);
    return (0);
}
