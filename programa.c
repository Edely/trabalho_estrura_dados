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

/*o guiche eh uma Pilha*/
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

int insere_guiche(Guiche* pi, struct cliente al){
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(pi == NULL) return 0;    
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int relatorio_guiche(Guiche* gi, int count){
    Elem *no;
    no = *gi;
    printf("Guiche %i\n", count);
    if(gi == NULL) return 0;
    if(no == NULL) return 0;        
    while(no != NULL){
        printf("%i %i %c %i\n", no->dados.CPF, no->dados.CPF_terceiro, no->dados.operacao, no->dados.valor);
        no = no->prox;
    }
    printf("\n");
    return 1;
}

int imprime_fila(Fila *fi){
    Elem *no;
    int count;
    count = 1;
    if(fi == NULL){
        return 0;
    } 
    if(fi->inicio == NULL){
        return 0;
    }else{
        no = fi->inicio;
    }
    while(no != NULL){
        printf("Cliente numero: %i\n", count);
        printf("Cpf: %i\n", no->dados.CPF);
        printf("Cpf do destinatario: %i\n", no->dados.CPF_terceiro);
        printf("Valor %i\n", no->dados.valor);
        printf("Operacao %c\n", no->dados.operacao);
        printf("\n");
        no = no->prox;
        count++;
    }
    return 0;
}

int percorre_fila_adiciona_no_guiche(Fila *fi, int M, Guiche* g1, Guiche* g2, Guiche* g3){
    Elem *no;
    int count;
    count = 1;
    if(fi == NULL){
        return 0;
    } 
    if(fi->inicio == NULL){
        return 0;
    }else{
        no = fi->inicio;
    }
    while(no != NULL){

        if(count % M == 1){
            insere_guiche(g1, no->dados);
        }else if(count % M == 2){
            insere_guiche(g2, no->dados);
        }else{
            insere_guiche(g3, no->dados);
        }
        no = no->prox;
        count++;
    }
    return 0;
}

int main(){

	int CPF, CPFT, N, i, valor, M;
    char temp;
    char operacao;
    Fila* fi; /* fila de clientes */
    Guiche* g1;
    Guiche* g2;
    Guiche* g3; /* guiches */
    i = 0;

    /*le numero de operacoes*/
    scanf("%d", &N);

    /*cria fila de clientes */
    fi = cria_fila();

    while(i<N){
        
        /* cria o cliente */
        t_cliente cl;
        scanf("%c", &temp);

        /* le os dados */
        scanf("%i %i %c %i", &CPF, &CPFT, &operacao, &valor);
        
        /* adiciona dados */
        cl.CPF = CPF;
        cl.CPF_terceiro = CPFT;
        cl.valor = valor;
        cl.operacao = operacao;

        /* insere na fila*/
        insere_fila(fi, cl);       
        i++;  
    } 
    /*imprime_fila(fi);*/

    M = 3;
    g1 = cria_guiche();
    g2 = cria_guiche();
    g3 = cria_guiche();

    percorre_fila_adiciona_no_guiche(fi, M, g1, g2, g3);

    printf("-:| RELATÓRIO PARCIAL |:-\n");
    printf("%i\n", M);

    relatorio_guiche(g1, 1);
    relatorio_guiche(g2, 2);
    relatorio_guiche(g3, 3);

    remove_fila(fi);
	
	return 0;
}