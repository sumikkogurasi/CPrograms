#include <stdio.h>

int main(void){
    /*moneyは支払額、priceは買い物額、changeはおつり、billsは紙幣や効果の枚数*/
    int money, price, change, bills;

    printf("Input price what you buy.\n");
    scanf("%d", &price);

    printf("Input money what you sell.\n");
    scanf("%d", &money);

    printf("\n****** change list*********\n\n");

    /*おつりを計算します。*/
    change = money - price;

    /*5000円の枚数を求める。int型同士の割り算なので余りを切り捨てます。*/
    bills = change / 5000;
    printf("5000 yen bills: %d\n", bills);

    /*5000円札の枚数を求め、残額を計算します。*/
    change = change % 5000;

    /*1000円の枚数を求め、残額を計算します。*/
    bills = change / 1000;
    printf("1000 yen bills: %d\n", bills);
    change = change % 1000;

    /*500円の枚数を求め、残額を計算します。*/
    bills = change / 500;
    printf("500 yen bills: %d\n", bills);
    change = change % 500;

    /*100円の枚数を求め、残額を計算します。*/
    bills = change / 100;
    printf("100 yen bills: %d\n", bills);
    change = change % 100;

    /*50円の枚数を求め。残額を計算します。*/
    bills = change / 50;
    printf("50 yen bills: %d\n", bills);
    change = change % 50;

    /*10円の枚数を求め、残額を計算します。*/
    bills = change / 10;
    printf("10 yen bills: %d\n", bills);
    change = change % 10;

    /*5円の枚数を求め、残額を計算します。*/
    bills = change / 5;
    printf("5 yen bills: %d\n", bills);
    bills = change % 5;

    /*1円玉の枚数を求めます。*/
    printf("1 yen bills: %d\n", bills);

    return 0;
}