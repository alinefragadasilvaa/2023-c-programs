// Posito, Negativo ou Zero
// E/S: Float -> Negativo ou Positivo ou Zero
// Ex.: 9 -> Postivo

#include <stdio.h>

int main(){

    float numero;

    printf("Digite um numero:\n");
    scanf("%f", &numero);

    if(numero < 0){
        printf("Negativo!");
    }
    if(numero > 0){
        printf("Positivo!");
    }
    if(numero == 0){
        printf("Zero!");
    }

    return 0;
}