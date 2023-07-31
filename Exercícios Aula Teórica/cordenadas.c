// Cordenadas
// E/S: Float Float -> quatrante 1 ou Quandrante 2 ou Quadrante 3 ou Quadrante 4
// Ex.: 2 3 -> Quadrante 1

#include <stdio.h>

int main(){
    
    float x, y;

    printf("Digite um valor para x:\n");
    scanf("%f", &x);
    printf("Digite um valor para y:\n");
    scanf("%f", &y);

    if(x > 0 && y > 0){
        printf("Quadrante 1");
    }
    if(x < 0 && y < 0){
        printf("Quadrante 3");
    }
    if(x > 0 && y < 0){
        printf("Quadrante 4");
    }
    if(x < 0 && y > 0){
        printf("Quadrante 2");
    }
    if (x == 0 && y == 0){
        printf( "Origem");
    }
    if (x == 0 && y != 0){
        printf("Na reta de y");
    }
    if (x != 0 && y == 0){
        printf("Na reta de x");
    }
    
    return 0;
}