#include <stdio.h>

void disp_stars(int num);

int main(void){
    int apple = 0;
    int orange = 0;

    printf("りんごを何個買いましたか？\n");
    scanf("%d", &apple);
    printf("みかんを何個買いましたか？\n");
    scanf("%D", &orange);
    printf("\n");
    printf("--棒グラフを作成します。--\n");

    printf("りんご：");
    disp_stars(apple);
    printf("みかん：");
    disp_stars(orange);

    return 0;
}

void disp_stars(int num){
    while(num > 0){
        printf("*");
        num = num - 1;
    }
    printf("\n");
}