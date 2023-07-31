#include <stdio.h>

int main(void){
    int data[20] = {1, 2, 5, 2, 3, 4, 0, 1, 1, 5, 3, 4, 4, 2, 5, 4, 0, 1 ,2 , 3};
    int i;
    int president[6] = {0, 0, 0, 0, 0, 0};

    for( i = 0; i < 20; i++){
        switch(data[i]){
            case 0:
                president[0]++;
                break;
            case 1:
                president[1]++;
                break;
            case 2:
                president[2]++;
                break;
            case 3:
                president[3]++;
                break;
            case 4:
                president[4]++;
                break;
            case 5:
                president[5]++;
                break;
        }
    }

    for( i = 0; i < 6; i++){
        printf("president[%d] : %d : %d\n", i , i,  president[i]);
    }

    printf("\n");
    
    int max = 0;
    int num = 0;

    for( i = 1; i < 6; i++){
        if(max <= president[i]){
            max = president[i];
            printf("president[%d] : %d : %d\n", i , i,  president[i]);
        }
    }

    return 0;
}