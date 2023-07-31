// o programa calcula a aproximação do exponencial de m número usando for

#include <stdio.h>
#include <math.h>

int main()
{
    int numTermos, i, fatorial = 1; // variável contadora e variável acumuladora do fatorial
    double x, potencia, exponencial = 0; // variável acumuladora do exponencial

    printf("Digite o numero de termos que deseja que o calculo do exponencial tenha:\n");
    scanf("%d", &numTermos);
    printf("Digite o valor de x que deseja calcular o exponencial:\n");
    scanf("%lf", &x);

    for (i = 0; i < numTermos; i++)
    {
        potencia = pow(x, i); // calculando numerador
        exponencial = exponencial + (potencia/fatorial); // calculando denominador
        fatorial = fatorial * (i+1); // calculando fatorial da pr óxima iteração aproveitando o fatorial da iteração atual
    }
    
    printf("Exponencial: %lf", exponencial);

    return 0;
}