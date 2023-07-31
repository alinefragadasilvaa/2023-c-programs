#include <stdio.h>
#include <string.h>

void limpaAcao(char *acao, int tamanho){
    int i;
    for(i=0;i<tamanho;i++){
        *(acao+i)='\0';
    }
}

int qualCaractere(char letra){
    int flag;

    if(letra>='a'&&letra<='z'){
        flag = 1;
    } else if(letra>='A'&&letra<='Z'){
        flag = 2;
    } else{
        flag=0;
    }
    
    return flag;
}

char qualNumero(char letra){
    char numero;

    if(letra=='a'||letra=='b'||letra=='c'||letra=='A'||letra=='B'||letra=='C'){
        numero = '2';
    } else if(letra=='d'||letra=='e'||letra=='f'||letra=='D'||letra=='E'||letra=='F'){
        numero = '3';
    } else if(letra=='g'||letra=='h'||letra=='i'||letra=='G'||letra=='H'||letra=='I'){
        numero = '4';
    } else if(letra=='j'||letra=='k'||letra=='l'||letra=='J'||letra=='K'||letra=='L'){
        numero = '5';
    } else if(letra=='m'||letra=='n'||letra=='o'||letra=='M'||letra=='N'||letra=='O'){
        numero = '6';
    } else if(letra=='p'||letra=='q'||letra=='r'||letra=='s'||letra=='P'||letra=='Q'||letra=='R'||letra=='S'){
        numero = '7';
    } else if(letra=='t'||letra=='u'||letra=='v'||letra=='T'||letra=='U'||letra=='V'){
        numero = '8';
    } else if(letra=='w'||letra=='x'||letra=='y'||letra=='z'||letra=='W'||letra=='X'||letra=='Y'||letra=='Z'){
        numero = '9';
    } 

    return numero;
}

int numTeclas(char letra){
   int numero;

    if(letra=='a'||letra=='d'||letra=='g'||letra=='j'||letra=='m'||letra=='p'||letra=='t'||letra=='w'||letra=='A'||letra=='D'||letra=='G'||letra=='J'||letra=='M'||letra=='P'||letra=='T'||letra=='W'){
        numero = 1;
    } else if(letra=='b'||letra=='e'||letra=='h'||letra=='k'||letra=='n'||letra=='q'||letra=='u'||letra=='x'||letra=='B'||letra=='E'||letra=='H'||letra=='K'||letra=='N'||letra=='Q'||letra=='U'||letra=='X'){
        numero = 2;
    } else if(letra=='c'||letra=='f'||letra=='i'||letra=='l'||letra=='o'||letra=='r'||letra=='v'||letra=='y'||letra=='C'||letra=='F'||letra=='I'||letra=='L'||letra=='O'||letra=='R'||letra=='V'||letra=='Y'){
        numero = 3;
    } else if(letra=='s'||letra=='z'||letra=='S'||letra=='Z'){
        numero = 4;
    }  

    return numero;   
}

int temAsterisco(char *palavra, char letra, int posicao){
    int flag;

    if(qualNumero(letra)==qualNumero(*(palavra+(posicao+1))) && (strlen(palavra)-1)>posicao && qualCaractere(*(palavra+(posicao+1))) != 2 && qualCaractere(*(palavra+(posicao+1))) != 0){
        flag = 1;
    } else {
        flag = 0;
    }

    return flag;
}

void defineAcao(char letra, char *acao, char *palavra, int posicao){
    int i;
    switch(qualCaractere(letra)){
        case 1:
            for(i=0;i<numTeclas(letra);i++){
                *(acao+i)=qualNumero(letra);
            }
            if(temAsterisco(palavra, letra, posicao) == 1){
                *(acao+numTeclas(letra)) = '*';
            }
        break;
        case 2:
            *acao = '#';
            for(i=1;i<numTeclas(letra)+1;i++){
                *(acao+i)=qualNumero(letra);
            }
            if(temAsterisco(palavra, letra, posicao) == 1){
                *(acao+(numTeclas(letra)+1))='*';
            }
        break;
        case 0: 
            *acao = '0';
        break;
    }
}

int main(){
    int casos, i, j;
    char palavra[141], acao[10];

    scanf("%d", &casos);
    getchar();

    for(i=0;i<casos;i++){
        do{
            gets(palavra);
        } while(!(1 <= strlen(palavra)&&strlen(palavra) <= 666));

        j=0;
        while(palavra[j]!='\0'){
            limpaAcao(acao, 6);
            defineAcao(palavra[j], acao, palavra, j);
            printf("%s", acao);
            j++;
        }
        printf("\n");
    }

    return 0;
}