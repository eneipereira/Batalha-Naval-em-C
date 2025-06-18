#include <stdio.h>
#include <stdlib.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Inicializa o tabuleiro com água (valor 0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Verifica se a posição está dentro dos limites e vazia
int podePosicionar(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    return linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO && tabuleiro[linha][coluna] == AGUA;
}

// Posiciona navio horizontal
int posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int colunaInicial) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (!podePosicionar(tabuleiro, linha, colunaInicial + i)) return 0;
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][colunaInicial + i] = NAVIO;
    }
    return 1;
}

// Posiciona navio vertical
int posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linhaInicial, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (!podePosicionar(tabuleiro, linhaInicial + i, coluna)) return 0;
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaInicial + i][coluna] = NAVIO;
    }
    return 1;
}

// Posiciona navio na diagonal principal (↘)
int posicionarNavioDiagonalPrincipal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linhaInicial, int colunaInicial) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (!podePosicionar(tabuleiro, linhaInicial + i, colunaInicial + i)) return 0;
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaInicial + i][colunaInicial + i] = NAVIO;
    }
    return 1;
}

// Posiciona navio na diagonal secundária (↙)
int posicionarNavioDiagonalSecundaria(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linhaInicial, int colunaInicial) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (!podePosicionar(tabuleiro, linhaInicial + i, colunaInicial - i)) return 0;
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaInicial + i][colunaInicial - i] = NAVIO;
    }
    return 1;
}

// Exibe o tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\n===== Tabuleiro Batalha Naval =====\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    if (!posicionarNavioHorizontal(tabuleiro, 0, 0)) {
      printf("Erro ao posicionar navio horizontal.\n");
      exit(1);
    }

    if (!posicionarNavioVertical(tabuleiro, 0, 9)) {
      printf("Erro ao posicionar navio vertical.\n");
      exit(1);
    }

    if (!posicionarNavioDiagonalPrincipal(tabuleiro, 7, 7)) {
      printf("Erro ao posicionar navio diagonal principal.\n");
      exit(1);
    }

    if (!posicionarNavioDiagonalSecundaria(tabuleiro, 7, 2)) {
      printf("Erro ao posicionar navio diagonal secundária.\n");
      exit(1);
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}
