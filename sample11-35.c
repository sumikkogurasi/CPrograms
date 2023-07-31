#include <stdio.h>

int main(void){
    int index1;
    int index2;

    for(index1 = 0; index1 < 10; index1++){
        for(index2 = 0; index2 < 10; index2++){
            if(index1 == index2){
                printf("X");
            } else{
                printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}