#include <stdio.h>
#include <string.h>

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

Posicao lePosicao(){
    Posicao posicao;
    printf("Digite a posicao i (linha) :\n");
    scanf("%d", &posicao.i);
    printf("Digite a posicao j (coluna) :\n");
    scanf("%d", &posicao.j);

    return posicao;
}

void leBuracos(char matriz[][100], Posicao buracos[], int quant_buracos){
    Posicao posicao;
    printf("Digite as posicoes dos buracos:\n");
    for(int i=0;i<quant_buracos;i++){
        printf("Digite a posicao do buraco %d:\n", i+1);
        posicao=lePosicao();
        buracos[i]=posicao;
        matriz[posicao.i][posicao.j]='o';
    }
}

int lePeca(Posicao *peca, Posicao buracos[], int quant_buracos){
    printf("Digite a posicao da peca:\n");
    Posicao posicao_peca = lePosicao();

    for(int i=0;i<quant_buracos;i++){
        if(posicao_peca.i == buracos[i].i && posicao_peca.j == buracos[i].j){
            return 0;
        }
    }

    *peca = posicao_peca;

    return 1;
}

void colocaPeca(Tabuleiro *tabuleiro){
    for(int i=0;i<tabuleiro->dimensao;i++){
        for(int j=0;j<tabuleiro->dimensao;j++){
            if(i == tabuleiro->peca.i && j == tabuleiro->peca.j){
                tabuleiro->matriz[i][j]='X';
            } else if (tabuleiro->matriz[i][j] != 'o'){
                tabuleiro->matriz[i][j] = '-';
            }
        }
    }
}

void leTabuleiro(Tabuleiro *tabuleiro){
    int libera = 0;

    printf("Digite a dimensao do tabuleiro:\n");
    scanf("%d", &tabuleiro->dimensao);
    printf("Digite a quantidade de buracos do tabuleiro:\n");
    scanf("%d", &tabuleiro->quant_buracos);
    leBuracos(tabuleiro->matriz, tabuleiro->buracos, tabuleiro->quant_buracos);
    while(libera == 0){
       libera = lePeca(&tabuleiro->peca, tabuleiro->buracos, tabuleiro->quant_buracos);
    }
    colocaPeca(tabuleiro);
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

void imprimeTabuleiro(Tabuleiro *tabuleiro){
    printf("Seu tabuleiro ficou assim:\n");
    for(int i=0;i<tabuleiro->dimensao;i++){
        for(int j=0;j<tabuleiro->dimensao;j++){
            printf("%c", tabuleiro->matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Tabuleiro tabuleiro;
    FILE *arq;

    leTabuleiro(&tabuleiro);

    if(!(arq = fopen("tabuleiro.bin", "w"))){
        printf("Erro!");
    } else {
        insereTabuleiro(arq, &tabuleiro);
        fclose(arq);
    }

    imprimeTabuleiro(&tabuleiro);

    return 0;
}
