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

typedef struct cliente t_cliente;
typedef struct cliente *Guiche;

Guiche* criaFila(){
    Guiche* G = malloc(sizeof(Guiche));
    if(G != NULL){
        *G = NULL;
    }
    return G;
}

void zeraFila(Guiche *G){

    if( G != NULL){
        t_cliente *no;
        while((*G) != NULL){
            no = *G;
            *G = (*G)->proximo;
            free(no);
        }
        free(G);
    }
    return 0;
}

int main(){
    //criar uma lista circular com cabeca que acessa uma fila de structs

    // tres guiches com n clientes

    //implementar Fila de clientes

    //implementar uma Lista de guiches

    return 0;
}
