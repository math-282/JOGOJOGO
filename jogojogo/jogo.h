#ifndef JOGO_H
#define JOGO_H
#define LARGURA 960
#define ALTURA 800
#define MAX_MAPA 600
#include <raylib.h>



typedef struct {
    char tipo;
    int vivo;
    Rectangle hitbox;
}BLOCO;

extern BLOCO mapa[MAX_MAPA];


void iniciar_jogo();
int menu();
void desenhar_mapa();
void carregar_mapa();

#endif
