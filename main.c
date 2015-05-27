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
    printf(" __________________________MENU______________________________|\\n");
    printf("| 1 - Inserir legenda                                        |\n");
    printf("| 2 - Remover uma Legenda                                    |\n");
    printf("| 3 - Consultar legendas                                     |\n");
    printf("| 4 - Atualizar Legendas                                     |\n");
    printf("| 5 - Atualizar Tempo                                        |\n");
    printf("| 6 - Sair                                                   |\n");
    printf("|____________________________________________________________|\n");
    printf("\n");
    printf("Qual a atividade desejada? ");
    scanf("%d", &escolha);

    return escolha;
}

int leArquivo(Legenda *L, char nomeDoArquivo[30]) {
    int numero;
    char inicial[13], final[13], seta[4], c;
    Texto t = NULL;
    FILE *arq = fopen(nomeDoArquivo, "r");
    if (!arq) {
        return 0;
    }
    while (fscanf(arq, "%d", &numero) != EOF) {
        fscanf(arq, "%s", inicial);
        fscanf(arq, "%s", seta);
        fscanf(arq, "%s", final);
        fscanf(arq, "%c", &c);
        fscanf(arq, "%c", &c);
        t = leTextoLegenda(arq);
        *L = inserirLegenda(*L, numero, inicial, final, t);
    }
    fclose(arq);
    return 1;
}

void escreverLegendaArquivo(Legenda *L, FILE *arq, char nomeDoArquivo[30]){
    arq = fopen(nomeDoArquivo, "w");
    int i=1;
    while(*L){
        fprintf(arq, "%d\r\n", i);
        fprintf(arq, "%s --> %s\r\n", (*L)->inicio, (*L)->fim);
        while((*L)->texto){
            fprintf(arq, "%c", (*L)->texto->info);
            Texto t = (*L)->texto;
            (*L)->texto = (*L)->texto->prox;
            free(t);
        }
        Legenda l = *L;
        *L = (*L)->proximo;
        free(l);
        i++;
    }
    fclose(arq);
}



int main(int argc, char** argv) {
    FILE * arq = NULL;
    Legenda L = iniciarLegenda();
    char nomeDoArquivo[100];
    printf("Digite o nome do arquivo: \n");
    scanf(" %100[^\n]", nomeDoArquivo);

    while (strstr(nomeDoArquivo, ".srt") == NULL) {
        printf("Digite o nome do arquivo com a extensão '.srt': ");
        scanf(" %100[^\n]", nomeDoArquivo);
    }
    if (!leArquivo(&L, nomeDoArquivo))
        printf("Arquivo não encontado!\n");
    int m = 0;
    int numLegenda, tempo;
    char tempoInicial[13], tempoFinal[13], medida;
    Texto t;
    while ((m = menu()) != 6) {
        switch (m) {
            case 1:
                printf("Digite o número da legenda: ");
                scanf(" %d", &numLegenda);
                printf("Digite o TEMPO INICIAL[00:00:00,000]: ");
                scanf(" %12[^\n]", tempoInicial);
                printf("Digite o TEMPO FINAL[00:00:00,000]: ");
                scanf(" %12[^\n]", tempoFinal);
                printf("Escreva o texto da legenda: ");
                t = escreveLegenda();
                L = inserirLegenda(L, numLegenda, tempoInicial, tempoFinal, t);
                break;
            case 2:
                printf("Digite o número da legenda a ser retirada: ");
                scanf(" %d", &numLegenda);
                retiraLegenda(&L, numLegenda);
                printf("Legenda Retirada com Sucesso!\n");
                break;
            case 3:
                printf("Digite o tempo que deseja pesquisar a legenda[00:00:00,000]: ");
                scanf(" %12[^\n]", tempoInicial);
                consultarLegenda(L,tempoInicial);
                break;
            case 4:
                printf("Digite o número da legenda: ");
                scanf(" %d", &numLegenda);
                printf("Digite o TEMPO INICIAL[00:00:00,000]: ");
                scanf(" %12[^\n]", tempoInicial);
                printf("Digite o TEMPO FINAL[00:00:00,000]: ");
                scanf(" %12[^\n]", tempoFinal);
                printf("Escreva o texto da legenda: ");
                t = escreveLegenda();
                atualizaLegenda(&L, tempoInicial, tempoFinal, t, numLegenda);
                printf("Legenda atualizada com sucesso!\n");
                break;
            case 5:
                printf("Digite o numero da legenda a ser adicionado o tempo: ");
                scanf(" %d", &numLegenda);
                printf("Digite a medida de tempo (h/m/s/l): ");
                scanf(" %c", &medida);
                printf("Digite a quantidade de tempo que deseja adicionar: ");
                scanf(" %d", &tempo);
                atualizarTempo(&L, numLegenda, tempo, medida);
                printf("Tempo atualizado com sucesso!\n");
                break;
        }
    }
    escreverLegendaArquivo(&L, arq, nomeDoArquivo);
    return (EXIT_SUCCESS);
}


