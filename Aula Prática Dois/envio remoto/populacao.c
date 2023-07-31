#include <stdio.h>

int main()
{

    int i, casosTeste, populacaoA, populacaoB, anos;
    double taxaA, taxaB;

    scanf("%d", &casosTeste);

    for (i = 0; i < casosTeste; i++)
    {
        anos = 0;

        scanf("%d", &populacaoA);
        scanf("%d", &populacaoB);
        scanf("%lf", &taxaA);
        scanf("%lf", &taxaB);

        while (populacaoA <= populacaoB && anos < 100)
        {
            populacaoA = populacaoA + (populacaoA * (taxaA / 100));
            populacaoB = populacaoB + (populacaoB * (taxaB / 100));

            anos++;
        }

        if(anos != 0 && anos <100){
            printf("%d anos.\n", anos);
        } else{
            printf("Mais de 1 seculo.\n");
        }  
    }
    

    return 0;
}