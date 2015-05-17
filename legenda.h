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

#include <stdlib.h>
#include <stdio.h>
#include "texto.h"

#ifndef LEGENDA_H
#define	LEGENDA_H
typedef struct no Item;

typedef struct no {
    char inicio[30];
    char fim[30];
    Texto texto;
    Item *proximo;
} *Legenda;

Legenda iniciarLegenda() {
    return NULL;
}

Legenda inserirLegenda(Legenda L, int num, char inicial[30], char final[30], Texto texto) {
    Legenda ptNo, ant, aux;
    int i = 1;
    ptNo = (Legenda) malloc(sizeof (Item));
    if (!ptNo)
        printf("Lista de legenda cheia!");
    else {
        ant = NULL;
        aux = L;
        while (aux && i < num) {
            ant = aux;
            aux = aux->proximo;
            i++;
        }
        strcpy(ptNo->inicio, inicial);
        strcpy(ptNo->fim, final);
        ptNo->texto = texto;
        //Compara disponibilidade da legenda estar na posicao.
        if (!ant) {
            ptNo->proximo = L;
            L = ptNo;
        } else {
            ptNo->proximo = ant->proximo;
            ant->proximo = ptNo;
        }
    }
    return L;
}

void desalocaTexto(Texto *t) {
    while (*t) {
        Texto aux = *t;
        (*t) = (*t)->prox;
        free(aux);
    }

}

void retiraLegenda(Legenda *L, int num) {
    if (!*L)
        printf("Lista de legendas vazia!");
    else {
        int i = 1;
        Legenda aux, ant;
        aux = *L;
        ant = NULL;
        while (aux && i < num) {
            ant = aux;
            aux = aux->proximo;
            i++;
        }
        if (!aux || i > num)
            printf("Não encontrado a legenda");
        else {
            if (!ant)
                *L = aux->proximo;
            else
                ant->proximo = aux->proximo;
            if (aux->texto){
                desalocaTexto(&(aux->texto));
            }
            free(aux);
        }
    }
}

Legenda consultarLegenda(Legenda L, char inicial[30]) {
    return NULL;
}

void atualizaLegenda(Legenda *L, char inicial[30], char final[30], Texto texto, int num) {
    if (!*L)
        printf("Lista de legendas vazia!");
    else {
        int i = 1;
        Legenda aux, ant;
        aux = *L;
        ant = NULL;
        while (aux && i < num) {
            ant = aux;
            aux = aux->proximo;
            i++;
        }
        if (!aux || i > num)
            printf("Não encontrado a legenda");
        else {
            strcpy(aux->inicio, inicial);
            strcpy(aux->fim, final);
            aux->texto = texto;
        }
    }

}

void funcaoTempo() {
}

void atualizarTempo(Legenda *L, int num, int tempo, char medida) {
    if (!*L)
        printf("Lista de legendas vazia!");
    else {
        int i = 1;
        Legenda aux, ant;
        aux = *L;
        ant = NULL;
        while (aux && i < num) {
            ant = aux;
            aux = aux->proximo;
            i++;
        }
        if (!aux || i > num)
            printf("Não encontrado a legenda");
        else {
            while (aux) {
                aux = aux->proximo;
                funcaoTempo();
            }
        }
    }

}
#endif	/* LEGENDA_H */

