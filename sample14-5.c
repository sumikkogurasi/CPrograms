#include <stdio.h>

void calc1(int *pa){
    printf("calc：a = %d\n", *pa);
    *pa = 10 * 10;
}

void calc2(int b){
    printf("calc：b = %d\n", b);
    b = 10 * 10;
}
int main(void){
    int data1 = 10;
    int data2 = 10;

    calc1(&data1);
    calc2(data2);

    printf("\n*****計算結果*****\n");
    printf("calc1：%d\n", data1);
    printf("calc2：%d\n", data2);

    return 0;
}