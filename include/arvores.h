#include <stdlib.h>
#include <string.h>

typedef struct Nodo{
    char jogo[256];
    float horas;
    struct Nodo *esq;
    struct Nodo *dir;
}Nodo;

extern int comp; //variável para contar o número de comparações

extern float horas_totais; //variável para contar as horas acumuladas dos jogos

extern int numero_nodos; 

extern int altura;

Nodo* consulta(Nodo *a, char *chave);

Nodo* ABP_insere(Nodo *a, char *titulo, float horas);

void destroi(Nodo *a);

int altura(Nodo *a);