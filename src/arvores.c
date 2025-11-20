#include "arvores.h"
#include <stdio.h>
#include <string.h>

int comp = 0;
float horas_totais = 0;
int numero_nodos = 0;

// Função que consulta um jogo está na árvore, atualiza o número de comparações e horas totais
Nodo* consulta(Nodo *a, char *chave){
    while (a != NULL){
        comp++;
        int cmp = strcmp(a->jogo, chave);

        if (cmp == 0){
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
        numero_nodos++;

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

int altura(Nodo *a)
{
    if(a == NULL)
    {
        return 0;
    }
    else
    {
        if(altura(a->dir ) > altura(a->esq))
        {
            return altura(a->dir) + 1;
        }
        else
        {
            return altura(a->esq) + 1;
        }
    }
}

void destroi(Nodo *a)
{
    if (a == NULL) return;

    destroi(a->esq);
    destroi(a->dir);
    free(a);
}

void destroi_arvores(ARVORE_INFO arvores[], int tam)
{
    for(int i = 0; i < tam; i++){
        destroi(arvores[i].raiz);
    }

}

ARVORE_INFO gera_info(Nodo *a, char *nome)
{
    ARVORE_INFO info;
    strcpy(info.nome, nome);
    info.raiz = a;
    info.altura = altura(a);
    info.numero_nodos = 0;
    info.comparacoes = 0;
    info.rotacoes = 0;
    return info;

}
