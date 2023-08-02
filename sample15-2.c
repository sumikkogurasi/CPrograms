#include <stdio.h>

struct shain_dt {
    long no;
    int nensu;
    long kihon;
};

int main(void){
    struct shain_dt shomu[10] = {
        {78027, 21, 346780},
        {84004, 15, 223640},
        {87022, 12, 208760},
        {93042,  6, 176530},
        {95005,  4, 166700},
        {99009,  1, 150140},
        {0, 0, 0},
    };

    int i;

    printf("社員番号　勤続年数　基本給\n");
    printf("------------------------------\n");

    for(i = 0; shomu[i].no != 0; i++){
        printf("   %5ld     %6d     %6ld\n",
        shomu[i].no, shomu[i].nensu, shomu[i].kihon);
    }

    return 0;
}