#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no* esq;
    struct no* dir;
};
struct no* criar_arvore();
struct no* inserir(struct no*, int);
void mostrar_pre(struct no*);
void mostrar_in(struct no*);
void mostrar_pos(struct no*);
struct no* esvaziar(struct no*);
int n_nos(struct no*);
int altura(struct no*);
int fator_balanceamento(struct no*);
struct no* rotacao_direita(struct no*);
struct no* rotacao_esquerda(struct no*);
struct no* balancear(struct no*);
struct no* inverter_arv(struct no*);
void printTree(struct no*, int);

int main(){
    struct no* arvore = 0;
    for(int i = 0; i < 30; i++){
        arvore = inserir(arvore, i);
    }
    mostrar_pre(arvore);
    printf("\n");
    mostrar_in(arvore);
    printf("\n");
    arvore = inverter_arv(arvore);
    mostrar_in(arvore);
    printf("\n");
    mostrar_pos(arvore);
    printTree(arvore, 0);
    return 0;
}

struct no* criar_arvore(){
    return 0;
}

struct no* inserir(struct no* raiz, int valor){
    if(!raiz){
        struct no* novo = (struct no*)malloc(sizeof(struct no));
        if(!novo) return 0;

        novo->valor = valor;
        novo->dir = 0;
        novo->esq = 0;
        return novo;
    }
    if(raiz->valor <= valor) raiz->esq = inserir(raiz->esq, valor);
    else raiz->dir = inserir(raiz->dir, valor);
    return balancear(raiz);
}

void mostrar_pre(struct no* raiz){
    if(!raiz) return;
    printf("%d ", raiz->valor);
    mostrar_pre(raiz->esq);
    mostrar_pre(raiz->dir);
}

void mostrar_in(struct no* raiz){
    if(!raiz) return;
    mostrar_in(raiz->esq);
    printf("%d ", raiz->valor);
    mostrar_in(raiz->dir);
}

void mostrar_pos(struct no* raiz){
    if(!raiz) return;
    mostrar_pos(raiz->esq);
    mostrar_pos(raiz->dir);
    printf("%d ", raiz->valor);
}

struct no* esvaziar(struct no* raiz){
    if(!raiz) return 0;
    raiz->esq = esvaziar(raiz->esq);
    raiz->dir = esvaziar(raiz->dir);
    free(raiz);
    return 0;
}

int n_nos(struct no* raiz){
    if(!raiz) return 0;
    return n_nos(raiz->esq) + n_nos(raiz->dir) + 1;
}

int altura(struct no* raiz){
    if(!raiz) return 0;
    int a = altura(raiz->esq);
    int b = altura(raiz->dir);
    if(a > b) return (a + 1);
    return (b + 1);
}

int fator_balanceamento(struct no* raiz){
    if(!raiz) return 0;
    return altura(raiz->esq) - altura(raiz->dir);
}
struct no* rotacao_direita(struct no* raiz){
    struct no* aux = raiz->esq;
    raiz->esq = aux->dir;
    aux->dir = raiz;
    raiz = aux;
    return raiz;
}
struct no* rotacao_esquerda(struct no* raiz){
    struct no* aux = raiz->dir;
    raiz->dir = aux->esq;
    aux->esq = raiz;
    raiz = aux;
    return raiz;
}
struct no* balancear(struct no* raiz){
    int fb = fator_balanceamento(raiz);

    if(fb > 1 && fator_balanceamento(raiz->esq) >= 0){
         return rotacao_direita(raiz);
    }
    if(fb > 1 && fator_balanceamento(raiz->esq) < 0){
        raiz->esq = rotacao_esquerda(raiz->esq);
        return rotacao_direita(raiz);
    }
    if(fb < -1 && fator_balanceamento(raiz->esq) <= 0){
         return rotacao_esquerda(raiz); 
    }
    if(fb < -1 && fator_balanceamento(raiz->dir) > 0){
        raiz->dir = rotacao_direita(raiz->dir);
        return rotacao_esquerda(raiz);
    }
    return raiz;
}
struct no* inverter_arv(struct no* raiz){
    if(!raiz) return 0;
    // pre-fixao
    struct no* aux = raiz->esq;
    raiz->esq = raiz->dir;
    raiz->dir = aux;

    inverter_arv(raiz->esq);
    inverter_arv(raiz->dir);

    return raiz;
}
void printTree(struct no* raiz, int space){
    if (!raiz) return;

    space += 6;

    printTree(raiz->dir, space);
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", raiz->valor);
    printTree(raiz->esq, space);
}
