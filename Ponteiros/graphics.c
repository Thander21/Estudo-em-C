/************************************************************
* @fileoverview Implementação das funções gráficas
* @module graphics
* @path c:/Users/Rahman/Documents/_Projetos/Cteste/graphics.c
* @requires 
* - SDL3/SDL.h
* - graphics.h
* @description
* Implementação das funções definidas em graphics.h para
* renderização de elementos gráficos na tela
**************************************************************/

#include "graphics.h"
#include <SDL3/SDL.h>
#include <stdio.h>
#include <math.h>

// Converte cor hexadecimal para SDL_Color
SDL_Color hexToSDLColor(uint32_t hex) {
    SDL_Color color;
    color.r = (hex >> 24) & 0xFF;
    color.g = (hex >> 16) & 0xFF;
    color.b = (hex >> 8) & 0xFF;
    color.a = hex & 0xFF;
    return color;
}

// Limpa a tela com uma cor específica
void clearScreen(SDL_Renderer* renderer, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}

// Desenha um retângulo preenchido
void drawRectangle(SDL_Renderer* renderer, Rectangle rect, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_FRect sdlRect = {rect.x, rect.y, rect.width, rect.height};
    SDL_RenderFillRect(renderer, &sdlRect);
}

// Desenha uma seta entre dois pontos
void drawArrow(SDL_Renderer* renderer, int startX, int startY, int endX, int endY, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    
    // Desenha a linha principal
    SDL_RenderLine(renderer, startX, startY, endX, endY);
    
    // Calcula o ângulo da seta
    double angle = atan2(endY - startY, endX - startX);
    
    // Desenha as pontas da seta
    int arrowLength = 15;
    double arrowAngle = M_PI / 6; // 30 graus
    
    int x1 = endX - arrowLength * cos(angle + arrowAngle);
    int y1 = endY - arrowLength * sin(angle + arrowAngle);
    int x2 = endX - arrowLength * cos(angle - arrowAngle);
    int y2 = endY - arrowLength * sin(angle - arrowAngle);
    
    SDL_RenderLine(renderer, endX, endY, x1, y1);
    SDL_RenderLine(renderer, endX, endY, x2, y2);
}

// Desenha texto na tela
void drawText(SDL_Renderer* renderer, const char* text, int x, int y, SDL_Color color) {
    // Por enquanto, apenas um placeholder
    // Será implementado quando adicionarmos suporte a SDL_ttf
    (void)renderer;
    (void)text;
    (void)x;
    (void)y;
    (void)color;
}

// Desenha uma caixa de memória com rótulo e valor
void drawMemoryBox(SDL_Renderer* renderer, Rectangle rect, const char* label, const char* value, SDL_Color color) {
    // Desenha o retângulo principal
    drawRectangle(renderer, rect, color);
    
    // Desenha uma borda mais escura
    SDL_Color borderColor = {
        color.r * 0.8,
        color.g * 0.8,
        color.b * 0.8,
        color.a
    };
    
    SDL_SetRenderDrawColor(renderer, borderColor.r, borderColor.g, borderColor.b, borderColor.a);
    SDL_FRect sdlRect = {rect.x, rect.y, rect.width, rect.height};
    SDL_RenderRect(renderer, &sdlRect);
    
    // Desenha o rótulo e o valor
    // Será implementado quando adicionarmos suporte a SDL_ttf
    (void)label;
    (void)value;
}

// Desenha uma conexão entre duas caixas (para ponteiros)
void drawPointerConnection(SDL_Renderer* renderer, Rectangle from, Rectangle to, SDL_Color color) {
    int startX = from.x + from.width;
    int startY = from.y + from.height / 2;
    int endX = to.x;
    int endY = to.y + to.height / 2;
    
    drawArrow(renderer, startX, startY, endX, endY, color);
}
