#include <stdio.h>

int main(void){
    double height = 0.0, weight = 0.0, meter_height = 0.0;
    double bmi = 0.0, standard_weight = 0.0;

    printf("Calc your BMI.\n");
    printf("Input Information.\n\n");
    printf("-------------------------------\n");
    printf("How tall are you(cm)?\n");
    scanf("%lf", &height);
    printf("How weight are you(kg)?\n");
    scanf("%lf", &weight);

    /*センチ(cm)からメートル(m)に変換*/
    meter_height = height / 100;
    /*BMIの計算*/
    bmi = weight / (meter_height * meter_height);
    /*標準体重の計算*/
    standard_weight = (meter_height * meter_height) * 22;

    /*結果の出力*/
    printf("\n");
    printf("Your tall is %5.1lf.\n", height);
    printf("Your weight is %5.1lf.\n", weight);
    printf("Your BMI is %4.1lf.\n", bmi);
    printf("The average BMI of %5.1lf height's people weight is %5.1lf.\n", height, standard_weight);

    return 0;
}