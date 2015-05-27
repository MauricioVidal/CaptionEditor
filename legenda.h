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
#include "calculo_hora.h"

#ifndef LEGENDA_H
#define	LEGENDA_H
typedef struct no Item;

typedef struct no {
    char inicio[13];
    char fim[13];
    Texto texto;
    Item *proximo;
} *Legenda;

Legenda iniciarLegenda() {
    return NULL;
}

int conflito(Legenda ant, Legenda prox, char inicio[13], char fim[13]) {
    if (ant) {
        if ((horaMenor(ant->inicio, inicio) && horaMenor(inicio, ant->fim)) ||
                (horaMenor(ant->inicio, fim) && horaMenor(fim, ant->fim)) ||
                (horaMenor(inicio, ant->inicio) && horaMenor(ant->inicio, fim)) ||
                (horaMenor(inicio, ant->fim) && horaMenor(ant->fim, fim)) ||
                horaIgual(ant->inicio, inicio))
            return 1;
    }
    if (prox) {
        if ((horaMenor(prox->inicio, inicio) && horaMenor(inicio, prox->fim)) ||
                (horaMenor(prox->inicio, fim) && horaMenor(fim, prox->fim)) ||
                (horaMenor(inicio, prox->inicio) && horaMenor(prox->inicio, fim)) ||
                (horaMenor(inicio, prox->fim) && horaMenor(prox->fim, fim)) ||
                horaIgual(prox->inicio, inicio))
            return 1;
    }
    return 0;
}

Legenda inserirLegenda(Legenda L, int num, char inicial[13], char final[13], Texto texto) {
    Legenda ptNo, ant, aux;
    int i = 1;
    ptNo = (Legenda) malloc(sizeof (Item));
    if (!ptNo)
        printf("Lista de legenda cheia!\n");
    else {
        ant = NULL;
        aux = L;
        while (aux && i < num) {
            ant = aux;
            aux = aux->proximo;
            i++;
        }
        if (i > num) {
            printf("Não encontrado a legenda\n");
            desalocaTexto(&texto);
        } else {
            strcpy(ptNo->inicio, inicial);
            strcpy(ptNo->fim, final);
            ptNo->texto = texto;
            if (!conflito(ant, aux, inicial, final) && horaMaior(final, inicial)) {
                if (!ant) {
                    ptNo->proximo = L;
                    L = ptNo;
                } else {
                    ptNo->proximo = ant->proximo;
                    ant->proximo = ptNo;
                }
            } else {
                desalocaTexto(&(ptNo->texto));
                free(ptNo);
                printf("Há conflito nos horarios!\n");
            }
        }
    }
    return L;
}

void retiraLegenda(Legenda *L, int num) {
    if (!*L)
        printf("Lista de legendas vazia!\n");
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
            printf("Não encontrado a legenda\n");
        else {
            if (!ant)
                *L = aux->proximo;
            else
                ant->proximo = aux->proximo;
            if (aux->texto) {
                desalocaTexto(&(aux->texto));
            }
            free(aux);
        }
    }
}

void consultarLegenda(Legenda L, char inicial[30]) {
    int num = 1, cont = 0;
    if (!L)
        printf("Lista de legendas vazia!\n");
    else {
        while (L && !horaIgual(inicial, L->inicio) && !horaMenor(inicial, L->inicio)) {
            L = L->proximo;
            num++;
        }
        if (!L)
            printf("Não encontrado\n");
        else {
            while (L && cont < 5) {
                printf("%d\r\n", num);
                printf("%s --> %s\r\n", L->inicio, L->fim);
                mostraTextoLegenda(L->texto);
                cont++;
                num++;
                L = L->proximo;
            }
        }
    }
}

void atualizaLegenda(Legenda *L, char inicial[13], char final[13], Texto texto, int num) {
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
            if (horaMaior(final, inicial)) {
                if (!conflito(ant, aux->proximo, inicial, final)) {
                    strcpy(aux->inicio, inicial);
                    strcpy(aux->fim, final);
                    aux->texto = texto;
                } else {
                    printf("Conflito de legendas!\n");
                }
            }else{
                printf("Tempo invalido.");
            }
        }
    }

}

void atualizarTempo(Legenda *L, int num, int tempo, char id) {
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
                somaTempo(aux->inicio, aux->fim, tempo, id);
                aux = aux->proximo;
            }
        }
    }

}
#endif	/* LEGENDA_H */

