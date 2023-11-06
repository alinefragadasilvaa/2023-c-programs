#define MAX 50

typedef struct InfoNodo{
    int id;
    char nome[MAX];
} InfoNodo;

typedef struct Nodo{
    InfoNodo *anterior;
    InfoNodo info;
    InfoNodo *proximo;
} Nodo;

Nodo* inicializa(void);
void imprime(Nodo* primeiro);
void imprimeInvertida(Nodo *primeiro);
Nodo* insereInicio(Nodo *primeiro, InfoNodo dado);
Nodo* insereFinal(Nodo *primeiro, InfoNodo dado);
Nodo* destroi(Nodo* primeiro);
Nodo* exclui(Nodo *primeiro, int codigo);

