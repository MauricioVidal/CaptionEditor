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

int main(int argc, char** argv) {
    char nomeDoArquivo[30];
    printf("Digite o nome do arquivo: \n");
    scanf(" %s", nomeDoArquivo);
    FILE *arq = fopen(nomeDoArquivo, 'r');
    if(!(*arq)){
        *arq = fopen(nomeDoArquivo, 'w');
    }
    
    return (EXIT_SUCCESS);
}



