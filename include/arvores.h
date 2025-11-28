#include <stdlib.h>
#include <string.h>

typedef struct Nodo{
    char jogo[256];
    float horas;
    struct Nodo *esq;
    struct Nodo *dir;
    int fator;
}Nodo;

typedef struct ARVORE_INFO{
    Nodo* raiz;
    char nome[64];
    int numero_nodos;
    int altura;
    int rotacoes;
    int comparacoes;
}ARVORE_INFO;


extern float horas_totais; 

extern int comp; 

extern int numero_nodos; 

extern int rotacoes;


Nodo* consulta(Nodo *a, char *chave);

Nodo* ABP_insere(Nodo *a, char *titulo, float horas);

Nodo* AVL_insere(Nodo *a, char *titulo, float horas, int* ok);

int altura(Nodo *a);

void destroi(Nodo *a);

void destroi_arvores(ARVORE_INFO arvores[], int tam);

ARVORE_INFO gera_info(Nodo *a, char *nome);

Nodo* Caso1 (Nodo *a , int *ok);
Nodo* Caso2 (Nodo *a , int *ok);

Nodo* rotacao_dupla_esquerda (Nodo *p);
Nodo* rotacao_dupla_direita (Nodo *p);
Nodo* rotacao_esquerda (Nodo *p);
Nodo* rotacao_direita (Nodo *p);