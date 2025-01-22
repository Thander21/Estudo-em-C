/************************************************************
* @fileoverview Implementação das demonstrações de ponteiros
* @module pointer_demo
* @path c:/Users/Rahman/Documents/_Projetos/Estudo em C/Ponteiros/pointer_demo.c
* @requires 
* - SDL3/SDL.h
* - graphics.h
* - pointer_demo.h
* @description
* Este arquivo implementa as diferentes demonstrações de ponteiros,
* incluindo ponteiros básicos, arrays, structs e ponteiros duplos.
* Cada demonstração é apresentada de forma visual e interativa.
**************************************************************/

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphics.h"
#include "pointer_demo.h"

// Estrutura para dados específicos de cada demonstração
typedef struct {
    int value;
    int* pointer;
    char description[256];
    Rectangle valueBox;
    Rectangle pointerBox;
} BasicPointerDemo;

typedef struct {
    int array[5];
    int* ptr;
    int currentIndex;
    Rectangle arrayBoxes[5];
    Rectangle pointerBox;
} ArrayPointerDemo;

typedef struct {
    char name[50];
    int value;
    Rectangle structBox;
    Rectangle pointerBox;
} StructPointerDemo;

// Inicializa uma demonstração
void initDemo(DemoState* state, DemoType demo) {
    state->currentDemo = demo;
    state->step = 0;
    state->animationFrame = 0;
    
    // Aloca e inicializa dados específicos da demonstração
    switch (demo) {
        case DEMO_BASIC_POINTER: {
            BasicPointerDemo* data = malloc(sizeof(BasicPointerDemo));
            data->value = 42;
            data->pointer = &data->value;
            data->valueBox = (Rectangle){200, 200, 100, 50};
            data->pointerBox = (Rectangle){400, 200, 150, 50};
            sprintf(data->description, "Demonstração de ponteiro básico");
            state->demoData = data;
            break;
        }
        case DEMO_POINTER_ARRAY: {
            ArrayPointerDemo* data = malloc(sizeof(ArrayPointerDemo));
            for (int i = 0; i < 5; i++) {
                data->array[i] = i + 1;
                data->arrayBoxes[i] = (Rectangle){100 + i * 120, 200, 100, 50};
            }
            data->ptr = data->array;
            data->currentIndex = 0;
            data->pointerBox = (Rectangle){150, 300, 150, 50};
            state->demoData = data;
            break;
        }
        case DEMO_POINTER_STRUCT: {
            StructPointerDemo* data = malloc(sizeof(StructPointerDemo));
            strcpy(data->name, "Exemplo");
            data->value = 100;
            data->structBox = (Rectangle){200, 200, 200, 100};
            data->pointerBox = (Rectangle){500, 200, 150, 50};
            state->demoData = data;
            break;
        }
        default:
            state->demoData = NULL;
            break;
    }
}

// Atualiza o estado da demonstração
void updateDemo(DemoState* state) {
    state->animationFrame++;
    
    switch (state->currentDemo) {
        case DEMO_POINTER_ARRAY: {
            ArrayPointerDemo* data = (ArrayPointerDemo*)state->demoData;
            if (state->step > data->currentIndex && data->currentIndex < 4) {
                data->currentIndex++;
                data->ptr++;
            }
            break;
        }
        default:
            break;
    }
}

// Renderiza a demonstração atual
void renderDemo(SDL_Renderer* renderer, DemoState* state) {
    // Limpa a tela
    clearScreen(renderer, hexToSDLColor(COLOR_BACKGROUND));
    
    // Renderiza a demonstração específica
    switch (state->currentDemo) {
        case DEMO_BASIC_POINTER: {
            BasicPointerDemo* data = (BasicPointerDemo*)state->demoData;
            
            // Desenha a variável
            char valueStr[32];
            sprintf(valueStr, "valor = %d", data->value);
            drawMemoryBox(renderer, data->valueBox, "variável", valueStr, hexToSDLColor(COLOR_VARIABLE));
            
            // Desenha o ponteiro
            char ptrStr[32];
            sprintf(ptrStr, "ptr = %p", (void*)data->pointer);
            drawMemoryBox(renderer, data->pointerBox, "ponteiro", ptrStr, hexToSDLColor(COLOR_POINTER));
            
            // Desenha a conexão
            drawPointerConnection(renderer, data->pointerBox, data->valueBox, hexToSDLColor(COLOR_ARROW));
            break;
        }
        case DEMO_POINTER_ARRAY: {
            ArrayPointerDemo* data = (ArrayPointerDemo*)state->demoData;
            
            // Desenha o array
            for (int i = 0; i < 5; i++) {
                char valueStr[32];
                sprintf(valueStr, "array[%d]=%d", i, data->array[i]);
                drawMemoryBox(renderer, data->arrayBoxes[i], "", valueStr, hexToSDLColor(COLOR_VARIABLE));
            }
            
            // Desenha o ponteiro
            char ptrStr[32];
            sprintf(ptrStr, "ptr = %p", (void*)data->ptr);
            drawMemoryBox(renderer, data->pointerBox, "ponteiro", ptrStr, hexToSDLColor(COLOR_POINTER));
            
            // Desenha a conexão
            drawPointerConnection(renderer, data->pointerBox, data->arrayBoxes[data->currentIndex], hexToSDLColor(COLOR_ARROW));
            break;
        }
        case DEMO_POINTER_STRUCT: {
            StructPointerDemo* data = (StructPointerDemo*)state->demoData;
            
            // Desenha a struct
            char structStr[64];
            sprintf(structStr, "name: %s\nvalue: %d", data->name, data->value);
            drawMemoryBox(renderer, data->structBox, "struct", structStr, hexToSDLColor(COLOR_VARIABLE));
            
            // Desenha o ponteiro
            char ptrStr[32];
            sprintf(ptrStr, "ptr = %p", (void*)data);
            drawMemoryBox(renderer, data->pointerBox, "ponteiro", ptrStr, hexToSDLColor(COLOR_POINTER));
            
            // Desenha a conexão
            drawPointerConnection(renderer, data->pointerBox, data->structBox, hexToSDLColor(COLOR_ARROW));
            break;
        }
        default:
            break;
    }
}

// Limpa os recursos da demonstração
void cleanupDemo(DemoState* state) {
    if (state->demoData) {
        free(state->demoData);
        state->demoData = NULL;
    }
}

// Avança para o próximo passo da demonstração
void nextDemoStep(DemoState* state) {
    state->step++;
}

// Volta para o passo anterior da demonstração
void previousDemoStep(DemoState* state) {
    if (state->step > 0) {
        state->step--;
    }
}

// Muda para outra demonstração
void switchDemo(DemoState* state, DemoType newDemo) {
    cleanupDemo(state);
    initDemo(state, newDemo);
}
