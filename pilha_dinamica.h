
struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct elemento* Pilha;

Pilha* cria_pilha();
void libera_pilha(Pilha* pi);