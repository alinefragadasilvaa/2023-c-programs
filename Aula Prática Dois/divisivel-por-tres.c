// Dvísíveis por três
// E/S: Inteiro -> É divisivel por 3 ou Não é divisível por 3
// Ex.: 10 -> Não é divisível por 3

int main(){

    int numero;

    printf("Digite um numero inteiro:\n");
    scanf("%d", &numero);

    if (numero%3 == 0){
        printf("Eh divisivel por 3!\n");
    }
    if (!(numero%3 == 0)){
        printf("Nao eh divisivel por 3!\n");
    }

    return 0;
}