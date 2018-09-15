#include <stdio.h>
#include <stdlib.h>

//o cliente
struct cliente{
    int CPF;
    char *operacao;
    int valor;
    int CPF_terceiro;
};

//no de cliente
struct elemento{
    struct cliente dados;
    struct cliente *prox;
};

//o guiche eh uma fila
struct guiche{
    int n_operacoes;
    struct cliente *inicio;
    struct cliente *final;
};

typedef struct cliente t_cliente;
typedef struct guiche t_guiche;

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

int main(int argc, char *argv[]){
	int CPF, CPFT, N, i, valor;
    char temp;
    char *operacao;
    i = 0;

    //le numero de operacoes
    scanf("%d", &N);

    //criar lista circular pra guardar guiches

    Fila *g1 = cria_fila();
    Fila *g2 = cria_fila();
    Fila *g3 = cria_fila();

    /*
    struct cliente selina;
    selina.CPF = 0;    
    selina->CPF_terceiro = 1;
    selina->valor = 7;
    selina->operacao = "d";
    
    printf("%i\n", selina.CPF);
    */
   
    /*
    while(i<N){
        scanf("%c", &temp);
        scanf("%i %i %c %i", &CPF, &CPFT, &operacao, &valor);

        t_cliente* cl;
        cl->CPF = CPF;
        cl->CPF_terceiro = CPFT;
        cl->valor = valor;
        cl->operacao = operacao;

        printf("Cliente nº %i:\n", i);
        printf("CPF nº %i:\n", cl->CPF);
        printf("CPF de Terceiro nº %i:\n", cl->CPF_terceiro);
        printf("Operacao do tipo %c:\n", cl->operacao);
        printf("Valor da operacao %i:\n", cl->valor);

        printf("\n");

        i++;
        //printf("%d %d %c %d\n", CPF, CPFT, operacao, valor);
        
    } 
    */   
	
	return 0;
}
