/************************************************************
* @fileoverview Implementação das demonstrações de ponteiros
* @module pointer_demo
* @path c:/Users/Rahman/Documents/_Projetos/Cteste/pointer_demo.c
* @requires 
* - SDL3/SDL.h
* - graphics.h
* - pointer_demo.h
* @description
* Implementa as demonstrações interativas de ponteiros,
* incluindo visualizações e animações didáticas
**************************************************************/

#include "pointer_demo.h"
#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>

// Demonstração básica de ponteiros
void demoBasicPointer(SDL_Renderer* renderer, int step) {
    int valor = 42;
    int* ptr = &valor;
    
    // Define as posições dos elementos na tela
    Rectangle valorRect = {200, 200, 100, 60};
    Rectangle ptrRect = {400, 200, 100, 60};
    
    // Limpa a tela
    clearScreen(renderer, hexToSDLColor(COLOR_BACKGROUND));
    
    // Desenha as caixas de memória
    drawMemoryBox(renderer, valorRect, "valor", "42", hexToSDLColor(COLOR_VARIABLE));
    drawMemoryBox(renderer, ptrRect, "ptr", "0x...", hexToSDLColor(COLOR_POINTER));
    
    // Desenha a conexão entre o ponteiro e a variável
    if (step >= 1) {
        drawPointerConnection(renderer, ptrRect, valorRect, hexToSDLColor(COLOR_ARROW));
    }
    
    // Adiciona explicações baseadas no passo atual
    char* explanation;
    switch(step) {
        case 0:
            explanation = "Temos uma variável 'valor' contendo 42";
            break;
        case 1:
            explanation = "O ponteiro 'ptr' armazena o endereço de 'valor'";
            break;
        case 2:
            explanation = "Usando *ptr podemos acessar o valor apontado (42)";
            break;
        default:
            explanation = "";
    }
    
    // Desenha a explicação
    SDL_Color textColor = hexToSDLColor(COLOR_TEXT);
    drawText(renderer, explanation, 200, 400, textColor);
}

// Demonstração de aritmética de ponteiros
void demoPointerArithmetic(SDL_Renderer* renderer, int step) {
    int array[] = {1, 2, 3, 4, 5};
    int* ptr = array;
    
    Rectangle arrayRects[5];
    for(int i = 0; i < 5; i++) {
        arrayRects[i] = (Rectangle){200 + (i * 120), 200, 100, 60};
    }
    
    clearScreen(renderer, hexToSDLColor(COLOR_BACKGROUND));
    
    // Desenha os elementos do array
    for(int i = 0; i < 5; i++) {
        char value[10];
        sprintf(value, "%d", array[i]);
        drawMemoryBox(renderer, arrayRects[i], "", value, hexToSDLColor(COLOR_VARIABLE));
    }
    
    // Desenha o ponteiro na posição atual
    if (step < 5) {
        Rectangle ptrRect = {200, 100, 100, 60};
        ptrRect.x += (step * 120);
        drawMemoryBox(renderer, ptrRect, "ptr", "", hexToSDLColor(COLOR_POINTER));
        drawPointerConnection(renderer, ptrRect, arrayRects[step], hexToSDLColor(COLOR_ARROW));
    }
    
    // Adiciona explicação
    char* explanation;
    switch(step) {
        case 0:
            explanation = "ptr aponta para o primeiro elemento";
            break;
        case 1:
            explanation = "ptr + 1 move para o próximo elemento";
            break;
        case 2:
            explanation = "ptr + 2 pula dois elementos";
            break;
        case 3:
            explanation = "ptr + 3 continua avançando";
            break;
        case 4:
            explanation = "ptr + 4 chega ao último elemento";
            break;
        default:
            explanation = "";
    }
    
    SDL_Color textColor = hexToSDLColor(COLOR_TEXT);
    drawText(renderer, explanation, 200, 400, textColor);
}

// Inicializa uma demonstração
void initDemo(DemoState* state, DemoType demo) {
    state->currentDemo = demo;
    state->step = 0;
    state->animationFrame = 0;
    state->demoData = NULL;
}

// Atualiza o estado da demonstração
void updateDemo(DemoState* state) {
    state->animationFrame++;
}

// Renderiza a demonstração atual
void renderDemo(SDL_Renderer* renderer, DemoState* state) {
    switch(state->currentDemo) {
        case DEMO_BASIC_POINTER:
            demoBasicPointer(renderer, state->step);
            break;
        case DEMO_POINTER_ARITHMETIC:
            demoPointerArithmetic(renderer, state->step);
            break;
        default:
            // Outras demonstrações serão implementadas posteriormente
            break;
    }
}

// Limpa os recursos da demonstração
void cleanupDemo(DemoState* state) {
    free(state->demoData);
    state->demoData = NULL;
}

// Avança para o próximo passo da demonstração
void nextDemoStep(DemoState* state) {
    state->step++;
    state->animationFrame = 0;
}

// Volta para o passo anterior da demonstração
void previousDemoStep(DemoState* state) {
    if (state->step > 0) {
        state->step--;
        state->animationFrame = 0;
    }
}

// Muda para outra demonstração
void switchDemo(DemoState* state, DemoType newDemo) {
    cleanupDemo(state);
    initDemo(state, newDemo);
}
