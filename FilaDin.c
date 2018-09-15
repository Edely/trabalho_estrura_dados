#include <stdio.h>

struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

struct fila{
    struct elemento *inicio;
    struct elemento *final;
};

typedef struct fila Fila;

typedef struct elemento Elem;


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

int tamanho_fila(Fila *fi){
    if(fi == NULL) return 0;
    Elem *no = fi->inicio;
    int count = 0;
    while(no != NULL){
        count++;
        no = no->prox;
    }
    return count;
}

int fila_vazia(Fila *fi){
    if(fi == NULL) return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int insere_fila(Fila *fi, struct aluno al){
    if(fi == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
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
    if(fi == NULL) return 0;
    if(fi->inicio == NULL)
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)
        fi->final = NULL;                
    free(no);
    return 1;
}


int consulta_fila(Fila *fi, struct aluno *al){
    if(fi == NULL) return 0;
    if(fi->inicio == NULL)
        return 0;
    *al = fi->inicio->dados;
    return 1;
}
int main(){

    Fila *fi;

    fi = cria_fila();

    libera_fila(fi);

    return 0;
}