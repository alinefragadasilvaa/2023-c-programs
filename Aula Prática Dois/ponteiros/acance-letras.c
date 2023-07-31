#include <stdio.h>
#include <string.h>

int calcula(char palavraA[], char palavraB[]){
    int cont=0, i, tamanho = strlen(palavraA);
    
    for(i=0;i<tamanho;i++){
        while(palavraA[i]!=palavraB[i]){
            if(palavraA[i]=='z'){
                palavraA[i] = 'a';
            } else {
                palavraA[i]++;
            }
            cont++;
        }
    }

    return cont;
}

int main(){
    int i, casos, resposta;
    char palavraA[10001], palavraB[10001];

    do{
        scanf("%d", &casos);
    } while(casos>100);

    for(i=0;i<casos;i++){
        do{
            scanf("%s", palavraA);
        } while(strlen(palavraA)>=1 && strlen(palavraA)<=10000);
        
        do{
            scanf("%s", palavraB);
         } while(strlen(palavraB)!=strlen(palavraA));
       
        resposta = calcula(palavraA, palavraB);
        printf("%d\n", resposta);
    }


    return 0;
}