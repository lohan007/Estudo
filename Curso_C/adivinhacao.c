#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//#define TENTATIVAS 5 //definindo constantes

int main(){

	setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português

	// imprimindo cabecalho bonito do jogo
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

	srand(time(0));
	int chute,
	 	numerodasorte = rand() % 100,  
	 	tentativas = 1,
		acertou = 0;
	double pontos = 1000;

	int nivel;
	printf("Qual o nivel de dificuldade?\n");
	printf("(1) Fácil (2) Médio (3) Difícil\n\n");
	printf("Escolha: ");
	scanf("%d", &nivel);

	int numerodetentativas;

	switch(nivel) {
		case 1:
			numerodetentativas = 20;
			break;
		case 2:
			numerodetentativas = 15;
			break;
		default:
			numerodetentativas = 6;
			break;
	}

	for(int i = 1; i <= numerodetentativas; i++){
		printf("Tentativa %d\n", tentativas);
		printf("Qual o seu chute?\n");

		scanf("%d", &chute);
		printf("Seu chute foi: %d\n", chute);

		if(chute < 0){
			printf("Voce nao pode usar numeros negativos!\n");
			continue; // continua a opeção para o proximo laço
		}

		acertou = (chute == numerodasorte);
		int	maior = chute > numerodasorte;

		if(acertou){
			break;
		} 

		else if(maior){
			printf("O seu chute foi maior que o número da sorte, tente de novo\n\n");
		}

		else{
			printf("Seu chute foi menor que o número da sorte, tente de novo\n\n");
		}

		tentativas++;

		double pontosperdidos = abs(chute - numerodasorte) / 2.0; //abs converte numero para positivo, numero absoluto
		pontos = pontos - pontosperdidos;
	}
	printf("Fim de jogo!\n");

	if(acertou){
		printf("Você ganhou!\n");
		printf("Voce acertou em %d tentativas.\n", tentativas);
		printf("Total de pontos: %.1f\n", pontos);
	} else{
		printf("Você perdeu! Tente de novo!\n");
	}
	return 0;
}