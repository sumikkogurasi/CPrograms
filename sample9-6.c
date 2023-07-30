#include <stdio.h>

int main(void){
    int counter;

    for(counter = 0; counter < 10; counter++){
        if(counter % 2 == 0){
            printf("%d is even.\n", counter);
        }else{
            printf("%d is odd.\n", counter);
        }
    }

    return 0;
}