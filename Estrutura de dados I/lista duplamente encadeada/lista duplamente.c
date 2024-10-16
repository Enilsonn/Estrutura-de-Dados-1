#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no* prox;
    struct no* ant;
};

struct lista{
    struct no* inicio;
    struct no* fim;
};

int main(){
    struct lista list = criar();
    return 0;
}

struct lista criar(){
    struct lista list;
    list.inicio = 0;
    list.fim = 0;
    return list;
}

int is_empty(struct no* lista){
    if(!lista->ant && !lista->prox) return 1;
    return 0;
}

int inserir_inicio(struct lista* list, int valor){
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    if(!novo) return 0;

    novo->valor = valor;
    novo->prox = list->inicio;
    novo->ant = 0;

    if(is_empty(list)){
        list->fim = novo;
        list->inicio = novo;
        return 1;
    }

    list->inicio->ant = novo;
    list->inicio = novo;
    return 1;
}

int inserir_fim(struct lista* list, int valor){
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    if(!novo) return 0;

    novo->valor = valor;
    novo->prox = 0;
    novo->ant = list->fim;

    if(is_empty(list)){
        list->inicio = novo;
        list->fim = novo;
        return 1;
    }

    list->fim->prox = novo;
    list->fim = novo;
    return 1;
}

int inserir_por_elemento(struct lista* list, int valor){
    if(is_empty(list)) return inserir_inicio(list, valor);
    if(list->inicio == list->fim){
        if(list->inicio->valor > valor) return inserir_inicio(list, valor);
        return inserir_fim(list, valor); 
    }

    struct no* novo = (struct no*)malloc(sizeof(struct no));
    if(!novo) return 0;

    novo->valor = valor;

    struct no* aux = list->inicio;
    for(; aux; aux = aux->prox)
        if(aux->prox->valor > valor || !aux->prox){
            break;
        }

    if(!aux->ant)
        return inserir_inicio(list, valor);

    if(!aux->prox)
        return inserir_fim(list, valor);

    novo->ant = aux;
    novo->prox = aux->prox;

    aux->prox->ant = novo;
    aux->prox = novo;
    return 1;
}

void remover_inicio(struct lista* list){
    if(is_empty(list)) return;
    if(list->inicio == list->fim){
        free(list->inicio);
        list->inicio = 0;
        list->fim = 0;
        return;
    }
    struct no* aux = list->inicio;
    list->inicio = list->inicio->prox;
    list->inicio->ant = 0;

    free(aux);
}

void remover_fim(struct lista* list){
    if(is_empty(list)) return;
    if(list->inicio == list->fim){
        free(list->inicio);
        list->inicio = 0;
        list->fim = 0;
        return;
    }
    struct no* aux = list->fim;
    list->fim = list->fim->ant;
    list->fim->prox = 0;

    free(aux);
}
