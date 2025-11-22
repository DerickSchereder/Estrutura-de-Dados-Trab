#include "arvores.h"
#include <stdio.h>
#include <string.h>

int comp = 0;
float horas_totais = 0;
int numero_nodos = 0;
int rotacoes = 0;

// Função que consulta se um jogo está na árvore, atualiza o número de comparações
Nodo* consulta(Nodo *a, char *chave){
    while (a != NULL){
    comp++;
        if (!strcmp(a->jogo, chave)){
        return a;
        } else {
            if (strcmp(a->jogo, chave) > 0)
                a = a->esq;
            else
                a = a->dir;
        }
    }
    return NULL;
}


Nodo* ABP_insere(Nodo *a, char *titulo, float horas)
{
    
    if (a == NULL)
    {
        a = (Nodo*) malloc(sizeof(Nodo));
        if(!a) return NULL;

        strcpy(a->jogo, titulo);
        a->horas = horas;
        a->esq = NULL;
        a->dir = NULL;
        numero_nodos++;
        return a;
    }
    int cmp = strcmp(titulo, a->jogo);
    if (cmp < 0) //strcmp retorna um valor negativo se a primeira string vem antes em ordem alfabetica
        a->esq = ABP_insere(a->esq,titulo,horas);
    else if (cmp > 0)
        a->dir = ABP_insere(a->dir,titulo,horas);
        
    return a;
}

int altura(Nodo *a)
{
     if (a == NULL)
        return 0;

    int h_esq = altura(a->esq);
    int h_dir = altura(a->dir);

    return 1 + (h_esq > h_dir ? h_esq : h_dir);
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
    info.numero_nodos = numero_nodos;
    info.comparacoes = 0;
    info.rotacoes = 0;
    return info;

}
