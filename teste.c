#include <stdio.h>

int main(int argc, char *argv[]){
	int CPF, CPFT, N, i, valor;
    char temp;
    char *operacao;
    i = 0;

    scanf("%d", &N);

    //criar lista circular

    while(i<N){
        scanf("%c", &temp);
        scanf("%i %i %c %i", &CPF, &CPFT, &operacao, &valor);
        printf("%d %d %c %d\n", CPF, CPFT, operacao, valor);
        i++;
    }    
	
	return 0;
}
