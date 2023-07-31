#include <stdio.h>

int main(){
    int impares[5], pares[5], i, j, k, l, m, valor, contImpar = 0, contPar = 0;

    for(i=0;i<15;i++){
        scanf("%d", &valor);

        if(valor%2 == 0){
            if (contPar<5){
                pares[contPar] = valor;
                contPar++;
            } else{
                contPar = 0;
                for(j=0;j<5;j++){
                    printf("par[%d] = %d\n", j, pares[j]);
                }
                pares[contPar] = valor;
                contPar++;
            }
        } else {
            if (contImpar<5){
                impares[contImpar] = valor;
                contImpar++;
            } else {
                contImpar = 0;
                for(k=0;k<5;k++){
                    printf("impar[%d] = %d\n", k, impares[k]);
                }
                impares[contImpar] = valor;
                contImpar++;
            }
        }
    }

        for(l=0;l<contImpar;l++){
       printf("impar[%d] = %d\n", l, impares[l]);
        }

        for(m=0;m<contPar;m++){
        printf("par[%d] = %d\n", m, pares[m]);
        }

    
    return 0;
}