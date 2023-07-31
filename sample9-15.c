#include <stdio.h>

int main(void){
    int a[5] = {1,2,3,4,5};
    int counter;
    int min;

    min = a[0];
    for(counter = 0; counter < 5; counter++){
        if(min > a[counter]){
            min = a[counter];
        }
        printf("counter = %d a[counter] = %d min = %d\n", counter, a[counter], min);
    }

    return 0;
}