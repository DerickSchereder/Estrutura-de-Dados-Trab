#include <stdlib.h>
#include <string.h>

typedef struct Nodo{
    char jogo[256];
    float horas;
    struct Nodo *esq;
    struct Nodo *dir;
}Nodo;

typedef struct ARVORE_INFO{
    Nodo* raiz;
    char nome[64];
    int numero_nodos;
    int altura;
    int rotacoes;
    int comparacoes;
}ARVORE_INFO;


extern float horas_totais; //variável para contar as horas acumuladas dos jogos

extern int comp; //variável para contar o número de comparações

extern int numero_nodos; 

extern int rotacoes;


Nodo* consulta(Nodo *a, char *chave);

Nodo* ABP_insere(Nodo *a, char *titulo, float horas);

int altura(Nodo *a);

void destroi(Nodo *a);

void destroi_arvores(ARVORE_INFO arvores[], int tam);

ARVORE_INFO gera_info(Nodo *a, char *nome);

