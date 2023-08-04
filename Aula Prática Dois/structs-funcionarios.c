#include <stdio.h>
#include <string.h>

#define N 5

typedef struct Funcionario {
  int codigo;
  char nome[50];
  float salario;
} FUNCIONARIO;

void leFuncionario(FUNCIONARIO funcionarios[], int numero){
  for(int i=0;i<numero;i++){
    printf("Digite o codigo do funcionario %d: (eh um inteiro)\n", i+1);
    scanf("%d", &funcionarios[i].codigo);
    getchar();
    printf("Digite o nome do funcionario %d:\n", i+1);
    gets(funcionarios[i].nome);
    printf("Digite o salario do funcionario %d:\n", i+1);
    scanf("%f", &funcionarios[i].salario);
    getchar();
  }
}

void mostraFuncionario(FUNCIONARIO funcionario){
  printf("Codigo: %d\n", funcionario.codigo);
  printf("Nome: %s\n", funcionario.nome);
  printf("Salario: %.2f\n", funcionario.salario);
}

int main(){
  FUNCIONARIO funcionarios[100];
  leFuncionario(funcionarios, N);
  for(int i=0;i<N;i++){
    printf("Funcionario %d:\n", i+1);
    mostraFuncionario(funcionarios[i]);
  }
  
  return 0;
}
