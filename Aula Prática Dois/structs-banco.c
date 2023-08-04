#include <stdio.h>
#include <string.h>

#define N 10

typedef struct Cliente {
  int codigo;
  float saldo;
} CLIENTE;

void armazenaCliente(CLIENTE clientes[], int numero){
  for(int i=0;i<numero;i++){
    printf("Digite o codigo do cliente %d: (eh um inteiro)\n", i+1);
    scanf("%d", &clientes[i].codigo);
    printf("Digite o saldo do cliente %d:\n", i+1);
    scanf("%f", &clientes[i].saldo);
  }
}

void achaMaiores(CLIENTE maiores[], CLIENTE clientes[], int numero){
  int contMaior=0;

  maiores[0]=clientes[0];
  contMaior++;
  for(int i=1;i<numero;i++){
    if(clientes[i]==maiores[0]){
      maiores[contMaior] = clientes[i];
      contMaior++;
    } else if(clientes[i]>maiores[0]){
        contMaior = 0;
        maiores[contMaior]=clientes[i];
        contMaior++;
    }
  }

  mostraMaiores(maiores, contMaior);
}

void mostraMaiores(CLIENTE maiores[], int numero){
  for(int i=0;i<numero;i++){
    printf("Maior numero %d\n", i+1);
    printf("Codigo: %d\n", cliente[i].codigo);
    printf("Saldo: %.2f\n", cliente[i].saldo); 
  }
}

int main(){
  CLIENTE clientes[100], maiores[100];
  armazenaCliente(clientes, N);
  achaMaiores(maiores, clientes, N);
  
  return 0;
}
