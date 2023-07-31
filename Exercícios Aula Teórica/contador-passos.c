// Contador de Passos
// E/S: Inteiro Inteiro Inteiro Inteiro - Float km
// Ex.: 10 10 1 0 -> 0.42 km

#include <stdio.h>

int main(){

    int numPassosPrimeiro, numPassosUltimo, horas, minutos;
    float distancia, mediaPassos;

    printf("Digite o numero de passos do primeiro minuto:\n");
    scanf("%d", &numPassosPrimeiro);
    printf("Digite o numero de passos do ultimo minuto:\n");
    scanf("%d", &numPassosUltimo);
    printf("Digite a quantidade de horas:\n");
    scanf("%d", &horas);
    printf("Digite a quantidade de minutos:\n");
    scanf("%d", &minutos);

    mediaPassos = (float)(numPassosPrimeiro + numPassosUltimo)/2; // quantidade de passos em 1 minuto
    distancia = (float)(((float)(horas*60)+minutos) * ((float)70*mediaPassos))/100000; // em 1 minuto ele dá x passos de 70 cm, em x minutos ele da x passos de 70 cm, para ser km divide por 10^5

    printf("Distancia total percorrida: %.2f km\n", distancia);

    return 0;
}
