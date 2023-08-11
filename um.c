/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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

void leBuracos(Posicao buracos[], int quant_buracos){
    printf("Digite as posicoes dos buracos:\n");
    for(int i=0;i<quant_buracos;i++){
        printf("Digite a posicao do buraco %d:\n", i+1);
        buracos[i]=lePosicao();
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

ehBuraco(Posicao buracos[], int quant_buracos, int i, int j){
    for(int i=0;i<quant_buracos;i++){
        if(i == buracos[i].i && j == buracos[i].j){
            return 1;
        }
    }
    
    return 0;
}

void preencheMatriz(Tabuleiro *tabuleiro){
    for(int i=0;i<tabuleiro->dimensao;i++){
        for(int j=0;j<tabuleiro->dimensao;j++){
     if(i == tabuleiro->peca.i && j == tabuleiro->peca.j){
                tabuleiro->matriz[i][j]='X';
            } else if(ehBuraco(tabuleiro->buracos, tabuleiro->quant_buracos, i, j)){
                tabuleiro->matriz[i][j]='o';
            } else {
                tabuleiro->matriz[i][j]='-';
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
    leBuracos(tabuleiro->buracos, tabuleiro->quant_buracos);
    while(libera == 0){
       libera = lePeca(&tabuleiro->peca, tabuleiro->buracos, tabuleiro->quant_buracos); 
    }
    preencheMatriz(tabuleiro);
}

void insereMatriz(Tabuleiro *tabuleiro, FILE *arq){
    for(int i=0;i<tabuleiro->dimensao;i++){
        for(int j=0;j<tabuleiro->dimensao;j++){
            fprintf(arq, "%c", tabuleiro->matriz[i][j]);
            if(j == tabuleiro->dimensao-1){
                putc("\n", arq);
            }
        }
    }
}

void insereTabuleiro(FILE *arq, Tabuleiro *tabuleiro){
    fprintf(arq, "%d\n", tabuleiro->dimensao);
    insereMatriz(arq, tabuleiro);
    

}

void imprimeTabuleiro(arq){
    char linha_dimensao[200], linha[200];
    int dimensao = strlen(linha_dimensao);
    fscanf(arq, "%s", linha_dimensao);
    for(int i=0;i<dimensao;i++){
       fscanf(arq, "%s", linha); 
       printf("%s\n", linha);
    }
}

int main()
{
    Tabuleiro tabuleiro;
    FILE *arq;
    
    
    leTabuleiro(&tabuleiro);
    
    arq = fopen("tabuleiro.txt", "w+");
    
    insereTabuleiro(arq, &tabuleiro);
    imprimeTabuleiro(arq);
    
    fclose(arq);

    return 0;
}
