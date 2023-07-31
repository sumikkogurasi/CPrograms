#include <stdio.h>

int main(void){
    int n;
    int target = 0;
    int money = 0;
    double prate;
    double rate = 0.0;
    int total = 0;

    printf("あなたの目標金額はいくらですか？\n");
    scanf("%d", &target);

    printf("最初にいくら預けますか？\n");
    scanf("%d", &money);

    printf("利率は何%%ですか？\n");
    scanf("%lf", &prate);

    rate = prate / 100;
    total = money;
    n = 0;

    while(1){
        if(total >= target){
            break;
        }
        total = total * (1 + rate);
        n++;
    }

    printf("目標金額：%d 円\n", target);
    printf("%d 円を%f %%で預けると\n", money , prate);
    printf("%d 年かかります。\n", n);
    printf("合計%d 円になります。\n", total);

    return 0;
}