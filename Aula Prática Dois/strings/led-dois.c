#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int i, j, numeroLeds, numeroCasos;

    char numero[102];

    scanf("%d", &numeroCasos);

    for(j=0;j<numeroCasos;j++){

        scanf(" %s", numero);

        numeroLeds = 0;

        i = 0;

            while (numero[i] != '\0'){

                switch (numero[i])
                {
                case '0':
                    numeroLeds += 6;
                    break;
                case '1':
                    numeroLeds += 2;
                    break;
                case '2':
                    numeroLeds += 5;
                    break;
                case '3':
                    numeroLeds += 5;
                    break;
                case '4':
                    numeroLeds += 4;
                    break;
                case '5':
                    numeroLeds += 5;
                    break;
                case '6':
                    numeroLeds += 6;
                    break;
                case '7':
                    numeroLeds += 3;
                    break;
                case '8':
                    numeroLeds += 7;
                    break;
                case '9':
                    numeroLeds += 6;
                    break;
                }

                i++;
            }

        printf("%d leds\n", numeroLeds);
    }


    return 0;
}