#include <stdio.h>

int main(void){
    int a[5] = {1,2,3,4,5};
    int counter;
    int index;
    int data = 0;

    index = -1;

    printf("Input a number what you want to find.\n");
    scanf("%d", &data);

    for(counter = 0; counter < 5; counter++){
        if(a[counter] == data){
            index = counter;
        }
        printf("counter = %d a[%d] = %d index = %d\n", counter , counter, a[counter], index);
    }

    return 0;
}