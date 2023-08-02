#include <stdio.h>

struct shain_dt{ /*社員情報の構造体*/
    long no;    /*社員番号*/
    int nensu;  /*勤続年数*/
    long kihon; /*基本給*/
};

int main(void){
    struct shain_dt shomu = {78027, 21, 346780}; /*庶務課*/

    printf("社員番号　勤続年数　基本給\n");
    printf("--------------------------------\n");
    printf(" %5ld   %6d    %6ld\n", shomu.no, shomu.nensu, shomu.kihon);

    return 0;
}