// o programa recebe inteiros e informa o maior e o menor com for

#include <stdio.h>

int main()
{
    int i, n, maior, menor;

    printf("Digite um número inteiro:\n");
    scanf("%d", &n);

    // inicializa ambas com o primeiro número
    maior = n;
    menor = n;

    for (i = 1; i < 5; i++)
    {
        printf("Digite um número inteiro:\n");
        scanf("%d", &n);

        if(n > maior){
            maior = n;
        } else if (n < menor){
            menor = n;
        }
    }

    printf("Maior: %d\nMenor: %d", maior, menor);

    return 0;
}