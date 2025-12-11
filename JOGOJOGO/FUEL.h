#ifndef FUEL
#define FUEL

#include "raylib.h"
#include "player.h"

// ALTURA DO MAPA
#define ALTURA_MAPA   (SCREEN_HEIGHT - HUD_HEIGHT)

// QUANTIDADE DE COMBUSTIVEL GANHO
extern int fuel_loss;
extern int fuel_gain;

// Estrutura para objetos de combustível
typedef struct {
    int x, y;              // posição no mapa
    float timer;           // tempo até desaparecer
    bool active;           // está visível/valendo?
    bool addsFuel;         // adiciona ou reduz fuel?

    Rectangle box;         // hitBOX
    Texture2D texture;     // SPRITE
} FuelBox;

// Inicializa o sprite
void Fuel_LoadSprite();

// Cria um novo item de combustível
void Fuel_Spawn(int x, int y);

// Desenha os itens de combustível ativos
void Fuel_Draw();

//checar colisão, mover, etc
void Fuel_Update(PLAYER *player, float previous_y);

#endif // FUEL_H_INCLUDED
