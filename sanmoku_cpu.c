#include <stdio.h>
#include <stdlib.h.>
#include <time.h>

/* 手番、コマの符号化*/
const int FIRST = 1;
const int SECOND = 2;
const int OPEN = 0;

/* k 番目の棋譜（最終盤面）を設定する k の値が不適切なら 1 を、適切なら 0 を返す*/
const int DATA_CASES = 3;

/* 三目並べ符号化*/
int board[3][3];

/* range_min 以上、range_max 未満の乱数を返します*/
int ranged_rand(int range_min, int range_max){
    int u;
    u = (double)rand()/(RAND_MAX + 1)*(range_max - range_min) + range_min;
    return u;
}
/* ここに必要な関数のプロトタイプを書く*/

void sanmoku(void);

/* ここに必要な関数の中身を書く*/
/* 関数プロトタイプ*/
void init_board(void);
void show_board(void);
int set_test_data(int k);
int is_open(int x, int y);
int is_board_full(void);

int is_win_horizontal(int turn);
int is_win_vertical(int turn);
int is_win_diagonal(int turn);
int is_win_reverse_diagonal(int turn);
int is_win(int turn);

void place(int turn, int x, int y);
void show_turn(int turn);

void get_move(int turn, int *p_x, int *p_y);
int show_status(int turn);

/* 手番 turn の手をもらう*/
void get_move(int turn, int *p_x, int *p_y){
    int n;
    while(1){
        show_turn(turn);
        printf("の番です。手を入力してください：");
        n = scanf("%d%d", p_x, p_y);
        /* 数字がふたつ入力されていなければ改行まで読み飛ばす。*/
        if(n != 2){
            while(getchar() != '\n'){

            }
        }
        if(is_open(*p_x, *p_y)){
            return;
        }
        printf("不適当です。もう一度入力してください。\n");
    }
}
/* 盤面の状況を検査して出力する*/
int show_status(int turn){
    if(is_win(turn)){
        show_turn(turn);
        printf("の勝ちです\n");
    }else if(is_board_full()){
        printf("引き分けです.\n");
    }
}
/* 盤面を更新する。引数の値x, yは予め、is_open() で検査済みと仮定*/
void place(int turn, int x, int y){
    board[x][y] = turn;
}

/* 手番をコマの種類により画面に表示する関数*/
void show_turn(int turn){
    if(turn == FIRST){
        printf("〇");
    }else if(turn == SECOND){
        printf("×");
    }
}
/* 水平方向に手番 turn の勝ちを判定する　手番 turn が勝ちなら 1 を、そうでなければ 0 を返す*/
int is_win_horizontal(int turn){
    int i,j,flag;
    for(i = 0; i < 3; i++){
        flag = 1;
        for(j = 0; j < 3; j++){
            if(board[i][j] != turn){ /* i の行は揃っていない*/
                flag = 0;
                break;
            }
        }
        if ( flag == 1){
            /* 勝っている行が見つかった*/
            return 1;
        }
    }
    return 0;
}

/* 垂直方向に手番 turn の勝ちを判定する　手番 turn が勝ちなら 1 を、そうでなければ 0 を返す*/
int is_win_vertical(int turn){
    int i,j,flag;
    for(j = 0; j < 3; j++){
        flag = 1;
        for(i = 0; i < 3; i++){
            if(board[i][j] != turn){ /* i の行は揃っていない*/
                flag = 0;
                break;
            }
        }
        if ( flag == 1){
            /* 勝っている行が見つかった*/
            return 1;
        }
    }
    return 0;
}

/* 右下斜め方向に手番 turn の勝ちを判定する 手番 turn が勝ちなら 1 を、そうでなければ 0 を返す*/
int is_win_diagonal(int turn){
    int i;
    for(i = 0;i < 3; i++){
        if(board[i][i] != turn){
            return 0;
        }
    }
    return 1;
}

/* 左下斜め方向に手番 turn の勝ちを判定する 手番 turn が勝ちなら 1 を、そうでなければ 0 を返す*/
int is_win_reverse_diagonal(int turn){
    int i;
    for(i = 0;i < 3; i++){
        if(board[i][2 - i] != turn){
            return 0;
        }
    }
    return 1;
}

