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
#include<stdio.h>
#include<stdlib.h>
#ifndef TEXTO_H
#define	TEXTO_H
typedef struct n No;

typedef struct n {
    char info;
    No *prox;
} *Texto;


Texto leTextoLegenda(FILE * arq) {
    Texto T = NULL, ant, aux;
    ant = NULL;
    char c;
    int cont10 = 0, cont13 = 0;
    do {
        fscanf(arq, "%c", &c);
        aux = (Texto) malloc(sizeof (No));
        aux->info = c;
        aux->prox = NULL;
        if (ant)
            ant->prox = aux;
        if (!T)
            T = aux;
        ant = aux;
        if(c == 10){
            cont10++;
        }else if(c == 13){
            cont13++;
        }else{
            cont10 = 0;
            cont13 = 0;
        }
    } while (cont10 != 2 || cont13 != 2);

    return T;
}

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

void mostraTextoLegenda(Texto t) {
    while (t) {
        printf("%c", t->info);
        t = t->prox;
    }
}


void desalocaTexto(Texto *t) {
    while (*t) {
        Texto aux = *t;
        (*t) = (*t)->prox;
        free(aux);
    }

}

#endif	/* TEXTO_H */

