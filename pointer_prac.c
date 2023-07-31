#include <stdio.h>

int main(void){

    int x;
    int* p;

    // xの値を12にする

    p = &x;
    *p = 12;

    printf( "%d\n", x );
    
    char str[] = "hello world";

    // 'h'と'w'を大文字にする
    char *ptr;

    ptr = str;
    *ptr = 'H';
    ptr = ptr + 6;
    *ptr = 'W';
    
    printf( "%s\n", str );
    
    return 0;
}