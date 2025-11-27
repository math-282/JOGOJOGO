#include "jogo.h"
#include "stdio.h"
#include "raylib.h"

void iniciar_jogo(){
    //largura e altura da tela
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "River Raid");
    SetTargetFPS(60);// Ajusta a janela para 60 frames por segundo

    Vector2 posicao_nave = { (float)screenWidth/2, (float)screenHeight/2 };
    //Este laco repete enquanto a janela nao for fechada
    //Utilizamos ele para atualizar o estado do programa / jogo
    while (!WindowShouldClose())
    {
	// Trata entrada do usuario e atualiza estado do jogo
	if (IsKeyDown(KEY_RIGHT)) posicao_nave.x += 2;
	if (IsKeyDown(KEY_LEFT)) posicao_nave.x -= 2;
	if (IsKeyDown(KEY_UP)) posicao_nave.y -= 2;
	if (IsKeyDown(KEY_DOWN)) posicao_nave.y += 2;

	// Atualiza o que eh mostrado na tela a partir do estado do jogo
	BeginDrawing(); //Inicia o ambiente de desenho na tela

	ClearBackground(RAYWHITE); //Limpa a tela e define cor de fundo

    DrawCircleV(posicao_nave, 30, RED);

	EndDrawing(); //Finaliza o ambiente de desenho na tela
    }


}
