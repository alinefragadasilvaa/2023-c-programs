// o programa monta a sequÊncia de fibonacci de n termos usanfo for

#include <stdio.h>

int main()
{
    int i, n, n1, n2, atual;

    printf("Digite o numero de termos da sequencia que deseja:\n");
    scanf("%d", &n);

    // dois primeiros termos por definição e são 1
    n1 = 1; 
    n2 = 1;

    printf("%d %d ", n1, n2);

    for (i = 2; i < n; i++) // inicia do dois pois o termo 0 e 1 já foram impressos por definição
    {
      atual = n1 + n2; // calcula o termo atual

      // atualiza n1 e n2 para a próxima iteração
      n1 = n2; 
      n2 = atual; 

      printf("%d ", atual); // imprimi termo atual, pois não será guardado na memória, já que na próxima iteração será atualizado
    }
    
    return 0;
}