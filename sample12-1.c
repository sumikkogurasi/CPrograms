#include <stdio.h>

int main(void){
    int n;
    int i;
    int money = 0;
    double rate = 0.0;
    double prate;
    int total = 0;

    printf("あなたの預金がいくらになるか計算しましょう！\n");
    printf("いくら預けますか？\n");
    scanf("%d", &money);

    printf("利率は何％ですか？\n");
    scanf("%lf", &prate);

    printf("何年預けますか？\n");
    scanf("%d", &n);

    rate = prate / 100;
    total = money;
    i = 0;
    while(i < n){
        total = total * (1 + rate);
        i++;
    }

    printf("%d 円を利率%f %%で%d 年預けると\n", money, rate, n);
    printf("合計%d 円になります。\n", total);

    return 0;
}