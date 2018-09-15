#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct elemento* Pilha;

struct elemento{
    struct aluno dados;
    struct aluno *prox;
};

typedef struct elemento Elem;

Pilha* cria_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_pilha(Pilha *pi){
    if(pi != NULL){
        Elem *no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int tamanho_pilha(Pilha *pi){
    if(pi == NULL) return 0;
    if(*pi == NULL) return 0;
    int count = 0;
    Elem *no = *pi;
    while(no->prox !=NULL){
        no = no->prox;
        count++;
    }
    return count;
}

int pilha_vazia(Pilha *pi){
    if(pi == NULL) return 1;
    if(*pi == NULL) return 1;
    return 0;
}

int insere_pilha(Pilha *pi, struct aluno al){
    if(pi == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remocao_pilha(Pilha *pi){
    if(pi == NULL) return 0;
    if((*pi) == NULL) return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int consulta_topo_pilha(Pilha *pi, struct aluno *al){
    if(pi == NULL) return 0;
    if((*pi) == NULL) return 0;
    *al = (*pi)->dados;
    return 1;
}

int main(){

    Pilha *pi;

    return 0;
}