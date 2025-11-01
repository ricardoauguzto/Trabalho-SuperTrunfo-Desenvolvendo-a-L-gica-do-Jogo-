#include <stdio.h>

// Estrutura que representa uma carta
struct Carta {
    char nomePais[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

int main() {
    struct Carta carta1, carta2;

    // Preenchendo cartas (exemplo)
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Nome do Pais: ");
    scanf(" %[^\n]", carta1.nomePais);
    printf("Populacao: ");
    scanf("%d", &carta1.populacao);
    printf("Area (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (bilhoes): ");
    scanf("%f", &carta1.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    carta1.densidadeDemografica = carta1.populacao / carta1.area;

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Nome do Pais: ");
    scanf(" %[^\n]", carta2.nomePais);
    printf("Populacao: ");
    scanf("%d", &carta2.populacao);
    printf("Area (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (bilhoes): ");
    scanf("%f", &carta2.pib);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    // Menu interativo
    int escolha;
    printf("\n=== Menu de Atributos ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de pontos turisticos\n");
    printf("5 - Densidade demografica\n");
    printf("Escolha o atributo para comparar: ");
    scanf("%d", &escolha);

    printf("\n=== Resultado da Comparacao ===\n");

    switch (escolha) {
        case 1: // População
            printf("Atributo: Populacao\n");
            printf("%s: %d\n", carta1.nomePais, carta1.populacao);
            printf("%s: %d\n", carta2.nomePais, carta2.populacao);

            if (carta1.populacao > carta2.populacao)
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            else if (carta2.populacao > carta1.populacao)
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 2: // Área
            printf("Atributo: Area\n");
            printf("%s: %.2f km²\n", carta1.nomePais, carta1.area);
            printf("%s: %.2f km²\n", carta2.nomePais, carta2.area);

            if (carta1.area > carta2.area)
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            else if (carta2.area > carta1.area)
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhoes\n", carta1.nomePais, carta1.pib);
            printf("%s: %.2f bilhoes\n", carta2.nomePais, carta2.pib);

            if (carta1.pib > carta2.pib)
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            else if (carta2.pib > carta1.pib)
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("Atributo: Numero de pontos turisticos\n");
            printf("%s: %d\n", carta1.nomePais, carta1.pontosTuristicos);
            printf("%s: %d\n", carta2.nomePais, carta2.pontosTuristicos);

            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            else if (carta2.pontosTuristicos > carta1.pontosTuristicos)
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 5: // Densidade Demográfica
            printf("Atributo: Densidade demografica\n");
            printf("%s: %.2f hab/km²\n", carta1.nomePais, carta1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", carta2.nomePais, carta2.densidadeDemografica);

            // Aqui vence quem tiver MENOR densidade
            if (carta1.densidadeDemografica < carta2.densidadeDemografica)
                printf("Resultado: %s venceu!\n", carta1.nomePais);
            else if (carta2.densidadeDemografica < carta1.densidadeDemografica)
                printf("Resultado: %s venceu!\n", carta2.nomePais);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
            break;
    }

    return 0;
}
