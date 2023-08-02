#include <stdio.h>

const double PI = 3.1415;

double ensyu(double radius){
    double ensyu;

    ensyu = PI * 2 * radius;
    return ensyu;
}

double menseki(double radius){
    double menseki;

    menseki = PI * radius * radius;
    return menseki;
}

int main(void){

    double radius = 0.1;
    double circle;
    double area;

    for(int i = 0; i < 20; i++){
        circle = ensyu(radius);
        area = menseki(radius);
        printf("radius: %lf, circle: %lf, area: %lf.\n", radius, circle, area);
        radius += 0.1;
    }

    return 0;
}