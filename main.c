#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Config
typedef struct {
    int num_jogadores;
    char nomes_jogadores[4][50]; // Máximo de 4 jogadores
} Config;

// Protótipos das funções
Config carregar_configuracao(const char *ficheiro);
void iniciar_jogo(Config *configuracao);
void carregar_historico();
void exibir_historico_texto(const char *ficheiro);
void configurar_jogadores(Config *configuracao);
void mostrar_menu();

// Função principal
int main() {
    int opcao;
    Config configuracao = carregar_configuracao("config_whot.txt");

    do {
        mostrar_menu();
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida! Por favor, insira um número.\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }

        switch (opcao) {
            case 1:
                iniciar_jogo(&configuracao);
                break;
            case 2:
                carregar_historico();
                break;
            case 3:
                exibir_historico_texto("historico_jogos.txt");
                break;
            case 4:
                configurar_jogadores(&configuracao);
                break;
            case 5:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

// Implementação das funções
void mostrar_menu() {
    printf("\n=== Jogo Whot! ===\n");
    printf("1. Iniciar Novo Jogo\n");
    printf("2. Carregar Jogo Salvo\n");
    printf("3. Exibir Histórico de Jogos\n");
    printf("4. Configurar Jogadores\n");
    printf("5. Sair\n");
}

// Função para carregar configurações iniciais do jogo
Config carregar_configuracao(const char *ficheiro) {
    Config config;
    FILE *f = fopen(ficheiro, "r");
    if (f == NULL) {
        printf("Não foi possível carregar o ficheiro de configuração. Usando valores padrão.\n");
        config.num_jogadores = 2;
        strcpy(config.nomes_jogadores[0], "Jogador 1");
        strcpy(config.nomes_jogadores[1], "Jogador 2");
    } else {
        fscanf(f, "%d", &config.num_jogadores);
        for (int i = 0; i < config.num_jogadores; i++) {
            fscanf(f, "%49s", config.nomes_jogadores[i]);
        }
        fclose(f);
    }
    return config;
}

// Função para iniciar um novo jogo
void iniciar_jogo(Config *configuracao) {
    printf("\nIniciando um novo jogo com %d jogadores.\n", configuracao->num_jogadores);
    for (int i = 0; i < configuracao->num_jogadores; i++) {
        printf("Jogador %d: %s\n", i + 1, configuracao->nomes_jogadores[i]);
    }
    printf("Jogo iniciado!\n");
}

// Função para carregar o histórico do jogo
void carregar_historico() {
    printf("\nCarregando histórico de jogos...\n");
    // Aqui poderia haver lógica para carregar o estado do jogo salvo.
    printf("Histórico carregado (simulado).\n");
}

// Função para exibir o histórico de jogos a partir de um ficheiro
void exibir_historico_texto(const char *ficheiro) {
    printf("\nExibindo histórico de jogos:\n");
    FILE *f = fopen(ficheiro, "r");
    if (f == NULL) {
        printf("Não foi possível abrir o ficheiro de histórico.\n");
        return;
    }
    char linha[256];
    while (fgets(linha, sizeof(linha), f)) {
        printf("%s", linha);
    }
    fclose(f);
}

// Função para configurar os jogadores
void configurar_jogadores(Config *configuracao) {
    printf("\nConfigurar jogadores:\n");
    printf("Número de jogadores (2-4): ");
    int num;
    if (scanf("%d", &num) != 1 || num < 2 || num > 4) {
        printf("Número inválido! Deve ser entre 2 e 4.\n");
        while (getchar() != '\n'); // Limpa o buffer
        return;
    }
    configuracao->num_jogadores = num;

    for (int i = 0; i < num; i++) {
        printf("Nome do Jogador %d: ", i + 1);
        scanf("%49s", configuracao->nomes_jogadores[i]);
    }
    printf("Configuração concluída!\n");
}
