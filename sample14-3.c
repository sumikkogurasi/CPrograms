#include <stdio.h>

void swap(int *pa, int *pb){
    int tmp;

    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
    
}
int main(void){
    int data1 = 0;
    int data2 = 0;

    printf("数値１を入力してください：");
    scanf("%d", &data1);

    printf("数値２を入力してください：");
    scanf("%d", &data2);

    swap(&data1, &data2);

    printf("\n*****値を交換した結果*****\n");
    printf("数値１：%d\n", data1);
    printf("数値２：%d\n", data2);

    return 0;
}