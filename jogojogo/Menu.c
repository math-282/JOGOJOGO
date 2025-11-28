#include "jogo.h"
#include "stdio.h"
#include "raylib.h"

int menu()
{

    int y_inicial = 150;
    int espacamento = 70;

    bool colisao(Vector2 point, Rectangle rec)
    {
        return (point.x >= rec.x && point.x <= rec.x + rec.width &&
                point.y >= rec.y && point.y <= rec.y + rec.height);
    }

    Rectangle rec_jogar = {(LARGURA/2) - 100, y_inicial, 200, 50};
    Rectangle rec_opcoes = {(LARGURA/2) - 100, y_inicial + espacamento, 200, 50};
    Rectangle rec_ranking = {(LARGURA/2) - 100, y_inicial + 2 * espacamento, 200, 50};
    Rectangle rec_sair = {(LARGURA/2) - 100, y_inicial + 3 * espacamento, 200, 50};

    while (!WindowShouldClose())
    {

        Vector2 mouse_pos = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionPointRec(mouse_pos, rec_jogar))
            {
                return 1; //jogar
            }
            else if (CheckCollisionPointRec(mouse_pos, rec_opcoes))
            {
                return 2; //opções
            }
            else if (CheckCollisionPointRec(mouse_pos, rec_ranking))
            {
                return 3;//ranking
            }
            else if (CheckCollisionPointRec(mouse_pos, rec_sair))
            {
                return 4;//sair
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("MENU", (LARGURA/2) - MeasureText("MENU", 40)/2, 50, 40, DARKGRAY);

        Color cor_jogar;
        if(CheckCollisionPointRec(mouse_pos, rec_jogar))cor_jogar = RED;
        else cor_jogar = LIGHTGRAY;
        DrawRectangleRec(rec_jogar, cor_jogar);
        DrawText("JOGAR", rec_jogar.x + 60, rec_jogar.y + 15, 20, BLACK);

        Color cor_opcoes;
        if(CheckCollisionPointRec(mouse_pos, rec_opcoes))cor_opcoes = RED;
        else cor_opcoes = LIGHTGRAY;
        DrawRectangleRec(rec_opcoes, cor_opcoes);
        DrawText("OPCOES", rec_opcoes.x + 50, rec_opcoes.y + 15, 20, BLACK);

        Color cor_ranking;
        if(CheckCollisionPointRec(mouse_pos, rec_ranking))cor_ranking = RED;
        else cor_ranking = LIGHTGRAY;
        DrawRectangleRec(rec_ranking, cor_ranking);
        DrawText("RANKING", rec_ranking.x + 65, rec_ranking.y + 15, 20, BLACK);


        Color cor_sair;
        if(CheckCollisionPointRec(mouse_pos, rec_sair))cor_sair = RED;
        else cor_sair = LIGHTGRAY;
        DrawRectangleRec(rec_sair, cor_sair);
        DrawText("SAIR", rec_sair.x + 65, rec_sair.y + 15, 20, BLACK);

        EndDrawing();
    }

    return 3; //sair (se a janela for fechada
}


