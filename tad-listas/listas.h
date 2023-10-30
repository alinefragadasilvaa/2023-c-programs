#define MAX 50

typedef struct InfoNodo{
    int id;
    char nome[MAX];
} InfoNodo;

typedef struct Nodo{
    InfoNodo info;
    InfoNodo *proximo;
} Nodo;

InfoNodo* inicializa();
void imprime(Nodo* primeiro);
void consulta(Nodo *primeiro, int id);
Nodo* insereInicio(Nodo *primeiro, InfoNodo dados);
Nodo* insereFim(Nodo *primeiro, InfoNodo dados);
int ContaNodos(Nodo *primeiro);
Nodo* exclui(Nodo* primeiro, int id);
Nodo* destroi(Nodo* primeiro);


