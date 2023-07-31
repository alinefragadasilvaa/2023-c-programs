// o programa calcula a aproximação da raiz de 2 usando o algoritmo de newton-raphson e for

#include <stdio.h>
#include <math.h>

int main()
{
    int niter, i; // quantidade de iterações e váriavel contadora
    double anterior, atual; // variável acumuladora e váriavel do calculo
    // sempre que calcular aproximação usar double 

    do
    {
        printf("Digite um numero inteiro e positivo de iterações:\n");
        scanf("%d", &niter);
        printf("Digite um chute inicial positivo:\n");
        scanf("%lf", &anterior); // iniciacilazação da variável acumuladora
    } while (niter < 0 || anterior < 0); // consistência de dados

    for (i = 0; i < niter; i++)
    {
        atual = anterior - (anterior*anterior-2)/(2*anterior); // calcula o termo atual
        anterior = atual; // atualiza o termo anterior usado para calcular o próximo termo
    }

    printf("Valor aproximado: %1.15lf", atual); // lembrar de definir quantidade de casas decimais

    return 0; 
}