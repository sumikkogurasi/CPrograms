#include <stdio.h>

int in_data(void){
    int data = 0;

    printf("星の数を入力してください:");
    scanf("%d", &data);
    return data;
}

int main(void){
    int num = 0;
    int i;

    num = in_data();
    printf("星の数：");

    for(i = 0; i < num; i++){
        printf("*");
    }
    printf("\n");

    return 0;
}