#include <stdio.h>
#include <ctype.h> // Inclua esta biblioteca para usar toupper()

// Definição da estrutura Cidade
typedef struct {
    char estado;
    char cidade[30];
    int numero_da_cidade;
    int pop;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;

// Função para entrada de dados
void entrada_dados(Cidade *c) {
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &c->estado);
    c->estado = toupper(c->estado); // Converte o estado para maiúscula
    printf("Digite o nome da Cidade: ");
    scanf(" %s", c->cidade);
    printf("Digite o código da carta: (1-4): ");
    scanf("%d", &c->numero_da_cidade);
    printf("Digite a População: ");
    scanf("%d", &c->pop); 
    printf("Digite a Área: km²: ");
    scanf("%f", &c->area);
    printf("Digite o PIB: ");
    scanf("%f", &c->pib);
    printf("Digite o Número de pontos turísticos: ");
    scanf("%d", &c->pontos_turisticos);   
}

// Função para calcular PIB per capita
float calcula_pib_per_capita(Cidade c) {
    if (c.pop == 0) return 0;
    return (c.pib * 1000000000) / (c.pop * 1000); // Convertendo PIB para reais e população para habitantes
}

// Função para calcular o Super Poder
float calcula_super_poder(Cidade c) {
    return c.pop + c.area + c.pib + c.pontos_turisticos; // Soma das propriedades
}

// Função para saída de dados
void saida_dados(Cidade c) {
    char codigo_carta[4];
    snprintf(codigo_carta, sizeof(codigo_carta), "%c%02d", c.estado, c.numero_da_cidade);
    printf("\nEstado: %c\n", c.estado); 
    printf("Código da carta: %s\n", codigo_carta); 
    printf("Nome da Cidade: %s\n", c.cidade);
    printf("População: %d mil habitantes\n", c.pop);
    printf("Área: %.2f km²\n", c.area); 
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Número de pontos turísticos: %d\n", c.pontos_turisticos); 
    printf("PIB per capita: %.2f reais\n", calcula_pib_per_capita(c)); // Exibe o PIB per capita
    printf("Super Poder: %.2f\n", calcula_super_poder(c)); // Exibe o Super Poder
    printf("CARTA CADASTRADA COM SUCESSO!\n");
}

// Função para comparar duas cartas
void comparar_cartas(Cidade c1, Cidade c2) {
    printf("\nComparando cartas:\n");
    
    // Comparação da Densidade Populacional
    printf("Densidade Populacional:\n");
    if (c1.pop < c2.pop) {
        printf("A carta 1 (Cidade: %s) vence com menor população: %d mil habitantes\n", c1.cidade, c1.pop);
    } else {
        printf("A carta 2 (Cidade: %s) vence com menor população: %d mil habitantes\n", c2.cidade, c2.pop);
    }

    // Comparação da Área
    printf("Área:\n");
    if (c1.area > c2.area) {
        printf("A carta 1 (Cidade: %s) vence com maior área: %.2f km²\n", c1.cidade, c1.area);
    } else {
        printf("A carta 2 (Cidade: %s) vence com maior área: %.2f km²\n", c2.cidade, c2.area);
    }

    // Comparação do PIB
    printf("PIB:\n");
    if (c1.pib > c2.pib) {
        printf("A carta 1 (Cidade: %s) vence com maior PIB: %.2f bilhões de reais\n", c1.cidade, c1.pib);
    } else {
        printf("A carta 2 (Cidade: %s) vence com maior PIB: %.2f bilhões de reais\n", c2.cidade, c2.pib);
    }

    // Comparação do Número de Pontos Turísticos
    printf("Número de Pontos Turísticos:\n");
    if (c1.pontos_turisticos > c2.pontos_turisticos) {
        printf("A carta 1 (Cidade: %s) vence com mais pontos turísticos: %d\n", c1.cidade, c1.pontos_turisticos);
    } else {
        printf("A carta 2 (Cidade: %s) vence com mais pontos turísticos: %d\n", c2.cidade, c2.pontos_turisticos);
    }

    // Comparação do Super Poder
    printf("Super Poder:\n");
    if (calcula_super_poder(c1) > calcula_super_poder(c2)) {
        printf("A carta 1 (Cidade: %s) vence com Super Poder: %.2f\n", c1.cidade, calcula_super_poder(c1));
    } else {
        printf("A carta 2 (Cidade: %s) vence com Super Poder: %.2f\n", c2.cidade, calcula_super_poder(c2));
    }
}

int main() {
    // Declaração de variáveis do tipo Cidade
    Cidade c1, c2;

    // Entrada nos dados da primeira carta
    printf("Cadastro da primeira carta:\n");
    entrada_dados(&c1);
    saida_dados(c1);

    // Entrada nos dados da segunda carta
    printf("\nCadastro da segunda carta:\n");
    entrada_dados(&c2);
    saida_dados(c2);

    // Comparar as duas cartas
    comparar_cartas(c1, c2);

    return 0; 
}
