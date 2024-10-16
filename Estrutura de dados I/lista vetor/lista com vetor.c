#include <stdio.h>
#include <stdlib.h>

struct lista{
    int* valores;
    int controle;
};
struct lista* criar_lista(int);
void desalocar(struct lista*);
int is_empty(struct lista);
int is_full(struct lista, int);
int inserir_inicio(struct lista*, int, int);
int inserir_fim(struct lista*, int, int);
void limpar(struct lista*);
void mostrar_lista(struct lista);
int mostrar_elemento(struct lista, int);
int remover_inicio_meio(struct lista*, int);
int remover_fim(struct lista*);

int main(){
    struct lista* list = criar_lista(10);
    for(int i = 0; i < 10; i++) inserir_fim(list, i, 10);
    mostrar_lista(*list);
    //printf("%d \n", remover_inicio_meio(list, 9));
    printf("%d \n", remover_fim(list));
    mostrar_lista(*list);
    /*printf("%d\n",inserir_inicio(list, 10, 10));
    printf("%d\n", mostrar_elemento(*list,0));
    printf("%d\n", remover_fim(list));
    printf("%d\n", mostrar_elemento(*list,0));*/
    desalocar(list);
    return 0;
}

struct lista* criar_lista(int tamanho){
    struct lista* list = (struct lista*)malloc(sizeof(struct lista));
    list->valores = (int*)malloc(tamanho * sizeof(int));
    list->controle = -1;
    return list;
}
int is_empty(struct lista list){
    if(list.controle == -1) return 1;
    return 0;
}
int is_full(struct lista list, int tamanho){
    if(list.controle == tamanho - 1) return 1;
    return 0;
}
int inserir_inicio(struct lista* list, int valor, int tamanho){
    if(is_full((*list),tamanho)) return 0;
    if(is_empty((*list))) return inserir_fim(list, valor, tamanho);
    int i;
    for(i = list->controle; i > 0; i++)
        list->valores[i + 1] = list->valores[i];
    list->valores[list->controle] = valor;
    list->controle = list->controle + 1;
    return 1;
}
int inserir_fim(struct lista* list, int valor, int tamanho){
    if(is_full((*list), tamanho)) return 0;
    list->valores[list->controle + 1] = valor;
    list->controle = list->controle + 1;
    return 1;
}
void mostrar_lista(struct lista list){
    if(is_empty(list)){
        printf("A lista esta vazia\n");
        return;
    }
    for(int i = 0; i <= list.controle; i++)
        printf("%d ", list.valores[i]);
    printf("\n");
}
int mostrar_elemento(struct lista list, int indice){
    if(is_empty(list)){
        printf("A lista esta vazia\n");
        return 0;
    }
    if(indice > list.controle){
        printf("O indice extrapola o tamanho da lista\n");
        return 0;
    }
    if(indice < 0){
        printf("O indice é invalido\n");
        return 0;
    }
    return list.valores[indice];
}
int remover_fim(struct lista* list){
    if(is_empty(*list)) return 0;
    list->controle = list->controle - 1;
    return 1;
}
int remover_inicio_meio(struct lista* list, int posicao){
    if(is_empty(*list)) return 0;
    if(posicao > list->controle) return 0;
    for(int i = posicao; i <= list->controle; i++)
        list->valores[i] = list->valores[i + 1];
    list->controle = list->controle - 1;
    return 1;
}
void limpar(struct lista* list){
    list->controle = -1;
}
void desalocar(struct lista* list){
    free(list->valores);
    free(list);
}