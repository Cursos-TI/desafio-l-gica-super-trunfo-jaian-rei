

// Desafio Super Trunfo - Países
 




    #include <stdio.h>
    #include <string.h>
    
    typedef struct {
        char codigo[10];
        char nome[100];
        char estado[3];
        int populacao;
        float area;
        float pib;
        int pontos_turisticos;
    } CartaCidade;
    
    // Função para calcular a densidade populacional
    float densidade_populacional(CartaCidade carta) {
        return carta.populacao / carta.area;
    }
    
    // Função para exibir as informações de uma cidade
    void exibir_informacoes(CartaCidade carta) {
        printf("\nInformações da cidade:\n");
        printf("Código: %s\n", carta.codigo);
        printf("Nome: %s\n", carta.nome);
        printf("Estado: %s\n", carta.estado);
        printf("População: %d\n", carta.populacao);
        printf("Área: %.2f km²\n", carta.area);
        printf("PIB: R$ %.2f\n", carta.pib);
        printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
        printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional(carta));
    }
    
    // Função para comparar duas cartas com base no critério
    CartaCidade comparar_cartas(CartaCidade carta1, CartaCidade carta2, const char* criterio) {
        if (strcmp(criterio, "densidade_populacional") == 0) {
            if (densidade_populacional(carta1) < densidade_populacional(carta2)) {
                return carta1;
            } else if (densidade_populacional(carta1) > densidade_populacional(carta2)) {
                return carta2;
            } else {
                CartaCidade empate = {"", "", "", 0, 0.0, 0.0, 0};
                return empate; // Empate
            }
        } else {
            float valor1 = 0, valor2 = 0;
    
            if (strcmp(criterio, "populacao") == 0) {
                valor1 = carta1.populacao;
                valor2 = carta2.populacao;
            } else if (strcmp(criterio, "area") == 0) {
                valor1 = carta1.area;
                valor2 = carta2.area;
            } else if (strcmp(criterio, "pib") == 0) {
                valor1 = carta1.pib;
                valor2 = carta2.pib;
            }
    
            if (valor1 > valor2) {
                return carta1;
            } else if (valor1 < valor2) {
                return carta2;
            } else {
                CartaCidade empate = {"", "", "", 0, 0.0, 0.0, 0};
                return empate; // Empate
            }
        }
    }
    
    // Função para cadastrar uma carta
    CartaCidade cadastro_carta() {
        CartaCidade carta;
    
        printf("\nDigite o código da carta: ");
        scanf("%s", carta.codigo);
        printf("Digite o nome da cidade: ");
        scanf(" %[^\n]s", carta.nome); // Lê o nome da cidade incluindo espaços
        printf("Digite o estado da cidade (2 letras): ");
        scanf("%s", carta.estado);
        printf("Digite a população da cidade: ");
        scanf("%d", &carta.populacao);
        printf("Digite a área da cidade em km²: ");
        scanf("%f", &carta.area);
        printf("Digite o PIB da cidade (em R$): ");
        scanf("%f", &carta.pib);
        printf("Digite o número de pontos turísticos: ");
        scanf("%d", &carta.pontos_turisticos);
    
        return carta;
    }
    
    int main() {
        printf("Cadastro da primeira carta de cidade:\n");
        CartaCidade carta1 = cadastro_carta();
    
        printf("\nCadastro da segunda carta de cidade:\n");
        CartaCidade carta2 = cadastro_carta();
    
        char criterio[20];
        printf("\nEscolha o critério para comparação (populacao, area, pib, densidade_populacional): ");
        scanf("%s", criterio);
    
        CartaCidade vencedor = comparar_cartas(carta1, carta2, criterio);
    
        if (strlen(vencedor.codigo) == 0) {
            printf("\nEmpate! Nenhuma cidade venceu.\n");
        } else {
            printf("\nResultado da comparação:\n");
            printf("A cidade vencedora é: %s\n", vencedor.nome);
            exibir_informacoes(vencedor);
        }
    
        return 0;
    }
    