#include <stdio.h>
#include <stdlib.h>

/*o cliente*/
struct cliente{
    int CPF;
    char operacao;
    int valor;
    int CPF_terceiro;
};

/*no == cliente*/
struct elemento{
    struct cliente dados;
    struct elemento *prox;
};

/*o guiche eh uma pilha*/
typedef struct elemento* Guiche;


typedef struct cliente t_cliente;

/*elemento da pilha*/
typedef struct elemento Elem;

/*funcoes*/
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

int main(){

	int CPF, CPFT, N, i, valor;
    char temp;
    char operacao;
    i = 0;

    /*le numero de operacoes*/
    scanf("%d", &N);


    while(i<N){
        t_cliente cl;
        scanf("%c", &temp);
        scanf("%i %i %c %i", &CPF, &CPFT, &operacao, &valor);

        
        cl.CPF = CPF;
        cl.CPF_terceiro = CPFT;
        cl.valor = valor;
        cl.operacao = operacao;

        printf("Cliente nº: %i\n", i);
        printf("CPF nº %i\n", cl.CPF);
        printf("CPF de Terceiro nº %i\n", cl.CPF_terceiro);
        printf("Operacao do tipo %c:\n", cl.operacao);
        printf("Valor da operacao %i:\n", cl.valor);

        printf("\n");

        i++;
        /* printf("%d %d %c %d\n", CPF, CPFT, operacao, valor);*/
  
    } 
	
	return 0;
}
