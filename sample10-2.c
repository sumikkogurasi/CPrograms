#include <stdio.h>

int main(void){
    int counter;
    double kisyo[2][12];

    printf("Input temp and rain.\n");

    for(counter = 0; counter < 12; counter++){
        printf("%2d month = ", counter + 1);
        scanf("%lf %lf", &kisyo[0][counter], &kisyo[1][counter]);
    }

    printf("month: temp[C] rain[mm]\n");

    for(counter = 0; counter < 12; counter++){
        printf("%2d month: %10.1f %10.1f\n", counter  + 1, kisyo[0][counter], kisyo[1][counter]);
    }

    return 0;
}