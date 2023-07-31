// o programa calcula o fatorial de n usando for

#include <stdio.h> 

int main()
{
    int i, n; // váriavel contadora e váriavel do n a ser calculado
    double fat = 1; // para não dar overflow usa double para variável acumulativa
    // a váriavel é pré-definida em 1 pois ela acumula por meio de multiplicação e o elelemto neutro dessa operação é 1

    do{
        printf("Digite um numero inteiro maior que 0:\n"); 
        scanf("%d", &n);
    } while (n < 0); // para garantir que o programa só segue com um dado consistente

    if(n == 0){
        printf("Fatorial de 0 eh igual a %d", fat); // se for 0 o fatorial é 1 por definição
    } else {
        for (i = 1; i <= n; i++)
        {
            fat = fat * i;
        }
        printf("Fatorial de %d eh igual a %.0lf", n, fat);
    }

    return 0;
}