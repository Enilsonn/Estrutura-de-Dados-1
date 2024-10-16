#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no* prox;
};

int is_empty(struct no*);
int inserir_inicio(struct no**, int);
int inserir_fim(struct no*, int);
int lenght_list(struct no*);
int inserir(struct no**, int, int);
void desalocar(struct no*);
void mostrar_lista(struct no*);

int main(){
    struct no* inicio = 0;
    //inserir_inicio(&inicio, 10);
    //mostrar_lista(inicio);
    for(int i = 0; i < 10; i++)
        inserir(&inicio,i,i);
    mostrar_lista(inicio);
    desalocar(inicio);
    return 0;
}
int is_empty(struct no* inicio){
    if(inicio) return 0;
    return 1; 
}

int inserir_inicio(struct no** inicio, int valor){
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    if(!novo) return 0;
    novo->valor = valor;
    novo->prox = *inicio;
    *inicio = novo;
    return 1;
}
int inserir_fim(struct no* inicio, int valor){
    for(struct no* aux = inicio; aux; aux = aux->prox)
        if(!aux->prox){
            struct no* novo = (struct no*)malloc(sizeof(struct no));
            if(!novo) return 0;
            novo->valor = valor;
            novo->prox = aux->prox;
            aux->prox = novo;
            return 1;
        }
    return 0;
}
int lenght_list(struct no* inicio){
    int i = 0;
    for(struct no* aux = inicio; aux; aux = aux->prox)
        i++;
    return i;
}
int inserir(struct no** inicio, int valor, int index){
    // caso indice seja invalido
    int tam = lenght_list(*inicio);
    if(index < 0 || index > tam) return 0;

    // caso o indeice seja 0 ou a lista esteja vazia = inserir no inicio
    if(is_empty(*inicio) || !index)
        return inserir_inicio(inicio, valor);

    // se (index == tam) entao inserir no fim
    if(index == tam) return inserir_fim(*inicio, valor);

    //inserindo entre o inicio e o fim
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    if(!novo) return 0;

    struct no* antes = *inicio;
    struct no* depois = antes->prox;
    int aux = index;
    for(;depois;antes = depois, depois = depois->prox)
        if(!aux--){
            novo->valor = valor;
            novo->prox = depois;
            antes = novo;
            return 1;
        }
    return 0;
}
void desalocar(struct no* inicio){
    for(;inicio;inicio=inicio->prox)free(inicio);
    free(inicio);
}
void mostrar_lista(struct no* inicio){
    for(struct no* aux = inicio; aux; aux = aux->prox)
        printf("%d ", aux->valor);
    printf("\n");
}