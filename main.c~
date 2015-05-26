/*-----------------------------------------------------------
*          UNIFAL – Universidade Federal de Alfenas.        
 * Trabalho..: Editor de Legendas usando lista encadeada    
 * Disciplina: Estrutura de Dados I                         
 * Professor.: Luiz Eduardo da Silva                        
 * Aluno(s)..: Beatriz de Oliveira Rodrigues
 *             Maurício Roque Vidal                             
 *             Monica de Cassia Roncada 
 *             Willian de Souza Soares       
 * Data......: 27/05/2015                                   
 *------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculo_hora.h"
#include "legenda.h"

/*
 * 
 */
 int menu() {
    int escolha;
    printf("---------------------------MENU-------------------------------\n");
    printf("| 1 - Inserir legenda                                        |\n");
    printf("| 2 - Remover uma Legenda                                    |\n");
    printf("| 3 - Consultar legendas                                     |\n");
    printf("| 4 - Atualizar Legendas                                     |\n");
    printf("| 5- Atualizaar Tempo                                        |\n");
    printf("| 6 - Sair                                                   |\n");
    printf("\n");
    printf("Qual a atividade desejada? ");
    scanf("%d", &escolha);

    return escolha;
}

int leArquivo(Legenda *L, char nomeDoArquivo[30]) {
    int numero;
    char inicial[13], final[13], seta[4];
    Texto t = NULL;

    FILE *arq = fopen(nomeDoArquivo, 'r');
    if (!(*arq)) {
        return 0;
    }
    while (fscanf(arq, "%d", &numero) != EOF) {
        sscanf(arq, "%s%s%s", inicial, seta, final);
        t = leTextoLegenda(arq);
        * L = inserirLegenda(*L, numero, inicial, final, t);
    }
    fclose(arq);
    return 1;
}


int main(int argc, char** argv) {
    FILE * arq = NULL;
    Legenda L = NULL;
    char nomeDoArquivo[30];
    printf("Digite o nome do arquivo: \n");
    scanf(" %30[^\n]", nomeDoArquivo);

    while (strstr(nomeDoArquivo, ".srt") == NULL) {
        printf("Digite o nome do arquivo com a extensão '.srt': ");
        scanf(" %30[^\n]", nomeDoArquivo);
    }
    if (!leArquivo(&L, nomeDoArquivo)) {
        arq = fopen(nomeDoArquivo, "w");
    }
    int menu;
    while ((menu = menu()) != 6) {

        switch (menu) {
            case 1:
                int numLegenda;
                char tempoInicial[13], tempoFinal[13];
                Texto t;
                printf("Digite o número da legenda");
                scanf("%d", &numLegenda);
                printf("Digite o TEMPO INICIAL: ");
                scanf("%s", &tempoInicial);
                printf("Digite o TEMPO FINAL: ");
                scanf("%s", &tempoFinal);
                printf("Escreva o texto da legenda: ");
                t = escreveLegenda();
                L = inserirLegenda(L,numLegenda,tempoInicial,tempoFinal,t);                
                break;
            case 2:
                int numLegenda;
                printf("Digite o número da legenda a ser retirada: ");
                scanf("%d", &numLegenda);
                retiraLegenda(L,numLegenda);
                printf("Legenda Retirada com Sucesso!");
                break;
            case 3:
                // ???????
                break;
            case 4:
                int numLegenda;
                char tempoInicial[13], tempoFinal[13];
                Texto t;
                
                printf("Digite o número da legenda");
                scanf("%d", &numLegenda);
                printf("Digite o TEMPO INICIAL: ");
                scanf("%s", &tempoInicial);
                printf("Digite o TEMPO FINAL: ");
                scanf("%s", &tempoFinal);
                printf("Escreva o texto da legenda: ");
                t = escreveLegenda();
                atualizaLegenda(L,tempoInicial,tempoFinal,t,numLegenda);
                printf("Legenda atualizada com sucesso!\n");
                break;
            case 5:
                int numLegenda, tempo;
                char medida;                
                printf("Digite o numero da legenda a ser adicionado o tempo: ");
                scanf("%d", &numLegenda);
                printf("Digite a medida de tempo (h/m/s/ms): ");
                scanf("%c", &medida);
                printf("Digite a quantidade de tempo que deseja adicionar: ");
                scanf("%d", tempo);
                atualizarTempo(L,numLegenda,tempo,medida);
                printf("Tempo atualizado com sucesso!");
                break;
        }
    }

    return (EXIT_SUCCESS);
}


