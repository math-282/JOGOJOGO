#ifndef JOGO_H
#define JOGO_H
#define LARGURA 800
#define ALTURA 450

typedef struct {
int posx;
int posy;
int largura;
int altura;
const char *texto;
};

void iniciar_jogo();
int menu();

#endif
