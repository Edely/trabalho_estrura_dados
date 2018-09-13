#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente{
    int CPF;
    char operacao[1];
    int valor;
    int CPF_terceiro;
    struct cliente *proximo;
};

struct elemento{
    struct cliente dados;
    struct elemento *prox;
};

struct guiche{
    int n_operacoes;
    struct elemento *inicio;
    struct elemento *final;
};

typedef struct cliente t_cliente;
typedef struct guiche Guiche;
typedef struct elemento Elem;
typedef struct guiche Fila;


Fila* cria_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        return 0;
    }
    return fi;
}

void libera_fila(Fila *fi){
    if(fi != NULL){
        Elem *no;
        while(fi->inicio !=NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int consulta_fila(Fila *fi, struct cliente *cl){
    if(fi == NULL) return 0;
    if(fi->inicio == NULL)
        return 0;
    Elem *no = fi->inicio;
    int posicao = 0;
    while(no->dados.CPF != cl->CPF){
        no = no->prox;
        posicao++;    
    }
    if(no->prox == NULL) 
        return 0;
    else 
        return no->dados.CPF;
    

    return 1;
}

int main(){
    int N;
    //criar uma lista circular com cabeca que acessa uma fila de structs
    // tres guiches com n clientes

    //implementar Fila de clientes

    //implementar uma Lista de guiches

    return 0;
}
