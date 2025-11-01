#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[2];
    char codigo[4];
    char nomeCidade[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

int main() {
    struct Carta carta1, carta2;

    // Cadastro da primeira carta
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado: ");
    scanf(" %1s", carta1.estado);

    printf("Codigo: ");
    scanf(" %3s", carta1.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);

    printf("Populacao: ");
    scanf("%d", &carta1.populacao);

    printf("Area (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Cálculos automáticos
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao; // convertendo PIB p/ reais


    // Cadastro da segunda carta
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado: ");
    scanf(" %1s", carta2.estado);

    printf("Codigo: ");
    scanf(" %3s", carta2.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);

    printf("Populacao: ");
    scanf("%d", &carta2.populacao);

    printf("Area (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculos automáticos
    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao; // convertendo PIB p/ reais


    // ===========================
    // 🔍 Escolha do atributo a comparar
    // ===========================
    // Altere aqui o atributo que será comparado:
    // 1 = População
    // 2 = Área
    // 3 = PIB
    // 4 = Densidade Populacional
    // 5 = PIB per Capita

    int atributo = 1; // <<--- MUDE AQUI para comparar outro atributo

    printf("\n=== Comparacao de Cartas ===\n");

    if (atributo == 1) {
        printf("Atributo: Populacao\n");
        printf("%s (%s): %d\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
        printf("%s (%s): %d\n", carta2.nomeCidade, carta2.estado, carta2.populacao);

        if (carta1.populacao > carta2.populacao)
            printf("Resultado: %s venceu!\n", carta1.nomeCidade);
        else if (carta2.populacao > carta1.populacao)
            printf("Resultado: %s venceu!\n", carta2.nomeCidade);
        else
            printf("Empate!\n");

    } else if (atributo == 2) {
        printf("Atributo: Area\n");
        printf("%s: %.2f km²\n", carta1.nomeCidade, carta1.area);
        printf("%s: %.2f km²\n", carta2.nomeCidade, carta2.area);

        if (carta1.area > carta2.area)
            printf("Resultado: %s venceu!\n", carta1.nomeCidade);
        else if (carta2.area > carta1.area)
            printf("Resultado: %s venceu!\n", carta2.nomeCidade);
        else
            printf("Empate!\n");

    } else if (atributo == 3) {
        printf("Atributo: PIB\n");
        printf("%s: %.2f bilhões\n", carta1.nomeCidade, carta1.pib);
        printf("%s: %.2f bilhões\n", carta2.nomeCidade, carta2.pib);

        if (carta1.pib > carta2.pib)
            printf("Resultado: %s venceu!\n", carta1.nomeCidade);
        else if (carta2.pib > carta1.pib)
            printf("Resultado: %s venceu!\n", carta2.nomeCidade);
        else
            printf("Empate!\n");

    } else if (atributo == 4) {
        printf("Atributo: Densidade Populacional\n");
        printf("%s: %.2f hab/km²\n", carta1.nomeCidade, carta1.densidadePopulacional);
        printf("%s: %.2f hab/km²\n", carta2.nomeCidade, carta2.densidadePopulacional);

        // Nesse caso, vence quem tiver MENOR valor
        if (carta1.densidadePopulacional < carta2.densidadePopulacional)
            printf("Resultado: %s venceu!\n", carta1.nomeCidade);
        else if (carta2.densidadePopulacional < carta1.densidadePopulacional)
            printf("Resultado: %s venceu!\n", carta2.nomeCidade);
        else
            printf("Empate!\n");

    } else if (atributo == 5) {
        printf("Atributo: PIB per Capita\n");
        printf("%s: R$ %.2f\n", carta1.nomeCidade, carta1.pibPerCapita);
        printf("%s: R$ %.2f\n", carta2.nomeCidade, carta2.pibPerCapita);

        if (carta1.pibPerCapita > carta2.pibPerCapita)
            printf("Resultado: %s venceu!\n", carta1.nomeCidade);
        else if (carta2.pibPerCapita > carta1.pibPerCapita)
            printf("Resultado: %s venceu!\n", carta2.nomeCidade);
        else
            printf("Empate!\n");
    }

    return 0;
}
