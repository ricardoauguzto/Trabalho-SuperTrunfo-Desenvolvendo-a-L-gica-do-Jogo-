#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char nomePais[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Função para exibir o menu de atributos
void exibirMenu(int atributoBloqueado) {
    printf("\nEscolha um atributo para comparar:\n");
    if (atributoBloqueado != 1) printf("1 - Populacao\n");
    if (atributoBloqueado != 2) printf("2 - Area\n");
    if (atributoBloqueado != 3) printf("3 - PIB\n");
    if (atributoBloqueado != 4) printf("4 - Numero de pontos turisticos\n");
    if (atributoBloqueado != 5) printf("5 - Densidade demografica\n");
    printf("Sua escolha: ");
}

// Função para calcular o valor comparável de um atributo
float obterValorAtributo(struct Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.pontosTuristicos;
        case 5: return carta.densidadeDemografica;
        default: return 0;
    }
}

// Função para exibir o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Demografica";
        default: return "Desconhecido";
    }
}

int main() {
    struct Carta carta1 = {"Brasil", 214000000, 8515767.0, 22440.0, 50, 214000000 / 8515767.0};
    struct Carta carta2 = {"Japao", 125000000, 377975.0, 49370.0, 40, 125000000 / 377975.0};

    int atributo1, atributo2;

    printf("=== SUPER TRUNFO - NIVEL MESTRE ===\n");
    printf("\nCartas em jogo:\n");
    printf("1️⃣  %s\n2️⃣  %s\n", carta1.nomePais, carta2.nomePais);

    // Escolha do primeiro atributo
    do {
        exibirMenu(0);
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5)
            printf("Opcao invalida! Escolha novamente.\n");
    } while (atributo1 < 1 || atributo1 > 5);

    // Escolha do segundo atributo (diferente do primeiro)
    do {
        exibirMenu(atributo1);
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 5)
            printf("Opcao invalida! Escolha novamente.\n");
        else if (atributo2 == atributo1)
            printf("Voce ja escolheu esse atributo! Escolha outro.\n");
    } while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1);

    // Obter valores dos atributos para ambas as cartas
    float valor1A1 = obterValorAtributo(carta1, atributo1);
    float valor2A1 = obterValorAtributo(carta2, atributo1);
    float valor1A2 = obterValorAtributo(carta1, atributo2);
    float valor2A2 = obterValorAtributo(carta2, atributo2);

    // Comparação individual com regra especial para Densidade
    int resultado1 = (atributo1 == 5) ? (valor1A1 < valor2A1) : (valor1A1 > valor2A1);
    int resultado2 = (atributo2 == 5) ? (valor1A2 < valor2A2) : (valor1A2 > valor2A2);

    // Soma dos atributos (ajustando densidade para inverter lógica)
    float somaCarta1 = (atributo1 == 5 ? -valor1A1 : valor1A1) +
                       (atributo2 == 5 ? -valor1A2 : valor1A2);
    float somaCarta2 = (atributo1 == 5 ? -valor2A1 : valor2A1) +
                       (atributo2 == 5 ? -valor2A2 : valor2A2);

    printf("\n=== RESULTADO DA COMPARACAO ===\n");
    printf("%s vs %s\n\n", carta1.nomePais, carta2.nomePais);

    printf("Atributo 1: %s\n", nomeAtributo(atributo1));
    printf(" - %s: %.2f\n - %s: %.2f\n", carta1.nomePais, valor1A1, carta2.nomePais, valor2A1);

    printf("\nAtributo 2: %s\n", nomeAtributo(atributo2));
    printf(" - %s: %.2f\n - %s: %.2f\n", carta1.nomePais, valor1A2, carta2.nomePais, valor2A2);

    printf("\nSoma final dos atributos:\n");
    printf(" - %s: %.2f\n", carta1.nomePais, somaCarta1);
    printf(" - %s: %.2f\n", carta2.nomePais, somaCarta2);

    // Determinar vencedor (usando operador ternário e if-else aninhado)
    if (somaCarta1 == somaCarta2) {
        printf("\nResultado: Empate!\n");
    } else {
        const char *vencedor = (somaCarta1 > somaCarta2) ? carta1.nomePais : carta2.nomePais;
        printf("\nResultado: %s venceu a rodada!\n", vencedor);
    }

    return 0;
}
