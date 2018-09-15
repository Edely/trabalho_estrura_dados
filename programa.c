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

struct fila{
    struct elemento *inicio;
    struct elemento *final;
};


/*uma fila de clientes */
typedef struct fila Fila;

/*o guiche eh uma pilha*/
typedef struct elemento* Guiche;

/* type para cliente */
typedef struct cliente t_cliente;

/*elemento da pilha*/
typedef struct elemento Elem;

/* funcoes para fila */
Fila* cria_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
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

int insere_fila(Fila *fi, struct cliente al){
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(fi == NULL) return 0;    
    if(no == NULL) return 0;    
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL){
        fi->inicio = no;
    }else{
        fi->final->prox = no;
    }
    fi->final = no;
    return 1;
}

int remove_fila(Fila *fi){
    Elem *no = fi->inicio;
    if(fi == NULL) return 0;
    if(fi->inicio == NULL)
        return 0;
    
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)
        fi->final = NULL;                
    free(no);
    return 1;
}

/*funcoes para guiches*/
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

int imprime_fila(Fila *fi){
    Elem *no;
    no = fi->inicio;

    if(fi == NULL) return 0;
    if(fi->inicio == NULL)
        return 0;

    while(no->prox !=NULL){
        no = no->prox;
        /*
        printf("%i\n", no->dados.CPF);
        */
    }
    return 0;
}

int main(){

	int CPF, CPFT, N, i, valor;
    char temp;
    char operacao;
    Fila* fi; /* fila de clientes */
    i = 0;

    /*le numero de operacoes*/
    scanf("%d", &N);

    /*cria fila de clientes */
    fi = cria_fila();

    while(i<N){
        t_cliente cl;
        
        scanf("%c", &temp);
        scanf("%i %i %c %i", &CPF, &CPFT, &operacao, &valor);
        
        
        cl.CPF = CPF;
        cl.CPF_terceiro = CPFT;
        cl.valor = valor;
        cl.operacao = operacao;
       

        insere_fila(fi, cl);
        remove_fila(fi);

        /*
        printf("Cliente nº: %i\n", i);
        printf("CPF nº %i\n", cl.CPF);
        printf("CPF de Terceiro nº %i\n", cl.CPF_terceiro);
        printf("Operacao do tipo %c:\n", cl.operacao);
        printf("Valor da operacao %i:\n", cl.valor);
        printf("\n");
        */
        
        i++;  
    } 
	
	return 0;
}
