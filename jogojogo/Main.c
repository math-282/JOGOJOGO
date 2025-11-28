#include "jogo.h"
#include "io.h"
#include "raylib.h"
#include <string.h>
#include <stdlib.h>
int main()
{
    InitWindow(LARGURA, ALTURA, "Menu"); //Inicializa janela, com certo tamanho e titulo
    SetTargetFPS(60);// Ajusta a janela para 60 frames por segundo

    int op = menu();

    switch(op)
    {
    case 1:
        iniciar_jogo();
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:
        CloseWindow();
        break;
    }

    CloseWindow(); // Fecha a janela
    return 0;
}
