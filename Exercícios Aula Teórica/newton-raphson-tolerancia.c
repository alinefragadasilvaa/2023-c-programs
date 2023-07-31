// o programa calcula a aproximação da raiz de 2 usando o algoritmo de newton-raphson e while

#include <stdio.h>
#include <math.h>

int main()
{
    double anterior, atual; // variável acumuladora e váriavel do calculo
    double tol, erro; // tolerancia e erro
    // sempre que calcular aproximação usar double 

    do
    {
        printf("Digite um chute inicial positivo:\n");
        scanf("%lf", &anterior); // iniciacilazação da variável acumuladora
        printf("Digite a tolerancia:\n");
        scanf("%d", &tol);
    } while (anterior < 0); // consistência de dados

    do{
        atual = anterior - (anterior*anterior-2)/(2*anterior); // calcula o termo atual
        erro = fabs(anterior - atual); // calcula o erro entre as duas parcelas anterior e atual
        anterior = atual; // atualiza o termo anterior usado para calcular o próximo termo

    } while(erro > tol); // erro mínimo é a tolerância
        
    printf("Valor aproximado: %1.15lf", atual); // lembrar de definir quantidade de casas decimais

    return 0; 
}