#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista_circular(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista_circular(Lista* li){
    Elem *no = *li;
    Elem *aux;
    if(li != NULL && (*li) != NULL){
        while((*li) != no->prox){
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(aux);
    }    
}

int tamanho_lista_circular(Lista *li){
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    int count = 0;
    Elem *no = *li;
    do{
        count++;
        no = no->prox;
    }while(no != (*li));
    return count;
}

int lista_circular_vazia(Lista* li){
    if(li == NULL && (*li) == NULL)
        return 1;
    else    
        return 0;
}

int insercao_inicio_circula(Lista *li, struct aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    if((*li) == NULL){
        *li = no;
        no->prox = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != (*li))
            aux = aux->prox;
        aux->prox = no;
        no->prox = *li;
        *li = no;
    }
    return 1;
}

int insercao_final_circula(Lista *li, struct aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    if((*li) == NULL){
        *li = no;
        no->prox = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != (*li))
            aux = aux->prox;
        aux->prox = no;
        no->prox = *li;
    }
    return 1;
}

int main(){
    Lista* li;
    li = cria_lista_circular();
    return 0;
}