#include "arvores.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct ARVORE_INFO{
    char nome[64];
    int numero_nodos;
    int altura;
    int rotacoes;
    int comparacoes;
}ARVORE_INFO;

Nodo* converte_ABP(FILE *arq); // recebe o arquivo csv e retorna uma ABP os jogos por ordem alfabética

void cria_relatorio(char arq[], ARVORE_INFO arvores[], int numero_arvores);