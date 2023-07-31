#include <stdio.h>

int main(void){
    int data[10] = {8, 5, 4, 3, 2, 1, 0, 7, 6, 9};
    int i;
    int j;
    int tmp;

    for(i = 9; i >= 0; i--){
        for(j = 0; j < i; j++){
            if(data[j] > data[j + 1]){
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }

    for(i = 0; i < 10; i++){
        printf("data[%d] = %d\n", i, data[i]);
    }

    return 0;
}