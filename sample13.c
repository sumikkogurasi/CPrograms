#include <stdio.h>

int main(void){
    int age;

    printf("あなたの年齢を入力してください。\n");
    scanf("%d", &age);

    printf("あなたの年齢は%d 歳です。\n", age);
    printf("年齢を格納していた変数age の場所は%p です。\n", &age);

    return 0;
}