#include<stdio.h>
int main(){
    char linhas[10] ={'A' ,'B' ,'C' ,'D' , 'E' ,'F' , 'G' ,'H' , 'I' ,'J'};
    int tabuleiro[10][10] = {0};

    tabuleiro[3][3] = 3;
    tabuleiro[3][4] = 3;
    tabuleiro[3][5] = 3;

    tabuleiro[3][7] = 3;
    tabuleiro[4][7] = 3;
    tabuleiro[5][7] = 3;

    tabuleiro[3][1] = 3;
    tabuleiro[4][2] = 3;
    tabuleiro[5][3] = 3;

    tabuleiro[7][7] = 3;
    tabuleiro[8][8] = 3;
    tabuleiro[9][9] = 3;


    printf("TABULEIRO BATALHA NAVAL\n");
    printf("  ");
    for (int i = 0; i < 10; i++){
        printf("%c ", linhas[i]);
    }
    for (int e = 0; e < 10; e++){
        printf("\n%2d ", e+1);
    for (int f = 0; f < 10; f++){
        printf("%d ", tabuleiro[e][f]);
    }
    
    
}
    return 0;   
}