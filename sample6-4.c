#include <stdio.h>

int main(void){
    int price1, price2, price3;
    int subtotal, tax_price, total;
    const double TAX_RATE = 0.05f;

    printf("Buy three times muximum is 10000.\n");
    printf("Input first time\n");
    scanf("%d",  &price1);

    printf("Input second time\n");
    scanf("%d",  &price2);

    printf("Input third time\n");
    scanf("%d",  &price3);

    subtotal = price1 + price2 + price3;
    tax_price = subtotal * TAX_RATE;
    total = subtotal + tax_price;

    printf("subtotal is %d yen.\n", subtotal);
    printf("tax is %d yen.\n", tax_price);
    printf("total is %d yen.\n", total);
    
    return 0;
}