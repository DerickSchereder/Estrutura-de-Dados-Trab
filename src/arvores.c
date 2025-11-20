#include "arvores.h"
#include <stdio.h>
#include <string.h>

int comp = 0;
float horas_totais = 0;

Nodo* consulta(Nodo *a, char *chave){
    while (a != NULL){
        comp++;
        int cmp = strcmp(a->jogo, chave);

        if (cmp == 0){
           // printf("%s, horas: %.2f\n", a->jogo, a->horas);
            horas_totais+= a->horas;
            return a;}
        else if (cmp > 0)
            a = a->esq;
        else
            a = a->dir;
    }
    return NULL;
}

Nodo* ABP_insere(Nodo *a, char *titulo, float horas)
{


    if (a == NULL)
    {
        a = (Nodo*) malloc(sizeof(Nodo));
        strcpy(a->jogo, titulo);
        a->horas = horas;
        a->esq = NULL;
        a->dir = NULL;
        return a;
    }

    if (strcmp(titulo, a->jogo) < 0) //strcmp retorna um valor negativo se a primeira string vem antes em ordem alfabetica
        a->esq = ABP_insere(a->esq,titulo,horas);
    else
        a->dir = ABP_insere(a->dir,titulo,horas);
        
    return a;
}



void destroi(Nodo *a)
{
    if (a == NULL) return;

    destroi(a->esq);
    destroi(a->dir);
    free(a);
}
