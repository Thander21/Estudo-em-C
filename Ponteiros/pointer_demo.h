/************************************************************
* @fileoverview Demonstrações didáticas de ponteiros
* @module pointer_demo
* @path c:/Users/Rahman/Documents/_Projetos/Cteste/pointer_demo.h
* @requires 
* - graphics.h
* @description
* Define as estruturas e funções para demonstrações
* interativas de diferentes tipos de ponteiros e seus usos
**************************************************************/

#ifndef POINTER_DEMO_H
#define POINTER_DEMO_H

#include <SDL3/SDL.h>
#include "graphics.h"

// Tipos de demonstrações disponíveis
typedef enum {
    DEMO_BASIC_POINTER,
    DEMO_POINTER_ARITHMETIC,
    DEMO_POINTER_ARRAY,
    DEMO_POINTER_STRUCT,
    DEMO_DOUBLE_POINTER
} DemoType;

// Estrutura para controlar o estado da demonstração
typedef struct {
    DemoType currentDemo;
    int step;
    int animationFrame;
    void* demoData;
} DemoState;

// Funções de demonstração
void initDemo(DemoState* state, DemoType demo);
void updateDemo(DemoState* state);
void renderDemo(SDL_Renderer* renderer, DemoState* state);
void cleanupDemo(DemoState* state);

// Demonstrações específicas
void demoBasicPointer(SDL_Renderer* renderer, int step);
void demoPointerArithmetic(SDL_Renderer* renderer, int step);
void demoPointerArray(SDL_Renderer* renderer, int step);
void demoPointerStruct(SDL_Renderer* renderer, int step);
void demoDoublePointer(SDL_Renderer* renderer, int step);

// Funções de controle
void nextDemoStep(DemoState* state);
void previousDemoStep(DemoState* state);
void switchDemo(DemoState* state, DemoType newDemo);

#endif // POINTER_DEMO_H
