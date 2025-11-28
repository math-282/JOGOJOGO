#include "jogo.h"
#include "stdio.h"
#include "raylib.h"

void iniciar_jogo() {
    // 1. CARREGAMENTO (Executado apenas 1 vez, fora do loop)
    carregar_mapa();
    Vector2 posicao_nave;
    // Inicializa a nave
    for(int i = 0; i < MAX_MAPA;i++){
        if(mapa[i].tipo == 'A') posicao_nave = (Vector2){mapa[i].hitbox.x, mapa[i].hitbox.y};
    }
    // Otimização: Apenas a nave e o mapa precisam ser desenhados no loop

    // LOOP PRINCIPAL DO JOGO
    while (!WindowShouldClose()) {

        // --- 1. ATUALIZAÇÃO (Lógica do Jogo) ---
        // Trata entrada do usuario e atualiza estado do jogo
        if (IsKeyDown(KEY_RIGHT)) posicao_nave.x += 2;
        if (IsKeyDown(KEY_LEFT))  posicao_nave.x -= 2;

        // --- 2. DESENHO ---
        // Atualiza o que eh mostrado na tela a partir do estado do jogo

        BeginDrawing(); // ⬅️ INÍCIO DO FRAME

            // A) Limpa a tela (Redesenha o fundo branco)
            ClearBackground(RAYWHITE);

            // B) Desenha o Mapa (Estático)
            desenhar_mapa();

            // C) Desenha a Nave (Dinâmico)
            DrawCircleV(posicao_nave, 20, YELLOW);

        EndDrawing(); // ⬅️ FIM DO FRAME: O novo quadro é exibido.
    }
}
