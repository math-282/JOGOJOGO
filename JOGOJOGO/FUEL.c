#include "raylib.h"
#include "fuel.h"
#include "jogo.h"   // contém SCREEN_HEIGHT, HUD_HEIGHT, MAXFUEL, etc.

// Lista global de postos de combustível
FuelBox fuel_list[MAXFUEL] = {0};

int fuel_loss = 10;   // PERDA
int fuel_gain = 30;   // GANHO

// CARREGA AS SPRITES
void Fuel_LoadSprite() {

    // MUDAAR PARA O NOME DO AQUIVO DO FUEL DA NOSSA PASTA
    Texture2D tex = LoadTexture("images/fuel.png");

    for (int i = 0; i < MAXFUEL; i++) {
        fuel_list[i].texture = tex;
    }
}

// SPAWNA POSTO DE COMBUSTIVEL NA POSIÇAO INDICADA
void Fuel_Spawn(int x, int y) {

    for (int i = 0; i < MAXFUEL; i++) {

        FuelBox *f = &fuel_list[i];

        if (!f->active) {

            f->active   = true;
            f->addsFuel = true;

            f->x = x;
            f->y = y;

            // DIMENSOES
            f->box = (Rectangle){
                (float)x,
                (float)y,
                (float)f->texture.width,
                (float)f->texture.height
            };

            f->timer = 0.0f; // temporizador caso vocês usem depois

            break;
        }
    }
}

// DESENHA OS COMBUSTIVEIS ATIVOS
void Fuel_Draw() {

    for (int i = 0; i < MAXFUEL; i++) {

        if (!fuel_list[i].active)
            continue;

        FuelBox *f = &fuel_list[i];

        Vector2 pos = { (float)f->x, (float)f->y };

        DrawTextureEx(f->texture, pos, 0.0f, 1.0f, WHITE);
    }
}

// DETECTA A COLETA DE COMBUSTIVEL PELO PLAYER
void Fuel_Update(PLAYER *player, float previous_y) { // MUDAR PLAYER PARA O NOME ESCOLHIDO NO NOSSO(N SEI)

    // CONSUMO AUTOMATICO DE COMBUSTIVEL DURANTE O JOGO
    // HUD E SCREEN TAMANHOS HUD E TELA
    if (player->posy > HUD_HEIGHT && player->posy < SCREEN_HEIGHT) {

        float deslocamento = previous_y - player->posy;
        float divisor = (SCREEN_HEIGHT - HUD_HEIGHT) / fuel_loss;

        if (divisor != 0) {
            player->fuel_quantity -= (deslocamento / divisor);
        }
    }

    // Verifica colisões com postos
    for (int i = 0; i < MAXFUEL; i++) {

        FuelBox *f = &fuel_list[i];

        if (!f->active || !f->addsFuel)
            continue;

        if (CheckCollisionRecs(f->box, player->hitbox)) {

            // SHIFT ativa o abastecimento
            if (IsKeyPressed(KEY_LEFT_SHIFT)) {

                int novo = player->fuel_quantity + fuel_gain;

                if (novo > 100)
                    novo = 100;

                player->fuel_quantity = novo;

                f->addsFuel = false;
            }
        }
    }
}
