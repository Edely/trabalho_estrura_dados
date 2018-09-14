#include <stdio.h>

struct cliente{
    int CPF;
    char operacao[1];
    int valor;
    int CPF_terceiro;
    struct cliente *proximo;
};

typedef struct cliente t_cliente;

int main(int argc, char *argv[]){
	int CPF, CPFT, N, i, valor;
    char temp;
    char *operacao;
    i = 0;

    //le numero de operacoes
    scanf("%d", &N);

    //criar lista circular pra guardar guiches

    while(i<N){
        scanf("%c", &temp);
        scanf("%i %i %c %i", &CPF, &CPFT, &operacao, &valor);

        //checa se valores foram inseridos
        if(CPF != NULL && CPFT != NULL && operacao != NULL && valor != NULL){

            t_cliente *cl = (t_cliente*) malloc(sizeof(t_cliente));

            i++;
        }

        //printf("%d %d %c %d\n", CPF, CPFT, operacao, valor);
        
    }    
	
	return 0;
}
