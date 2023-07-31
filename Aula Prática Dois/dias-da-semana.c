// Dias da Semana
// E/S: Inteiro -> Dia útil ou Fim de Semana ou Inválido
// Ex.: 1 -> Fim de Semana
// Obs.: dias da semana de 1 a 7, sendo 1 domingo e 7 sábado

int main(){

    int dia;

    printf("Digite um dia da semana usando o seguinte codigo:\n");
    printf("1 = domingo\n");
    printf("2 = segunda\n");
    printf("3 = terca\n");
    printf("4 = quarta\n");
    printf("5 = quinta\n");
    printf("6 = sexta\n");
    printf("7 = sabado\n");
    scanf("%d", &dia);

    if (dia == 1 || dia == 7){
        printf("Fim de Semana!");
    }
    if (dia > 1 && dia < 7){
        printf("Dia Util!");
    }
    if(!((dia == 1 || dia == 7)||(dia > 1 && dia < 7))){
        printf("Invalido!");
    }

    return 0;
}