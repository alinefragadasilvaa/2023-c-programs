// o programa calcula o tempo até a perda de massa atingir limite x com while

#include <stdio.h>

int main()
{
    float massaInicial, massaFinal;
    int tempo = 0, horas, minutos, segundos;

    do{
            printf("Digite uma massa em gramas maior que 0.5:\n");
            scanf("%f", &massaInicial);
        } while (massaInicial < 0.5); // consistência

    massaFinal = massaInicial;
    
    do{
        massaFinal = massaFinal / 2;
        tempo = tempo + 50; 
    } while (massaFinal >= 0.5);

    horas = tempo / 3600; // segundos convertidos para hora
    minutos = (tempo % 3600) / 60; // os segundos que sobram da conversão para hora convertido para minutos
    segundos = (tempo % 3600) % 60; // os segundos que sobram da conversão para hora e os que sobram da conversão para minutos
    
    printf("Massa inicial:n %f\nMassa final: %f\nTempo: %d horas, %d minutos, %d segundos\n", massaInicial, massaFinal, horas, minutos, segundos);

    return 0;
}