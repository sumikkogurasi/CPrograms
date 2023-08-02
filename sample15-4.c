#include <stdio.h>

/* カロリー表の1行を保持するための構造体です。*/
struct calorie{
    int number;
    double value;
};

/* カロリー表を外部変数として持ちます。*/

struct calorie cal[10] = {
    {1, 150.0}, {2, 57.1}, {3, 133.3}, {4, 100.0}, {5, 250.0}\
};

/* カロリー表の項目数です。*/
int cal_num = 5;

/*　食材と数量を尋ねて総カロリーを計算する関数
    戻り値は総カロリーです。
    外部変数 cal と cal_num を参照します。*/

double calccal(void){
    int no = 0;
    double gram;
    double totalcal;
    int i; /* 食材を検索するカウンタ*/
    int hit; /* 食材が見つかったかどうか*/

    printf("\n--------------------\n");
    /* 総カロリーを 0.0 に初期化します*/
    totalcal = 0.0;
    /* 食材を尋ねて総カロリーを加算する無限ループ*/
    /* 食材番号が 0ならループを脱出して結果を返します。*/

    while(1){
        printf("食材番号(0 で入力終了)：");
        scanf("%d", &no);
        /* 0 が入力されたら while文を脱出して終了します。*/
        if(no == 0){
            break;
        }
        printf("グラム数：");
        scanf("%lf", &gram);

        /* noに一致する食材を検索します。*/
        hit = 0; /* まず見つかってない(0)とします*/
        for(i = 0; i < cal_num ; i++){
            if(cal[i].number == no){
                totalcal += cal[i].value * gram/100.0;
                /* 見つけたことを覚えます*/
                hit = 1;
                /* 経過を報告します。*/
                printf("　食材 %d を %6.2f グラム追加しました。\n", no, gram);
                printf("　カロリーの小計は %6.2f です。\n", totalcal);
                /* for文を脱出して計算を終わります。*/
                break;
            }
        }
        /* 見つからなかったことを報告します。*/
        if (hit == 0){
            printf("食材番号 %d は登録されていません。\n", no);
        }
    }
    return totalcal;
}
int main(void){
    int mode;
    double totalcal;

    printf("*** カロリー計算ツール ***\n");

    /* カロリー計算を繰り返す無限ループ*/
    while(1){
        printf("データ入力→1, 終了→0 を入力してください：");
        scanf("%d", &mode);
        if(mode == 0){
            /* 無限ループを脱出して終了 */
            break;
        }else if(mode == 1){
            /* calccal を呼び出してカロリーを計算し、総カロリーを表示します。*/
            totalcal = calccal();
            printf("総カロリー：%6.2f kcal\n\n", totalcal);
        }else {
            /* 想定していない入力です。*/
            printf("入力 %d に対応する処理はありません。\n", mode);
        }
    }

    return 0;
}