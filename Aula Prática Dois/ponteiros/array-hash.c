#include <stdio.h>
#include <string.h>

int posicaoAlfabeto(char letra){
    int cont = 0;
    char letraAlfabeto = 'A';

    while(letra != letraAlfabeto){
        letraAlfabeto++;
        cont++;
    }

    return cont;
}

int calculaHash(char palavra[], int elemento){
    int i, soma = 0;

    for(i=0;i<strlen(palavra);i++){
        soma += posicaoAlfabeto(palavra[i]) + elemento + i;
    }

    return soma;
}
 
int main() {
 
    int i, j;
    int casos, quant, hash;
    char palavra[51];

    scanf("%d", &casos);

    for(i=0;i<casos;i++){
        hash = 0;

        scanf("%d", &quant);

        for (j=0;j<quant;j++){
            scanf("%s", palavra);
            hash += calculaHash(palavra, j);
        }
        
        printf("%d\n", hash);
    }
 
    return 0;
}