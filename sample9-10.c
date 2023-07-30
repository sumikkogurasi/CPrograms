#include <stdio.h>

int main(void){
    int price[3];
    int subtotal;
    int tax;
    int total;
    const double TAX_RATE = 0.05;

    printf("Buy three times limit 10000 yen.\n");
    printf("Input first time.\n");
    scanf("%d", &price[0]);

    printf("Input second time.\n");
    scanf("%d", &price[1]);

    printf("Input third time.\n");
    scanf("%d", &price[2]);

    subtotal = price[0] + price[1] + price[2];
    tax = subtotal * TAX_RATE;
    total = subtotal + tax;

    printf("subtotal is %d yen.\n", subtotal);
    printf("tax is %d yen.\n", tax);
    printf("total is %d yen.\n", total);

    return 0;
}