#include <stdio.h>

int main(void){
    int year, birthday, age;

    printf("What year is it now?\n");
    scanf("%d", &year);

    printf("What year was you born?\n");
    scanf("%d", &birthday);

    age = year - birthday;

    printf("Your age is %d.\n", age);

    return 0;
}