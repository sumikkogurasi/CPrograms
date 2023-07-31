#include <stdio.h>

int main(void){
    int i;
    int j;
    int data[10][10];

    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            data[i][j] = 1;
        }
    }

    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){

            if(j != 0){
                printf(",");
            }
            printf("%d", data[i][j]);
        }
        printf("\n");
    }

    return 0;
}