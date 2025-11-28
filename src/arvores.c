#include "arvores.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

    return 1 + ((h_esq > h_dir) ? h_esq : h_dir);
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

ARVORE_INFO gera_info(Nodo *a, char *nome, int* rot)
{
    ARVORE_INFO info;
    strcpy(info.nome, nome);
    info.raiz = a;
    info.altura = altura(a);
    info.numero_nodos = numero_nodos;
    info.comparacoes = 0;
    info.rotacoes = *rot;
    return info;

}

Nodo* AVL_insere(Nodo *a, char *titulo, float horas, int *ok, int* rot)
{
    
    if (a == NULL)
    {
        a = (Nodo*) malloc(sizeof(Nodo));
        if(!a) return NULL;

        strcpy(a->jogo, titulo);
        a->horas = horas;
        a->esq = NULL;
        a->dir = NULL;
        a->fator = 0;
        numero_nodos++;
        *ok = 1;
        return a;
    }
    int cmp = strcmp(titulo, a->jogo); 
    if (cmp < 0) //strcmp retorna um valor negativo se a primeira string vem antes em ordem alfabetica
    {
        a->esq = AVL_insere(a->esq,titulo,horas, ok, rot);
        if (*ok) {
            switch (a->fator) {
                case -1: a->fator = 0; *ok = 0; break;
                case 0: a->fator = 1; break;
                case 1: a=Caso1(a,ok); *rot += 1; break;
            }
        }
    }
    else if (cmp > 0)
    {
        a->dir = AVL_insere(a->dir,titulo,horas, ok, rot);
        if (*ok) {
            switch (a->fator) {
                case 1: a->fator = 0; *ok = 0; break;
                case 0: a->fator = -1; break;
                case -1: a = Caso2(a,ok); *rot += 1; break;
            }
        }
    }
        
    return a;
}

Nodo* rotacao_direita(Nodo* p)
{
    Nodo *u;
    u = p->esq;
    p->esq = u->dir;
    u->dir = p;
    p->fator = 0;
    p = u;
    return p;
}

Nodo* rotacao_esquerda(Nodo* p)
{
    Nodo *u;
    u = p->dir;
    p->dir = u->esq;
    u->esq = p;
    p->fator = 0;
    p = u;
    return p;
}

Nodo* rotacao_dupla_direita (Nodo* p)
{
    Nodo *u, *v;
    u = p->esq;
    v = u->dir;
    u->dir = v->esq;
    v->esq = u;
    p->esq = v->dir;
    v->dir = p;

    if (v->fator == 1)
        p->fator = -1;
    else 
        p->fator = 0;

    if (v->fator == -1)
        u->fator = 1;
    else
        u->fator = 0;
    p = v;
    return p;
}

Nodo* rotacao_dupla_esquerda (Nodo *p){
Nodo *z, *y;
z = p->dir;
y = z->esq;
z->esq = y->dir;
y->dir = z;
p->dir = y->esq;
y->esq = p;
if (y->fator == -1) p->fator = 1;
else p->fator = 0;
if (y->fator == 1) z->fator = -1;
else z->fator = 0;
p = y;
return p;
}

Nodo* Caso1 (Nodo *a , int *ok)
{
Nodo *z;
z = a->esq;
if (z->fator == 1)
a = rotacao_direita(a);
else
a = rotacao_dupla_direita(a);
a->fator = 0;
*ok = 0;
return a;
}

Nodo* Caso2 (Nodo *a , int *ok)
{
Nodo *z;
z = a->dir;
if (z->fator == -1)
a = rotacao_esquerda(a);
else
a = rotacao_dupla_esquerda(a);
a->fator = 0;
*ok = 0;
return a;
}