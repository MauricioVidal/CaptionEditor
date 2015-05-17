/* 
 * File:   texto.h
 * Author: a14020
 *
 * Created on 8 de Maio de 2015, 11:31
 */
#include<stdio.h>
#include<stdlib.h>
#ifndef TEXTO_H
#define	TEXTO_H
typedef struct n No;

typedef struct n {
    char info;
    No *prox;
} *Texto;

Texto escreveLegenda() {
    Texto T = NULL, ant, aux;
    ant = NULL;
    char c;
    printf("Digite '#' para finalizar!");
    while ((c = getchar()) != '#') {
        aux = (Texto) malloc(sizeof (No));
        aux->info = c;
        aux->prox = NULL;
        if (ant)
            ant->prox = aux;
        if (!T)
            T = aux;
        ant = aux;
    }
    
    return T;
}

void mostraLegenda(Texto t) {
    while (t) {
        printf("%c", t->info);
        t = t->prox;
    }
}


#endif	/* TEXTO_H */

