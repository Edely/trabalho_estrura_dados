#include <stdio.h>
#include <stdlib.h>
#include "pilha_dinamica.c"

int main(){

    Pilha* pi;
    pi = cria_pilha();
    libera_pilha(pi);
    return 0;
}