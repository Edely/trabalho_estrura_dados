#include <stdio.h>

int main(int argc, char *argv[]){
	int CPF, CPFT, N, i, valor;
    char temp;
    //unsigned  CPF, CPFT;
    char *operacao[1];
    i = 0;

    scanf("%d", &N);

    while(i<N){
        scanf("%c", &temp);
        scanf("%i %i %c %i", &CPF, &CPFT, &operacao, &valor);
        printf("%d %d %d %d\n", CPF, CPFT, operacao, valor);
        i++;
    }    
	
	return 0;
}
