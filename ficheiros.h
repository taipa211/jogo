#ifndef FICHEIROS_H
#define FICHEIROS_H
#include "jogo.h"

void salvar_historico_binario(const char *arquivo, const Jogo *jogo);
void carregar_historico_binario(const char *arquivo);
void salvar_historico_texto(const char *arquivo, const Jogo *jogo);
void exibir_historico_texto(const char *arquivo);

#endif