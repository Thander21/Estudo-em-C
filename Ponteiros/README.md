# Estudo de Ponteiros em C com Visualização Gráfica

Este projeto é uma ferramenta didática para aprender e visualizar o funcionamento de ponteiros em C.

## Funcionalidades

- Visualização gráfica de ponteiros e seus endereços de memória
- Demonstração de diferentes tipos de ponteiros
- Exemplos interativos de manipulação de memória
- Interface gráfica simples para melhor compreensão

## Estrutura do Projeto

projeto/
├── lib/           # Bibliotecas (SDL3.dll)
├── main.c         # Arquivo principal do programa
├── graphics.h/c   # Funções para renderização gráfica
├── pointer_demo.h/c # Implementações das demonstrações de ponteiros
└── README.md      # Este arquivo

## Requisitos

- Compilador C (GCC/MinGW recomendado)
- SDL3 (incluído na pasta lib/)

## Configuração

1. Certifique-se de ter o MinGW instalado e configurado no PATH
2. Copie o arquivo SDL3.dll para a pasta `lib/` do projeto
3. Configure o compilador para incluir os headers do SDL3

## Como Compilar

```powershell
gcc -o pointer_study main.c -I./include -L./lib -lSDL3
```

## Como Executar

```powershell
./pointer_study
