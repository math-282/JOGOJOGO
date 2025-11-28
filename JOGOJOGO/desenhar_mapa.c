#include "jogo.h"
#include "stdio.h"
#include "raylib.h"
BLOCO mapa[MAX_MAPA];
void carregar_mapa()
{
    int total_blocos = 0;
    int x = 0, y = 0, i = 0;
    char c;
    FILE *mapa1 = fopen("mapas/mapa1.txt", "r");

    if (mapa1 != NULL)
    {
        while((c = fgetc(mapa1))!=EOF)
        {
            if (c == ' ' || c == '\r') continue;
            switch(c)
            {
            case 'T':
                mapa[i].hitbox = (Rectangle)
                {
                    x, y, 40, 40
                };
                mapa[i].tipo = 'T';
                mapa[i].vivo = 1;
                break;
            case 'A':
                mapa[i].hitbox = (Rectangle)
                {
                    x, y, 40, 40
                };
                mapa[i].tipo = 'A';
                mapa[i].vivo = 1;
                break;
            case 'N':
                mapa[i].hitbox = (Rectangle)
                {
                    x, y, 40, 40
                };
                mapa[i].tipo = 'N';
                mapa[i].vivo = 1;
                break;
            case 'X':
                mapa[i].hitbox = (Rectangle)
                {
                    x, y, 40, 40
                };
                mapa[i].tipo = 'X';
                mapa[i].vivo = 1;
                break;
            case 'G':
                mapa[i].hitbox = (Rectangle)
                {
                    x, y, 40, 40
                };
                mapa[i].tipo = 'G';
                mapa[i].vivo = 1;
                break;
            case 'P':
                mapa[i].hitbox = (Rectangle)
                {
                    x, y, 40, 40
                };
                mapa[i].tipo = 'P';
                mapa[i].vivo = 1;
                break;
            case '\n':
                x = 0;
                y+= 40;
            default:
                mapa[i].hitbox = (Rectangle)
                {
                    x, y, 40, 40
                };
                mapa[i].tipo = 'V';
                mapa[i].vivo = 1;
                break;

            }
            i++;
            if (c != '\n') x+=40;
        }
    }
    total_blocos = i; // ⬅️ Armazena o total lido
printf("Total de blocos lidos: %d\n", total_blocos);
    fclose(mapa1);
}

void desenhar_mapa()
{
    // Este loop deve iterar sobre a matriz JÁ CARREGADA
    for (int i = 0; i < MAX_MAPA; i++)
    {
        Color cor = WHITE; // Define a cor inicial

        // Lógica de cor baseada no tipo (T, A, N, etc.)
        switch (mapa[i].tipo)
        {
        case 'T':
            cor = GREEN;
            break;
        case 'N':
            cor = GRAY;
            break;
        case 'A':
            cor = DARKBLUE;
            break;
        case 'X':
            cor = BLACK;
            break;
        case 'G':
            cor = RED;
            break;
        case 'P':
            cor = BROWN;
            break;
        case 'V':
            cor = DARKBLUE;
        }

        // Verifica se o bloco está vivo antes de desenhar
        if (mapa[i].vivo)
        {
            DrawRectangleRec(mapa[i].hitbox, cor);
        }
    }
}

