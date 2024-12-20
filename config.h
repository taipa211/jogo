#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
    int num_jogadores;
    char jogadores[4][20];
} Config;

Config carregar_configuracao(const char *arquivo);
void configurar_jogadores(Config *configuracao);

#endif