/* 手番 turn の勝ちを判定する。手番 turn が勝ちなら 1 を、そうでなければ 0 を返す*/
int is_win(int turn){
    if(is_win_horizontal(turn)){
        return 1;
    }
    if(is_win_vertical(turn)){
        return 1;
    }
    if(is_win_diagonal(turn)){
        return 1;
    }
    if(is_win_reverse_diagonal(turn)){
        return 1;
    }
    return 0;
}
void test3(void){
    int turn;
    int test;
    init_board();
    for(test = 0; test < DATA_CASES; test++){
        set_test_data(test);
        show_board();
        for(turn = 1; turn < 3; turn++){
            printf("水平方向に %d の勝ちがどうか：%d\n", turn, is_win_horizontal(turn));
            printf("垂直方向に %d の勝ちがどうか：%d\n", turn, is_win_vertical(turn));
            printf("対角方向に %d の勝ちがどうか：%d\n", turn, is_win_diagonal(turn));
            printf("逆対角方向に %d の勝ちがどうか：%d\n", turn, is_win_reverse_diagonal(turn));
            
            printf("%d の勝ちかどうか：%d\n", turn, is_win(turn));
        }
    }
}
/* 引数x,yを与えられる一を検査して空きなら１を、そうでなければ０を返す。*/
int is_open(int x, int y){
    /* 引数の検査、不適当なら 0 を返す*/
    if((x < 0) || (x >= 3)){
        return 0;
    }
    if((y < 0) || (y >= 3)){
        return 0;
    }
    /* 盤面の検査*/
    if(board[x][y] == OPEN){
        return 1;
    }else {
        return 0;
    }
}
/* 盤面にひとつでも空きがあれば0を、全て埋まっていれば、1を返す*/
int is_board_full(void){
    int i,j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(board[i][j] == OPEN){
                /* 空いている所があれば 0 を返す。*/
                return 0;
            }
        }
    }
    /* どこも空いていないので 1 を返す。*/
    return 1;
}

void test2(void){
    init_board();
    /* 0番目の盤面を使っていくつかのテストをします。*/
    set_test_data(0);
    show_board();
    if(is_open(-1,-1)){
        printf("-1,-1には打てます。\n");
    }else{
        printf("-1,-1には打てません\n");
    }
    if(is_open(0,0)){
        printf("0,0には打てます。\n");
    }else{
        printf("0,0には打てません\n");
    }
    if(is_open(0,2)){
        printf("0,2には打てます。\n");
    }else{
        printf("0,2には打てません\n");
    }
    if(is_board_full()){
        printf("盤面にはもう空きがありません\n");
    }else{
        printf("盤面にはまだ空きがあります\n");
    }
    /* 2番目の盤面を使っていくつかのテストをします*/
    set_test_data(2);
    show_board();
    if(is_board_full()){
        printf("盤面にはもう空きがありません\n");
    }else {
        printf("盤面にはまだ空きがあります\n");
    }
}
/* 配列 board のすべての要素にOPEN を代入する。*/
void init_board(void){
    int i,j;
    for ( i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            board[i][j] = OPEN;
        }
    }
}

/* 配列 board の状況を端末に出力する*/
void show_board(void){
    int i, j;
    printf("    0 1 2\n");
    printf("-----------\n");
    for(i = 0; i < 3; i++){
        printf("%1d |", i);
        for(j = 0; j < 3; j++){
            if(board[i][j] == FIRST){
                printf("〇");
            }else if(board[i][j] == SECOND){
                printf("✖");
            }else{
                printf("　");
            }
            printf("|");
        }
        printf("\n");
        printf("-------------------\n");
    }
}


int set_test_data(int k){
    int i, j; /*棋譜データ（三次元配列を使っています）*/
    //test_case[DATA_CASES][3][3]
int test_case[3][3][3] = {
    {{1,2,0},{1,1,1},{2,0,2}},
    {{2,0,0},{2,1,1},{2,0,1}},
    {{1,2,1},{2,2,1},{1,2,1}}
};

    if((k < 0) || (k >= DATA_CASES)) { /* kの範囲のデータ*/
        return 1;
    }else { 
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                board[i][j] = test_case[k][i][j];
            }
        }
        return 0;
    }
}

