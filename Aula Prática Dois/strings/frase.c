#include <stdio.h>
#include <string.h>

int main(){
    
    char alfabeto[26], frase[1001], letrasFrase[27];  
    int i, j, k, l, m, cont, naoTem, casos;

    for(i=0;i<26;i++){ 
        alfabeto[i] = 97 + i;
    }

    scanf("%d", &casos);
    getchar();

    for(k=0;k<casos;k++){
     
        for(l=0;l<1001;l++){
            frase[l] = '\0';
        }
       
        for(m=0;m<27;m++){
            letrasFrase[m] = '\0';
        }

        do{
            fgets(frase, 1001, stdin); 
        } while (strlen(frase)<3);
    

        cont = 0;

        while(frase[cont] != '\0'){ 
            naoTem = 0;

            if(frase[cont] >= 97 && frase[cont] <= 122){ 

                for(j=0;j<26;j++){ 
                    if(letrasFrase[j] == frase[cont]){
                        naoTem = 1; 
                    }
                }

                if(naoTem == 0){
                    letrasFrase[strlen(letrasFrase)] = frase[cont]; 
                }
            } 
            cont++;
        }

        if(strlen(letrasFrase) == 26){
            printf("frase completa\n");
        } else if(strlen(letrasFrase) >= 26/2){
            printf("frase quase completa\n");
        } else {
            printf("frase mal elaborada\n");
        }
    }

    return 0;
}