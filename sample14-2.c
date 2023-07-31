#include <stdio.h>

int maxdata(int d[]);

int main(void){
    int data[5] = {1, 25, 19, 53, 9};
    int maximum;

    maximum = maxdata(data);
    printf("最大値は%d です。\n", maximum);
    return 0;
}

int maxdata(int d[]){
    int i;
    int max = d[0];

    for(i = 0; i < 5; i++){
        if(max < d[i]){
            max = d[i];
        }
    }

    return max;
}