void test1(void){
    init_board();
    show_board();
    set_test_data(0);
    show_board();
    set_test_data(1);
    show_board();
    set_test_data(2);
    show_board();
}

void test4(void){
    int turn;
    init_board();
    turn = FIRST;
    show_board();
    show_turn(turn);
    printf("\n");
    place(turn, 0, 0);
    show_board();
    if(turn == FIRST){
        turn = SECOND;
    } else {
        turn = FIRST;
    }
    show_turn(turn);
    printf("\n");
    place(turn, 1, 1);
    show_board();
}

void test5(void){
    int turn;
    int x,y;
    init_board();
    turn = FIRST;
    board[0][0] = 1;
    board[1][1] = 2;
    board[0][1] = 1;
    board[1][0] = 2;
    show_board();
    get_move(turn,&x,&y);
    printf("Move = %d, %d\n", x, y);
    place(turn ,x, y);
    show_board();
    show_status(turn);
    if(turn == FIRST){
        turn = SECOND;
    }else {
        turn = FIRST;
    }
    get_move(turn,&x,&y);
    printf("Move = %d, %d\n", x, y);
    place(turn, x, y);
    show_board();
    show_status(turn);
}
/* 三目並べのプログラム*/
void sanmoku(void){
    /* turn は手番、 FIRSTかSECOND*/
    int turn;
    /* 今は何もしないで終わる。*/
    int x;
    int y;
    turn = FIRST; /* 手番と盤面の初期化*/
    init_board();
    while(1){       /* 手番を交代しながら繰り返し*/
        show_board();
        get_move(turn, &x, &y);
        place(turn, x, y);
        show_status(turn);
        /* 勝負がつくか引き分けならループを脱出して終了*/
        if((is_win(turn)) || (is_board_full())){
            show_board();
            break;
        }
        if(turn == FIRST){  /* 手番の交代*/
            turn = SECOND;
        }else{
            turn = FIRST;
        }
    }
}

/* コンピュータの手を決める関数。いまは人間が代わりに打つ*/
void get_computers_move(int turn, int *p_x, int *p_y){
    //get_move(turn, p_x, p_y);
    int i, j, n, r;
    /* 空白の数を数える*/
    n = 0;
    for(i =0; i < 3; i++){
        for(j = 0;j < 3; j++){
            if(is_open(i,j)){
                n++;
            }
        }
    }
    /* 乱数を発生させる*/
    r = ranged_rand(0, n);
    /* r　番目（0 から数えて）の空白を探し、引数を返す*/
    n = 0;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(is_open(i,j)){
                if(r == n){
                    *p_x = i;
                    *p_y = j;
                    return;
                }
                n++;
            }
        }
    }
}

int sanmoku_with_computer(void){
    int turn;
    int x, y;
    int t, i;
    /* 人間が先手か後手かを記録する変数*/
    int human;
    /* 乱数を初期化して人間が先手か後手かを決めます*/
    t = time(NULL);
    srand((unsigned)t);
    rand();
    /* 人間が先手か後手かを決めます*/
    human = ranged_rand(1, 3);
    if(human == FIRST){
        printf("人が先手です。\n");
    }else{
        printf("コンピュータが先手です。\n");
    }
    turn = FIRST;
    init_board();
    show_board();
    while(1){
        if(turn == human){
        get_move(turn, &x, &y);
        }else{
            get_computers_move(turn, &x, &y);
            printf("コンピュータは%d %dに打ちます。\n", x, y);
        }
        place(turn, x, y);
        show_board();
        show_status(turn);
        /* 勝負がつくか引き分けならループを脱出して終了*/
        if((is_win(turn)) || (is_board_full())){
            break;
        }
        if(turn == FIRST){  /* 手番の交代*/
            turn = SECOND;
        }else{
            turn = FIRST;
        }
    }
}
/* テストをする度に中身を変える*/
int main(void){
    //test5();
    //test4();
    //test3();
    //test2();
    //test1();
    sanmoku_with_computer();
    return 0;
}