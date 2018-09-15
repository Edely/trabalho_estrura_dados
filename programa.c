#include <stdio.h>
#include <stdlib.h>

//o cliente
struct cliente{
    int CPF;
    char *operacao;
    int valor;
    int CPF_terceiro;
};

//no == cliente
struct elemento{
    struct cliente dados;
    struct cliente *prox;
};

//o guiche eh uma pilha
typedef struct elemento* Guiche;

//elemento da pilha
typedef struct elemento Elem;

//funcoes
Guiche* cria_guiche(){
    Guiche* pi = (Guiche*) malloc(sizeof(Guiche));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_guiche(Guiche *pi){
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

int main(int argc, char *argv[]){

    struct cliente *selina;
    selina->CPF = 0;
    selina->CPF_terceiro = 1;
    selina->valor = 7;
    selina->operacao = 'd';

    
	
	return 0;
}
