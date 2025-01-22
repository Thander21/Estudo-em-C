/************************************************************
* @fileoverview Programa principal para estudo de ponteiros
* @module main
* @path c:/Users/Rahman/Documents/_Projetos/Cteste/main.c
* @description
* Este arquivo contém o programa principal que demonstra
* o funcionamento de ponteiros de forma didática
**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cores para console (Windows)
#define COLOR_RESET   "\x1B[0m"
#define COLOR_RED     "\x1B[31m"
#define COLOR_GREEN   "\x1B[32m"
#define COLOR_YELLOW  "\x1B[33m"
#define COLOR_BLUE    "\x1B[34m"

// Estrutura para demonstração
typedef struct {
    char name[50];
    int value;
} DemoData;

// Funções de demonstração
void demonstrarPonteiroBasico(void) {
    printf("\n%s=== Demonstração de Ponteiro Básico ===%s\n\n", COLOR_BLUE, COLOR_RESET);
    
    int numero = 42;
    int* ponteiro = &numero;
    
    printf("Variável 'numero':\n");
    printf("  Valor: %s%d%s\n", COLOR_GREEN, numero, COLOR_RESET);
    printf("  Endereço: %s%p%s\n\n", COLOR_YELLOW, (void*)&numero, COLOR_RESET);
    
    printf("Ponteiro 'ponteiro':\n");
    printf("  Valor (endereço armazenado): %s%p%s\n", COLOR_YELLOW, (void*)ponteiro, COLOR_RESET);
    printf("  Valor apontado: %s%d%s\n", COLOR_GREEN, *ponteiro, COLOR_RESET);
    printf("  Endereço do ponteiro: %s%p%s\n", COLOR_RED, (void*)&ponteiro, COLOR_RESET);
    
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void demonstrarArrayPonteiros(void) {
    printf("\n%s=== Demonstração de Array e Ponteiros ===%s\n\n", COLOR_BLUE, COLOR_RESET);
    
    int array[] = {1, 2, 3, 4, 5};
    int* ptr = array;
    
    printf("Array e ponteiro:\n");
    for (int i = 0; i < 5; i++) {
        printf("array[%d] = %s%d%s\t", i, COLOR_GREEN, array[i], COLOR_RESET);
        printf("Endereço: %s%p%s\n", COLOR_YELLOW, (void*)&array[i], COLOR_RESET);
    }
    
    printf("\nNavegando com aritmética de ponteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("*(ptr + %d) = %s%d%s\t", i, COLOR_GREEN, *(ptr + i), COLOR_RESET);
        printf("Endereço: %s%p%s\n", COLOR_YELLOW, (void*)(ptr + i), COLOR_RESET);
    }
    
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void demonstrarPonteiroStruct(void) {
    printf("\n%s=== Demonstração de Ponteiro para Struct ===%s\n\n", COLOR_BLUE, COLOR_RESET);
    
    DemoData data = {"Exemplo", 100};
    DemoData* ptrStruct = &data;
    
    printf("Struct DemoData:\n");
    printf("  Usando variável:\n");
    printf("    Nome: %s%s%s\n", COLOR_GREEN, data.name, COLOR_RESET);
    printf("    Valor: %s%d%s\n\n", COLOR_GREEN, data.value, COLOR_RESET);
    
    printf("  Usando ponteiro:\n");
    printf("    Nome: %s%s%s\n", COLOR_GREEN, ptrStruct->name, COLOR_RESET);
    printf("    Valor: %s%d%s\n", COLOR_GREEN, ptrStruct->value, COLOR_RESET);
    printf("    Endereço: %s%p%s\n", COLOR_YELLOW, (void*)ptrStruct, COLOR_RESET);
    
    printf("\nPressione ENTER para continuar...");
    getchar();
}

int main(void) {
    printf("Bem-vindo ao Estudo de Ponteiros em C!\n\n");
    printf("Este programa demonstrará diferentes aspectos de ponteiros\n");
    printf("de forma interativa e didática.\n\n");
    
    while (1) {
        printf("\n%s=== Menu Principal ===%s\n", COLOR_BLUE, COLOR_RESET);
        printf("1. Ponteiro Básico\n");
        printf("2. Arrays e Ponteiros\n");
        printf("3. Ponteiros e Structs\n");
        printf("0. Sair\n\n");
        
        printf("Escolha uma opção: ");
        int opcao;
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer
        
        switch (opcao) {
            case 0:
                printf("\nObrigado por usar o programa!\n");
                return 0;
            case 1:
                demonstrarPonteiroBasico();
                break;
            case 2:
                demonstrarArrayPonteiros();
                break;
            case 3:
                demonstrarPonteiroStruct();
                break;
            default:
                printf("%sOpção inválida!%s\n", COLOR_RED, COLOR_RESET);
        }
    }
    
    return 0;
}
