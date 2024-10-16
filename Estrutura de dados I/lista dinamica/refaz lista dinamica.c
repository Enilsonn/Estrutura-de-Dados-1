#include <stdio.h>
#include <stdlib.h>
struct no{
    int dado;
    struct no* prox;
};

int is_empty(struct no*);
int inserir_inicio(struct no**, int value);

int main(){

    return 0;
}
int is_empty(struct no* lista){
    if(!lista) return 1;
    return 0;
}
int inserir_inicio(struct no** lista, int value){
    struct no* novo = (int*)malloc(sizeof(struct no));
    novo->dado = value;
    novo->prox = *lista;
    *lista = novo;
    return 1 ;
}
int inserir_fim(struct no* lista, int value){
    struct no* aux = lista;
    while(aux->prox) aux = aux->prox;
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    novo->dado = value;
    novo->prox = aux->prox;
    aux->prox = novo;
    return 1;
}
int len(struct no* lista){
    int tam = 0;
    while(lista->prox){
        lista = lista->prox;
        tam++;
    }
    return tam;
}
int inserir(struct no* lista, int value, int index){
    if(is_empty(lista)) return inserir_inicio(&lista, value);
    if(index < 0 || index >= len(lista)){
        printf("index fora do dominio da lista\n");
        return 0;
    }
}