#include <stdio.h>

int main()
{

    int a, b, soma, i, elementosMeio;
 
    do {
        soma = 0;

        scanf("%d", &a);
        scanf("%d", &b);

        if(a > 0 && b >0)
        {   
            if(a>b){ // caso primeira entrada for maior
                elementosMeio = a - b - 1;

                soma = soma + b;
                printf("%d ", b);
                for (i = 1; i <= elementosMeio; i++)
                {
                    soma = soma + (b+i);
                    printf("%d ", b+i);
                }
                soma = soma + a;
                printf("%d ", a);
            } else if(b>a){ // caso segunda entrada for maior 
                elementosMeio = b - a - 1;
                
                soma = soma + a;
                printf("%d ", a);
                for (i = 1; i <= elementosMeio; i++)
                {
                    soma = soma + (a+i);
                    printf("%d ", a+i);
                }
                soma = soma + b;
                printf("%d ", b);
            } else { // caso ambas entradas sejam iguais
                soma = soma + a;
                printf("%d ", a);
            }  
            printf("Sum=%d\n", soma); 
        }
    } while (a > 0 && b > 0);

    return 0;
}