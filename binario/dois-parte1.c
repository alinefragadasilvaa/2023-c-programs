#include <stdio.h>
#include <string.h>

typedef struct Pergunta{
    char enunciado[100];
    char respostas[4][100];
    int resposta;
} Pergunta;

Pergunta lePergunta(){
    Pergunta pergunta;

    printf("Siga o seguinte modelo:\nEnunciado\nAlternativa 1\nAlternativa 2\nAlternativa 3\nAlternativa 4\nResposta(em numero)");

    gets(pergunta.enunciado);
    gets(pergunta.respostas[0]);
    gets(pergunta.respostas[1]);
    gets(pergunta.respostas[2]);
    gets(pergunta.respostas[3]);
    scanf("%d", &pergunta.resposta);
    pergunta.resposta--;
    getchar();

    return pergunta;
}

void inserePerguntas(FILE *arq, int n, int numero_existente){
    Pergunta pergunta;
    pergunta = lePergunta();

    if(fwrite(&n, sizeof(int), 1, arq)==1){
        printf("Numero de perguntas salvo com sucesso!\n");
    } else {
        printf("Erro ao salvar numero de perguntas!\n");
    }

    fseek(arq, numero_existente*sizeof(Pergunta), SEEK_CUR);

    for(int i=0;i<n;i++){
        if(fwrite(&pergunta, sizeof(Pergunta), 1, arq)==1){
        printf("Pergunta salva com sucesso!\n");
        } else {
            printf("Erro ao salvar pergunta!\n");
        }
    }
}

int veSeTaVazio(FILE *arq){
    while(!feof(arq)){
        return 1;
    }
    return 0;
}

int pegaNumPerguntas(FILE *arq){
   int num;

    if(fread(&num, sizeof(int), 1, arq)==1){
        printf("Numero existente lido!");
    } else {
        printf("Numero existente nao lido!");
    }

    return num;
}

int main()
{
    FILE *arq;
    int n, numero_existente;
    char caractere, string[2];

    printf("Digite o numero de perguntas:\n");
    scanf("%d", &n);
    getchar();


    if(!(arq = fopen("perguntas.bin", "w+"))){
        printf("Erro!");
    } else {
        if(veSeTaVazio(arq)){
            numero_existente = pegaNumPerguntas(arq);
        }
        inserePerguntas(arq, n+numero_existente, numero_existente);
        fclose(arq);
    }

    return 0;
}
