#include <stdio.h>
#include <math.h>

int main()
{
    double tol, pi = 0, termo = 1; // tolerância, variável acumuladora dos termos de aproximação de pi, incialização do primeiro termo que é 1
    int sinal = 1, cont = 0; // troca de sinal e contador para definir ímpar

    printf("Digite uma tolerancia:");
    scanf("%lf", &tol);

    while(fabs(termo) > tol) // teste da tolerância
    {
        pi += termo; // atualiza pi pois o termo anterior a essa iteração já foi calculado
        cont++; // atualiza contador para calcular novo ímpar
        sinal = -sinal; // mudando sinal da iteração
        termo = sinal/(2.0*cont+1); // atualizando termo para próxima iteração
    } 

    pi = 4.0*pi; // 4 * (... somatória dos termos calculada no while ...)
    printf("Valor aproximado de pi: %lf", pi);
    
    return 0;
}