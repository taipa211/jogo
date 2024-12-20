#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo.h"

void embaralhar(int *baralho, int tamanho) {
    srand(time(NULL));
    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

void distribuir_cartas(Jogo *jogo) {
    for (int i = 0; i < jogo->num_jogadores; i++) {
        for (int j = 0; j < 6; j++) {
            jogo->jogadores[i].cartas_na_mao[j] = jogo->draw_pile[j];
            jogo->jogadores[i].num_cartas++;
        }
    }
    jogo->call_card = jogo->draw_pile[6];
}

int carta_valida(int call_card, int carta_escolhida) {
    // Implementar lógica para verificar se a carta é válida
    return 1;
}

void realizar_jogada(Jogo *jogo) {
    // Implementar a lógica de uma jogada
}

void iniciar_jogo(Config *configuracao) {
    Jogo jogo;
    jogo.num_jogadores = configuracao->num_jogadores;
    jogo.jogador_atual = 0;

    // Inicializar baralho
    for (int i = 0; i < 54; i++) {
        jogo.baralho[i] = i + 1;
    }

    embaralhar(jogo.baralho, 54);
    distribuir_cartas(&jogo);

    // Lógica do loop do jogo
    while (1) {
        realizar_jogada(&jogo);
        // Verificar condição de vitória
    }
}