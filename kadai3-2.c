#include <stdio.h>

void data_in(int *p_price, int *p_num){
    
    printf("Input price.\n");
    scanf("%d", p_price);

    printf("How many do you buy?\n");
    scanf("%d", p_num);
}
int main(void){
    int price = 1000, total = 0, subtotal = 0, num = 0;
    double discount;
    const double DISCOUNT_RATE1 = 0.1;
    const double DISCOUNT_RATE2 = 0.2;

    data_in(&price, &num);

    if(num >= 20){
        discount = price * 10 * (1.0 - DISCOUNT_RATE1) + price * (num - 19) * (1.0 - DISCOUNT_RATE2);
        total = price * 9 + discount;
    }
    else if(num > 10 && num < 20){
        discount = price * (num - 9) * (1.0 - DISCOUNT_RATE1);
        total = price * 9 + discount;
    }
    else if(num < 10){
        total = price * num;
    }
    else if(num < 0 || num > 1000){
        total = -1;
    }

    if((num < 0 || num > 1000) && (price < 0 || price > 10000000)){
        printf("error num and price.\n");
    }
    else if(num < 0 || num > 1000){
        printf("error num.\n");
    }
    else if(price < 0 || price > 10000000){
        printf("error price.\n");
    }
    else{
        printf("You bought %d yen.\n", total);
    }

    return 0;
}