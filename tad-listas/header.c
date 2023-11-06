#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Nodo* inicializa(){
    return NULL;
}

void imprime(Nodo* primeiro){
    Nodo* aux=primeiro;
    if (primeiro == NULL)
        printf("Lista vazia!");
    else{
        do{
            printf("Id = %d Nome = %s\n ",
            aux->info.id,
            aux->info.nome);
            aux = aux->proximo;
        } while (aux != NULL);      
    }
} 

void imprimeInvertida(Nodo *primeiro){
    Nodo *aux;
    if (primeiro==NULL){
        printf("Lista vazia!\n");
    }else{
        aux=primeiro;
        while (aux->proximo!=NULL){
             aux=aux->proximo;
        }
        while (aux!=NULL) {
            printf("Id = %d Nome = %s\n ",
            aux->info.id,
            aux->info.nome);
            aux= aux->anterior;
        }
    }
}

Nodo* insereInicio(Nodo *primeiro, InfoNodo dado){
    Nodo *novo;
    novo = (Nodo*) malloc(sizeof(Nodo));
    novo->info = dado;
    novo->anterior = NULL;
    novo->proximo = primeiro;
    if (primeiro != NULL){
        primeiro->anterior = novo;
    }
    primeiro = novo;
    return primeiro;
}

Nodo* insereFinal(Nodo *primeiro, InfoNodo dado){
    Nodo *novo, *aux;
    novo = (Nodo*) malloc(sizeof(Nodo));
    novo->info = dado; 
    novo->proximo = NULL;
    if(primeiro == NULL){ //lista vazia
        primeiro = novo;
        novo->anterior = NULL;
    }
    else{ 
        aux = primeiro;
        while (aux->proximo != NULL) 
        aux=aux->proximo; 
        aux->proximo = novo;
        novo->anterior = aux; 
    }
    return primeiro;
}

Nodo* insereCrescente(Nodo *primeiro, InfoNodo dado){
    Nodo *novo, *aux, *ant;

    novo = (Nodo*)malloc(sizeof(Nodo));
    novo->anterior = NULL;
    novo->info = dado;
    novo->proximo = NULL;

    if(primeiro==NULL){
        return novo;
    } else{
        aux=primeiro;
        while(aux->proximo!=NULL && aux->info.id < novo->info.id){
            aux = aux->proximo;
        }

        if(aux->proximo == NULL){
            novo->anterior = aux;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        } else{
            
        }

        

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