#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais do navio horizontal
    int linha_h = 0;
    int coluna_h = 0;

    // Validação: cabe no tabuleiro horizontalmente?
    if (coluna_h + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_h][coluna_h + i] = NAVIO;
        }
    } else {
        printf("Navio horizontal ultrapassa os limites do tabuleiro!\n");
        exit(1);
    }

    // Coordenadas iniciais do navio vertical
    int linha_v = 7;
    int coluna_v = 9;

    // Validação: cabe no tabuleiro verticalmente e não sobrepõe outro navio?
    if (linha_v + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int podePosicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != AGUA) {
                podePosicionar = 0;
                break;
            }
        }

        if (podePosicionar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_v + i][coluna_v] = NAVIO;
            }
        } else {
            printf("Navio vertical colide com outro navio!\n");
            exit(1);
        }
    } else {
        printf("Navio vertical ultrapassa os limites do tabuleiro!\n");
        exit(1);
    }

    // Exibe o tabuleiro
    printf("\n===== Tabuleiro Batalha Naval =====\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
