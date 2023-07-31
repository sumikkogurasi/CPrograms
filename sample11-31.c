#include <stdio.h>

int main(void){
    int index;
    int money = 10000;
    double kinri = 0.05;

    for(index = 0; index < 10; index++){
        money = (int)(money * (1 + kinri));
        printf("%d years later's money is %d.\n", index + 1, money);
    }

    return 0;
}