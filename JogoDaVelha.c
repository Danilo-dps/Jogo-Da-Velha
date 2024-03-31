#include <stdio.h>
#include <locale.h>

char tabuleiro[3][3];

void inicializarTabuleiro() {
	int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void imprimirTabuleiro() {
    printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}

int verificarVitoria() {
    // Verifica linhas
    int linha, coluna;
    for (linha = 0; linha < 3; linha++) {
        if (tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]) {
            if (tabuleiro[linha][0] == 'X') {
                return 1;
            } else if (tabuleiro[linha][0] == 'O') {
                return -1;
            }
        }
    }
    // Verifica colunas
    for (coluna = 0; coluna < 3; coluna++) {
        if (tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]) {
            if (tabuleiro[0][coluna] == 'X') {
                return 1;
            } else if (tabuleiro[0][coluna] == 'O') {
                return -1;
            }
        }
    }
    // Verifica diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        if (tabuleiro[0][0] == 'X') {
            return 1;
        } else if (tabuleiro[0][0] == 'O') {
            return -1;
        }
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        if (tabuleiro[0][2] == 'X') {
            return 1;
        } else if (tabuleiro[0][2] == 'O') {
            return -1;
        }
    }
    // Ninguém venceu ainda
    return 0;
}
int jogadasInvalidas(int linha, int coluna) {
    if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
        return 1; // Jogada fora do tabuleiro
    }
    if (tabuleiro[linha][coluna] != ' ') {
        return 1; // Posição já ocupada
    }
    return 0; // Jogada válida
}

int empate() {
	int jogadas;
    if (jogadas == 9) {
        return 1; // Empate
    }
    return 0; // Ainda há jogadas possíveis
}

void jogar(int jogador, int linha, int coluna) {
    char marca = (jogador == 1) ? 'X' : 'O';
    if (tabuleiro[linha][coluna] == ' ') {
        tabuleiro[linha][coluna] = marca;
    } else {
        printf("Posição já ocupada! Escolha outra.\n");
    }
}

int main() {
			setlocale (LC_ALL, "Portuguese");
    int jogadorAtual = 1;
    int linha, coluna;
    int estadoJogo = 0;

    inicializarTabuleiro();

    while (estadoJogo == 0) {
        imprimirTabuleiro();
        printf("Jogador %d, escolha linha e coluna: ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);
        jogar(jogadorAtual, linha, coluna);

        estadoJogo = verificarVitoria();

        if (estadoJogo == 0) {
            jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
        }
    }

    imprimirTabuleiro();
    if (estadoJogo == 1) {
        printf("Jogador X venceu!\n");
    } else if (estadoJogo == -1) {
        printf("Jogador O venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}

