#include <stdio.h>

struct Carta {
    char nome[100];
    float area;
    unsigned long int populacao;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
};

int main() {
    struct Carta carta1 = {"Brasil", 8515767.0f, 214300000UL, 2490.0f, 150, 0.0f, 0.0f};
    struct Carta carta2 = {"Canada", 9984670.0f, 38000000UL, 2260.0f, 200, 0.0f, 0.0f};

    /* === Calculos === */
    carta1.densidade = (carta1.area > 0.0f) ? (carta1.populacao / carta1.area) : 0.0f;
    carta2.densidade = (carta2.area > 0.0f) ? (carta2.populacao / carta2.area) : 0.0f;
    carta1.pibPerCapita = (carta1.populacao > 0) ? ((carta1.pib * 1e9f) / (float)carta1.populacao) : 0.0f;
    carta2.pibPerCapita = (carta2.populacao > 0) ? ((carta2.pib * 1e9f) / (float)carta2.populacao) : 0.0f;

    int opcao1 = 0, opcao2 = 0;
    float v1_a = 0.0f, v1_b = 0.0f; // valores do atributo 1 para carta1 e carta2
    float v2_a = 0.0f, v2_b = 0.0f; // valores do atributo 2 para carta1 e carta2

    printf("==== SUPER TRUNFO - NIVEL FINAL ====\n\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    printf("Escolha o primeiro atributo para comparacao:\n");
    printf("1 - Area\n");
    printf("2 - Populacao\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("6 - PIB per Capita\n");
    printf("Opcao: ");
    if (scanf("%d", &opcao1) != 1) {
        printf("Entrada invalida.\n");
        return 0;
    }

    /* Impressao do menu dinamico para o segundo atributo evitando repetir o primeiro */
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    if (opcao1 != 1) printf("1 - Area\n");
    if (opcao1 != 2) printf("2 - Populacao\n");
    if (opcao1 != 3) printf("3 - PIB\n");
    if (opcao1 != 4) printf("4 - Pontos Turisticos\n");
    if (opcao1 != 5) printf("5 - Densidade Demografica\n");
    if (opcao1 != 6) printf("6 - PIB per Capita\n");
    printf("Opcao: ");
    if (scanf("%d", &opcao2) != 1) {
        printf("Entrada invalida.\n");
        return 0;
    }

    if (opcao1 < 1 || opcao1 > 6 || opcao2 < 1 || opcao2 > 6) {
        printf("Opcao invalida! Escolha numeros entre 1 e 6.\n");
        return 0;
    }
    if (opcao1 == opcao2) {
        printf("Voce nao pode escolher o mesmo atributo duas vezes!\n");
        return 0;
    }

    /* === Calculos: obter os valores dos dois atributos para cada carta === */
    switch (opcao1) {
        case 1: v1_a = carta1.area; v1_b = carta2.area; break;
        case 2: v1_a = (float)carta1.populacao; v1_b = (float)carta2.populacao; break;
        case 3: v1_a = carta1.pib; v1_b = carta2.pib; break;
        case 4: v1_a = (float)carta1.pontosTuristicos; v1_b = (float)carta2.pontosTuristicos; break;
        case 5: v1_a = carta1.densidade; v1_b = carta2.densidade; break;
        case 6: v1_a = carta1.pibPerCapita; v1_b = carta2.pibPerCapita; break;
        default: printf("Atributo invalido!\n"); return 0;
    }

    switch (opcao2) {
        case 1: v2_a = carta1.area; v2_b = carta2.area; break;
        case 2: v2_a = (float)carta1.populacao; v2_b = (float)carta2.populacao; break;
        case 3: v2_a = carta1.pib; v2_b = carta2.pib; break;
        case 4: v2_a = (float)carta1.pontosTuristicos; v2_b = (float)carta2.pontosTuristicos; break;
        case 5: v2_a = carta1.densidade; v2_b = carta2.densidade; break;
        case 6: v2_a = carta1.pibPerCapita; v2_b = carta2.pibPerCapita; break;
        default: printf("Atributo invalido!\n"); return 0;
    }

    /* Mostrar detalhes dos atributos escolhidos */
    printf("\n==== RESULTADOS PARCIAIS ====\n");
    // Atributo 1
    printf("Atributo 1 (opcao %d):\n", opcao1);
    printf("%s -> %.2f\n", carta1.nome, v1_a);
    printf("%s -> %.2f\n", carta2.nome, v1_b);
    // Atributo 2
    printf("\nAtributo 2 (opcao %d):\n", opcao2);
    printf("%s -> %.2f\n", carta1.nome, v2_a);
    printf("%s -> %.2f\n", carta2.nome, v2_b);

    /* Comparacoes individuais (mostra vencedor por atributo) */
    printf("\n==== COMPARACOES POR ATRIBUTO ====\n");
    // Atributo 1
    if (opcao1 == 5) { // densidade: menor vence
        if (v1_a < v1_b) printf("Atributo 1: Vencedor -> %s (menor densidade)\n", carta1.nome);
        else if (v1_b < v1_a) printf("Atributo 1: Vencedor -> %s (menor densidade)\n", carta2.nome);
        else printf("Atributo 1: Empate!\n");
    } else { // maior vence
        if (v1_a > v1_b) printf("Atributo 1: Vencedor -> %s\n", carta1.nome);
        else if (v1_b > v1_a) printf("Atributo 1: Vencedor -> %s\n", carta2.nome);
        else printf("Atributo 1: Empate!\n");
    }

    // Atributo 2
    if (opcao2 == 5) { // densidade: menor vence
        if (v2_a < v2_b) printf("Atributo 2: Vencedor -> %s (menor densidade)\n", carta1.nome);
        else if (v2_b < v2_a) printf("Atributo 2: Vencedor -> %s (menor densidade)\n", carta2.nome);
        else printf("Atributo 2: Empate!\n");
    } else { // maior vence
        if (v2_a > v2_b) printf("Atributo 2: Vencedor -> %s\n", carta1.nome);
        else if (v2_b > v2_a) printf("Atributo 2: Vencedor -> %s\n", carta2.nome);
        else printf("Atributo 2: Empate!\n");
    }

    /* === Calculos: soma dos valores dos atributos e decisao final === */
    float somaCarta1 = v1_a + v2_a;
    float somaCarta2 = v1_b + v2_b;

    printf("\n==== SOMA DOS ATRIBUTOS ====\n");
    printf("%s -> Soma: %.2f\n", carta1.nome, somaCarta1);
    printf("%s -> Soma: %.2f\n", carta2.nome, somaCarta2);

    printf("\n==== VENCEDOR FINAL (pela maior soma) ====\n");
    if (somaCarta1 > somaCarta2) printf("A carta vencedora e: %s!\n", carta1.nome);
    else if (somaCarta2 > somaCarta1) printf("A carta vencedora e: %s!\n", carta2.nome);
    else printf("Empate!\n");

    return 0;
}
