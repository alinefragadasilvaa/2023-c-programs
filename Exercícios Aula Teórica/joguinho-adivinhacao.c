// joguinho de adivinhação usando números pseudo-aleatórios

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
     
     int pontos = 0, i, inicio, fim, comando, chute, numero;

     srand(time(NULL));

     printf("Seja bem vindo ao joguinho da adivinhacao!\nAo definir um intervalo, 5 numeros pseudo-aleatorios serao gerados e voce deve adivinhar se cada numero gerado e impar ou par\nBoa sorte!\n");

    do
    {
        do
        {
            printf("Digite 0 para jogar ou 1 para encerrar o jogo:\n");
            scanf("%d", &comando);
        } while (comando != 0 && comando != 1);

        printf("Digite o inicio do intervalo de numeros pseudo-aleatorios:\n");
        scanf("%d", &inicio);
        printf("Digite o fim do intervalo de numeros pseudo-aleatorios:\n");
        scanf("%d", &fim);

        for (i = 0; i < 5; i++)
        {
            do
            {
                printf("Digite 0 para chute par e 1 para chute impar:\n");
                scanf("%d", &chute);
            } while (chute != 1 && chute != 0);

            numero = inicio + ((float)rand() / RAND_MAX) * (fim - inicio);

            if(numero % 2 == 0 && chute == 0){
                pontos++;
                printf("Acertou! O numero era %d\n", numero);
            } else if(numero % 2 != 0 && chute == 1){
                pontos++;
                printf("Acertou! O numero era %d\n", numero);
            } else {
                printf("Errou! O numero era %d\n", numero);
            }
        }
        
        printf("Voce fez %d pontos!\n", pontos);
        
    } while (comando == 0);
    
    system("pause");
}