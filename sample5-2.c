#include <stdio.h>

int main(void){
    double height;

    printf("How tall are you?\n");
    scanf("%lf", &height);

    printf("Your height is %lf.", height);

    return 0;
}