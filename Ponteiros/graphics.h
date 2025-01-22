/************************************************************
* @fileoverview Funções para renderização gráfica do programa
* @module graphics
* @path c:/Users/Rahman/Documents/_Projetos/Cteste/graphics.h
* @requires SDL3/SDL.h
* @description
* Este arquivo contém as funções necessárias para renderizar
* elementos gráficos na tela, incluindo textos, retângulos,
* setas e outros elementos visuais para demonstração de ponteiros
**************************************************************/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL3/SDL.h>

// Cores predefinidas
#define COLOR_BACKGROUND    0x282c34FF
#define COLOR_TEXT         0xFFFFFFFF
#define COLOR_POINTER      0x61afefFF
#define COLOR_VARIABLE     0x98c379FF
#define COLOR_HIGHLIGHT    0xe06c75FF
#define COLOR_ARROW        0xc678ddFF

// Estrutura para posição e dimensões
typedef struct {
    int x, y, width, height;
} Rectangle;

// Estrutura para texto
typedef struct {
    const char* text;
    int x, y;
    SDL_Color color;
} TextItem;

// Funções de renderização
void drawRectangle(SDL_Renderer* renderer, Rectangle rect, SDL_Color color);
void drawArrow(SDL_Renderer* renderer, int startX, int startY, int endX, int endY, SDL_Color color);
void drawText(SDL_Renderer* renderer, const char* text, int x, int y, SDL_Color color);
void drawMemoryBox(SDL_Renderer* renderer, Rectangle rect, const char* label, const char* value, SDL_Color color);
void drawPointerConnection(SDL_Renderer* renderer, Rectangle from, Rectangle to, SDL_Color color);

// Funções de utilidade
SDL_Color hexToSDLColor(uint32_t hex);
void clearScreen(SDL_Renderer* renderer, SDL_Color color);

#endif // GRAPHICS_H
