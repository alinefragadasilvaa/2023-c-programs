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

    if(fread(&tabuleiro->dimensao, sizeof(int), 1, arq)==1){
        //printf("Dimensao lida com sucesso!");
    } else {
        //printf("Erro ao ler dimensao!");
    }

    for(int i=0;i<tabuleiro->dimensao;i++){
        for(int j=0;j<tabuleiro->dimensao;j++){
            if(fread(&tabuleiro->matriz[i][j], sizeof(char), 1, arq)==1){
                //printf("Caractere [%d][%d] lido com sucesso!\n", i, j);
            } else {
                //printf("Erro ao ler caractere [%d][%d]!\n", i, j);
            }
            if (tabuleiro->matriz[i][j] == 'o'){
                tabuleiro->quant_buracos++;
                tabuleiro->buracos[cont] = (Posicao) {i, j};
                cont++;
            } else if(tabuleiro->matriz[i][j] == 'X'){
                    tabuleiro->peca = (Posicao) {i, j};
            } else {
                tabuleiro->matriz[i][j] = ' ';
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

int jogar(HANDLE h, Tabuleiro *tabuleiro, int *linha_impressa){
    CONSOLE_CURSOR_INFO info;
    SetConsoleCursorInfo(h, &info);
    imprimeTabuleiro(tabuleiro);
    goto_position(h, 3, 0);

        if(kbhit()) {//Se houve alguma tecla apertada
            switch(getch()) {
                case SPACE:
                    goto_position(h, 3+tabuleiro->dimensao+(*linha_impressa)+*linha_impressa, 0);
                    printf("Parou!\n");
                    *(linha_impressa)++;
                    return 3;
                    break;
                case UP:
                    if(tabuleiro->matriz[tabuleiro->peca.i-1][tabuleiro->peca.j]){
                        goto_position(h, 3+tabuleiro->dimensao+(*linha_impressa), 0);
                        printf("Caiu!");
                        (*linha_impressa)++;
                        return 1;
                    } else if(tabuleiro->peca.i == 0){
                        goto_position(h, 3+tabuleiro->dimensao+(*linha_impressa), 0);
                        printf("Limite!");
                        (*linha_impressa)++;
                        goto_position(h, 3, 0);
                        return 0;
                    } else {
                        tabuleiro->matriz[tabuleiro->peca.i][tabuleiro->peca.j] = ' ';
                        tabuleiro->matriz[tabuleiro->peca.i-1][tabuleiro->peca.j] = 'X';
                        tabuleiro->peca.i--;
                        return 0;
                    }
                    break;
                case DOWN:
                    if(tabuleiro->matriz[tabuleiro->peca.i+1][tabuleiro->peca.j] == 'o'){
                        goto_position(h, 3+tabuleiro->dimensao+(*linha_impressa), 0);
                        printf("Caiu!");
                        (*linha_impressa)++;
                        return 1;
                    } else if(tabuleiro->peca.i == tabuleiro->dimensao-1){
                        goto_position(h, 3+tabuleiro->dimensao+(*linha_impressa), 0);
                        printf("Limite!");
                        *(linha_impressa)++;
                        goto_position(h, 3, 0);
                        return 0;
                    } else {
                        tabuleiro->matriz[tabuleiro->peca.i][tabuleiro->peca.j] = ' ';
                        tabuleiro->matriz[tabuleiro->peca.i+1][tabuleiro->peca.j] = 'X';
                        tabuleiro->peca.i++;
                        return 0;
                    }
                    break;
                case LEFT:
                    if(tabuleiro->matriz[tabuleiro->peca.i][tabuleiro->peca.j-1] == 'o'){
                        goto_position(h, 3+tabuleiro->dimensao+(*linha_impressa), 0);
                        printf("Caiu!");
                        (*linha_impressa)++;
                        return 1;
                    } else if(tabuleiro->peca.j == 0){
                        goto_position(h, 3+tabuleiro->dimensao+(*linha_impressa), 0);
                        printf("Limite!");
                        (*linha_impressa)++;
                        goto_position(h, 3, 0);
                        return 0;
                    } else {
                        tabuleiro->matriz[tabuleiro->peca.i][tabuleiro->peca.j] = ' ';
                        tabuleiro->matriz[tabuleiro->peca.i][tabuleiro->peca.j-1] = 'X';
                        tabuleiro->peca.j--;
                        return 0;
                    }
                    break;
                case RIGHT:
                    if(tabuleiro->matriz[tabuleiro->peca.i][tabuleiro->peca.j+1] == 'o'){
                        goto_position(h, 3+tabuleiro->dimensao+(*linha_impressa), 0);
                        printf("Caiu!");
                        (*linha_impressa)++;
                        return 1;
                    } else if(tabuleiro->peca.j == tabuleiro->dimensao-1){
                        goto_position(h, 3+tabuleiro->dimensao+(*linha_impressa), 0);
                        printf("Limite!");
                        (*linha_impressa)++;
                        goto_position(h, 3, 0);
                        return 0;
                    } else {
                        tabuleiro->matriz[tabuleiro->peca.i][tabuleiro->peca.j] = ' ';
                        tabuleiro->matriz[tabuleiro->peca.i][tabuleiro->peca.j+1] = 'X';
                        tabuleiro->peca.j++;
                        return 0;
                    }
                    break;
                default:
                    goto_position(h, 3+tabuleiro->dimensao+(*linha_impressa), 0);
                    printf("Tecla invalida!");
                    (*linha_impressa)++;
                    goto_position(h, 3, 0);
                    return 0;
                    break;
            }
        }
}

void insereMatriz(FILE *arq, Tabuleiro *tabuleiro){
    for(int i=0;i<tabuleiro->dimensao;i++){
        for(int j=0;j<tabuleiro->dimensao;j++){
            if(fwrite(&tabuleiro->matriz[i][j], sizeof(char), 1, arq)){
                 printf("Caractere [%d][%d] salvo com sucesso!\n", i, j);
            } else {
                printf("Erro ao salvar caractere [%d][%d]!\n", i, j);
            }
        }
    }
}

void insereTabuleiro(FILE *arq, Tabuleiro *tabuleiro){
    if(fwrite(&tabuleiro->dimensao, sizeof(int), 1, arq)==1){
        printf("Dimensao salva com sucesso!\n");
    } else {
        printf("Erro ao salvar dimensao!\n");
    }
    insereMatriz(arq, tabuleiro);
}

int main()
{
    Tabuleiro tabuleiro;
    FILE *arq;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//Controla o prompt de comandos
    int parar = 0, linha_impressa = 0;
    if(!(arq = fopen("tabuleiro.bin", "r"))){
        printf("Erro!");
    } else {
        leTabuleiro(arq, &tabuleiro);
        fclose(arq);
    }

    printf("Use w para 'up', s para 'down', a para 'left' e d para 'right'\nE mova a peca X pelo tabuleiro!\n");
    printf("Clique espaco para encerra o jogo, caso queira...\n");

    while(parar == 0){
        parar = jogar(h, &tabuleiro, &linha_impressa);
    }

    if(parar == 3){
        if(!(arq = fopen("tabuleiro.bin", "w"))){
        printf("Erro!");
        } else {
            printf("Resultados do salvamento no arquivo:\n");
            insereTabuleiro(arq, &tabuleiro);
            fclose(arq);
        }
    }
    return 0;
}
