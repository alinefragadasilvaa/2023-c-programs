// o programa calcula o somatório de r usando while e tolerância

#include <stdio.h>
#include <math.h>

int main (){
    
    double r, exato, somatorio=0; // variável para calcular o exato e a acumuladora do cálculo do somátório
    int i=0; // contatora para calcular a potência do somatório

    do
    {
        printf("Digite um valor r que satisfaz |r| < 1:\n");
        scanf("%lf", &r);
    } while(fabs(r) >= 1); // consistência de dados

    exato = 1/(1-r); // calculo do valor exato

    while(fabs(somatorio-exato)>=0.0001) // teste de tolerância
    {
        somatorio = somatorio + pow(r, i); // calcula somatório até a tolerância
        i++; // atualiza contador para próxima iteração
    }
    
    printf("Valor exato: %lf\nSomatorio: %lf", exato, somatorio);
    
    return 0; 
}