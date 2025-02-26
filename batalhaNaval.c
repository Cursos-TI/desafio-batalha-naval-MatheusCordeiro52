#include <stdio.h>
#define TAM 10
#define TAM_HAB 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar navios no tabuleiro
void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Navio vertical
    for (int i = 2; i < 5; i++) {
        tabuleiro[i][4] = 3; // Navio na coluna 4 (E)
    }
    // Navio horizontal
    for (int j = 1; j < 4; j++) {
        tabuleiro[6][j] = 3; // Navio na linha 6 (7)
    }
    // Navios na diagonal
    for (int d = 0; d < 3; d++) {
        tabuleiro[d][d] = 3; // Diagonal principal
        tabuleiro[d][9 - d] = 3; // Diagonal inversa
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("   A B C D E F G H I J\n"); // Cabeçalho com letras das colunas
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1); // Numeração das linhas (1 a 10)
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime os valores da matriz
        }
        printf("\n");
    }
    printf("\n");
}

// Função para sobrepor uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int x, int y, int tipo) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int posX = x + i - TAM_HAB / 2;
            int posY = y + j - TAM_HAB / 2;
            if (posX >= 0 && posX < TAM && posY >= 0 && posY < TAM) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[posX][posY] = tipo; // Usar o tipo para representar diferentes habilidades
                }
            }
        }
    }
}

// Matrizes de habilidades
int cone[TAM_HAB][TAM_HAB] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

int cruz[TAM_HAB][TAM_HAB] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
};

int octaedro[TAM_HAB][TAM_HAB] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0}
};

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);
    
    // Posicionar navios no tabuleiro
    posicionarNavios(tabuleiro);
    
    // Aplicar todas as habilidades no mesmo tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2, 4);      // Habilidade cone
    aplicarHabilidade(tabuleiro, cruz, 4, 4, 5);      // Habilidade cruz
    aplicarHabilidade(tabuleiro, octaedro, 6, 6, 6);  // Habilidade octaedro
    
    printf("TABULEIRO BATALHA NAVAL\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
