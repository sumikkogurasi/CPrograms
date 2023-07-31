#include <stdio.h>

int main(void){
    int index;
    int data[10] = {1,3,5,7,9,11,13,15,17,19};
    int sagasu;
    int mitsuketa = 0;

    printf("What data do you need?\n");
    scanf("%d", &sagasu);

    for(index = 0; index < 10; index++){
        if(data[index] == sagasu){
            mitsuketa = 1;
            break;
        }
    }

    if(mitsuketa == 1){
        printf("found\n");
    }else{
        printf("Not found\n");
    }

    return 0;
}