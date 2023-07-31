// Plano de Saúde
// E/S: Inteiro -> R$ Float 
// Ex.: 9 -> R$ 180,00

#include <stdio.h>


int main(){

    int idade;
    float preco;

    preco = 100; // valor fixo

    printf("Digite a idade:\n");
    scanf("%d", &idade);

    if (idade < 10){ // somando adicionais com o valor fixo
        preco += 80;
    }
    if (idade >= 10 && idade <= 39){
        preco += 50;
    }
    if (idade >= 40 && idade <= 60){
        preco += 95;
    }
    if (idade > 60){
        preco += 130;
    }

    printf("R$ %.2f", preco);

    return 0;
}