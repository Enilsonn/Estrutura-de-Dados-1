#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no* prox;
};

struct lista_circular{
    struct no* inicio;
    struct no* fim;
};

struct lista_circular criar();
int is_empty(struct lista_circular);
int inserir_inicio(struct lista_circular*, int);
int inserir_fim(struct lista_circular*, int);
void remover_inicio(struct lista_circular*);
void mostrar_lista(struct lista_circular);
void destruir_lista(struct lista_circular*);

int main(){
    struct lista_circular lista = criar();
    for(int i = 0; i < 10; i++) inserir_fim(&lista, i);
    mostrar_lista(lista);
    destruir_lista(&lista);
    return 0;
}

struct lista_circular criar(){
    struct lista_circular lista;
    lista.inicio = 0;
    lista.fim = 0;
    return lista;
}

int is_empty(struct lista_circular lista){
    if(!lista.inicio && !lista.fim) return 1;
    return 0;
}

int inserir_primeiro_elemento(struct lista_circular* lista, int valor){
    struct no* novo= (struct no*)malloc(sizeof(struct no));
    if(!novo) return 0;
    novo->valor = valor;
    novo->prox = novo;

    lista->inicio = novo;
    lista->fim = novo;
    return 1;
}

int inserir_inicio(struct lista_circular* lista, int valor){
    if(is_empty(*lista)) return inserir_primeiro_elemento(lista, valor);

    struct no* novo = (struct no*)malloc(sizeof(struct no));
    if(!novo) return 0;

    novo->valor = valor;
    novo->prox = lista->inicio;

    lista->inicio = novo;
    lista->fim->prox = novo;

    return 1;
}
int inserir_fim(struct lista_circular* lista, int valor){
    if(is_empty(*lista)) return inserir_inicio(lista, valor);

    struct no* novo = (struct no*)malloc(sizeof(struct no));
    if(!novo) return 0;

    novo->valor = valor;
    novo->prox = lista->inicio;

    lista->fim->prox = novo;
    lista->fim = novo;

    return 1;
}
void remover_inicio(struct lista_circular* lista){
    lista->inicio = lista->inicio->prox;
    free(lista->fim->prox);
    lista->fim->prox = lista->inicio;
}

void mostrar_lista(struct lista_circular lista){
    if(is_empty(lista)) return;
    if(lista.inicio == lista.fim){
        printf("%d\n", lista.inicio->valor);
        return;
    }
    printf("%d ", lista.inicio->valor);
    for(struct no* aux = lista.inicio->prox; aux != lista.inicio; aux = aux->prox){
        printf("%d ", aux->valor);
    }
    printf("\n");
}

void destruir_lista(struct lista_circular* lista){
    if(is_empty(*lista)) return;
    if(lista->inicio == lista->fim){
        free(lista->inicio);
        return;
    }
    while(lista->inicio != lista->fim)
        remover_inicio(lista);
}

