#include <stdio.h>

int main(){
		int i = 1, soma;
		
		while(i <= 100){
            soma = soma + i;
            i++;
		}

        printf("%d \n", soma);

        return 0;
}