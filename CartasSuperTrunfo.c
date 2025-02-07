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
     //  Exibe mensagem para o usuário informar uma letra via terminal de comando.
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &c->estado);//c é um ponteiro para uma estrutura, e -> é o operador usado para acessar membros de uma estrutura através de um ponteiro.
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

// Função para saída de dados
void saida_dados(Cidade c) {
    char codigo_carta[4]; // Declaração da variável
     // Gera o código da carta com base no estado e no número da cidade.
     //A função snprintf formata e armazena uma string em um buffer.
    snprintf(codigo_carta, sizeof(codigo_carta), "%c%02d", c.estado, c.numero_da_cidade);
    //Exibe Saída de dados  estado da carta via terminal de comando.
    printf("\nEstado: %c\n", c.estado); 
    printf("Código da carta: %s\n", codigo_carta); 
    printf("Nome da Cidade: %s\n", c.cidade);
    printf("População: %d mil habitantes\n", c.pop);
    printf("Área: %.2f km²\n", c.area); 
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Número de pontos turísticos: %d\n", c.pontos_turisticos); 
    printf("PIB per capita: %.2f reais\n", calcula_pib_per_capita(c)); // Exibe o PIB per capita
    printf("CARTA CADASTRADA COM SUCESSO!\n");
}

int main() {
    // Declaração de uma variável do tipo Cidade
    Cidade c;

    // Entrada nos dados da carta via terminal de comando.
    entrada_dados(&c);
    
    // Saída de dados
    saida_dados(c);
    //Indica que o programa foi executado com sucesso.
    return 0; 
}
