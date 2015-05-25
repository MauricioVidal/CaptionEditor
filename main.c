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

int leArquivo(Legenda *L){
    int numero;
    char inicial[13], final[13], seta[4];
    Texto t = NULL;
    
    FILE *arq  = fopen(nomeDoArquivo, 'r');
    if(!(*arq)){
        return 0;
    }
    while(fscanf(arq, "%d",&numero) != EOF){
        sscanf(arq,"%s%s%s",inicial,seta,final);
        t = leTextoLegenda(arq);
        inserirLegenda(*L, numero,inicial, final, t);
    }

}

int main(int argc, char** argv) {
    Legenda L = NULL;
    char nomeDoArquivo[30];
    printf("Digite o nome do arquivo: \n");
    scanf(" %30[^\n]", nomeDoArquivo);

    while (strstr(nomeDoArquivo, ".srt") == NULL) {
       printf("Digite o nome do arquivo com a extensão '.srt': ");
       scanf(" %30[^\n]", nomeDoArquivo);
    }

    leArquivo(&L);
    
    return (EXIT_SUCCESS);
}

/*
int main(int argc, char** argv) {
    char c;
    FILE *arq = fopen("l.srt", "r");
    while(fscanf(arq, "%c", &c)!= EOF){
        printf("(%d) - %c\n", c,c);
    }
    
    return (EXIT_SUCCESS);
}
*/


