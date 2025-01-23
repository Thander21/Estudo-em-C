#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Bem vindo ao nosso jogo de adivinhação!\n");

    int numero_aleatorio = rand() % 1000 + 1;

    int tentativas = 10;

    printf("Digite um número entre 1 e 100 para adivinha o número: \n");

    while (tentativas > 0) {
        int chute;
        scanf("%d", &chute);

        if (chute == numero_aleatorio) {
            printf("Parabéns, vocé acertou o número! O número era: %d\n", numero_aleatorio);
            break;
        } else if (chute > numero_aleatorio) {
            printf("O chute foi maior que o número aleatório. Tente novamente!\n");
        } else {
            printf("O chute foi menor que o número aleatório. Tente novamente!\n");
        }
        tentativas--;
        printf("Tentativas restantes: %d\n", tentativas);
        
    }

    if (tentativas == 0)  
        printf("Suas tentativas acabaram. O número era: %d\n", numero_aleatorio);
    
}


