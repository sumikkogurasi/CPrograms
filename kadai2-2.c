#include <stdio.h>

int main(void){
    int game[8][8] = {{0,0,0,1,1,0,0,0},
                      {0,0,1,0,0,1,0,0},
                      {0,1,0,0,0,0,1,0},
                      {1,0,0,0,0,0,0,1},
                      {1,1,1,1,1,1,1,1},
                      {1,0,0,0,0,0,0,1},
                      {1,0,0,0,0,0,0,1},
                      {1,0,0,0,0,0,0,2}};

    int i, j;

    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            switch(game[i][j]){
                case 0:
                    printf(".");
                    break;
                case 1:
                    printf("*");
                    break;
                default:
                    printf("?");
                    break;
            }
        }
        printf("\n");
    }

    printf("\n");

    int k = 0;

    while(k < 8){
    for(i = 0; i < 8; i++){
        for(j = 7; j >= 0; j--){
            if(j != 0){
                game[i][j] = game[i][j - 1];
            }else{
                game[i][0] = 0;
            }
        }
    }

    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            switch(game[i][j]){
                case 0:
                    printf(".");
                    break;
                case 1:
                    printf("*");
                    break;
                default:
                    printf("?");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
    k++;
    }
}