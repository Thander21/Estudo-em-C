/************************************************************
* @fileoverview Programa principal para estudo de ponteiros com visualização gráfica
* @module main
* @path c:/Users/Rahman/Documents/_Projetos/Estudo em C/Ponteiros/main.c
* @flow
* 1. Inicialização da janela gráfica
* 2. Loop principal do programa
* 3. Demonstração interativa de ponteiros
* 4. Renderização gráfica dos resultados
* @requires 
* - SDL3/SDL.h
* - graphics.h
* - pointer_demo.h
* @description
* Este arquivo contém o programa principal que gerencia a interface gráfica
* e as demonstrações de ponteiros. Ele coordena a exibição visual dos
* conceitos de ponteiros de forma didática e interativa.
**************************************************************/

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "pointer_demo.h"

// Constantes para a janela
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Estudo de Ponteiros em C"

// Estrutura para manter o estado do programa
typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
    int running;
    DemoState demoState;
} ProgramState;

// Função para inicializar SDL e criar janela
int initializeSDL(ProgramState* state) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erro ao inicializar SDL: %s\n", SDL_GetError());
        return 0;
    }

    state->window = SDL_CreateWindow(
        WINDOW_TITLE,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        0  // flags
    );

    if (!state->window) {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        return 0;
    }

    state->renderer = SDL_CreateRenderer(state->window, -1, SDL_RENDERER_ACCELERATED);
    if (!state->renderer) {
        printf("Erro ao criar renderer: %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}

// Processa eventos de entrada
void handleInput(ProgramState* state, SDL_Event* event) {
    switch (event->type) {
        case SDL_KEYDOWN:
            switch (event->key.keysym.sym) {
                case SDLK_RIGHT:
                case SDLK_SPACE:
                    nextDemoStep(&state->demoState);
                    break;
                case SDLK_LEFT:
                    previousDemoStep(&state->demoState);
                    break;
                case SDLK_1:
                    switchDemo(&state->demoState, DEMO_BASIC_POINTER);
                    break;
                case SDLK_2:
                    switchDemo(&state->demoState, DEMO_POINTER_ARITHMETIC);
                    break;
                case SDLK_3:
                    switchDemo(&state->demoState, DEMO_POINTER_ARRAY);
                    break;
                case SDLK_4:
                    switchDemo(&state->demoState, DEMO_POINTER_STRUCT);
                    break;
                case SDLK_5:
                    switchDemo(&state->demoState, DEMO_DOUBLE_POINTER);
                    break;
                case SDLK_ESCAPE:
                    state->running = 0;
                    break;
            }
            break;
        case SDL_QUIT:
            state->running = 0;
            break;
    }
}

// Função principal
int main(int argc, char* argv[]) {
    ProgramState state = {0};
    state.running = 1;

    if (!initializeSDL(&state)) {
        return 1;
    }

    // Inicializa a primeira demonstração
    initDemo(&state.demoState, DEMO_BASIC_POINTER);

    // Instruções iniciais
    printf("\nBem-vindo ao Estudo de Ponteiros em C!\n");
    printf("Controles:\n");
    printf("- Seta Direita/Espaço: Próximo passo\n");
    printf("- Seta Esquerda: Passo anterior\n");
    printf("- 1: Demonstração básica de ponteiros\n");
    printf("- 2: Demonstração de aritmética de ponteiros\n");
    printf("- 3: Demonstração de arrays e ponteiros\n");
    printf("- 4: Demonstração de structs e ponteiros\n");
    printf("- 5: Demonstração de ponteiros duplos\n");
    printf("- ESC: Sair\n\n");

    // Loop principal
    while (state.running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            handleInput(&state, &event);
        }

        // Atualiza e renderiza a demonstração atual
        updateDemo(&state.demoState);
        renderDemo(state.renderer, &state.demoState);
        SDL_RenderPresent(state.renderer);

        SDL_Delay(16); // Aproximadamente 60 FPS
    }

    // Limpeza
    cleanupDemo(&state.demoState);
    SDL_DestroyRenderer(state.renderer);
    SDL_DestroyWindow(state.window);
    SDL_Quit();

    return 0;
}
