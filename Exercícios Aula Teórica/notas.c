// Notas
// E/S: Float -> Inteiro notas de 100, Inteiro notas de 50 ...
// Ex.: 200,00 -> 2 notas de 100, 0 notas de 50 ...

#include <stdio.h>

int main(){
    int valor;
    int notasCem, notasCinquenta, notasVinte, notasDez, notasCinco, notasDois, moedaUm;

    printf("Digite um valor inteiro:\n");
    scanf("%d", &valor);

    notasCem = (int)valor/100;
    valor = valor%100;
    notasCinquenta = (int)valor/50;
    valor = valor%50;
    notasVinte = (int)valor/20;
    valor = valor%20;
    notasDez = (int)valor/10;
    valor = valor%10;
    notasCinco = (int)valor/5;
    valor = valor%5;
    notasDois = (int)valor/2;
    valor = valor%2;
    moedaUm = (int)valor/1;
    valor = valor%1;
    
    printf("%d notas de cem, %d notas de cinquenta, %d notas de vinte, %d notas de dez, %d notas de cinco, %d notas de dois, %d moedas de um", notasCem, notasCinquenta, notasVinte, notasDez, notasCinco, notasDois, moedaUm);

    return 0;
}
