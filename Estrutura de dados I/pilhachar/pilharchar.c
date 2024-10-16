#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct no{
    int valor;
    struct no* prox;
};
struct no* criar_pilha();
void push(struct no**, int);
int pop(struct no**);
///////////////////////////////////////////////////////////////////////////////////





























int main(){
    struct no* pilha = criar_pilha();
    char conta[100];
    fgets(conta, 100, stdin);

    for(int i = 0; conta[i] != '\0'; i++){

        if(conta[i] > 47){
            push(&pilha, (conta[i] - 48));
            continue;
        } 

        int a = pop(&pilha), b = pop(&pilha);
        if(conta[i] == '+') push(&pilha, (a+b));
        else if(conta[i] == '-') push(&pilha, (a-b));
        else if(conta[i] == '*') push(&pilha, (a*b));
        else if(conta[i] == '/'){
            if(b) push(&pilha, (a/b));
        }
    }
    while(pilha)
        printf("%d\n", pop(&pilha));
    return 0;
}





















struct no* criar_pilha(){
    return 0;
}

int is_empty(struct no* pilha){
    if(!pilha) return 1;
    return 0;
}

void push(struct no** pilha, int valor){
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    if(!novo) return;

    novo->valor = valor;
    novo->prox = (*pilha);

    (*pilha) = novo;
}

int pop(struct no** pilha){
    if(is_empty(*pilha)) return 0;

    struct no* aux = (*pilha);
    int valor = (*pilha)->valor;

    (*pilha) = (*pilha)->prox;
    free(aux);
    return valor;
}
