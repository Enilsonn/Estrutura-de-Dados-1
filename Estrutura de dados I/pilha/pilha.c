#include<stdio.h>
#include<stdlib.h>

struct no{
    int valor;
    struct no* prox;
};




















////////////////////////////////////////////////////////////////////////////////////
struct no* criar();
int push(struct no**, int);
int pop(struct no**);
int top(struct no*);
void destruir_pilha(struct no**);

int main(){
    struct no* pilha = criar();
    for(int i = 0; i < 10; i++)
        push(&pilha, i);
    
    while(pilha){
        printf("%d ", top(pilha));
        pop(&pilha);
    }

    destruir_pilha(&pilha);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////


















struct no* criar(){
    return 0;
}

int is_empty(struct no* pilha){
    if(!pilha) return 1;
    return 0;
}

int push(struct no** pilha, int valor){
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    if(!novo) return 0;

    novo->valor = valor;
    novo->prox = (*pilha);

    (*pilha) = novo;

    return 1;
}

int pop(struct no** pilha){
    if(is_empty(*pilha)) return 0;
    struct no* aux = (*pilha);
    (*pilha) = (*pilha)->prox;
    free(aux);
    return 1;
}

int top(struct no* pilha){
    return pilha->valor;
}

void destruir_pilha(struct no** pilha){
    while((*pilha))
        pop(pilha);
}