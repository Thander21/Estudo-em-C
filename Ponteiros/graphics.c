/************************************************************
* @fileoverview Implementação das funções de renderização gráfica
* @module graphics
* @path c:/Users/Rahman/Documents/_Projetos/Estudo em C/Ponteiros/graphics.c
* @requires 
* - SDL3/SDL.h
* - graphics.h
* @description
* Este arquivo implementa as funções necessárias para renderizar
* elementos gráficos na tela, incluindo textos, retângulos,
* setas e outros elementos visuais para demonstração de ponteiros
**************************************************************/

#include <SDL3/SDL.h>
#include "graphics.h"
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

// Desenha um retângulo
void drawRectangle(SDL_Renderer* renderer, Rectangle rect, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_FRect sdlRect = {
        .x = (float)rect.x,
        .y = (float)rect.y,
        .w = (float)rect.width,
        .h = (float)rect.height
    };
    SDL_RenderFillRect(renderer, &sdlRect);
}

// Desenha uma seta
void drawArrow(SDL_Renderer* renderer, int startX, int startY, int endX, int endY, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    
    // Desenha a linha principal
    SDL_RenderLine(renderer, startX, startY, endX, endY);
    
    // Calcula o ângulo da seta
    float angle = atan2(endY - startY, endX - startX);
    
    // Comprimento e ângulo das pontas da seta
    int arrowLength = 20;
    float arrowAngle = 0.5; // ~30 graus
    
    // Desenha as pontas da seta
    SDL_RenderLine(renderer, endX, endY,
                  endX - arrowLength * cos(angle + arrowAngle),
                  endY - arrowLength * sin(angle + arrowAngle));
                  
    SDL_RenderLine(renderer, endX, endY,
                  endX - arrowLength * cos(angle - arrowAngle),
                  endY - arrowLength * sin(angle - arrowAngle));
}

// Desenha texto
void drawText(SDL_Renderer* renderer, const char* text, int x, int y, SDL_Color color) {
    // Como SDL3 não inclui renderização de texto por padrão,
    // vamos desenhar um retângulo simples para representar o texto
    // Em uma implementação real, você usaria SDL_ttf
    Rectangle textRect = {x, y, 100, 20};
    drawRectangle(renderer, textRect, color);
}

// Desenha uma caixa de memória com rótulo e valor
void drawMemoryBox(SDL_Renderer* renderer, Rectangle rect, const char* label, const char* value, SDL_Color color) {
    // Desenha o retângulo principal
    drawRectangle(renderer, rect, color);
    
    // Desenha o rótulo acima do retângulo
    SDL_Color textColor = hexToSDLColor(COLOR_TEXT);
    drawText(renderer, label, rect.x, rect.y - 25, textColor);
    
    // Desenha o valor dentro do retângulo
    drawText(renderer, value, rect.x + 5, rect.y + 5, textColor);
}

// Desenha uma conexão entre duas caixas de memória
void drawPointerConnection(SDL_Renderer* renderer, Rectangle from, Rectangle to, SDL_Color color) {
    // Calcula os pontos de início e fim da seta
    int startX = from.x + from.width;
    int startY = from.y + from.height / 2;
    int endX = to.x;
    int endY = to.y + to.height / 2;
    
    // Desenha a seta
    drawArrow(renderer, startX, startY, endX, endY, color);
}
