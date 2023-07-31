// Comissão de Venda
//E/S: Float Inteiro -> Float
// Ex.: 100,00 20 -> 20,00

#include <stdio.h>

int main(){
    
    float valorVenda, valorComissao;
    int percentualComissao;

    printf("Digite o valor da venda (apenas números):\n");
    scanf("%f", &valorVenda);
    printf("Digite o percentual da comissao (apenas números)\n");
    scanf("%d", &percentualComissao);

    valorComissao = valorVenda*((float)percentualComissao/100);
    
    printf("Valor da Comissao: %.2f", valorComissao);

    return 0;

    system("pause");
}