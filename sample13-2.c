#include <stdio.h>

int main(void){
    int age_in;
    int age_out;
    int *p;

    printf("あなたの年齢を入力してください。\n");
    scanf("%d", &age_in);

    p = &age_in;
    age_out = *p;

    printf("あなたの年齢は(age_in)は %d です。\n", age_in);
    printf("あなたの年齢は(age_out)は %d です。\n", age_out);

    return 0;
}