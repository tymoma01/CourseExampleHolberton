#include <stdio.h>

int main() {
    int age = 25;
    float weight = 80;
    char grade = 'C';
    char name[] = "Lachie";

    if (age > 20){
        printf("You are young");
    }
    else{
        printf("You are too young");
    }




    printf("Name: %s\n", name);          // string
    printf("Age: %d\n", age);            // integer
    printf("Weight: %.1f kg\n", weight); // float, 1 decimal
    printf("Grade: %c\n", grade);        // char

    return 0;
}
