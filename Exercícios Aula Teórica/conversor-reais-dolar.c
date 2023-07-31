// Conversor Reais e Dólar
//E/S: Inteiro Float Float -> Float
// 1 2,00 2,00 -> 1,00
// 1 será a escolha de conversão real para dólar e 0 será escolha de conversão dólar para real

#include <stdio.h>

int main(){
    
    int tipoConversao;
    float valorConverter, taxaConversao, valorConvertido;

    printf("Qual conversao deseja realizar?\n");
    printf("Digite 1 para real -> dolar\n");
    printf("Digite 0 para dolar -> real\n");
    scanf("%d", &tipoConversao);
    printf("Qual valor a ser convertido?\n");
    scanf("%f", &valorConverter);
    printf("Qual a taxa de conversao?\n");
    scanf("%f", &taxaConversao);

    if(tipoConversao == 1){
        valorConvertido = valorConverter/taxaConversao;
    }
    if(tipoConversao == 0){
        valorConvertido = valorConverter*taxaConversao;
    }

    printf("Valor convertido: %.2f", valorConvertido);

    return 0;
}