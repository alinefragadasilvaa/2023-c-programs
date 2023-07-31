// Dias do mês
// E/S: Inteiro Inteiro -> Inteiro + "dias!"
// Ex.: 1 2020 - 31 dias!
// Obs.: meses são inteiros de 1 a 12 e é preciso considerar os anos bissextos

#include <stdio.h>

int main (){
     
    int mes, ano, dias;

    printf("Digite um mes de 1 a 12 e um ano:\n");
    scanf("%d", &mes);
    scanf("%d", &ano);

    if(mes == 2){ // tratando exceção de fevereiro em anos bissextos
        if (ano%4 == 0){
            if(ano%100 == 0 && !(ano%400 ==0)){
                dias = 28;
            }
            if(!(ano%100 == 0 && !(ano%400 ==0))){
                dias = 29;
            }
        }
        if (!(ano%4 == 0)){
            dias = 28;
        }
    }
    if(!(mes == 2)){ // outros meses além de fevereiro
        if(mes >= 1 && mes <=7){ //até julho os meses impares são de 31 dias e os meses pares são 30 dias
            if(mes%2 == 0){
                dias = 30;
            }
            if (!(mes%2 == 0)){
                dias = 31;
            }
        }
        if(mes >= 8 && mes <=12){ //a partir de agosto os meses impares são de 30 dias e os meses pares são 31 dias
            if(mes%2 == 0){
                dias = 31;
            }
            if (!(mes%2 == 0)){
                dias = 30;
            }
        }
    }
    if (!(mes >=1 && mes <= 12)){ //caso o mes não seja válido
        printf("Mes invalido!\n");
    }
    if (mes >=1 && mes <= 12){
        printf("%d dias!\n", dias); // resposta de quantos dias
    }

    return 0;
}