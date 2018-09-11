#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    // tres guiches, n clientes

    struct cliente{
        int CPF;
        char operacao[1];
        int valor;
        int CPF_terceiro;
    };

    typedef struct Cliente cli;
    typedef struct Cliente Guiche;

    return 0;
}
