#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

Nodo* inicializa(){
    return NULL;
}

void imprime(Nodo* primeiro){
    Nodo *aux;
    if (primeiro == NULL){
        printf("Lista vazia!\n");
    }else{
        for(aux=primeiro; aux!=NULL; aux=aux->proximo){
            printf("Id = %d\nNome = %s\n",
            aux->info.id,
            aux->info.nome);
        }
    }
} 

void consulta(Nodo *primeiro, int id){
    Nodo *aux;
    int flag=0;
  
    aux=primeiro;
    while(aux!=NULL&&flag==0){
        if(aux->info.id == id){
            printf("Id = %d\nNome = %s\n",
            aux->info.id,
            aux->info.nome);
            flag=1;
        }
        aux=aux->proximo;
    }
    
    if(!aux){
        printf("Não encontrado!\n");
    }
}


Nodo* insereInicio(Nodo *primeiro, InfoNodo dados){
    Nodo *novo;

    novo = (Nodo*) malloc(sizeof(Nodo));
    novo->info = dados;
    novo->proximo = primeiro;
    primeiro = novo;

    return primeiro;
}

Nodo* insereFim(Nodo *primeiro, InfoNodo dados){
    Nodo *novo, *aux=primeiro;

    novo = (Nodo*) malloc(sizeof(Nodo));
    novo->info = dados;
    novo->proximo = NULL;

    if(aux){
        for(aux=primeiro; aux->proximo; aux=aux->proximo);
        aux->proximo = novo;
    } else{
        primeiro = novo;
    }

    return primeiro;
}

int ContaNodos(Nodo *primeiro){
    int cont = 0;
    Nodo *aux;

    for(aux=primeiro; aux!=NULL; aux=aux->proximo){
        cont++;
    }

    return cont;
}

Nodo* exclui(Nodo* primeiro, int id){
    Nodo *anterior = NULL;
    Nodo *aux = primeiro; 
  
    while (aux !=NULL && aux->info.id != id){
        anterior = aux;
        aux = aux->proximo;
    }

    if(aux == NULL)
        return primeiro; 
    if(anterior == NULL)
        primeiro = primeiro->proximo;
    else{
        anterior->proximo = aux->proximo;
        free(aux); 
    }
        

    return primeiro;
} 

Nodo* destroi(Nodo* primeiro){
    Nodo *aux;
    
    while (primeiro != NULL){
        aux = primeiro;
        primeiro = primeiro->proximo;
        free(aux);
    }
    free(primeiro);

    return NULL;
} 


