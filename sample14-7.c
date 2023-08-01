#include <stdio.h>
int x;
int y;

void myfunc(int a){
    int x;
    int z;

    x = a;
    y = a;
    z = a;
}
int main(void){
    int z;

    x = 10;
    y = 10;
    z = 10;

    printf("x,y,zの値は%d, %d, %dです。\n", x,y,z);
    myfunc(2);
    printf("関数から戻ってきた後の値");
    printf("x,y,zは%d, %d, %dです。\n", x,y,z);

    return 0;
}