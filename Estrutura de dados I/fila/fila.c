#include<stdio.h>
#include<stdlib.h>

struct fila{
    struct no* head;
    struct no* tail;
};

struct no{
    int valor;
    struct no* prox;
};

struct fila criar();
int is_empty(struct fila);
int push(struct fila*, int);
int pop(struct fila*);
int front(struct fila);
void destruir_fila(struct fila*);


int main(){
    struct fila fila = criar();
    for(int i = 0; i < 10; i++)
        push(&fila, i);

    while(!is_empty(fila)){
        printf("%d ", front(fila));
        pop(&fila);
    }

    destruir_fila(&fila);
    return 0;
}

struct fila criar(){
    struct fila fila;
    fila.head = 0;
    fila.tail = 0;
    return fila;
}

int is_empty(struct fila fila){
    if(!fila.head && !fila.tail) return 1;
    return 0;
}

int push(struct fila* fila, int valor){
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    if(!novo) return 0;

    novo->valor = valor;

    if(is_empty(*fila)){
        fila->head = novo;
        fila->tail = novo;
        return 1;
    }

    novo->prox = 0;
    fila->tail->prox = novo;
    fila->tail = novo;
    return 1;
}

int pop(struct fila* fila){
    if(is_empty(*fila)) return 0;
    if(fila->head == fila->tail){
        free(fila->head);
        fila->head = 0;
        fila->tail = 0;
        return 1;
    }
    struct no* aux = fila->head;
    fila->head = fila->head->prox;
    free(aux);
    return 1;
}

int front(struct fila fila){
    return fila.head->valor;
}

void destruir_fila(struct fila* fila){
    while(!is_empty(*fila))
        pop(fila);
}