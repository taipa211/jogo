#ifndef JOGO_H
#define JOGO_H

#include "jogador.h"
#include "config.h"

typedef struct {
    int id;
    int baralho[54];
    int draw_pile[54];
    int call_card;
    int cartas_jogadas[54];
    int num_cartas_jogadas;
    Jogador jogadores[4];
    int num_jogadores;
    int jogador_atual;
} Jogo;

void iniciar_jogo(Config *configuracao);
void embaralhar(int *baralho, int tamanho);
void distribuir_cartas(Jogo *jogo);
int carta_valida(int call_card, int carta_escolhida);
void realizar_jogada(Jogo *jogo);

#endif