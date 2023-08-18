#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define SPACE ' '
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'


typedef struct Posicao{
    int i;
    int j;
} Posicao;

typedef struct Tabuleiro{
    int dimensao;
    int quant_buracos;
    Posicao buracos[10000];
    Posicao peca;
    char matriz[100][100];
} Tabuleiro;


void leTabuleiro(FILE *arq, Tabuleiro *tabuleiro){
    char caractere;
    int cont = 0;
    fscanf(arq, "%d", &tabuleiro->dimensao);
    caractere = getc(arq); // \n após dimensão
    for(int i=0;i<tabuleiro->dimensao;i++){
        for(int j=0;j<tabuleiro->dimensao+1;j++){
            caractere = getc(arq);
            if(caractere != '\n'){
                tabuleiro->matriz[i][j] = caractere;
                if (caractere == 'o'){
                tabuleiro->quant_buracos++;
                tabuleiro->buracos[cont] = (Posicao) {i, j};
                cont++;
                } else if(caractere == 'X'){
                    tabuleiro->peca = (Posicao) {i, j};
                }
            }
        }
    }
}

void imprimeTabuleiro(Tabuleiro *tabuleiro){
    for(int i=0;i<tabuleiro->dimensao;i++){
        for(int j=0;j<tabuleiro->dimensao;j++){
            printf("%c", tabuleiro->matriz[i][j]);
        }
        printf("\n");
    }
}

void goto_position(HANDLE h, int linha, int coluna){
    COORD coord;
    coord.X = coluna;
    coord.Y = linha;
    SetConsoleCursorPosition(h, coord);
}

void goto_column(HANDLE h, int coluna){
    goto_position(h, 1, 2 + coluna);
}

int jogar(HANDLE h, Tabuleiro *tabuleiro){
    CONSOLE_CURSOR_INFO info;
    SetConsoleCursorInfo(h, &info);
    imprimeTabuleiro(tabuleiro);
    goto_position(h, 3, 0);

        if(kbhit()) {//Se houve alguma tecla apertada
            switch(getch()) {
                case SPACE:
                    goto_position(h, 7, 0);
                    printf("Parou!");
                    return 3;
                    break;
                case UP:
                    if(tabuleiro->matriz[tabuleiro->peca.i-1][tabuleiro->peca.j]){
                        goto_position(h, 7, 0);
                        printf("Caiu!");
                        return 1;
                    } else if(tabuleiro->peca.i == 0){
                        goto_position(h, 7, 0);
                        printf("Limite!");
                        goto_position(h, 3, 0);
                        return 0;
                    } else {
                        tabuleiro->matriz[tabuleiro->peca.i][tabuleiro->peca.j] = '-';
                        tabuleiro->matriz[tabuleiro->peca.i-1][tabuleiro->peca.j] = 'X';
                        tabuleiro->peca.i--;
                        return 0;
                    }
                    break;
                case DOWN:
                    if(tabuleiro->matriz[tabuleiro->peca.i+1][tabuleiro->peca.j] == 'o'){
                        goto_position(h, 7, 0);
                        printf("Caiu!");
                        return 1;
                    } else if(tabuleiro->peca.i == tabuleiro->dimensao-1){
                        goto_position(h, 7, 0);
                        printf("Limite!");
                        goto_position(h, 3, 0);
                        return 0;
                    } else {
                        tabuleiro->matriz[tabuleiro->peca.i][tabuleiro->peca.j] = '-';
                        tabuleiro->matriz[tabuleiro->peca.i+1][tabuleiro->peca.j] = 'X';
                        tabuleiro->peca.i++;
                        return 0;
                    }
                    break;
                case LEFT:
                    if(tabuleiro->matriz[tabuleiro->peca.i][tabuleiro->peca.j-1] == 'o'){
                        goto_position(h, 7, 0);
                        printf("Caiu!");
                        return 1;
                    } else if(tabuleiro->peca.j == 0){
                        goto_position(h, 7, 0);
                        printf("Limite!");
                        goto_position(h, 3, 0);
                        return 0;
                    } else {
                        tabuleiro->matriz[tabuleiro->peca.i][tabuleiro->peca.j] = '-';
                        tabuleiro->matriz[tabuleiro->peca.i][tabuleiro->peca.j-1] = 'X';
                        tabuleiro->peca.j--;
                        return 0;
                    }
                    break;
                case RIGHT:
                    if(tabuleiro->matriz[tabuleiro->peca.i][tabuleiro->peca.j+1] == 'o'){
                        goto_position(h, 7, 0);
                        printf("Caiu!");
                        return 1;
                    } else if(tabuleiro->peca.j == tabuleiro->dimensao-1){
                        goto_position(h, 7, 0);
                        printf("Limite!");
                        goto_position(h, 3, 0);
                        return 0;
                    } else {
                        tabuleiro->matriz[tabuleiro->peca.i][tabuleiro->peca.j] = '-';
                        tabuleiro->matriz[tabuleiro->peca.i][tabuleiro->peca.j+1] = 'X';
                        tabuleiro->peca.j++;
                        return 0;
                    }
                    break;
            }
        }
}

void insereMatriz(FILE *arq, Tabuleiro *tabuleiro){
    for(int i=0;i<tabuleiro->dimensao;i++){
        for(int j=0;j<tabuleiro->dimensao;j++){
            fprintf(arq, "%c", tabuleiro->matriz[i][j]);
            if(j == tabuleiro->dimensao-1){
                putc('\n', arq);
            }
        }
    }
}

void insereTabuleiro(FILE *arq, Tabuleiro *tabuleiro){
    fprintf(arq, "%d\n", tabuleiro->dimensao);
    insereMatriz(arq, tabuleiro);


}

int main()
{
    Tabuleiro tabuleiro;
    FILE *arq;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//Controla o prompt de comandos
    int parar = 0;
    if(!(arq = fopen("tabuleiro.txt", "r"))){
        printf("Erro!");
    } else {
        leTabuleiro(arq, &tabuleiro);
        fclose(arq);
    }

    printf("Use w para 'up', s para 'down', a para 'left' e d para 'right'\nE mova a peca X pelo tabuleiro!\n");
    printf("Clique espaco para encerra o jogo, caso queira...\n");

    while(parar == 0){
        parar = jogar(h, &tabuleiro);
    }

    if(parar == 3){
        if(!(arq = fopen("tabuleiro.txt", "w"))){
        printf("Erro!");
        } else {
            insereTabuleiro(arq, &tabuleiro);
            fclose(arq);
        }
    }
    return 0;
}
