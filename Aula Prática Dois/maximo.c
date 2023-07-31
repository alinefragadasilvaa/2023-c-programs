// Máximo
// E/S: Float Float -> Float
// Ex.: 4 2 -> 4

#include <stdio.h>

int main(){

    float numeroUm, numeroDois;

    printf("Digite dois numeros:\n");
    scanf("%f", &numeroUm);
    scanf("%f", &numeroDois);

    if(numeroUm > numeroDois){
        printf("%.0f.\n", numeroUm);
    }
    if(numeroDois > numeroUm){
        printf("%.0f.\n", numeroDois);
    }

    return 0;
}