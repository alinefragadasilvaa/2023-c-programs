#include <stdio.h>
#include <string.h>

#define N 2

typedef struct Aluno {
  char nome[50];
  int matricula;
  char email[50];
  char curso[50];
} ALUNO;

typedef struct AlunoProg {
  ALUNO aluno;
  int presenca;
  float notas[4]; // todas menos rec
  float recuperacao;
  char conceito;
} ALUNOPROG;

void leAluno(ALUNO *aluno){
    printf("Digite o nome do aluno:\n");
    gets(aluno->nome);
    printf("Digite a matricula do aluno:\n");
    scanf("%d", &aluno->matricula);
    getchar();
    printf("Digite o email do aluno:\n");
    gets(aluno->email);
    printf("Digite o curso do aluno:\n");
    gets(aluno->curso);
}

void mostraAluno(ALUNO aluno){
    printf("Nome do aluno: %s\n", aluno.nome);
    printf("Matricula do aluno: %d\n", aluno.matricula);
    printf("Email do aluno: %s\n", aluno.email);
    printf("Curso do aluno: %s\n", aluno.curso);
}

void leAlunoProg(ALUNOPROG *aluno_prog){
    float media_final;

    leAluno(&aluno_prog->aluno);
    printf("Digite a presenca do aluno:\n");
    scanf("%d", &aluno_prog->presenca);
    printf("Digite a nota da p1 do aluno:\n");
    scanf("%f", &aluno_prog->notas[0]);
    printf("Digite a nota da p2 do aluno:\n");
    scanf("%f", &aluno_prog->notas[1]);
    printf("Digite a nota do trabalho final do aluno:\n");
    scanf("%f", &aluno_prog->notas[2]);
    printf("Digite a nota das praticas do aluno:\n");
    scanf("%f", &aluno_prog->notas[3]);
    getchar();

    if(aluno_prog->presenca>=75){
        media_final = defineConceito(aluno_prog->notas, &aluno_prog->conceito);
    } else {
        aluno_prog->conceito = 'F';
    }

    if(aluno_prog->conceito=='D'){
        Rec(media_final, &aluno_prog->recuperacao, &aluno_prog->conceito);
    }
}

void defineConceito(float notas[], char *conceito){
    float media_final;
    media_final=0.3*notas[0]+0.4*notas[1]+0.15*notas[2]+0.15*notas[3];

    if(media_final>8.5&&media_final<=10){
       *conceito = 'A';
    } else if(media_final>7.5&&media_final<=8.5){
       *conceito = 'B';
    } else if(media_final>6.0&&media_final<=7.5){
       *conceito = 'C';
    } else {
        *conceito = 'D';
    }
}

void Rec(float media_final, float *recuperacao, char *conceito){
    printf("Digite a nota da rec do aluno:\n");
    scanf("%f", recuperacao);
    float media_rec = (media_final+*recuperacao)/2;

    if(media_rec>=6&&media_rec<=10){
        *conceito = 'C';
    }
}

/*void ordena(ALUNOPROG reprovados[], reprovados_ordenado[], int num){
    ALUNOPROG
    for(int i=0;i<num;i++){

        for(int j=0;j<num;j++){

        }
    }
}*/

int main(){
    ALUNOPROG alunos[N], reprovados[N], reprovados_ordenado[N];
    int cont=0;

    for(int i=0;i<N;i++){
        leAlunoProg(&alunos[i]);

        if(alunos[i].conceito == 'D' || alunos[i].conceito == 'F'){
            reprovados[cont] = alunos[i];
            cont++;
        }
    }

    for(int i=0;i<cont;i++){
        mostraAluno(reprovados[i].aluno);
    }



  return 0;
}
