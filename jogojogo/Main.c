#include "jogo.h"
#include "io.h"
#include "raylib.h"
#include <string.h>
#include <stdlib.h>

int main(){
    InitWindow(LARGURA, ALTURA, "Teclas"); //Inicializa janela, com certo tamanho e titulo
    SetTargetFPS(60);// Ajusta a janela para 60 frames por segundo

    int op = menu();

    switch(op){
    case 1:
        iniciar_jogo();
    case 2:


    default:
    CloseWindow();
    }

    CloseWindow(); // Fecha a janela
    return 0;
}
