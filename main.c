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
    
    Legenda L = iniciarLegenda();
    L = inserirLegenda(L, 1, "300", "teste1",NULL);
    L = inserirLegenda(L, 2, "300", "teste2",NULL);
    L = inserirLegenda(L, 3, "300", "teste3",NULL);
    L = inserirLegenda(L, 4, "300", "teste4",NULL);
    
    printf("%s", L->fim);
    printf("%s", L->proximo->fim);
    printf("%s", L->proximo->proximo->fim);
    printf("%s", L->proximo->proximo->proximo->fim);
    
    atualizaLegenda(&L,"300", "teste_teste", NULL, 1);
    
    printf("\n%s\n", L->fim);
    printf("%s\n", L->proximo->fim);
    printf("%s\n", L->proximo->proximo->fim);
    printf("%s\n", L->proximo->proximo->proximo->fim);
    retiraLegenda(&L, 1);
    retiraLegenda(&L, 1);
    retiraLegenda(&L, 1);
    
    
    return (EXIT_SUCCESS);
}



