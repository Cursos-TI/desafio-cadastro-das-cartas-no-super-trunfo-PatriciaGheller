
#include <stdio.h>

int main(){
    // Declaração de variáveis para armazenamento de dados.
    int pop, pontos_turisticos;   
    char cidade[30];               
    float area, pib;              
    char estado;                      
    char codigo_carta[4];            

         // Entrada nos dados da carta via terminal de comando:
       
        printf("Digite o Estado (A-H): ");
         //  Exibe mensagem para o usuário informar uma letra via terminal de comando.
        scanf(" %c", &estado);         
        // Entra com a letra da carta via terminal de comando. 
        printf("Digite o nome da Cidade: ");
        // Exibe mensagem para o usuário informar o nome da cidade via terminal de comando.
        scanf(" %s", cidade);
        //Entra com o nome da cidade via terminal de comando.

        printf("Digite o código da carta: (1-4): ");
        // Exibe mensagem para o usuário informar o código da carta via terminal de comando.
        int numero_da_cidade;
        // Declaração de variável para armazenamento do número da cidade.
        scanf("%d", &numero_da_cidade); 
        //Entra com o número da Cidade via terminal de comando.
        printf("Digite a População: ");
        // Exibe mensagem para o usuário informar a população da cidade via terminal de comando.
        scanf("%d", &pop);         
        //Entra com os dados de população inseridos pelo usuário via terminal de comando.
        printf("Digite a Área: ");
        // Exibe mensagem para o usuário informar a área da cidade via terminal de comando.
        scanf("%f", &area);       
        // Entra com os dados da área inseridos pelo usuário via terminal de comando.
        printf("Digite o PIB: ");
        scanf("%f", &pib);      
        // Entra com os dados de PIB inseridos pelo usuário via terminal de comando.
        printf("Digite o Número de pontos turísticos: ");
        // Exibe mensagem para o usuário informar o número de pontos turísticos da cidade via terminal de comando.
        scanf("%d", &pontos_turisticos); 
        // Entra com os dados de pontos turísticos inseridos pelo usuário via terminal de comando.

        //Gerando código da carta

        /*Afunção snprintf () é usada para formatar strings e armazenar em codico_carta, evitando estouros de buffer.
        sizeof(codigo_carta): Tamanho do buffer, garantindo que não exceda sua capacidade.
        "%c%02d": Formato da string, onde %c é um caractere e %02d é um número com dois dígitos, preenchido com zero se necessário.*/

        snprintf(codigo_carta, sizeof(codigo_carta), "%c%02d", estado, numero_da_cidade);
        // Gera o código da carta com base no estado e no número da cidade.

        //Saída de dados                                                                           
       //Exibindo as informações da carta
   
        printf("\nEstado: %c\n", estado);  
        //Exibe Saída de dados  estado da carta via terminal de comando.
        printf("Código da carta: %s\n", codigo_carta); 
        //Exibe Saída de dados código da carta via terminal de comando.
        printf("Nome da Cidade: %s\n", cidade); 
        //Exibe Saída de dados nome da cidade via terminal de comando.
        printf("População: %d mil habitantes\n", pop); 
        //Exibe Saída de dados população da cidade via terminal de comando.
        printf("Área: %f km²\n", area); 
        //Exibe Saída de dados área da cidade via terminal de comando.
        printf("PIB: %.2f bilhões de reais\n", pib); 
        //Exibe Saída de dados PIB da cidade via terminal de comando.
        printf("Número de pontos turísticos: %d\n", pontos_turisticos); 
        // Exibe Saída de dados pontos turísticos da cidade via terminal de comando.

        printf("CARTA CADASTRADA COM SUCESSO!!!\n\n");

        return 0; 
        //Retorna 0, indicando que o programa foi executado com sucesso.
    }
