#ifndef JOGADOR_H
#define JOGADOR_H

typedef struct {
    char username[20];
    char nome[50];
    int cartas_na_mao[10];
    int num_cartas;
    int pontos;
} Jogador;

#endif